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
        productos.insertarAlFinal(producto);
        precio += producto.getPrecio();
    }

    double calcularTotal() const {
        return precio;
    }

    void mostrarPedido() const{
        cout << "Contenido:" << endl;
        productos.imprimirLista();
        cout << "Total del pedido: $" << calcularTotal() << endl << endl;
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

    void generarComprobante(){
        cout<<"Comprobante de pago."<<endl;
        cout<<"Orden #: "<<id<<endl;
        cout<<"Cliente: "<<cliente.getNombre()<<endl;
        cout<<"Productos adquiridos: "<<endl;
        productos.imprimirListaComida();
        cout<<"Total: "<<calcularTotal()<<endl;
        cout<<"Estado: "<<estado<<endl;

    }
private:
    void recalcularPrecio() {
        precio = 0.0;
    }

};

#endif // PEDIDO_H
