#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <sstream>

#include "../include/monitor.h"
#include "../include/constantes.h"
#include "../include/utils.h"


Monitor::Monitor(int tamanio_inicial_cola, int tiempo_bloqueo) {
    this->ruta_log = "log.txt";
    utils::generar_log("\n\n\nNUEVA EJECUCION\n", this->ruta_log);
        
    this->buffer = new Cola<int>(tamanio_inicial_cola);

    this->tiempo_bloqueo = tiempo_bloqueo;
}

void Monitor::agregarElemento(int elemento) {
    std::lock_guard<std::mutex> lock(this->mutex);

    buffer->push(elemento);
    this->condConsumidores.notify_one();
}

void Monitor::quitarElemento() {
    std::unique_lock<std::mutex> lock(this->mutex);

    std::ostringstream oss;

    while (true) {
        try {
            buffer->pop();
            return;
        }
        catch (const std::exception& e) {
            utils::generar_log(e.what(), this->ruta_log);

            oss << "Consumidor bloqueado en la hebra: " << std::this_thread::get_id();
            utils::generar_log(oss.str(), this->ruta_log);
            oss.str(""); // Vacía el contenido
            oss.clear(); // Opcional, pero asegura el estado limpio del flujo
        }

        if (this->condConsumidores.wait_for(lock, std::chrono::seconds(this->tiempo_bloqueo)) == std::cv_status::timeout) {
            oss << "Timeout agotado del consumidor en la hebra: " << std::this_thread::get_id();
            utils::generar_log(oss.str(), this->ruta_log);
                        
            return;
        }

        oss << "Consumidor desbloqueado en la hebra: " << std::this_thread::get_id();
        utils::generar_log(oss.str(), this->ruta_log);
        oss.str("");
        oss.clear();
    }
}

void Monitor::mostrarElementos() {
    this->mutex.lock();

    std::cout << AMARILLO << "Buffer: " << RESET_COLOR;
    buffer->mostrar_contenedor();

    this->mutex.unlock();
}

bool Monitor::isEmpty() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer->size() == 0;
}

int Monitor::cantidadElementos() {
    std::lock_guard<std::mutex> lock(this->mutex);
    return buffer->size();
}