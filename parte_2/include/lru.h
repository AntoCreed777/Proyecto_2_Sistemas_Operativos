#pragma once
#include <iostream>
#include <vector>
#include <queue>

#include "constantes.h"
#include "MapAbierto.h"
#include "Marco.h"

#define NO_SE_ENCONTRO -1

class LRU {
    private:
        MapAbierto map;
        std::queue<int> cola;
        int hits, misses, tamanio;
    public:
        LRU(int size);
        void push(int e);
        int getHits() {return this->hits;};
        int getMisses(){return this->misses;};
};

/**
 * Constructor
 */

LRU::LRU(int tamanio) {
    this->hits = 0;
    this->misses = 0;
    this->tamanio = tamanio;
    this->cola = std::queue<int>();
    this->map = MapAbierto();
}

void LRU::push(int element){
    auto resultado = this->map.get(element);
    
    if(resultado.has_value()){
        this->hits++;

        std::queue<int> cola_aux;

        while(!this->cola.empty()){
            if(this->cola.front() != element)
                cola_aux.push(this->cola.front());
            this->cola.pop();
        }

        this->cola = cola_aux;
        this->cola.push(element);

    }
    else {
        this->misses++;
        
        if(this->map.size() < this->tamanio){   // Si hay espacio en el map
            this->map.put({element, this->map.size() + 1});
            this->cola.push(element);
            return;
        }
        
        int victima = this->cola.front();            // Tomo el ultimo de la queue
        this->cola.pop();                           // Elimino el ultimo 

        auto resultado = this->map.get(victima);   // Tomar los datos del map de la victima

        if(!resultado.has_value())
            exit(EXIT_FAILURE);

        this->map.remove(victima);

        this->map.put({element, resultado->valor});
        this->cola.push(element);
    }

}

