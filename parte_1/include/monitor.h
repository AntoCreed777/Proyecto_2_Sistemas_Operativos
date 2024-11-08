#pragma once

#include <mutex>
#include <condition_variable>
#include <vector>

#include "cola.h"

class Monitor {
private:
    Cola<int> buffer;
    std::mutex mutex;
    std::condition_variable condConsumidores;
    int productores_esperados, productores_actuales;
    int tiempo_bloqueo;
    bool bloqueado;

public:
    Monitor(int productores_esperados, int tiempo_bloqueo);

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

    /**
     * @brief Espera un tiempo determinado para desbloquear el monitor
     * 
     * @param segundos Tiempo en segundos
     */
    void esperar_para_desbloquear(int segundos);
};