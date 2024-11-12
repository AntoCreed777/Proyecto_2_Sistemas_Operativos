#include <iostream>

#include <lru.h>

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada 
al insertar elementos en el contenedor que sean distintos a los que ya se encuentran en él
superando la capacidad del contenedor.
*/

int main(){
    LRU<int> lru(5);

    lru.push(1);
        lru.mostrar_contenedor();

    lru.push(2);
        lru.mostrar_contenedor();

    lru.push(3);
        lru.mostrar_contenedor();

    lru.push(4);
        lru.mostrar_contenedor();

    lru.push(5);
        lru.mostrar_contenedor();
    
    lru.push(6);
        lru.mostrar_contenedor();

    lru.push(7);
        lru.mostrar_contenedor();

    lru.push(8);
        lru.mostrar_contenedor();

    lru.push(9);
        lru.mostrar_contenedor();

    lru.push(10);
        lru.mostrar_contenedor();
    

    // Deberia imprimir:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    // 2 3 4 5 6
    // 3 4 5 6 7
    // 4 5 6 7 8
    // 5 6 7 8 9
    // 6 7 8 9 10

    return 0;

}