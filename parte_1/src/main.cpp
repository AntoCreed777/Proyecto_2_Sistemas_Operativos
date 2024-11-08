#include <iostream>
#include <thread>

#include "monitor.h"
#include "constantes.h"

void productor(Monitor &monitor, int id) {
    monitor.agregarElemento(id);

    std::cout << VERDE << "Productor: " << BLANCO << id << " " << RESET_COLOR;
    monitor.mostrarElementos();
}

void consumidor(Monitor &monitor, int id) {
    monitor.quitarElemento();

    std::cout << ROJO << "Consumidor: " << BLANCO << id << " " << RESET_COLOR;
    monitor.mostrarElementos();
}

void bloqueo(Monitor &monitor, int tiempo) {
    monitor.bloqueo(tiempo);
}

int main() {
    Monitor monitor;
    int cantidad_productores = 10;
    int cantidad_consumidores = 5;
    int tiempo_espera = 2; // En Segundos

    std::vector<std::thread> hilos;

    // Productores
    for (int i = 0; i < cantidad_productores; ++i) {
        hilos.push_back(std::thread(productor, std::ref(monitor), i));
    }
    
    for (auto &hilo : hilos) hilo.join();
    hilos.clear();

    // Intermedio
    hilos.push_back(std::thread(bloqueo, std::ref(monitor), tiempo_espera));
    hilos[0].join();
    hilos.clear();
    std::cout << std::endl;

    // Consumidores
    for (int i = 0; i < cantidad_consumidores; ++i) {
        hilos.push_back(std::thread(consumidor, std::ref(monitor), i));
    }

    for (auto &hilo : hilos) hilo.join();
    hilos.clear();

    // Final
    std::cout << std::endl;
    std::cout << BLANCO << "Elementos finales: ";
    monitor.mostrarElementos();

    return 0;
}