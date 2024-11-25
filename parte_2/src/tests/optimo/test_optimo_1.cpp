#include <iostream>
#include <vector>
#include "../../../include/optimo.h"

int main() {
    std::vector<int> lista_de_referencias = {1, 2, 3, 4, 2, 1, 2, 3, 1};

    Optimo optimo(3, lista_de_referencias);

    for (int elemento : lista_de_referencias) {
        optimo.push(elemento);
        optimo.mostrar_contenedor();
    }

    std::cout << "Hits: " << optimo.getHits() << std::endl;
    std::cout << "Misses: " << optimo.getMisses() << std::endl;

    /*
    Hits: 4
    Misses: 5
    */

    // Caso Ideal
    // 1        miss
    // 1 2      miss
    // 1 2 3    miss
    // 1 2 4    miss
    // 1 2 4    hit
    // 1 2 4    hit
    // 1 2 4    hit
    // 1 4 3    miss
    // 1 4 3    hit




    return 0;
}