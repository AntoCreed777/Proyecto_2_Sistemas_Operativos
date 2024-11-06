#include <iostream>
#include "cola.h"

int main() {
    Cola<int> cola;

    // Agregamos elementos para forzar el redimensionamiento hacia arriba
    for (int i = 1; i <= 10; ++i) {
        cola.push(i);
        cola.mostrar_contenedor();
    }

    std::cout << "Comenzamos a eliminar para probar redimensionamiento hacia abajo\n\n";

    // Eliminamos elementos hasta que el contenedor se reduzca
    while (cola.size()) {  // Dejamos algunos elementos para ver el redimensionamiento
        std::cout << "Se elimina: " << cola.pop() << std::endl;
        cola.mostrar_contenedor();
    }

    return 0;
}
