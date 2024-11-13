#include <iostream>

#include <lru_time.h>

int main(){
    LRU_TIME<int> lru_time(3);

    lru_time.push(1);
        lru_time.mostrar_contenedor();

    lru_time.push(2);
        lru_time.mostrar_contenedor();

    lru_time.push(1);
        lru_time.mostrar_contenedor();

    lru_time.push(3);
        lru_time.mostrar_contenedor();

    lru_time.push(4);
        lru_time.mostrar_contenedor();

    lru_time.push(2);
        lru_time.mostrar_contenedor();

    lru_time.push(5);
        lru_time.mostrar_contenedor();
    
    // Deberia imprimir:
    // 1
    // 1 2
    // 1 2
    // 1 2 3
    // 4 2 3
    // 4 2 3
    // 4 2 5

    return 0;
}