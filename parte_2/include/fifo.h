#pragma once

#include <iostream>
#include <queue>

#include "manejador_fallos_pagina.h"
#include "MapAbierto.h"
#include "Marco.h"
#include "constantes.h"

class FIFO: public ManejadorFallosPagina {
    private:
        MapAbierto map;
        std::queue<int> cola;
        int tamano, hits, misses;

    public:
        FIFO(int tamano);
        void push(int valor) override;
        int getHits() override { return hits;}
        int getMisses() override { return misses;}
};
