#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "constantes.h"
#include "MapAbierto.h"
#include "Marco.h"


#define NO_SE_ENCONTRO -1



class LRU_TIME{
private:
    std::vector<int> contenedor;
    MapAbierto map;
    std::vector<bool> validos;
    int cantidad_elementos;
    int hits;
    int misses;
    int posicion_puntero;

    bool is_empty() {return cantidad_elementos == 0;}

    bool is_full() {return int(contenedor.size()) == cantidad_elementos;}

    void actualizar_posicion_puntero() {
        posicion_puntero = (posicion_puntero + 1) % contenedor.size();
    }

    /**
     * @brief Verifica si un elemento ya esta en el contenedor
     * 
     * @param elem Elemento a buscar
     * @return ``int`` La posicion del elemento.
     * @return ``-1`` Si no se encontro el elemento
     */
    int existe_elemento(int elem);

    /**
     * @brief Busca un elemento que se pueda eliminar en el contenedor
     * 
     * @return ``int`` Posicion del elemento en el contenedor
     * 
     * @note Al ingresar a esta funcion el contenedor debe estar lleno
     */
    int buscar_candidato();


public:
    LRU_TIME(int tamano);

    void push(int elem);

    int getHits() {return hits;}

    int getMisses() {return misses;}
};

LRU_TIME::LRU_TIME(int tamano){
    this->contenedor = std::vector<int>(tamano);
    this->validos = std::vector<bool>(tamano);  // Se rellena inicializa con false
    this->map = MapAbierto();
    this->cantidad_elementos = 0;
    this->hits = 0;
    this->misses = 0;
    this->posicion_puntero = 0;
}

void LRU_TIME::push(int elem) {
    int posicion = existe_elemento(elem);       // Indice elemento
    auto valor = this->map.get(elem);           // Elemento en la tabla

    if (valor.has_value()) {                    // Lo encontró
        this->hits++;
        validos[posicion] = true;               // Lo marca como true, visitado
        return;

    } else {
        misses++;                               
        
        if(this->map.size() < this->cantidad_elementos){      // Si hay espacio
            this->map.put({elem, this->map.size() + 1});      // Lo agrega sin mas
            
        } else {                                              // Si no hay esspacio, eliminar la referencia
            
            // Valor a eliminar
            int pos_candidato = buscar_candidato();
            int eliminar = this->contenedor[pos_candidato];

            auto posicion = this->map.get(eliminar);
            this->map.remove(eliminar);

            this->map.put({elem, posicion->valor});

            if (is_full()) {
                this->contenedor[pos_candidato] = elem;
                this->validos[pos_candidato] = true;
            } else {
                this->contenedor[this->cantidad_elementos] = elem;
                this->validos[this->cantidad_elementos] = true;
                this->cantidad_elementos++;
            }
        }
    }
}


int LRU_TIME::existe_elemento(int elem){
    if (is_empty()) return NO_SE_ENCONTRO;

    for(int i=0;i<cantidad_elementos;i++){
        if (contenedor[i] == elem) return i;
    }

    return NO_SE_ENCONTRO;
}

int LRU_TIME::buscar_candidato(){
    int posicion_encontrada = -1;

    while(posicion_encontrada == -1) {
        if (validos[posicion_puntero]) validos[posicion_puntero] = false;
        
        else posicion_encontrada = posicion_puntero;

        actualizar_posicion_puntero();
    }

    return posicion_encontrada;
}
