#include <iostream>
#include "../../include/MapAbierto.h"

int main() {

    MapAbierto map;

    // Inserciones con valores arbitrarios
    map.put({10, 20});   // Clave 10, Valor 20
    map.put({15, 30});   // Clave 15, Valor 30
    map.put({20, 40});   // Clave 20, Valor 40
    map.put({25, 50});   // Clave 25, Valor 50
    map.put({30, 60});   // Clave 30, Valor 60
    map.put({35, 70});   // Clave 35, Valor 70
    map.put({40, 80});   // Clave 40, Valor 80

    // Realizamos prints manuales para verificar la correcta inserción
    std::cout << "Verificando los valores insertados:" << std::endl;

    // Verificamos la clave 10
    auto result = map.get(10);
    std::cout << "Clave: 10, Valor esperado: 20, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 15
    result = map.get(15);
    std::cout << "Clave: 15, Valor esperado: 30, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 20
    result = map.get(20);
    std::cout << "Clave: 20, Valor esperado: 40, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 25
    result = map.get(25);
    std::cout << "Clave: 25, Valor esperado: 50, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 30
    result = map.get(30);
    std::cout << "Clave: 30, Valor esperado: 60, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 35
    result = map.get(35);
    std::cout << "Clave: 35, Valor esperado: 70, Valor obtenido: " << result.valor << std::endl;

    // Verificamos la clave 40
    result = map.get(40);
    std::cout << "Clave: 40, Valor esperado: 80, Valor obtenido: " << result.valor << std::endl;

   

    return 0;
}
