#pragma once
#include <string>
#include <optional>
#include "Marco.h"


/**
 * @brief Clase abstracta que sirve para definir el adt map
 */
class MapADT{
    public:
     /**
     * @brief Construye un nuevo mapADT
     * 
     * @param opcion eleccion de key que se utilizara en el map. 
     */
        MapADT(){

        }

        /**
         * @brief Metodo para ingresar marcos a partir de la pagina
         * 
         * @param pagina 
         * @param marco 
         */
        virtual void put(Marco marco) = 0;
        //metodos para user ID

        /**
         * @brief Obtiene pagina a partir de una key long long (la pagina)
         * 
         * @param pagina La pagina del seguidor a buscar
         * @return Marco El marco de pagina que se esta buscando.
         */
        virtual std::optional<Marco> get(long long pagina) = 0;

        /**
         * @brief Elimina un valor del map a partir de una key long long (para identificar pagina)
         * 
         * @param pagina La pagina que se desea eliminar
         * @return Marco La pagina eliminada.
         */
        virtual std::optional<Marco> remove(long long pagina) = 0;

        virtual bool empty() = 0;
        virtual int size() = 0;

        /**
         * @brief Destruye el mapADT
         * 
         */
        ~MapADT(){

        }
};