#pragma once
#include <iostream>
#include <vector>
#include <queue>

#include "manejador_fallos_pagina.h"
#include "MapAbierto.h"
#include "Marco.h"
#include "constantes.h"

#define NO_SE_ENCONTRO -1

class LRU: public ManejadorFallosPagina {
    private:
        MapAbierto map;
        std::queue<int> cola;
        int hits, misses, tamanio;

    public:
        LRU(int size);
        void push(int element) override;
        int getHits() override {return this->hits;};
        int getMisses() override {return this->misses;};
};
