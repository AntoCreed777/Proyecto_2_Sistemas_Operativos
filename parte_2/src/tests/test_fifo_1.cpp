#include <iostream>

#include "../../include/fifo.h"

int main(){
    FIFO fifo(5);

    fifo.push(2); // Miss

    fifo.push(2); // Hit

    fifo.push(3); // Miss

    fifo.push(2); // Hit
    
    fifo.push(3); // Hit

    std::cout << "Hits: " << fifo.getHits() << std::endl;
    std::cout << "Misses: " << fifo.getMisses() << std::endl;

    /*
    Dereria imprimir:
    Hits: 3
    Misses: 2
    */

    return 0;

}