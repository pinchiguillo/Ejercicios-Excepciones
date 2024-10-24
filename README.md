# Ejercicios-Excepciones

[Link del repositorio](https://github.com/pinchiguillo/Ejercicios-Excepciones)

## Enunciado de Ejercicios
Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C:

### Ejercicio 1:
Implementa un programa en C++ que simule un sistema con banderas de error. Si ocurre un error, en lugar de lanzar una excepción, establece una bandera de error. Luego, comprueba regularmente la bandera de error para manejarla.
Las excepciones son más seguras que los errores:

### Ejercicio 2:
Implementa dos versiones de una función que pueda provocar un error (como la división por cero). La primera versión debe manejar el error devolviendo un valor de error, mientras que la segunda versión debe lanzar una excepción en caso de error. Compara la seguridad y facilidad de uso de ambas versiones.
Propagación explícita:

### Ejercicio 3:
Crea un programa que demuestre cómo se propaga una excepción a través de varias funciones. Asegúrate de que algunas funciones no manejen la excepción, de modo que tenga que propagarse hasta una función que la maneje.
Tipos de excepciones personalizadas: Definición de clases de excepción, Instanciación de clases, Clases de excepción derivadas:

### Ejercicio 4:
Define tus propias clases de excepción que hereden de la clase std::exception. Haz que estas clases representen diferentes tipos de errores que podrían ocurrir en tu programa. Utiliza estas excepciones en tu programa y asegúrate de que se manejan correctamente.
Manejo de una excepción y reactivación:

### Ejercicio 5:
Escribe un programa en el que una función lanza una excepción, la cual es manejada en otra parte del programa. Luego, la excepción se relanza para que sea manejada por otro manejador de excepciones.
Excepciones no interceptadas:

### Ejercicio 6:
Escribe un programa que lance una excepción que no sea capturada por ningún bloque de catch. Observa lo que sucede cuando se ejecuta el programa.
Adquisición de recursos:

### Ejercicio 7:
Implementa una clase que adquiere un recurso (como memoria dinámica o un archivo) en su constructor y libera el recurso en su destructor. Haz que el constructor lance una excepción si no se puede adquirir el recurso. Demuestra que, a pesar de la excepción, no se produce una fuga de recursos.
Recuerda que debes encerrar cada uno de estos ejercicios en bloques de try/catch para manejar las excepciones y así evitar que tu programa se cierre inesperadamente.

## Resolución de Ejercicios Paso a Paso

Los enfoques de bajo nivel: Banderas e interrupciones y tratamiento de los errores en lenguaje C:
### Ejercicio 1:
Implementa un programa en C++ que simule un sistema con banderas de error. Si ocurre un error, en lugar de lanzar una excepción, establece una bandera de error. Luego, comprueba regularmente la bandera de error para manejarla.
Resolución:
```cpp
#include<iostream>

// Variable global que actúa como bandera de error
bool errorFlag = false;

int divide(int a, int b) {
    if (b == 0) {
        // Si ocurre un error, se establece la bandera de error
        errorFlag = true;
        return 0;
    }
    else {
        return a / b;
    }
}

int main() {
    int result = divide(5, 0);

    // Se verifica regularmente la bandera de error
    if (errorFlag) {
        std::cout << "Ocurrió un error: división por cero." << std::endl;
        // Se maneja el error y se reinicia la bandera
        errorFlag = false;
    }

    return 0;
}
```
Este programa intenta dividir 5 por 0, lo que debería causar un error. En lugar de lanzar una excepción, establece una bandera de error, que luego se comprueba en el programa principal.

Las excepciones son más seguras que los errores:
### Ejercicio 2:
Implementa dos versiones de una función que pueda provocar un error (como la división por cero). La primera versión debe manejar el error devolviendo un valor de error, mientras que la segunda versión debe lanzar una excepción en caso de error. Compara la seguridad y facilidad de uso de ambas versiones.
Resolución:
```cpp
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
```
Este programa implementa dos versiones de una función que divide dos números. La primera versión devuelve un valor de error en caso de error (división por cero), mientras que la segunda versión lanza una excepción en caso de error. Luego, se usan ambas versiones de la función en el programa principal, y se manejan los posibles errores.

Propagación explícita:
### Ejercicio 3:
Crea un programa que demuestre cómo se propaga una excepción a través de varias funciones. Asegúrate de que algunas funciones no manejen la excepción, de modo que tenga que propagarse hasta una función que la maneje.
Resolución:
```cpp
#include<iostream>
#include<stdexcept>

void func3() {
    throw std::runtime_error("Error en func3");
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {
    try {
        func1();
    }
    catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada en main: " << e.what() << std::endl;
    }

    return 0;
}
```
Este programa demuestra la propagación de excepciones. Una excepción lanzada en func3 se propaga a través de func2 y func1 hasta main, donde finalmente se captura y se maneja.

Tipos de excepciones personalizadas: Definición de clases de excepción, instanciación de clases y clases de excepción derivadas:
### Ejercicio 4:
Define una clase de excepción personalizada llamada MiExcepcion, que hereda de std::exception. Añade un mensaje de error personalizado a la clase. Luego, en una función, lanza una excepción de este tipo. En el método main, captura y maneja esta excepción.
Resolución:
```cpp
#include<iostream>
#include<exception>
#include<string>

// Definición de la clase de excepción personalizada
class MiExcepcion : public std::exception {
private:
    std::string mensaje;
public:
    explicit MiExcepcion(const std::string& msg) : mensaje(msg) {}
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

void lanzaExcepcion() {
    throw MiExcepcion("Ocurrió un error en la función lanzaExcepcion");
}

int main() {
    try {
        lanzaExcepcion();
    }
    catch (const MiExcepcion& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}
```
En este programa, se define una clase de excepción personalizada MiExcepcion que hereda de std::exception. Esta clase contiene un mensaje de error personalizado que se pasa al constructor. La función lanzaExcepcion lanza una excepción de este tipo, que luego se captura y se maneja en main.

Manejo de una excepción y reactivación:
### Ejercicio 5:
Implementa un programa que lance una excepción, la capture, realice alguna acción para manejarla y luego relance la excepción. Asegúrate de que la excepción relanzada sea capturada y manejada en otro lugar.
Resolución:
```cpp
#include<iostream>
#include<stdexcept>

void lanzaExcepcion() {
    throw std::runtime_error("Error en la función lanzaExcepcion");
}

int main() {
    try {
        try {
            lanzaExcepcion();
        }
        catch (const std::runtime_error& e) {
            std::cout << "Excepción capturada y manejada. Reactivando..." << std::endl;
            throw; // Relanza la excepción
        }
    }
    catch (const std::runtime_error& e) {
        std::cout << "Excepción reactivada capturada: " << e.what() << std::endl;
    }

    return 0;
}
Este programa lanza una excepción que se captura y maneja en un bloque catch interno. Luego, la excepción se relanza y se captura en un bloque catch externo.

Excepciones no interceptadas:
Ejercicio: Escribe un programa que lance una excepción que no sea capturada. Observa qué sucede cuando se ejecuta el programa.
Resolución:
#include<iostream>
#include<stdexcept>

void lanzaExcepcion() {
    throw std::runtime_error("Error en la función lanzaExcepcion");
}

int main() {
    lanzaExcepcion();

    return 0;
}
```
Cuando ejecutes este programa, deberías ver que se lanza una excepción que no es capturada, lo que causa que el programa termine abruptamente. El mensaje de la excepción debería imprimirse en la consola.

Adquisición de recursos:
### Ejercicio 6:
Implementa un programa que abra un archivo de texto para escritura (usando std::ofstream). Luego, en un bloque try/catch, intenta escribir en el archivo. Si ocurre un error (puedes simularlo cerrando el archivo antes de intentar escribir en él), lanza y maneja una excepción. Asegúrate de cerrar el archivo correctamente en todos los casos.
Resolución:
```cpp
#include<iostream>
#include<stdexcept>
#include<fstream>

void escribeEnArchivo(std::ofstream& file) {
    if (!file.is_open()) {
        throw std::runtime_error("No se puede escribir en un archivo cerrado");
    }
    file << "Hola, mundo!";
}

int main() {
    std::ofstream file("archivo.txt");
    
    try {
        file.close(); // Cierra el archivo para simular un error
        escribeEnArchivo(file);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Excepción capturada: " << e.what() << std::endl;
    }

    // Asegurarse de que el archivo esté cerrado
    if (file.is_open()) {
        file.close();
    }

    return 0;
}
```
Este programa intenta escribir en un archivo de texto. Si el archivo no está abierto, lanza una excepción. La excepción se captura y se maneja en main. Independientemente de si ocurre una excepción, el programa se asegura de que el archivo esté cerrado antes de terminar.
