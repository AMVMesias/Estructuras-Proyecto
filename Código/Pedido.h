// Pedido.h

#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Producto.h"
#include "Lista.h"
#include "Estudiante.h"

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

    void setCliente(const Estudiante& cliente){
        this->cliente=cliente;
    }
    void agregarProducto(const Producto& producto) {
        productos.insertarComida(producto);
        precio += producto.getPrecio();
    }

    double calcularTotal() const {
        return precio;
    }

    void mostrarPedido() const{
        float pago;
        string orden=productos.imprimirListaComida(pago);
        cout<<orden;
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

    int generarId(){
        return rand()%5999+399;
    }

    string generarComprobante(){
        string comprobante;
        comprobante+="Comprobante de pago.";
        comprobante+="Orden #: "+to_string(id);
        comprobante+="Cliente: "+cliente.getNombre();
        comprobante+="Productos adquiridos: ";
        Nodo<Producto>* actual=productos.getCabeza();
        while(actual){
            comprobante+=actual->dato.getDescripcion()+"........$ "+to_string(actual->dato.getPrecio());
            actual=actual->siguiente;
        }
        comprobante+="Total: "+to_string(calcularTotal());
        comprobante+="Estado: "+estado;
        return comprobante;
    }
private:
    void recalcularPrecio() {
        precio = 0.0;
    }

};

#endif // PEDIDO_H
