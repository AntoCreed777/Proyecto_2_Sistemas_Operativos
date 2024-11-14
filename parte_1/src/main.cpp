#include <iostream>
#include <thread>
#include "../include/monitor.h"
#include "../include/constantes.h"


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
    int cantidad_productores = 10;
    int cantidad_consumidores = 5;
    int tiempo_espera = 2; // En Segundos
    
    Monitor monitor(cantidad_productores, tiempo_espera);

    std::vector<std::thread> hilos;

    // Productores
    for (int i = 0; i < cantidad_productores; i++) {
        hilos.push_back(std::thread(productor, std::ref(monitor), i));
    }

    for (int i = 0; i < cantidad_consumidores; i++) {
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