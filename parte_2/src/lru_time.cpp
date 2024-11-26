#include "../include/lru_time.h"

LRU_TIME::LRU_TIME(int tamano){
    this->paginas_cargadas = std::vector<int>(tamano);
    this->map = MapAbierto();
    this->hits = 0;
    this->misses = 0;
    this->posicion_puntero = 0;
}

void LRU_TIME::push(int elem) {
    if (this->map.get(elem).has_value()) {      // Si ya esta en la tabla
        this->hits++;
        this->map.modificar_referenciado(elem, true);
        return;
    }
    
    this->misses++;

    if(this->map.size() < int(this->paginas_cargadas.size()) ) {  // Si hay espacio
        this->paginas_cargadas[this->map.size()] = elem;
        this->map.put({elem, this->map.size(), true});
    }

    else {
        int victima = buscar_victima();

        auto marco_victima = this->map.get(victima);
        this->map.remove(victima);

        this->map.put({elem, marco_victima->valor, true});
        this->paginas_cargadas[marco_victima->valor] = elem;
    }
}

int LRU_TIME::buscar_victima(){
    while(true) {
        if (this->map.get(this->paginas_cargadas[posicion_puntero])->referenciado)
            this->map.modificar_referenciado(this->paginas_cargadas[posicion_puntero], false);
        
        else return this->paginas_cargadas[posicion_puntero];
    }
}