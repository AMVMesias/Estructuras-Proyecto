#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
#include "Pedido.h"
#include "Lista.h"

class Historial {
private:
    Lista<Pedido> listaPedidos;

public:
    Historial() {}

    void agregarPedido(const Pedido& pedido) {
        listaPedidos.insertarAlFinal(pedido);
    }

    void mostrarHistorial() const {
        Nodo<Pedido>* actual = listaPedidos.getCabeza(); 
        while (actual) {
            actual->dato.mostrarPedido();
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

#endif // HISTORIAL_H