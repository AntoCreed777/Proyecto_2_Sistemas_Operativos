#include "../include/MapAbierto.h"

MapAbierto::MapAbierto() {
    siguiente_tam_contenedor = numeros_primos_interesantes.begin();
    contenedor_marcos.resize(*siguiente_tam_contenedor);
    siguiente_tam_contenedor++;
    marcos_totales = 0;
}

void MapAbierto::put(Marco marco) {
    _put_with_longlong(marco);
    _verificar_cantidad_ocupada();
}

std::optional<Marco> MapAbierto::get(long long key) {
    int index = _hashf1(key);
    std::list<Marco> lista = contenedor_marcos[index];
    for (auto elem : lista) {
        if (elem.pagina == key) {
            return elem;
        }
    }
    return std::nullopt;
}

std::optional<Marco> MapAbierto::remove(long long key) {
    int index = _hashf1(key);
    std::list<Marco>::iterator it = contenedor_marcos[index].begin();
    for (; it != contenedor_marcos[index].end(); ++it) {
        if (it->pagina == key) {
            Marco elemento_buscado = *it;
            contenedor_marcos[index].erase(it);
            marcos_totales--;
            return elemento_buscado;
        }
    }
    return {};
}

int MapAbierto::size() {
    return marcos_totales;
}

bool MapAbierto::empty() {
    return (size() == 0) ? true : false;
}

MapAbierto::~MapAbierto() {
    // Destructor por defecto
}

void MapAbierto::_put_with_longlong(Marco marco) {
    int index = _hashf1(marco.pagina);
    std::optional<Marco> busqueda = this->get(marco.pagina);
    if (!busqueda) {
        contenedor_marcos[index].push_back(marco);
        marcos_totales++;
    }
}

float MapAbierto::_porcentaje_llenado() {
    return float(marcos_totales) / float(contenedor_marcos.size());
}

void MapAbierto::_verificar_cantidad_ocupada() {
    if (_porcentaje_llenado() < 0.9) {
        return;
    }
    std::vector<std::list<Marco>> viejo_contenedor_marcos = this->contenedor_marcos;
    contenedor_marcos.clear();
    this->contenedor_marcos.resize(*siguiente_tam_contenedor);
    siguiente_tam_contenedor++;
    marcos_totales = 0;

    for (auto lista : viejo_contenedor_marcos) {
        while (!lista.empty()) {
            Marco elemento = lista.back();
            lista.pop_back();
            put(elemento);
        }
    }
}

int MapAbierto::_hashf1(int k) {
    return k % contenedor_marcos.size();
}

void MapAbierto::modificar_referenciado(long long key, bool referencia) {
    int index = _hashf1(key);
    std::list<Marco>::iterator it = contenedor_marcos[index].begin();
    for (; it != contenedor_marcos[index].end(); ++it) {
        if (it->pagina == key) {
            it->referenciado = referencia;
            return;
        }
    }
}