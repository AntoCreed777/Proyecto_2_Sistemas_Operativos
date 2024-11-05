#pragma once

#include <pthread.h>
#include <vector>

class Monitor {
private:
    std::vector<int> buffer;
    pthread_mutex_t mutex;
    int size;

public:
    Monitor();

    ~Monitor();

    /**
     * @brief Agrega un elemento al buffer
     * 
     * @param elemento Elemento a agregar
     */
    void agregarElemento(int elemento);

    /**
     * @brief Elimina un elemento del buffer
     * 
     */
    void quitarElemento();

    /**
     * @brief Imprime los elementos del buffer en la salida estandar
     */
    void mostrarElementos();

    /**
     * @brief Indica si el buffer esta vacio
     * 
     * @return `True` si el buffer esta vacio, `False` en caso contrario
     */
    bool isEmpty();

    /**
     * @brief Indica la cantidad de elementos en el buffer
     * 
     * @return `int`
     */
    int cantidadElementos();
};