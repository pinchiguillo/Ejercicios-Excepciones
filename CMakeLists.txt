cmake_minimum_required(VERSION 3.29)
project(Ejercicios_Excepciones)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ejercicios_Excepciones main.cpp
        Ejercicio1/flags.cpp
        Ejercicio1/flags.h
        Ejercicio2/e2.cpp
        Ejercicio2/e2.h
        Ejercicio3/e3.h
        Ejercicio3/e3.cpp
        Ejercicio4/MiExcepcion.h
        Ejercicio4/MiExcepcion.cpp
        Ejercicio7/e7.cpp
        Ejercicio7/e7.h
)

add_executable(Ejercicio5 Ejercicio5/main5.cpp)
add_executable(Ejercicio6 Ejercicio6/main6.cpp)
