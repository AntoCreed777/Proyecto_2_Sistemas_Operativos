#pragma once
#include <vector>


/**
 * @brief Esta constante contienen los numeros primos interesantes.
 * Para efectos de esta tarea se define como un numero primo interesante
 * aquel que es primo y ademas es el primero despues de una potencia de 2.
 * Estos serviran para el tamaño de los contenedores
 * Los numeros fueron buscados ocupando https://t5k.org/lists/small/millions/
 * y un script en python
 * 
 */
extern std::vector<long long> numeros_primos_interesantes;