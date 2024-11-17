#include <iostream>
#include <optional>
#include "../../include/MapAbierto.h"

int main() {
    // Creamos una instancia de MapAbierto
    MapAbierto map;

    // Inserciones con valores arbitrarios
    std::cout << "Insertando valores:" << std::endl;
    map.put({1, 100});
    map.put({2, 200});
    map.put({3, 300});
    map.put({4, 400});
    map.put({5, 500});

    // Verificación de inserción y obtención
    std::cout << "Verificando los valores insertados:" << std::endl;
    auto result = map.get(1);
    std::cout << "Clave: 1, Valor esperado: 100, Valor obtenido: " << result->valor << std::endl;

    result = map.get(2);
    std::cout << "Clave: 2, Valor esperado: 200, Valor obtenido: " << result->valor << std::endl;

    result = map.get(3);
    std::cout << "Clave: 3, Valor esperado: 300, Valor obtenido: " << result->valor << std::endl;

    result = map.get(4);
    std::cout << "Clave: 4, Valor esperado: 400, Valor obtenido: " << result->valor << std::endl;

    result = map.get(5);
    std::cout << "Clave: 5, Valor esperado: 500, Valor obtenido: " << result->valor << std::endl;

    // Comprobación de tamaño
    std::cout << "\nVerificando el tamaño del mapa:" << std::endl;
    std::cout << "Tamaño esperado: 5, Tamaño obtenido: " << map.size() << std::endl;

    // Eliminar un elemento y verificar que ha sido eliminado
    std::cout << "\nEliminando clave 3:" << std::endl;
    map.remove(3);
    std::cout << "Tamaño esperado después de eliminar: 4, Tamaño obtenido: " << map.size() << std::endl;

    // Verificar que la clave 3 ya no está presente
    try {
        result = map.get(3);
        std::cout << "Error: Clave 3 debería haber sido eliminada, pero se encontró con valor: " << result->valor << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Clave 3 correctamente eliminada. Excepción capturada: " << e.what() << std::endl;
    }

    // Verificar si el mapa está vacío
    std::cout << "\nVerificando si el mapa está vacío:" << std::endl;
    std::cout << "¿Está vacío? " << (map.empty() ? "Sí" : "No") << std::endl;

    // Eliminar todos los elementos restantes
    std::optional<Marco> valor;
    valor = map.remove(1);
    if(valor){
        std::cout << "Se encontro el valor " << valor->valor << "y se va a eliminar" <<std::endl;
    }
    else{
        std::cout << "Se perdio un valor valor " << std::endl;
    }
    valor = map.remove(2);
    if(valor){
        std::cout << "Se encontro el valor " << valor->valor  << "y se va a eliminar" <<std::endl;
    }
    else{
        std::cout << "Se perdio un valor valor " << std::endl;
    }
    valor = map.remove(4);
    if(valor){
        std::cout << "Se encontro el valor " << valor->valor  << "y se va a eliminar" <<std::endl;
    }
    else{
        std::cout << "Se perdio un valor valor " << std::endl;
    }
    valor = map.remove(5);
    if(valor){
        std::cout << "Se encontro el valor " << valor->valor  << "y se va a eliminar" <<std::endl;
    }
    else{
        std::cout << "Se perdio un valor valor " << std::endl;
    }

    // Verificar que el mapa está vacío después de eliminar todos los elementos
    std::cout << "\nVerificación final después de eliminar todos los elementos:" << std::endl;
    std::cout << "Tamaño esperado: 0, Tamaño obtenido: " << map.size() << std::endl;
    std::cout << "¿Está vacío? " << (map.empty() ? "Sí" : "No") << std::endl;

    return 0;
}
