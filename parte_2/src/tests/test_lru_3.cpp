#include <iostream>

#include <lru.h>

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada 
al insertar elementos en el contenedor superando la capacidad del contenedor
y que los elementos que se insertan son iguales o distintos a los que ya se encuentran en él.
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
    
    lru.push(1);
        lru.mostrar_contenedor();

    lru.push(2);
        lru.mostrar_contenedor();

    lru.push(5);
        lru.mostrar_contenedor();
    
    lru.push(6);
        lru.mostrar_contenedor();
    

    // Deberia imprimir:
    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
    // 2 3 4 5 1
    // 3 4 5 1 2
    // 3 4 1 2 5
    // 4 1 2 5 6

    return 0;
}