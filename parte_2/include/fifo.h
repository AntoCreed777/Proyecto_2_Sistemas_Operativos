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
