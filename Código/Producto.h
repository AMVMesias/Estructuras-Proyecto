#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include <iostream>

using namespace std;

class Producto {
private:
    string descripcion;
    float precio;
    int id;


public:
    Producto(string _descripcion = " ", float _precio = 0, int _id=0)
        : descripcion(_descripcion), precio(_precio), id(_id){}

    void setDescripcion(string _descripcion) {
        descripcion = _descripcion;
    }

    void setPrecio(float _precio) {
        precio = _precio;
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


    int getId() const {
        return id;
    }
    bool operator==(const Producto& otro) const {
        return this->id == otro.id;  // Comparaci�n por id
    }
    void mostrarDatos() const {
        cout << "Descripcion: " << descripcion << endl;
        cout << "Precio del producto (unidad) $" << precio << "." << endl;
    }
};
#endif
