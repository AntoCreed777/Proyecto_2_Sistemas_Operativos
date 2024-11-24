#include <iostream>
#include <vector>
#include "../../include/optimo.h"

int main() {
    std::vector<int> lista_de_referencias = {1, 2, 3, 4, 2, 1, 2, 3, 1}, nuevo;

    Optimo<int> optimo(3, lista_de_referencias);

    for (int elemento: lista_de_referencias) {
        optimo.push(elemento);
        optimo.mostrar_contenedor();    
    }

    // Caso Ideal
    // 1
    // 1 2 
    // 1 2 3 
    // 1 2 4 
    // 1 2 4 
    // 1 2 4 
    // 1 2 4 
    // 1 4 3 
    // 1 4 3 




    return 0;
}