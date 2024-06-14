#include <string>
#include <iostream>

using namespace std;

class Producto {
private:
    string descripcion;
    float precio;
    int cantidad;

public:
    Producto(string _descripcion = " ", float _precio = 0, int _cantidad = 0)
        : descripcion(_descripcion), precio(_precio), cantidad(_cantidad) {}

    void setDescripcion(string _descripcion) {
        descripcion = _descripcion;
    }

    void setPrecio(float _precio) {
        precio = _precio;
    }

    void setCantidad(int _cantidad) {
        cantidad = _cantidad;
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

    void mostrarDatos() const {
        cout << "Descripcion del producto: " << descripcion << endl;
        cout << "Precio del producto (unidad) $" << precio << "." << endl;
        cout << "Cantidad: " << cantidad << endl;
    }
};
