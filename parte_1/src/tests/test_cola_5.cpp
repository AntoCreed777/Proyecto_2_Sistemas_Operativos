#include <iostream>
#include "cola.h"

int main() {
    Cola<int> cola;

    try {
        std::cout << "Intentando eliminar de una cola vacía\n";
        cola.pop();
    } catch (const std::out_of_range& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    // Llenamos la cola y vaciamos nuevamente
    cola.push(1);
    cola.mostrar_contenedor();
    cola.pop();
    cola.mostrar_contenedor();

    try {
        std::cout << "Intentando eliminar de nuevo en una cola vacía\n";
        cola.pop();
    } catch (const std::out_of_range& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}
