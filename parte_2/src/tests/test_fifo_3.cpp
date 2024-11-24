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

    std:: cout << "Hits: " << fifo.getHits() << "\t" << "Misses: " << fifo.getMisses() << std::endl;

    // Deberia imprimir:
    // 0 7

    fifo.push(1);   // Miss

    fifo.push(5);   // Hit

    fifo.push(6);   // Hit

    std:: cout << "Hits: " << fifo.getHits() << "\t" << "Misses: " << fifo.getMisses() << std::endl;


    // Deberia imprimir:
    // 2 8

    return 0;

}