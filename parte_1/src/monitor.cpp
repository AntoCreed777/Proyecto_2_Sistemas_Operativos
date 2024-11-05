#include <iostream>
#include <pthread.h>
#include <vector>

#include "monitor.h"
#include "constantes.h"

Monitor::Monitor() {
    pthread_mutex_init(&mutex, NULL);
    this->buffer = std::vector<int>();
}

Monitor::~Monitor() {
    pthread_mutex_destroy(&mutex);
    this->buffer.clear();
}

void Monitor::agregarElemento(int elemento) {
    pthread_mutex_lock(&mutex);
    buffer.push_back(elemento);
    pthread_mutex_unlock(&mutex);
}

void Monitor::quitarElemento() {
    pthread_mutex_lock(&mutex);
    if (!buffer.empty()) {
        buffer.erase(buffer.begin());
    }
    pthread_mutex_unlock(&mutex);
}

void Monitor::mostrarElementos() {
    pthread_mutex_lock(&mutex);
    std::cout << AMARILLO << "Buffer: " << RESET_COLOR;
    std::cout << AZUL;

    if (buffer.empty()) std::cout << "Vacio";
    else {
        for (size_t i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
    }
    std::cout << RESET_COLOR << std::endl;
    pthread_mutex_unlock(&mutex);
}

bool Monitor::isEmpty() {
    pthread_mutex_lock(&mutex);
    bool empty = buffer.empty();
    pthread_mutex_unlock(&mutex);
    return empty;
}

int Monitor::cantidadElementos() {
    pthread_mutex_lock(&mutex);
    int cantidad = buffer.size();
    pthread_mutex_unlock(&mutex);
    return cantidad;
}