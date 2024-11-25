#include <iostream>
#include <vector>
#include "../../../include/optimo.h"

int main() {
    std::vector<int> lista_de_referencias = {1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 3};

    Optimo optimo(3, lista_de_referencias);


    for (int elemento: lista_de_referencias) {
        optimo.push(elemento);
        optimo.mostrar_contenedor();
    }

    std::cout << "Hits: " << optimo.getHits() << std::endl;
    std::cout << "Misses: " << optimo.getMisses() << std::endl;

    /*
    Hits: 6
    Misses: 9
    */


    // Como se vería el sistema
    // 1 
    // 1 
    // 1 
    // 1 
    // 1 
    // 1 
    // 1 2 
    // 1 2 3 
    // 2 3 4 
    // 3 4 5 
    // 3 5 6 
    // 3 6 7 
    // 3 7 8 
    // 3 8 9 
    // 3 8 9 



    return 0;
}