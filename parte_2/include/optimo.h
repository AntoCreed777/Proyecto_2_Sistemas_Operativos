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
        MapAbierto map;
        std::vector<int> lista_de_referencias;
        int indice_lista_referencia;
        int hits;
        int misses;
        int cantidad_elementos;
        int paginaRemplazo();

    public:
        Optimo(int size, std::vector<int> lista_de_procesos);
        void push(int e);
        void mostrar_contenedor();
        int getHits() { return this->hits; };
        int getMisses() { return this->misses; };
};
