#include "../include/utils.h"
#include <fstream>
#include <vector>
#include <random>
#include <sstream>

void utils::generar_log(std::string msg, std::string ruta){
    std::fstream archivo(ruta, std::ios::app);
    if (!archivo.is_open()){
        std::cerr << "archivo no se a podido abrir/crear el log\n";
        return;
    }
    archivo << msg << std::endl;
    archivo.close();
}

// Función para generar un vector de enteros aleatorios
std::vector<int> utils::generar_lista_aleatoria(int tamanio, int min, int max) {
    std::vector<int> lista(tamanio);
    std::random_device rd;  // Generador de números aleatorios basado en hardware
    std::mt19937 gen(rd()); // Generador de números aleatorios Mersenne Twister
    std::uniform_int_distribution<> dis(min, max); // Distribución uniforme en el rango [min, max]

    for (int i = 0; i < tamanio; ++i)
        lista[i] = dis(gen);

    return lista;
}

std::string utils::vector_to_string(const std::vector<int>& vec) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}