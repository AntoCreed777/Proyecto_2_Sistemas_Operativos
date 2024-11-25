#include <iostream>

#include "../../../include/lru.h"

/*
Este test verifica que el contenedor LRU se comporte de la forma esperada
al insertar elementos en el contenedor que ya se encuentran en él.
*/

int main(){
    LRU lru(5);

    lru.push(2);
    lru.push(2);
    lru.push(2);
    lru.push(2);
    lru.push(2);

    std::cout << "Hits: " << lru.getHits() << std::endl;
    std::cout << "Misses: " << lru.getMisses() << std::endl;

    /*
    Hits: 4
    Misses: 1 
    */

    return 0;

}