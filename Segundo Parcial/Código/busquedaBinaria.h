#ifndef BUSQUEDABINARIA_H
#define BUSQUEDABINARIA_H

#include <iostream>
#include "Lista.h"
#include "Estudiante.h"
//#include "ManejoArchivos.cpp"

void ordenarPorBurbuja(Lista<Estudiante>& lista) {
    int n = lista.size();
    bool swapped;
    

    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (lista[i - 1].get_Promedio() > lista[i].get_Promedio()) {
                Estudiante temp = lista[i - 1];
                lista[i - 1] = lista[i];
                lista[i] = temp;
                swapped = true;
            }
        }
        n--; 
    } while (swapped);
}

void busquedaBinaria(Lista<Estudiante>& lista, float promedio,Estudiante &encontrado) {
    ordenarPorBurbuja(lista); 
	//ManejoArchivos manejo;
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
            encontrado=estudiante;
            estudiante.mostrarInformacion();
            return;
        } else {
            ultimo = medio - 1;
        }
    }
    std::cout << "No se encontró un estudiante con el promedio: " << promedio << std::endl;
}

#endif