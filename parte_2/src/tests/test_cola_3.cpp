#include <iostream>
#include "cola.h"

/*
Este test verifica que la cola se comporte correctamente al insertar elementos
y consultar la cantidad de hits y misses.
*/

int main(){
    Cola<int> cola(5);

    cola.push(2);   // Miss

    cola.push(3);   // Miss

    cola.push(4);   // Miss

    cola.push(5);   // Miss

    cola.push(6);   // Miss

    cola.push(7);   // Miss

    cola.push(8);   // Miss

    std:: cout << "Hits: " << cola.getHits() << "\t" << "Misses: " << cola.getMisses() << std::endl;

    // Deberia imprimir:
    // 0
    // 7

    cola.push(1);   // Miss

    cola.push(5);   // Hit

    cola.push(6);   // Hit

    std:: cout << "Hits: " << cola.getHits() << "\t" << "Misses: " << cola.getMisses() << std::endl;


    // Deberia imprimir:
    // 2
    // 8

    return 0;

}