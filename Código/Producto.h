#ifndef PRODUCTO_H
#define PRODUCTO_H


#include <string>
#include <iostream>

using namespace std;

class Producto {
private:
    string descripcion;
    float precio;
    int cantidad;
    int id;


public:
    Producto(string _descripcion = " ", float _precio = 0, int _cantidad = 0, int _id=0)
        : descripcion(_descripcion), precio(_precio), cantidad(_cantidad), id(_id){}

    void setDescripcion(string _descripcion) {
        descripcion = _descripcion;
    }

    void setPrecio(float _precio) {
        precio = _precio;
    }

    void setCantidad(int _cantidad) {
        cantidad = _cantidad;
    }

    void setId(int _id){
        id = _id;
    }

    string getDescripcion() const {
        return descripcion;
    }

    float getPrecio() const {
        return precio;
    }

    int getCantidad() const {
        return cantidad;
    }

    int getId() const {
        return id;
    }
    void mostrarDatos() const {
        cout << "Id del producto: " << id << endl;
        cout << "Descripcion del producto: " << descripcion << endl;
        cout << "Precio del producto (unidad) $" << precio << "." << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};
#endif