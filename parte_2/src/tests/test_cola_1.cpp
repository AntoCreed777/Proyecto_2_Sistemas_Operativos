#include <iostream>
#include "cola.h"

int main(){
    Cola<int> cola(5);

    cola.push(2);
        cola.mostrar_contenedor();

    cola.push(2);
        cola.mostrar_contenedor();

    cola.push(3);
        cola.mostrar_contenedor();

    // Deberia imprimir:
    // 2
    // 2
    // 2 3

    return 0;

}