#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

#include "monitor.h"
#include "constantes.h"

Monitor::Monitor(int productores_esperados, int tiempo_bloqueo) {
    this->buffer = Cola<int>();
    this->productores_esperados = productores_esperados;
    this->productores_actuales = 0;
    this->tiempo_bloqueo = tiempo_bloqueo;
    this->bloqueado = true;
}

void Monitor::agregarElemento(int elemento) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->productores_actuales++;
    buffer.push(elemento);

    if (this->productores_actuales == this->productores_esperados) {
        std::thread hilo(&Monitor::esperar_para_desbloquear, this, this->tiempo_bloqueo);
        hilo.detach();
    }
}

void Monitor::quitarElemento() {
    std::unique_lock<std::mutex> lock(this->mutex);
    while (this->bloqueado) {
        this->condConsumidores.wait(lock);
    }

    try {
        buffer.pop();
    }
    catch(const std::exception& e) {
        // PASS
    }
}

void Monitor::mostrarElementos() {
    this->mutex.lock();

    std::cout << AMARILLO << "Buffer: " << RESET_COLOR;
    buffer.mostrar_contenedor();

    this->mutex.unlock();
}

bool Monitor::isEmpty() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer.size() == 0;
}

int Monitor::cantidadElementos() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer.size();
}

void Monitor::esperar_para_desbloquear(int segundos) {
        std::this_thread::sleep_for(std::chrono::seconds(this->tiempo_bloqueo));
        this->bloqueado = false;
        this->productores_actuales = 0;
        this->condConsumidores.notify_all();
}