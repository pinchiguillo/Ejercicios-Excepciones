#ifndef MIEXCEPCION_H
#define MIEXCEPCION_H

#include <exception>
#include <string>

class MiExcepcion : public std::exception {
private:
    std::string mensaje;

public:
    // Constructor explícito que recibe un mensaje
    explicit MiExcepcion(const std::string& msg) : mensaje(msg) {}

    // Sobrescribe el método what() de std::exception
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void lanzaExcepcion();

#endif // MIEXCEPCION_H
