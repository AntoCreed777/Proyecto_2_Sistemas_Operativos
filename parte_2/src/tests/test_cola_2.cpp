#include <iostream>
#include "cola.h"

/*
Este test verifica que la cola se comporte correctamente al insertar elementos
sobrepasando el tamaño del contenedor.
*/

int main(){
    Cola<int> cola(5);

    cola.push(2);
        cola.mostrar_contenedor();

    cola.push(3);
        cola.mostrar_contenedor();    

    cola.push(4);
        cola.mostrar_contenedor();

    cola.push(5);
        cola.mostrar_contenedor();

    cola.push(6);
        cola.mostrar_contenedor();

    cola.push(7);
        cola.mostrar_contenedor();

    cola.push(8);
        cola.mostrar_contenedor();

    // Deberia imprimir:
    // 2
    // 2 3
    // 2 3 4
    // 2 3 4 5
    // 2 3 4 5 6
    // 3 4 5 6 7
    // 4 5 6 7 8
    return 0;

}