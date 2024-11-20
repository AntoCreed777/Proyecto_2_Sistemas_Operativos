#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "constantes.h"
#include "utils.h"

template <typename elemento>
class Cola{
private:
    std::vector<elemento> contenedor;
    int tail;
    int head;
    int size_cola;

    void aumentar_tamanio();
    void reducir_tamanio();

public:
    Cola();
    Cola(std::vector<elemento> cola_inicial);
    Cola(int tamanio_inicial);

    void push(elemento elem);

    elemento front();

    elemento pop();
    
    int tamanio_contenedor();
    int size();

    void mostrar_contenedor(){
        if (this->size() == 0) {
            std::cout << std::endl;
            return;
        }
        
        std::cout << AZUL;
        for (int i = tail; i != head; i = (i + 1)%tamanio_contenedor()){
            std::cout << contenedor[i] << " ";
        }
        std::cout << contenedor[head] << " ";
        
        std::cout << RESET_COLOR << std::endl;
    }
};


template <typename elemento>
Cola<elemento>::Cola(){
    head = 0;
    tail = 0;
    size_cola = 0;
    contenedor = std::vector<elemento>(1);

} 

template <typename elemento>
Cola<elemento>::Cola(std::vector<elemento> cola_inicial){
    head = cola_inicial.size() - 1;
    tail = 0;
    size_cola = cola_inicial.size();
    contenedor = cola_inicial;
    utils::generar_log("Se inicializa la cola en " + utils::vector_to_string(contenedor) + "\n\n", "log.txt");
} 

template<typename elemento>
Cola<elemento>::Cola(int tamanio_inicial){
    head = 0;
    tail = 0;
    size_cola = 0;
    contenedor = std::vector<elemento>(tamanio_inicial);

}



template <typename elemento>
void Cola<elemento>::aumentar_tamanio(){
    std::vector<elemento> contenedor_secundario(contenedor.size() * 2);
    int j = 0;
    for (int i = tail; i != head; i = (i + 1)%tamanio_contenedor(), j++){
        contenedor_secundario[j] = contenedor[i];
    }
    contenedor_secundario[j] = contenedor[head];
    head = j;
    tail = 0;
    contenedor = contenedor_secundario;
    utils::generar_log("Se a aumentado el tamanio al doble\nTamanio actual " + std::to_string(this->tamanio_contenedor()), "log.txt");
}

template <typename elemento>
void Cola<elemento>::reducir_tamanio(){
    std::vector<elemento> contenedor_secundario(contenedor.size() * 0.5);
    int j = 0;
    for (int i = tail; i != head; i = (i + 1)%tamanio_contenedor(), j++){
        contenedor_secundario[j] = contenedor[i];
    }
    contenedor_secundario[j] = contenedor[head];

    head = j;
    tail = 0;
    contenedor = contenedor_secundario;
    utils::generar_log("Se a reducido el tamanio a la mitad\nTamanio actual " + std::to_string(this->tamanio_contenedor()), "log.txt");
}

template <typename elemento>
void Cola<elemento>::push(elemento elem){
    if (this->size() == this->tamanio_contenedor())
        this->aumentar_tamanio();

    head = (head + 1) % this->tamanio_contenedor();
    contenedor[head] = elem;
    size_cola++;
}


template <typename elemento>
elemento Cola<elemento>::front(){
    return this->contenedor[tail];
}

template <typename elemento>
elemento Cola<elemento>::pop(){
    if (!this->size())
        throw std::out_of_range("No hay elementos en la cola");
    if (this->size() <= this->tamanio_contenedor() * 0.25)
        this->reducir_tamanio();
    
    elemento elem = contenedor[this->tail];
    this->tail = (this->tail + 1) % this->tamanio_contenedor();
    size_cola--;
    return elem;
}

template <typename elemento>
int Cola<elemento>::tamanio_contenedor(){
    return this->contenedor.size();
} 

template <typename elemento>
int Cola<elemento>::size(){
    return size_cola;
} 

