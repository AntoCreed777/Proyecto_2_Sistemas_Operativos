#include <iostream>

#include "../../../include/lru.h"

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada 
al insertar elementos en el contenedor que sean distintos a los que ya se encuentran en él
superando la capacidad del contenedor.
*/

int main(){
    LRU lru(5);

    lru.push(1);
    lru.push(2);
    lru.push(3);
    lru.push(4);
    lru.push(5);
    lru.push(6);
    lru.push(7);
    lru.push(8);
    lru.push(9);
    lru.push(10);
    
    std::cout << "Hits: " << lru.getHits() << std::endl;
    std::cout << "Misses: " << lru.getMisses() << std::endl;

    /*
     Hits: 0
     Misses: 10 
     */

    return 0;

}