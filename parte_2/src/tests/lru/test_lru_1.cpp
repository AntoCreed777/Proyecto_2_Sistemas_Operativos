#include <iostream>

#include <lru.h>

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada
al insertar elementos en el contenedor que ya se encuentran en él.
*/

int main(){
    LRU<int> lru(5);

    lru.push(2);
        lru.mostrar_contenedor();

    lru.push(2);
        lru.mostrar_contenedor();

    lru.push(3);
        lru.mostrar_contenedor();

    lru.push(3);
        lru.mostrar_contenedor();

    lru.push(2);
        lru.mostrar_contenedor();
    
    lru.push(3);
        lru.mostrar_contenedor();

    // Deberia imprimir:
    // 2
    // 2
    // 2 3
    // 2 3
    // 3 2
    // 2 3

    return 0;

}