#pragma once
#include <iostream>
#include <vector>

#include "constantes.h"
#include "MapAbierto.h"
#include "Marco.h"

#define NO_SE_ENCONTRO -1
#define MAXVALUE 1024
 
class Optimo{
    private: 
        std::vector<int> contenedor;
        int indice_lista_referencia;
        int hits;
        int misses;
        int cantidad_elementos;
        MapAbierto map;
        std::vector<int> lista_de_referencias;
        int paginaRemplazo(){
            int distancia_maxima = -1;
            int indice_remplazar = -1;

            for(size_t i = 0; i < contenedor.size(); i++){
                int distancia = MAXVALUE; // numero grande
                
                for(size_t j = indice_lista_referencia + 1; j < lista_de_referencias.size(); j++){
                    if(contenedor[i] == lista_de_referencias[j]){
                        distancia = j - indice_lista_referencia;
                        break;
                    }
                }

                if(distancia == MAXVALUE){
                    return i;
                }

                if(distancia > distancia_maxima){
                    distancia_maxima = distancia;
                    indice_remplazar = i;
                }
            }
            
            return indice_remplazar;
        }

    public:
        Optimo(int size, std::vector<int> lista_de_procesos);
        void push(int e);
        void mostrar_contenedor();
        int getHits() { return this->hits; };
        int getMisses() { return this->misses; };
};

Optimo::Optimo(int size, std::vector<int> lista_de_referencias) {
    this->contenedor = std::vector<int>(size);
    this->map = MapAbierto();
    this->lista_de_referencias = lista_de_referencias;
    this->hits = 0;
    this->misses = 0;
    this->cantidad_elementos = 0;
    this->indice_lista_referencia = 0;
}


void Optimo::push(int valor) {
    auto posicion = this->map.get(valor);


    // Si no lo encuentra en el contenedor
    if (posicion.has_value()){
        this->hits++;

    } else {
        this->misses++;

        if (this->map.size() < this->cantidad_elementos) {  // Si el contenedor tiene espacio
            this->map.put({valor, this->map.size() + 1});
            this->contenedor[this->cantidad_elementos] = valor;

        } else {
            int remplazo = paginaRemplazo();
            int eliminar = this->contenedor[remplazo];

            auto resultado = this->map.get(eliminar);
            this->map.remove(eliminar);

            this->contenedor.erase(this->contenedor.begin() + remplazo); // Elimina el que mas lejos está referenciado
            this->contenedor.push_back(valor);                           // Inserta el nuevo elemento al final

            this->map.put({valor, posicion->valor});
        }
    }
    
    this->indice_lista_referencia++;
}


void Optimo::mostrar_contenedor() {
    if (this->cantidad_elementos == 0) {
        return;
    }

    std::cout << AZUL;
    for (int i = 0; i < this->cantidad_elementos; i++) {
        std::cout << this->contenedor[i] << " ";
    }
    std::cout << RESET_COLOR << std::endl;
}