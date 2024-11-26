#pragma once
#include <iostream>
#include <vector>

#include "manejador_fallos_pagina.h"
#include "MapAbierto.h"
#include "Marco.h"
#include "constantes.h"

#define NO_SE_ENCONTRO -1
#define MAXVALUE 1024
 
class Optimo: public ManejadorFallosPagina {
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
        void push(int valor) override;
        void mostrar_contenedor();
        int getHits() override { return this->hits; };
        int getMisses() override { return this->misses; };
};
