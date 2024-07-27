#include <iostream>
#include "Lista.h"
#include "Estudiante.h"
#include "busquedaBinaria.h"
//#include "ManejoArchivos.cpp"

int main() {
    float notas[] = {12.4, 12.8, 15};
    float notas1[] = {12.4, 14.8, 15};
    float notas2[] = {13.4, 12.8, 19};

    // ManejoArchivos manejo; // Descomentar si ManejoArchivos.cpp está disponible
    Estudiante estudiante1("Denise", "Rea", notas, 3, "dnrea@espe.edu.ec", 14.5);
    Estudiante estudiante2("7dfghj", "ghj", notas2, 3, "fgh@espe.edu.ec", 17.5);
    Estudiante estudiante3("cvbn", "74411", notas2, 3, "dnrea@vbn.edu.ec", 19.5);
    // Profesor profe("Chimuelo", "1478541", "DCCO"); // Descomentar si Profesor está disponible

    Lista<Estudiante> lista;
    lista.insertarAlFinal(estudiante1);
    lista.insertarAlFinal(estudiante2);
    lista.insertarAlFinal(estudiante3);

    float promedioBuscado = 17.5;
    busquedaBinaria(lista, promedioBuscado);

    return 0;
}
