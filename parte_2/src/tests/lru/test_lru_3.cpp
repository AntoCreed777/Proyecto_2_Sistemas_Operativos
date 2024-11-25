#include <iostream>

#include "../../../include/lru.h"

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada 
al insertar elementos en el contenedor superando la capacidad del contenedor
y que los elementos que se insertan son iguales o distintos a los que ya se encuentran en él.
*/

int main(){
    LRU lru(5);

    lru.push(1);
    lru.push(2);
    lru.push(3);
    lru.push(4);
    lru.push(5);
    lru.push(1);
    lru.push(2);
    lru.push(5);
    lru.push(6);

    std::cout << "Hits: " << lru.getHits() << std::endl;
    std::cout << "Misses: " << lru.getMisses() << std::endl;

    /*
    Hits: 3
    Misses: 6 
    */

    return 0;
}