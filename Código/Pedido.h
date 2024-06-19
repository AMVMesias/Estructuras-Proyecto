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
#include <sstream>
#include <iomanip>
#include <string>

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
    void eliminarProducto(Producto& producto) {
    	system("cls");
        if (productos.eliminar(producto)) {
            precio -= producto.getPrecio();
            cout << "Se ha eliminado " << producto.getDescripcion() << endl;
        }
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

    int generarId() const {
        return rand()%5999+399;
    }

    /*tring generarComprobante()const {
    	system("cls");
        string comprobante;
        comprobante+="Comprobante de pago.\n";
        comprobante+= "\nCI: " + to_string(cliente.getUsuario());
        comprobante+="\nCliente: "+cliente.getNombre();
        comprobante+="\nProductos adquiridos: ";
        Nodo<Producto>* actual=productos.getCabeza();
        while(actual){
            comprobante+=actual->dato.getDescripcion()+"........$ "+to_string(actual->dato.getPrecio()*actual->contador)+"\n";
            actual=actual->siguiente;
        }
        comprobante+="Total: "+to_string(calcularTotal())+"\n";
        comprobante+="Estado: "+estado+"\n";
        return comprobante;
    }*/
    
    string generarComprobante() const {
    system("cls");
    string comprobante;
    comprobante += "Comprobante de pago.\n";
    comprobante += "\nCI: " + to_string(cliente.getUsuario());
    comprobante += "\nCliente: " + cliente.getNombre();
    comprobante += "\nProductos adquiridos: ";
    
    Nodo<Producto>* actual = productos.getCabeza();
    while (actual) {
        ostringstream precioStream;
        precioStream << fixed << setprecision(2) << (actual->dato.getPrecio() * actual->contador);
        comprobante += actual->dato.getDescripcion() + "........$ " + precioStream.str() + "\n";
        actual = actual->siguiente;
    }
    
    std::ostringstream totalStream;
    totalStream << std::fixed << std::setprecision(2) << calcularTotal();
    comprobante += "Total: " + totalStream.str() + "\n";
    comprobante += "Estado: " + estado + "\n";
    return comprobante;
}


private:
    void recalcularPrecio() {
        precio = 0.0;
    }

};

#endif // PEDIDO_H
