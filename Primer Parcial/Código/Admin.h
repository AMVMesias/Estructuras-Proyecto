#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "Producto.h"
#include "Pedido.h"
#include "ManejoJson.h"

using namespace std;

class Admin {
private:
    int id;
    string nombre;
    string contrasena;

public:
    Admin(int _id, string _nombre, string _contrasena)
        : id(_id), nombre(_nombre), contrasena(_contrasena) {}

    int getId() const {
        return id;
    }

    string getNombre() const {
        return nombre;
    }

    string getContrasena() const {
        return contrasena;
    }

    bool iniciarSesion(int _id, string _contrasena) {
        return id == _id && contrasena == _contrasena;
    }

    void agregarProducto(Lista<Producto>& listaProductos, int prodId, const string& descripcion, float precio, int cantidad) {
        if (productoExiste(prodId)) {
            cout << "Error: El producto con ID '" << prodId << "' ya existe." << endl;
            return;
        }

        Producto nuevoProducto(descripcion, precio, prodId);
        listaProductos.insertarAlFinal(nuevoProducto);
        crearNuevoProducto(prodId, descripcion, precio, cantidad);
        cout << "Producto agregado exitosamente: " << descripcion << endl;
    }

    void verProductos(const Lista<Producto>& listaProductos) const {
        listaProductos.imprimirLista();
    }

    void verHistorial(const Lista<Pedido>& listaPedidos) const {
        Nodo<Pedido>* actual = listaPedidos.getCabeza();
        while (actual) {
            actual->dato.mostrarPedido();
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

#endif // ADMIN_H