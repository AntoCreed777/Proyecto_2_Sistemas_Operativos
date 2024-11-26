#pragma once

#include <iostream>
#include <queue>

#include "MapAbierto.h"
#include "constantes.h"
#include "Marco.h"

class FIFO {
    private:
        MapAbierto map;
        std::queue<int> cola;
        int tamano, hits, misses;

    public:
        FIFO(int tamano);
        void push(int valor);
        int getHits() { return hits;}
        int getMisses() { return misses;}
};

FIFO::FIFO(int tamano) {
    this->map = MapAbierto();
    this->cola = std::queue<int>();
    this->tamano = tamano;
    this->hits = 0;
    this->misses = 0;
}

void FIFO::push(int valor) {

    std::optional<Marco> resultado = this->map.get(valor);
    if (resultado.has_value())
        this->hits++;

    else {
        this->misses++;

        if (this->map.size() < this->tamano) {
            this->map.put({valor, this->map.size()});
            this->cola.push(valor);
            return;
        }

        int clave = this->cola.front();
        this->cola.pop();

        auto resultado = this->map.get(clave);
        this->map.remove(clave);

        this->map.put({valor, resultado->valor});
        this->cola.push(valor);
    }
}