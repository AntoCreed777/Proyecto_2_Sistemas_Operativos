#pragma once
#include <iostream>
#include <vector>
#include "constantes.h"

#define NO_SE_ENCONTRO -1

template <typename element>
class LRU {
    private:
        std::vector<element> contenedor;
        int hits;
        int misses;
        int cantidad_elementos;
        int busqueda_lineal(element e);
    public:
        LRU(int size);
        void push(element e);
        void mostrar_contenedor();
        int getHits();
        int getMisses();
};

template <typename element>
LRU<element>::LRU(int size) {
    this->contenedor = std::vector<element>(size);
    this->hits = 0;
    this->misses = 0;
    this->cantidad_elementos = 0;
}

/**
 * @brief Inserta un elemento en el contenedor
 * 
 * Si ya existe el elemento en el contenedor, lo elimina y lo inserta al final.
 * Si el contenedor está lleno, elimina el primer elemento y agrega el nuevo al final.
 * 
 * @tparam element Tipo de dato que guarda el contenedor
 * @param e Elemento a insertar
 */
template <typename element>
void LRU<element>::push(element e) {
    int posicion = this->busqueda_lineal(e);

    // Si no lo encuentra en el contenedor
    if (posicion == NO_SE_ENCONTRO) {
        this->misses++;
        if (int(this->contenedor.size()) == cantidad_elementos) {  // Si el contenedor está lleno
            this->contenedor.erase(this->contenedor.begin());    // Elimina el primer elemento
            this->contenedor.push_back(e);                      // Inserta el nuevo elemento al final
        }
        else{
            this->contenedor[this->cantidad_elementos] = e;
            this->cantidad_elementos++;
        }
    }
    else {  // Si lo encuentra en el contenedor
        this->hits++;
        this->contenedor.erase(this->contenedor.begin() + posicion);    // Lo elimina y reordena todo lo que le sigue
        this->contenedor.insert(this->contenedor.begin() + this->cantidad_elementos - 1, e);    // Lo inserta al final
    }
}

/**
 * @brief Funcion que busca un elemento en el contenedor mediante busqueda binaria
 * 
 * @tparam element Tipo de dato que guarda el contenedor
 * @param e Elemento a buscar
 * @return ``int`` Posicion del elemento en el contenedor, ``-1`` si no lo encuentra
 */
template <typename element>
int LRU<element>::busqueda_lineal(element e) {
    for (int i=0;i<cantidad_elementos;i++)
        if (contenedor[i] == e) return i;
    
    return NO_SE_ENCONTRO;
}

template <typename element>
void LRU<element>::mostrar_contenedor() {
    if (this->cantidad_elementos == 0) {
        std::cout << std::endl;
        return;
    }

    std::cout << AZUL;
    for (int i = 0; i < this->cantidad_elementos; i++) {
        std::cout << this->contenedor[i] << " ";
    }
    std::cout << RESET_COLOR << std::endl;
}