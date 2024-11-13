#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "constantes.h"

#define NO_SE_ENCONTRO -1


template <typename elemento>
class LRU_TIME{
private:
    std::vector<elemento> contenedor;
    std::vector<bool> validos;
    int cantidad_elementos;
    int hits;
    int misses;
    int posicion_puntero;

    bool is_empty() {return cantidad_elementos == 0;}

    bool is_full() {return int(contenedor.size()) == cantidad_elementos;}

    void actualizar_posicion_puntero() {
        posicion_puntero = (posicion_puntero + 1) % contenedor.size();
    }

    /**
     * @brief Verifica si un elemento ya esta en el contenedor
     * 
     * @param elem Elemento a buscar
     * @return ``int`` La posicion del elemento.
     * @return ``-1`` Si no se encontro el elemento
     */
    int existe_elemento(elemento elem);

    /**
     * @brief Busca un elemento que se pueda eliminar en el contenedor
     * 
     * @return ``int`` Posicion del elemento en el contenedor
     * 
     * @note Al ingresar a esta funcion el contenedor debe estar lleno
     */
    int buscar_candidato();


public:
    LRU_TIME(int tamano);

    void push(elemento elem);

    int getHits() {return hits;}

    int getMisses() {return misses;}

    void mostrar_contenedor(){
        if (this->is_empty()) {
            std::cout << std::endl;
            return;
        }

        std::cout << AZUL;
        
       for(int i=0;i<cantidad_elementos;i++){
            std::cout << contenedor[i] << " ";
       }
        
        std::cout << RESET_COLOR << std::endl;
    }
};

template <typename elemento>
LRU_TIME<elemento>::LRU_TIME(int tamano){
    this->contenedor = std::vector<elemento>(tamano);
    this->validos = std::vector<bool>(tamano);  // Se rellena inicializa con false
    this->cantidad_elementos = 0;
    this->hits = 0;
    this->misses = 0;
    this->posicion_puntero = 0;
}

template <typename elemento>
void LRU_TIME<elemento>::push(elemento elem) {
    int posicion = existe_elemento(elem);

    if (posicion != NO_SE_ENCONTRO) { // Lo encontró
        hits++;
        validos[posicion] = true;
        return;
    }
    
    misses++;

    if (is_full()) {
        int pos_candidato = buscar_candidato();
        contenedor[pos_candidato] = elem;
        validos[pos_candidato] = true;
    } else {
        contenedor[cantidad_elementos] = elem;
        validos[cantidad_elementos] = true;
        cantidad_elementos++;
    }
}


template <typename elemento>
int LRU_TIME<elemento>::existe_elemento(elemento elem){
    if (is_empty()) return NO_SE_ENCONTRO;

    for(int i=0;i<cantidad_elementos;i++){
        if (contenedor[i] == elem) return i;
    }

    return NO_SE_ENCONTRO;
}

template <typename elemento>
int LRU_TIME<elemento>::buscar_candidato(){
    int posicion_encontrada = -1;

    while(posicion_encontrada == -1) {
        if (validos[posicion_puntero]) validos[posicion_puntero] = false;
        
        else posicion_encontrada = posicion_puntero;

        actualizar_posicion_puntero();
    }

    return posicion_encontrada;
}
