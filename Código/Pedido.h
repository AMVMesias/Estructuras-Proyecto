#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Lista.h"
#include "Estudiante.h"
#include "Producto.h"

using namespace std;

class Pedido {
private:
    int id;
    Lista<Producto> productos;
    double precio;
    string estado;
    Estudiante cliente;

public:
    Pedido() : id(generarId()), precio(0.0), estado("pendiente") {}

    void setCliente(const Estudiante& cliente) {
        this->cliente = cliente;
    }

    void agregarProducto(const Producto& producto) {
        productos.insertarComida(producto);
        precio += producto.getPrecio();
    }

    void eliminarProducto(Producto& producto) {
        if (productos.eliminar(producto)) {
            precio -= producto.getPrecio();
            cout << "Se ha eliminado " << producto.getDescripcion() << endl;
        }
    }

    double calcularTotal() const {
        return precio;
    }

    void mostrarPedido() const {
        float pago;
        string orden = productos.imprimirListaComida(pago);
        cout << orden;
    }

    void pagar() {
        estado = "pagado";
        cout << "El pedido ha sido pagado.\n" << endl;
    }

    void setEstado(const string& nuevo_estado) {
        estado = nuevo_estado;
    }

    string getEstado() const {
        return estado;
    }

    int generarId() const {
        return rand() % 5999 + 399;
    }
    const Estudiante& getCliente() const {
        return cliente;
    }
    const Lista<Producto>& getProductos() const {
        return productos;
    }
    
    string generarComprobante() const {
        stringstream comprobante;
        comprobante << "Comprobante de pago.\n";
        comprobante << "\nCI: " << cliente.getUsuario();
        comprobante << "\nCliente: " << cliente.getNombre();
        comprobante << "\nProductos adquiridos: ";

        Nodo<Producto>* actual = productos.getCabeza();
        while (actual) {
            stringstream precioStream;
            precioStream << fixed << setprecision(2) << (actual->dato.getPrecio() * actual->contador);
            comprobante << actual->dato.getDescripcion() << "........$ " << precioStream.str() << "\n";
            actual = actual->siguiente;
        }

        comprobante << "Total: " << fixed << setprecision(2) << calcularTotal() << "\n";
        comprobante << "Estado: " << estado << "\n";
        
        return comprobante.str();
    }

    friend void guardarPedido(const Pedido& pedido);
};

#endif 
