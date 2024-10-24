//
// Created by pinchiguillo on 24/10/2024.
//

#include "e7.h"

#include<iostream>
#include<stdexcept>
#include<fstream>

void escribeEnArchivo(std::ofstream& file) {
    if (!file.is_open()) {
        throw std::runtime_error("No se puede escribir en un archivo cerrado");
    }
    file << "Hola, mundo!";
}