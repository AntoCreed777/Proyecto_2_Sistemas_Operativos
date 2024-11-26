#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/lru.h"
#include "../include/lru_time.h"
#include "../include/optimo.h"
#include "../include/fifo.h"
#include "../include/constantes.h"

void mensaje_error_argumentos(char const *argv[]) {
    std::cerr << ROJO << "Error: Argumentos invalidos" << RESET_COLOR << std::endl;
    std::cerr << AZUL << "Use: " << AMARILLO << argv[0] << " -m <numero marco de páginas> -a <algoritmo de remplazo> -f <nombre del archivo con las referencias>" RESET_COLOR << std::endl;
    exit(EXIT_FAILURE);
}

void manejar_argumentos(int argc, char const *argv[], int &numero_de_marcos, std::vector<int> &referencias, std::string &algoritmo){
    for(int i=1; i < argc; i+=2){
        if (std::string(argv[i]) == "-m" && i+1 < argc) {
            if (std::atoi(argv[i + 1]) <= 0) {
                std::cerr << ROJO "El numero de marcos debe ser mayor a 0.\n" RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            numero_de_marcos = std::atoi(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-a" && i+1 < argc) {
            if (std::string(argv[i + 1]) != "FIFO" && std::string(argv[i + 1]) != "LRU" && std::string(argv[i + 1]) != "LRUR" && std::string(argv[i + 1]) != "Optimo") {
                std::cerr << ROJO "Algoritmo invalido.\n" RESET_COLOR << std::endl;
                std::cerr << AMARILLO "Algoritmos validos son FIFO, LRU, LRUR (Reloj simple) y Optimo" RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }

            algoritmo = std::string(argv[i + 1]);
        }
        else if (std::string(argv[i]) == "-f" && i+1 < argc) {
            std::ifstream archivo_referencias(argv[i + 1]);
            if (archivo_referencias) {
                std::string linea;
                while (std::getline(archivo_referencias, linea)) {
                    std::istringstream iss(linea);
                    std::string token;
                    while (std::getline(iss, token, ' ')) {
                        referencias.push_back(std::stoi(token));
                    }
                }

                archivo_referencias.close();

                if (referencias.empty()) {
                    std::cerr << ROJO "El archivo de referencias esta vacio.\n" RESET_COLOR << std::endl;
                    mensaje_error_argumentos(argv);
                }
            }
            else {
                std::cout << ROJO "No se pudo abrir el archivo.\n" RESET_COLOR << std::endl;
                mensaje_error_argumentos(argv);
            }
        }
    }
}

int main(int argc, char const *argv[]) {

    if(argc != 7) mensaje_error_argumentos(argv);

    int numero_de_marcos;
    std::string nombre_algoritmo;
    std::vector<int> referencias = {};

    manejar_argumentos(argc, argv, numero_de_marcos, referencias, nombre_algoritmo);

    if(nombre_algoritmo == "FIFO"){
        FIFO algoritmo(numero_de_marcos);

        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
        }

        std::cout << AMARILLO "Hits: " RESET_COLOR << algoritmo.getHits() << std::endl;
        std::cout << AMARILLO "Misses: " RESET_COLOR << algoritmo.getMisses() << std::endl;
    }
    else if(nombre_algoritmo == "LRUR"){                // LRU Reloj Simple  
        LRU_TIME algoritmo(numero_de_marcos);

        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
        }

        std::cout << AMARILLO "Hits: " RESET_COLOR << algoritmo.getHits() << std::endl;
        std::cout << AMARILLO "Misses: " RESET_COLOR << algoritmo.getMisses() << std::endl;
    }   
    else if(nombre_algoritmo == "LRU"){
        LRU algoritmo(numero_de_marcos);
        
        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
        }

        std::cout << AMARILLO "Hits: " RESET_COLOR << algoritmo.getHits() << std::endl;
        std::cout << AMARILLO "Misses: " RESET_COLOR << algoritmo.getMisses() << std::endl;
    }
    else if(nombre_algoritmo == "Optimo"){
        Optimo algoritmo(numero_de_marcos, referencias);
        
        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
        }

        std::cout << AMARILLO "Hits: " RESET_COLOR << algoritmo.getHits() << std::endl;
        std::cout << AMARILLO "Misses: " RESET_COLOR << algoritmo.getMisses() << std::endl;
    }
    else {
        std::cerr << ROJO "Algoritmo invalido" << std::endl;
        std::cerr << AMARILLO "Algoritmos validos son FIFO, LRU, LRUR (Reloj simple) y Optimo" RESET_COLOR << std::endl;
        return 1;
    }

    return 0;
}