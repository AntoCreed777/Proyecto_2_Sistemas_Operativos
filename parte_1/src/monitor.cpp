#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <fstream>

#include "../include/monitor.h"
#include "../include/constantes.h"
#include "../include/utils.h"


Monitor::Monitor(int productores_esperados, int tiempo_bloqueo) {
    this->buffer = Cola<int>();
    this->productores_esperados = productores_esperados;
    this->productores_actuales = 0;
    this->tiempo_bloqueo = tiempo_bloqueo;
    this->bloqueado = true;
    this->ruta_log = "log.txt";

    utils::generar_log("\n\n\nNUEVA EJECUCION\n", this->ruta_log);
}

void Monitor::agregarElemento(int elemento) {
    std::lock_guard<std::mutex> lock(this->mutex);
    this->productores_actuales++;
    buffer.push(elemento);
    utils::generar_log("Se agrego el elemento "+ std::to_string(elemento), this->ruta_log);

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
        int elemento = buffer.pop();
        utils::generar_log("el elemento "+ std::to_string(elemento), this->ruta_log);
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