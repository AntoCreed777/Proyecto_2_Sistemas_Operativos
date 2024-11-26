#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "manejador_fallos_pagina.h"
#include "MapAbierto.h"
#include "Marco.h"
#include "constantes.h"

#define NO_SE_ENCONTRO -1


class LRU_TIME: public ManejadorFallosPagina {
private:
    std::vector<int> paginas_cargadas;
    MapAbierto map;
    int hits;
    int misses;
    int posicion_puntero;


    void actualizar_posicion_puntero() {
        posicion_puntero = (posicion_puntero + 1) % paginas_cargadas.size();
    }

    /**
     * @brief Busca una pagina que se pueda eliminar
     * 
     * @return int Numero de pagina a eliminar
     * 
     * @note Al ingresar a esta funcion el contenedor debe estar lleno
     */
    int buscar_victima();

    void mostrar_paginas_cargadas() {
        std::cout << AZUL << "Paginas cargadas: ";
        for (int i = 0; i < int(this->paginas_cargadas.size()); i++) {
            std::cout << this->paginas_cargadas[i] << " ";
        }
        std::cout << RESET_COLOR << std::endl;
    }


public:
    LRU_TIME(int tamano);

    void push(int elem) override;

    int getHits() override {return hits;}

    int getMisses() override {return misses;}
};
