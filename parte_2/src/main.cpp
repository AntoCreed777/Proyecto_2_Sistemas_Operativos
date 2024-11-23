#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "../include/lru.h"
#include "../include/lru_time.h"
#include "../include/optimo.h"
#include "../include/cola.h"
#include "../include/constantes.h"

void manejar_argumentos(int argc, char const *argv[], int &numero_de_marcos, std::vector<int> &referencias, std::string &algoritmo){
    for(int i = 0; i < argc; i++){
        if(std::string(argv[i]) == "-m"){                            // Numero de marcos
            numero_de_marcos = std::atoi(argv[i + 1]) ? std::atoi(argv[++i]) : -1;
        }
        else if(std::string(argv[i]) == "-a"){                       // Seleccionar algoritmo
            algoritmo = std::string(argv[++i]);
        }
        else if(std::string(argv[i]) == "-f"){                       // Archivo con las referencias
            std::ifstream archivo_referencias(argv[++i]);
            if(archivo_referencias){
                
                std::string linea;
                
                while(std::getline(archivo_referencias, linea)){
                    std::istringstream iss(linea);
                    std::string token;

                    while(std::getline(iss, token, ' ')){                   // Extraer por separado los numeros
                        referencias.push_back(std::stoi(token));            // stoi() maneja un string directamente y lo transforma a int 
                    }
                }
                archivo_referencias.close();
            }
            else 
                std::cout << ROJO "No se pudo abrir el archivo.\n" RESET_COLOR << std::endl;
        }
    }
}

int main(int argc, char const *argv[]) {

    if(argc != 7){
        std::cerr << ROJO "Los argumentos debe ser" << argv[0] << " -m <numero marco de páginas> -a <algoritmo de remplazo> -f <nombre del archivo con las referencias>" RESET_COLOR << std::endl;
        return 1;
    }

    int numero_de_marcos = -1;
    std::string nombre_algoritmo = "";
    std::vector<int> referencias = {};

    manejar_argumentos(argc, argv, numero_de_marcos, referencias, nombre_algoritmo); // Funciona

    if(numero_de_marcos < 0 || nombre_algoritmo == "" || referencias.empty()){
        std::cerr << ROJO "Argumentos erroneos" RESET_COLOR << std::endl;
        std::cerr << ROJO "Los argumentos debe ser" << argv[0] << " -m <numero marco de páginas> -a <algoritmo de remplazo> -f <nombre del archivo con las referencias>" RESET_COLOR <<std::endl;
        return 1;
    }

    if(nombre_algoritmo == "FIFO"){
        Cola<int> algoritmo(numero_de_marcos);

        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
            algoritmo.mostrar_contenedor();
        }
    }
    else if(nombre_algoritmo == "LRUR"){                // LRU Reloj Simple  
        LRU_TIME<int> algoritmo(numero_de_marcos);

        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
            algoritmo.mostrar_contenedor();
        }
    }   
    else if(nombre_algoritmo == "LRU"){
        LRU<int> algoritmo(numero_de_marcos);
        
        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
            algoritmo.mostrar_contenedor();
        }
    }
    else if(nombre_algoritmo == "Optimo"){
        Optimo<int> algoritmo(numero_de_marcos, referencias);
        
        for(int valores_referencias : referencias){
            algoritmo.push(valores_referencias);
            algoritmo.mostrar_contenedor();
        }
    }
    else {
        std::cerr << ROJO "Algoritmo invalido" << std::endl;
        std::cerr << AMARILLO "Algoritmos validos son FIFO, LRU, LRUR (Reloj simple) y Optimo" RESET_COLOR << std::endl;
        return 1;
    }

    return 0;
}