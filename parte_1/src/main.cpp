#include <iostream>
#include <thread>

#include "monitor.h"
#include "constantes.h"

void productor(Monitor &monitor, int id) {
    std::cout << VERDE << "Soy el productor: " << BLANCO << id << "\n" << RESET_COLOR;
    monitor.agregarElemento(id);
}

void consumidor(Monitor &monitor, int id) {
    std::cout << ROJO << "Soy el consumidor: " << BLANCO << id << "\n" << RESET_COLOR;
    monitor.quitarElemento();
}

int main() {
    Monitor monitor;
    int cantidad = 5;

    std::vector<std::thread> hilos;

    // Productores
    for (int i = 0; i < cantidad; ++i) {
        hilos.push_back(std::thread(productor, std::ref(monitor), i));
    }
    
    for (auto &hilo : hilos) hilo.join();


    // Fase intermedia
    monitor.mostrarElementos();

    std::cout << std::endl;
    hilos.clear();

    // Consumidores
    for (int i = 0; i < cantidad; ++i) {
        hilos.push_back(std::thread(consumidor, std::ref(monitor), i));
    }
    for (auto &hilo : hilos) {
        hilo.join();
    }

    monitor.mostrarElementos();

    return 0;
}