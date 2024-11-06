#include <iostream>
#include "cola.h"

int main(){
    Cola<int> cola;
    cola.push(2);
    cola.mostrar_contenedor();
    cola.push(3);
        cola.mostrar_contenedor();

    cola.push(4);
        cola.mostrar_contenedor();

    cola.push(5);
        cola.mostrar_contenedor();

    cola.push(6);
        cola.mostrar_contenedor();

    cola.push(7);
        cola.mostrar_contenedor();

    cola.push(8);
        cola.mostrar_contenedor();
    std::cout << "se inicia eliminado\n\n";
    // std::cout << "el tamanio es " << cola.tamanio_contenedor() << std::endl;
    while (cola.size() > 0){
        std:: cout << cola.pop() << std::endl;
        cola.mostrar_contenedor();
    }

    return 0;

}