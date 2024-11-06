#include <iostream>
#include "cola.h"

int main() {
    Cola<int> cola;

    // Insertamos y eliminamos alternadamente
    cola.push(10);
    cola.mostrar_contenedor();

    std::cout << "Se elimina: " << cola.pop() << std::endl;
    cola.mostrar_contenedor();

    cola.push(20);
    cola.mostrar_contenedor();

    cola.push(30);
    cola.mostrar_contenedor();

    std::cout << "Se elimina: " << cola.pop() << std::endl;
    cola.mostrar_contenedor();

    cola.push(40);
    cola.mostrar_contenedor();

    std::cout << "Se elimina: " << cola.pop() << std::endl;
    cola.mostrar_contenedor();

    cola.push(50);
    cola.mostrar_contenedor();

    return 0;
}
