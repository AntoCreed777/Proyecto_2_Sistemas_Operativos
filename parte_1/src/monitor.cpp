#include <iostream>
#include <mutex>
#include <vector>

#include "monitor.h"
#include "constantes.h"

Monitor::Monitor() {
    this->buffer = std::vector<int>();
}

Monitor::~Monitor() {
    this->buffer.clear();
}

void Monitor::agregarElemento(int elemento) {
    this->mutex.lock();
    buffer.push_back(elemento);
    this->mutex.unlock();
}

void Monitor::quitarElemento() {
    this->mutex.lock();
    if (!buffer.empty()) {
        buffer.erase(buffer.begin());
    }
    this->mutex.unlock();
}

void Monitor::mostrarElementos() {
    this->mutex.lock();
    std::cout << AMARILLO << "Buffer: " << RESET_COLOR;
    std::cout << AZUL;

    if (buffer.empty()) std::cout << "Vacio";
    else {
        for (size_t i = 0; i < buffer.size(); i++) {
            std::cout << buffer[i] << " ";
        }
    }
    std::cout << RESET_COLOR << std::endl;
    this->mutex.unlock();
}

bool Monitor::isEmpty() {
    this->mutex.lock();
    bool empty = buffer.empty();
    this->mutex.unlock();
    return empty;
}

int Monitor::cantidadElementos() {
    this->mutex.lock();
    int cantidad = buffer.size();
    this->mutex.unlock();
    return cantidad;
}