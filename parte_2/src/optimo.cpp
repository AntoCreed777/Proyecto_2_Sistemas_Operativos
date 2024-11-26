#include "../include/optimo.h"


Optimo::Optimo(int size, std::vector<int> lista_de_referencias) {
    this->contenedor = std::vector<int>(size);
    this->map = MapAbierto();
    this->lista_de_referencias = lista_de_referencias;
    this->hits = 0;
    this->misses = 0;
    this->cantidad_elementos = 0;
    this->indice_lista_referencia = 0;
}


int Optimo::paginaRemplazo() {
    int distancia_maxima = -1;
    int indice_remplazar = -1;

    for(size_t i = 0; i < contenedor.size(); i++){
        int distancia = MAXVALUE; // numero grande
        
        for(size_t j = indice_lista_referencia + 1; j < lista_de_referencias.size(); j++){
            if(contenedor[i] == lista_de_referencias[j]){
                distancia = j - indice_lista_referencia;
                break;
            }
        }

        if(distancia == MAXVALUE) return i;

        if(distancia > distancia_maxima){
            distancia_maxima = distancia;
            indice_remplazar = i;
        }
    }
    
    return indice_remplazar;
}


void Optimo::push(int valor) {
    auto posicion = this->map.get(valor);

    if (posicion.has_value())     // Si lo encuentra en el contenedor
        this->hits++;

    else {
        this->misses++;

        if (this->map.size() < this->cantidad_elementos) {  // Si el contenedor tiene espacio
            this->map.put({valor, this->map.size()});
            this->contenedor[this->cantidad_elementos] = valor;
        }
        else {
            int posicion_victima = paginaRemplazo();
            int pagina_victima = this->contenedor[posicion_victima];

            auto marco_victima = this->map.get(pagina_victima);
            this->map.remove(pagina_victima);

            this->contenedor.erase(this->contenedor.begin() + posicion_victima); // Elimina el que mas lejos está referenciado
            this->contenedor.push_back(valor);                           // Inserta el nuevo elemento al final

            this->map.put({valor, marco_victima->valor});
        }
    }
    
    this->indice_lista_referencia++;
}


void Optimo::mostrar_contenedor() {
    std::cout << AZUL;
    for (auto &i : this->contenedor)
        std::cout << i << " ";
    std::cout << RESET_COLOR << std::endl;
}