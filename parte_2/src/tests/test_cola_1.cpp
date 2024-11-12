#include <iostream>
#include "cola.h"

/*
Este test verifica que la cola se comporte correctamente al hacer insertar elementos
que ya existen en la cola.
*/

int main(){
    Cola<int> cola(5);

    cola.push(2);
        cola.mostrar_contenedor();

    cola.push(2);
        cola.mostrar_contenedor();

    cola.push(3);
        cola.mostrar_contenedor();

    cola.push(2);
        cola.mostrar_contenedor();
    
    cola.push(3);
        cola.mostrar_contenedor();

    // Deberia imprimir:
    // 2
    // 2
    // 2 3
    // 2 3
    // 2 3

    return 0;

}