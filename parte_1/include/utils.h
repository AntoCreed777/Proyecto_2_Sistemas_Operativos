#pragma once
#include <fstream>
#include <iostream>
#include <vector>


namespace utils {
    void generar_log(std::string msg, std::string ruta);
    std::vector<int> generar_lista_aleatoria(int tamanio, int min, int max);
    std::string vector_to_string(const std::vector<int>& vec);
}
