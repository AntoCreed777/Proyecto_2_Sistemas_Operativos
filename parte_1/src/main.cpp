#include <cstdio>
#include <iostream>
#include <thread>
#include <cctype>
#include <algorithm>
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

bool es_numero(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

void mensaje_error_argumentos(char const *argv[]) {
    std::cerr << ROJO << "Error: Argumentos invalidos" << RESET_COLOR << std::endl;
    std::cerr << AZUL << "Use: "<< AMARILLO << argv[0] << " -p <cantidad_productores> -c <cantidad_consumidores> -s <tamano_inicial_cola> -t <tiempo_espera>" << std::endl;
    exit(EXIT_FAILURE);
}

void cargar_argumentos(int argc, char const *argv[], int &cantidad_productores, int &cantidad_consumidores, int &tamano_inicial_cola, int &tiempo_espera) {
    for (int i = 1; i < argc; i+=2) {
        if (std::string(argv[i]) == "-p") {
            if (i + 1 >= argc) {
                std::cerr << ROJO << "Error: Falta el argumento para -p" << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            if (es_numero(argv[i + 1])) {
                cantidad_productores = std::stoi(argv[i + 1]);
            }            
            else {
                std::cerr << ROJO << "Error: El argumento para -p debe ser un número positivo." << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }
        }
        else if (std::string(argv[i]) == "-c") {
            if (i + 1 >= argc) {
                std::cerr << ROJO << "Error: Falta el argumento para -c" << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            if (es_numero(argv[i + 1])) {
                cantidad_consumidores = std::stoi(argv[i + 1]);
            }
            else {
                std::cerr << ROJO << "Error: El argumento para -c debe ser un número positivo." << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }
        }
        else if (std::string(argv[i]) == "-s") {
            if (i + 1 >= argc) {
                std::cerr << ROJO << "Error: Falta el argumento para -s" << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            if (es_numero(argv[i + 1])) {
                tamano_inicial_cola = std::stoi(argv[i + 1]);
                if (tamano_inicial_cola == 0){
                    std::cerr << ROJO << "Error: El argumento para -s debe ser un número diferente de 0" << RESET_COLOR << std::endl;
                    mensaje_error_argumentos(argv);

                }
            }
            else {
                std::cerr << ROJO << "Error: El argumento para -s debe ser un número positivo." << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }
        }
        else if (std::string(argv[i]) == "-t") {
            if (i + 1 >= argc) {
                std::cerr << ROJO << "Error: Falta el argumento para -t" << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            if (es_numero(argv[i + 1])) {
                tiempo_espera = std::stoi(argv[i + 1]);
            }
            else {
                std::cerr << ROJO << "Error: El argumento para -t debe ser un número positivo." << RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }
        }
        else {
            std::cerr << ROJO << "Error: Argumento invalido" << RESET_COLOR << std::endl;
            mensaje_error_argumentos(argv);
        }
    }
}

int main(int argc, char const *argv[]) {
    if (argc != 9) 
        mensaje_error_argumentos(argv);
    
    int cantidad_productores;
    int cantidad_consumidores;
    int tiempo_espera;      // En Segundos
    int tamanio_inicial_cola;

    cargar_argumentos(argc, argv, cantidad_productores, cantidad_consumidores, tamanio_inicial_cola, tiempo_espera);
    
    Monitor monitor(tamanio_inicial_cola, tiempo_espera);

    std::vector<std::thread> hilos;

    for (int i = 0; i < cantidad_productores; i++)
        hilos.push_back(std::thread(productor, std::ref(monitor), i));

    for (int i = 0; i < cantidad_consumidores; i++)
        hilos.push_back(std::thread(consumidor, std::ref(monitor), i));
    
    for (auto &hilo : hilos) hilo.join();
    hilos.clear();

    // Final
    std::cout << std::endl;
    std::cout << BLANCO << "Elementos finales: ";
    monitor.mostrarElementos();

    return 0;
}