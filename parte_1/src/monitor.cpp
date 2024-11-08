#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#include "monitor.h"
#include "constantes.h"

Monitor::Monitor() {
    this->buffer = Cola<int>();
}

void Monitor::agregarElemento(int elemento) {
    std::lock_guard<std::mutex> lock(this->mutex);
    buffer.push(elemento);
}

void Monitor::quitarElemento() {
    std::lock_guard<std::mutex> lock(this->mutex);
    try {
        buffer.pop();
    }
    catch(const std::exception& e) {
        // PASS
    }
}

void Monitor::mostrarElementos() {
    std::lock_guard<std::mutex> lock(this->mutex);

    std::cout << AMARILLO << "Buffer: " << RESET_COLOR;
    buffer.mostrar_contenedor();
}

bool Monitor::isEmpty() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer.size() == 0;
}

int Monitor::cantidadElementos() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer.size();
}

void Monitor::bloqueo(int tiempo) {
    std::lock_guard<std::mutex> lock(this->mutex);
    std::this_thread::sleep_for(std::chrono::seconds(tiempo));
}