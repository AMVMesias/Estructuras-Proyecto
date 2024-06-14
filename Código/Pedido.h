// Pedido.h

#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <iostream>
#include "Producto.h"
#include "Lista.h"

using namespace std;

class Pedido {
private:
    int id;
    Lista<Producto> productos;
    double precio;
    string estado;

public:
    Pedido() : id(0), precio(0.0), estado("pendiente") {}

    void agregarProducto(const Producto& producto) {
        productos.insertarAlFinal(producto);
        precio += producto.getCantidad() * producto.getPrecio();
    }
	
    double calcularTotal() const {
        return precio;
    }
    
    void mostrarPedido() const {
        cout << "ID del pedido: " << id << endl;
        cout << "Estado del pedido: " << estado << endl;
        cout << "Productos en el pedido:" << endl;
        //productos.imprimirLista(); // Utilizando el método imprimirLista() de la clase Lista
        cout << "Total del pedido: $" << calcularTotal() << endl;
    }
    
    void pagar() {
        estado = "pagado";
        cout << "El pedido ha sido pagado." << endl;
    }

    void setEstado(const string& nuevo_estado) {
        estado = nuevo_estado;
    }

    string getEstado() const {
        return estado;
    }

private:
    void recalcularPrecio() {
        precio = 0.0;
    }
};

#endif // PEDIDO_H
