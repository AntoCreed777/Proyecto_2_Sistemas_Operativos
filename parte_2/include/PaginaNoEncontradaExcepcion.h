#include <stdexcept>

class PaginaNoEncontradaExcepcion : public std::exception {
public:
    const char* what() const noexcept override {
        return "No se a encontrado al pagina que esta buscando";
    }
};