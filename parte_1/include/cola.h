#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename elemento>
class Cola{
private:
    std::vector<elemento> contenedor;
    int tail;
    int head;
    int size_cola;

public:
    Cola();

    void push(elemento elem);

    elemento front();

    elemento pop();
    
    int tamanio_contenedor();
    int size();

    void mostrar_contenedor(){
        for (auto elem: contenedor){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
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
void Cola<elemento>::push(elemento elem){
    if (this->size() == this->tamanio_contenedor()){
        std::vector<elemento> contenedor_secundario(contenedor.size() * 2);
        int j = 0;
        for (int i = tail; i != head; i = (i + 1)%tamanio_contenedor(), j++){
            contenedor_secundario[j] = contenedor[i];
        }
        contenedor_secundario[j] = contenedor[head];

        head = j;
        tail = 0;
        contenedor = contenedor_secundario;
    }

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
    if (this->size() <= this->tamanio_contenedor() * 0.25){
        std::vector<elemento> contenedor_secundario(contenedor.size() * 0.5);
        int j = 0;
        for (int i = tail; i != head; i = (i + 1)%tamanio_contenedor(), j++){
            contenedor_secundario[j] = contenedor[i];
        }
        contenedor_secundario[j] = contenedor[head];

        head = j;
        tail = 0;
        contenedor = contenedor_secundario;        
        
    }
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
