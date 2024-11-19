#pragma once
#include <iostream>
#include <vector>
#include "constantes.h"

#define NO_SE_ENCONTRO -1
#define MAXVALUE 1024
 
template <typename element>
class Optimo{
    private: 
        std::vector<element> contenedor;
        int indice_lista_referencia;
        int hits;
        int misses;
        int cantidad_elementos;
        int busqueda_lineal(element e);
        std::vector<element> lista_de_referencias;

        int paginaRemplazo(){
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

                if(distancia == MAXVALUE){
                    return i;
                }

                if(distancia > distancia_maxima){
                    distancia_maxima = distancia;
                    indice_remplazar = i;
                }
            }
            
            return indice_remplazar;
        }

    public:
        Optimo(int size, std::vector<element> lista_de_procesos);
        void push(element e);
        void mostrar_contenedor();
        int getHits() { return hits; };
        int getMisses() { return misses; };
};

template <typename element>
Optimo<element>::Optimo(int size, std::vector<element> lista_de_referencias) {
    this->contenedor = std::vector<element>(size);
    this->lista_de_referencias = lista_de_referencias;
    this->hits = 0;
    this->misses = 0;
    this->cantidad_elementos = 0;
    this->indice_lista_referencia = 0;
}


template <typename element>
void Optimo<element>::push(element e) {
    int posicion = this->busqueda_lineal(e);

    // Si no lo encuentra en el contenedor
    if (posicion == NO_SE_ENCONTRO) {
        this->misses++;
        if (int(this->contenedor.size()) == cantidad_elementos) {  // Si el contenedor está lleno
            int remplazo = paginaRemplazo();
            this->contenedor.erase(this->contenedor.begin() + remplazo); // Elimina el que mas lejos está referenciado
            this->contenedor.push_back(e);                      // Inserta el nuevo elemento al final
        }
        else{
            this->contenedor[this->cantidad_elementos] = e;
            this->cantidad_elementos++;
        }
    } else {
        this->hits++;
    }
    this->indice_lista_referencia++;
}




template <typename element>
int Optimo<element>::busqueda_lineal(element e) {
    for (int i=0;i<cantidad_elementos;i++)
        if (contenedor[i] == e) return i;
    
    return NO_SE_ENCONTRO;
}





template <typename element>
void Optimo<element>::mostrar_contenedor() {
    if (this->cantidad_elementos == 0) {
        std::cout << std::endl;
        return;
    }

    std::cout << AZUL;
    for (int i = 0; i < this->cantidad_elementos; i++) {
        std::cout << this->contenedor[i] << " ";
    }
    std::cout << RESET_COLOR << std::endl;
}