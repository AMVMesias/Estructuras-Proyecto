#ifndef BUSQUEDABINARIA_H
#define BUSQUEDABINARIA_H

#include <iostream>
#include "Lista.h"
#include "Estudiante.h"

void busquedaBinaria(Lista<Estudiante>& lista, float promedio) {
    int primero = 0;
    int ultimo = lista.size() - 1;
    int medio;

    while (primero <= ultimo) {
        medio = (primero + ultimo) / 2;
        Estudiante estudiante = lista[medio];
        
        if (estudiante.get_Promedio() < promedio) {
            primero = medio + 1;
        } else if (estudiante.get_Promedio() == promedio) {
            std::cout << "Estudiante encontrado:" << std::endl;
            estudiante.mostrarInformacion();
            return;
        } else {
            ultimo = medio - 1;
        }
    }
    std::cout << "No se encontró un estudiante con el promedio: " << promedio << std::endl;
}

#endif 