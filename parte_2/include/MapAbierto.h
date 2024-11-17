#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <optional>
#include "MapADT.h"
#include "interesting_prime_numbers.h"

/**
 * @brief Implementacion de MapADT utilizando hashing abierto
 * 
 */
class MapAbierto : public MapADT {
    private:
        int marcos_totales;
        std::vector<long long>::iterator siguiente_tam_contenedor;
        std::vector<std::list<Marco>> contenedor_marcos;
    public:
        /**
         * @brief Construye un nuevo MapAbierto
         */
        MapAbierto();

        /**
         * @brief implementacion de put de mapADT
         * Dependiendo de cual sea la key se llama a una funcion distinta para añadirla al map
         * Despues se verifica si se nececita aumentar el espacio 
         * 
         * @param usuarios usuario a añadir
         */
        void put(Marco marco) override;

        /**
         * @brief Metodo para obtener un usuario a partir de su user_id
         * En caso de que algo salga mal se va a devolver un usuario con el nombre Invalid user name
         * @param key user_id del usuario a buscar
         * @return Marco seguidor buscado
         * @return En casonumeros_primos_interesantes de que algo salga mal se va a devolver un usuario con el nombre Invalid user name
         */
        std::optional<Marco> get(long long key) override;

        /**
         * @brief Implementacion clase para eliminar un elemento del map a partir de su pagina
         * En caso de que algo salga mal se va a devolver una excepcion alertando que la pagina no ha sido encontrada
         * @param key user_id del usuario a eliminiar
         * @return Marco el usuario eliminado.
         * @throw En caso de que algo salga mal se va a devolver un marco con pagina -1 valor -1
         */
        std::optional<Marco> remove(long long key) override;

        int size() override;

        /**
         * @brief se verifica si el map esta vacio o no
         * 
         * @return true esta vacio
         * @return false no esta vacio
         */
        bool empty() override;

        ~MapAbierto();
    private:
        /**
         * @brief funcion para insertar un marco
         * 
         * @param marco marco a insertar
         */
        void _put_with_longlong(Marco marco);

        /**
         * @brief Devuelve el porcentaje de llenado del map
         * Se define como porcentaje de llenado la division entre los seguidores insertados en el map
         * y el tamanio actual del contenedor
         * @return float porcentaje de llenado
         */
        float _porcentaje_llenado();

        /**
         * @brief esta funcion aniade espacios al map en caso de que el porcentaje de llenado sea muy alto (0.9)
         * Si el map esta proximo a llenarse se rellena de nuevo el map.
         * Posterior a esto se procede a hacer un rehash
         */
        void _verificar_cantidad_ocupada();

        /**
         * @brief funcion para generar el hash correspondiente dependiendo de un valor numerico
         * 
         * @param k valor numerico a hashear
         * @return int valor ya hasheado
         */
        int _hashf1(int k);
};
