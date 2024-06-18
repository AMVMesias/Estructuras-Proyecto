#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
#include "Recibo.h"
#include "Estudiante.h"
#include "Lista.h"


class Historial {
private:
    Lista<Recibo> listaRecibos;

public:
	
	Historial(){}
	
	
    void agregarRecibo(const Recibo& recibo) {
        listaRecibos.insertarAlFinal(recibo);
    }

    void mostrarHistorial() const {
        Nodo<Recibo>* actual = listaRecibos.getCabeza(); 
        while (actual) {
            actual->dato.mostrarRecibo();
            actual = actual->siguiente;
        }
        cout << endl;
    }

};


#endif // HISTORIAL_H