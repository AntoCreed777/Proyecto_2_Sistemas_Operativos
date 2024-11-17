#pragma once
#include <vector>
#include <list>
#include <iostream>
#include "MapADT.h"
#include "interesting_prime_numbers.h"
#include "PaginaNoEncontradaExcepcion.h"


/**
 * @brief Implementacion de MapADT utilizando hashing abierto
 * 
 */
class MapAbierto : public MapADT{
    private:
        int marcos_totales;
        std::vector<long long>::iterator siguiente_tam_contenedor;
        std::vector<std::list<Marco>> contenedor_marcos;
    public:
        /**
         * @brief Construye un nuevo MapAbierto
         */
        MapAbierto(){
            siguiente_tam_contenedor = numeros_primos_interesantes.begin();
            contenedor_marcos.resize(*siguiente_tam_contenedor);
            siguiente_tam_contenedor++;
            marcos_totales = 0;
        }

        /**
         * @brief implementacion de put de mapADT
         * Dependiendo de cual sea la key se llama a una funcion distinta para añadirla al map
         * Despues se verifica si se nececita aumentar el espacio 
         * 
         * @param usuarios usuario a añadir
         */


                /**
         * @brief funcion para insertar un elemento cuando se esta en modo user_id
         * 
         * @param usuarios usuario a insertar
         */
        void _put_with_longlong(Marco marco){
            int index = _hashf1(marco.pagina);

            //revisamos si hay un elemento con la misma key
            try{
                
                Marco busqueda = this->get(marco.pagina);

            }
            catch (const PaginaNoEncontradaExcepcion& e){
                (contenedor_marcos)[index].push_back(marco);

                marcos_totales++;
                std::cerr << "Pagina no econtrada\n";
                return;
            }

        } 
        void put(Marco marco) override {
            _put_with_longlong(marco);

            
            _verificar_cantidad_ocupada();

        }
        
        /**
         * @brief Metodo para obtener un usuario a partir de su user_id
         * En caso de que algo salga mal se va a devolver un usuario con el nombre Invalid user name
         * @param key user_id del usuario a buscar
         * @return Marco seguidor buscado
         * @return En caso de que algo salga mal se va a devolver un usuario con el nombre Invalid user name
         */
        Marco get(long long key) override {


            int index = _hashf1(key);
            std::list<Marco> lista = contenedor_marcos[index];
            for (auto elem : lista){
                if (elem.pagina == key)
                    return elem;
            }

            throw PaginaNoEncontradaExcepcion();
        }

        /**
         * @brief Implementacion clase para eliminar un elemento del map a partir de su pagina
         * En caso de que algo salga mal se va a devolver una excepcion alertando que la pagina no ha sido encontrada
         * @param key user_id del usuario a eliminiar
         * @return Marco el usuario eliminado.
         * @throw En caso de que algo salga mal se va a devolver un marco con pagina -1 valor -1
         */
         
        Marco remove(long long key) override {

            int index = _hashf1(key);
            std::list<Marco>::iterator it = (contenedor_marcos)[index].begin();
            for (auto it = (contenedor_marcos)[index].begin(); it != (contenedor_marcos)[index].end(); it++){
                if(it->pagina == key){
                    Marco elemento_buscado = *it;
                    (contenedor_marcos)[index].erase(it);
                    marcos_totales--;
                    return elemento_buscado;
                }

            }
            Marco marco = {-1,-1};

            return marco;

        }

       
        int size() override {
            return marcos_totales;
        }

        /**
         * @brief se verifica si el map esta vacio o no
         * 
         * @return true esta vacio
         * @return false no esta vacio
         */
        bool empty() override {
            return (size() == 0) ? true :  false;
        };


        ~MapAbierto(){

        }
    private:

        /**
         * @brief Devuelve el porcentaje de llenado del map
         * Se define como porcentaje de llenado la division entre los seguidores insertados en el map
         * y el tamanio actual del contenedor
         * @return float porcentaje de llenado
         */
        float _porcentaje_llenado(){
            return float(marcos_totales) / float(contenedor_marcos.size());
        }

        /**
         * @brief esta funcion aniade espacios al map en caso de que el porcentaje de llenado sea muy alto (0.9)
         * Si el map esta proximo a llenarse se rellena de nuevo el map.
         * Posterior a esto se procede a hacer un rehash
         */
        void _verificar_cantidad_ocupada(){
            if (_porcentaje_llenado() < 0.9)
                return;
            std::vector<std::list<Marco>>  viejo_contenedor_marcos = this->contenedor_marcos;
            contenedor_marcos.clear();
            this->contenedor_marcos.resize(*siguiente_tam_contenedor);
            siguiente_tam_contenedor++;
            marcos_totales = 0;

            //hacemos rehashing
            for (auto lista : viejo_contenedor_marcos){
                while (!lista.empty()){
                    Marco elemento = lista.back();
                    lista.pop_back();
                    put(elemento);
                }
            }

        }

        /**
         * @brief funcion para generar el hash correspondiente dependiendo de un valor numerico
         * 
         * @param k valor numerico a hashear
         * @return int valor ya hasheado
         */
        int _hashf1(int k) {
            return k % (contenedor_marcos).size();
        }

};