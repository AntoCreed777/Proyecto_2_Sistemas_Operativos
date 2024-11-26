#include "../include/lru.h"


LRU::LRU(int tamanio) {
    this->map = MapAbierto();
    this->cola = std::queue<int>();
    this->hits = 0;
    this->misses = 0;
    this->tamanio = tamanio;
}

void LRU::push(int element){
    auto resultado = this->map.get(element);
    
    if(resultado.has_value()){
        this->hits++;

        std::queue<int> cola_aux;

        while(!this->cola.empty()){
            if(this->cola.front() != element)
                cola_aux.push(this->cola.front());
            this->cola.pop();
        }

        this->cola = cola_aux;
        this->cola.push(element);
        
        return;
    }

    this->misses++;
    
    if(this->map.size() < this->tamanio){   // Si hay espacio en el map
        this->map.put({element, this->map.size()});
        this->cola.push(element);
        return;
    }
    
    int victima = this->cola.front();            // Tomo el ultimo de la queue
    this->cola.pop();                           // Elimino el ultimo 

    auto marco_victima = this->map.get(victima);   // Tomar los datos del map de la victima

    if(!marco_victima.has_value())
        throw std::runtime_error("No se encontro el marco de la victima");

    this->map.remove(victima);

    this->map.put({element, marco_victima->valor});
    this->cola.push(element);
}
