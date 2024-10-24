#include<iostream>
#include<stdexcept>

// Versión de la función que devuelve un valor de error
int divideError(int a, int b) {
    if (b == 0) {
        return -1; // valor de error
    }
    else {
        return a / b;
    }
}

// Versión de la función que lanza una excepción
int divideException(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("División por cero"); // lanza una excepción
    }
    else {
        return a / b;
    }
}

int main() {
    // Uso de la versión que devuelve un valor de error
    int resultError = divideError(5, 0);
    if (resultError == -1) {
        std::cout << "Error: división por cero." << std::endl;
    }

    // Uso de la versión que lanza una excepción
    try {
        int resultException = divideException(5, 0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Excepción: " << e.what() << std::endl;
    }

    return 0;
}