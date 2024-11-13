#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

#include "constantes.h"

/**
 * @brief Clase que implementa una cola de tamaño fijo
 * 
 * La cola se implementa con un contenedor de tamaño fijo, si la cola esta llena
 * se elimina el primer elemento para poder insertar uno nuevo.
 * 
 * @tparam elemento Tipo de dato que almacena la cola
 */
template <typename elemento>
class Cola{
private:
    std::vector<elemento> contenedor;
    int tail;
    int head;
    int cantidad_elementos;
    int hits;
    int misses;

    bool is_empty() {return cantidad_elementos == 0;}

    bool is_full() {return tail == head && !is_empty();}

    int tamanio_contenedor() {return contenedor.size();}

    /**
     * @brief Busca un elemento en el contenedor de la cola
     * 
     * @param elem Elemento a buscar
     * @return ``true`` Si se encontro el elemento.
     * @return ``false`` En caso contrario
     */
    bool busqueda_lineal(elemento elem);

    /**
     * @brief Verifica si un elemento ya esta en la cola
     * 
     * @param elem Elemento a buscar
     * @return ``true`` Si el elemento ya esta en la cola
     * @return ``false`` En caso contrario
     */
    bool existe_elemento(elemento elem);

    /**
     * @brief Elimina el primer elemento de la cola
     */
    void pop();

public:
    Cola(int tamano);

    /**
     * @brief Agrega un elemento a la cola, si la cola esta llena elimina el primer elemento
     * 
     * @param elem Elemento a insertar
     */
    void push(elemento elem);

    int getHits() {return hits;}

    int getMisses() {return misses;}

    void mostrar_contenedor(){
        if (this->is_empty()) {
            std::cout << std::endl;
            return;
        }

        std::cout << AZUL;
        
        if (tail < head){
            for (int i = tail; i < head; i++){
                std::cout << contenedor[i] << " ";
            }
        } else {
            for (int i = tail; i < tamanio_contenedor(); i++){
                std::cout << contenedor[i] << " ";
            }
            for (int i = 0; i < head; i++){
                std::cout << contenedor[i] << " ";
            }
        }
        
        std::cout << RESET_COLOR << std::endl;
    }
};

template <typename elemento>
Cola<elemento>::Cola(int tamano){
    this->contenedor = std::vector<elemento>(tamano);
    this->head = 0;
    this->tail = 0;
    this->cantidad_elementos = 0;
    this->hits = 0;
    this->misses = 0;
}

template <typename elemento>
void Cola<elemento>::push(elemento elem){
    // Si el elemento ya esta en la cola no se inserta
    if (existe_elemento(elem)) {
        hits++;
        return;
    }
    misses++;

    if (is_full()) pop();
    
    contenedor[head] = elem;
    head = (head + 1) % tamanio_contenedor();
    cantidad_elementos++;
}

template <typename elemento>
void Cola<elemento>::pop(){
    if (is_empty()){
        throw std::out_of_range("La cola esta vacia");
    }
    tail = (tail + 1)%tamanio_contenedor();
    cantidad_elementos--;
}

template <typename elemento>
bool Cola<elemento>::busqueda_lineal(elemento elem){
    if (tail < head) {
        for (int i = tail; i < head; i++)
            if (contenedor[i] == elem) return true;
    }
    else {
        for (int i = tail; i < tamanio_contenedor(); i++)
            if (contenedor[i] == elem) return true;

        for (int i = 0; i < head; i++)
            if (contenedor[i] == elem) return true;
    }

    return false;
}

template <typename elemento>
bool Cola<elemento>::existe_elemento(elemento elem){
    if (is_empty()) return false;

    return busqueda_lineal(elem);
}