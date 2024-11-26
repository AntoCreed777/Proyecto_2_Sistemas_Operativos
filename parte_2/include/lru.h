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
