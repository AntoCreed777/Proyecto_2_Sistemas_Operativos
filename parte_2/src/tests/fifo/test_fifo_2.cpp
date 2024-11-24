#include <iostream>
#include "../../include/fifo.h"


int main(){
    FIFO fifo(5);

    fifo.push(2);   // Miss

    fifo.push(3);   // Miss

    fifo.push(4);   // Miss

    fifo.push(5);   // Miss

    fifo.push(6);   // Miss

    fifo.push(7);   // Miss

    fifo.push(8);   // Miss

    std::cout << fifo.getHits() << std::endl;
    std::cout << fifo.getMisses() << std::endl;

    // Deberia imprimir:
    // Hits: 0
    // Misses: 7
    return 0;

}