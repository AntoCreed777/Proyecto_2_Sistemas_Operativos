#include <iostream>
#include <vector>
#include "../../include/optimo.h"

int main() {
    std::vector<int> lista_de_referencias = {1, 1, 1, 1, 1, 1}, nuevo;

    Optimo<int> optimo(3, lista_de_referencias);

    for (int elemento: lista_de_referencias) {
        optimo.push(elemento);
    }

    std::cout << "hits: " << optimo.getHits() << " and Misses: " << optimo.getMisses() << "\n";
    // Hits: 5
    // Misses: 1

    optimo.push(2);
    optimo.push(2);

    std::cout << "hits: " << optimo.getHits() << " and Misses: " << optimo.getMisses() << std::endl;
    // Hits: 6
    // Misses: 2

    return 0;
}