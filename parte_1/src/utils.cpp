#include "../include/utils.h"
#include <fstream>

void generar_log(std::string msg, std::string ruta){
    std::fstream archivo(ruta, std::ios::app);
    if (!archivo.is_open()){
        std::cerr << "archivo no se a podido abrir\n";
        return;
    }
    archivo << msg << std::endl;
    archivo.close();
}