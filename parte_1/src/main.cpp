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

int main() {
    Monitor monitor;
    int cantidad_productores = 5;
    int cantidad_consumidores = 5;

    std::vector<std::thread> hilos;

    // Productores
    for (int i = 0; i < cantidad_productores; ++i) {
        hilos.push_back(std::thread(productor, std::ref(monitor), i));
    }

    for (int i = 0; i < cantidad_consumidores + 1; ++i) {
        hilos.push_back(std::thread(consumidor, std::ref(monitor), i));
    }
    
    for (auto &hilo : hilos) hilo.join();

    hilos.clear();

    std::cout << BLANCO << "Elementos finales: ";
    monitor.mostrarElementos();

    return 0;
}