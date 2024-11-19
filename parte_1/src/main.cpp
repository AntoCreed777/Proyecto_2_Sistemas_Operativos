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

void cargar_argumentos(int argc, char const *argv[], int &cantidad_productores, int &cantidad_consumidores, int &tamano_inicial_cola, int &tiempo_espera) {
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "-p") {
            cantidad_productores = std::stoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-c") {
            cantidad_consumidores = std::stoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-s") {
            tamano_inicial_cola = std::stoi(argv[i + 1]);
        } else if (std::string(argv[i]) == "-t") {
            tiempo_espera = std::stoi(argv[i + 1]);
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 9) {
        std::cerr << "Error: Argumentos invalidos" << std::endl;
        std::cerr << "Use: " << argv[0] << " -p <cantidad_productores> -c <cantidad_consumidores> -s <tamano_inicial_cola> -t <tiempo_espera>" << std::endl;
        return 1;
    }

    int cantidad_productores;
    int cantidad_consumidores;
    int tiempo_espera; // En Segundos
    int tamanio_inicial_cola;

    cargar_argumentos(argc, argv, cantidad_productores, cantidad_consumidores, tamanio_inicial_cola, tiempo_espera);

    if (cantidad_productores < 0 || cantidad_consumidores < 0 || tamanio_inicial_cola < 0 || tiempo_espera < 0) {
        std::cerr << "Error: Argumentos invalidos" << std::endl;
        std::cerr << "Use: " << argv[0] << " -p <cantidad_productores> -c <cantidad_consumidores> -s <tamano_inicial_cola> -t <tiempo_espera>" << std::endl;
        return 1;
    }
    
    Monitor monitor(cantidad_productores, tamanio_inicial_cola, tiempo_espera);

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