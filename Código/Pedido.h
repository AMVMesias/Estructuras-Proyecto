#pragma once
#include <string>
#include "Producto.h"
#include "lista.h"

class Pedido {
private:
    int id;
    Lista<Producto> productos;
    double precio;
    std::string estado;

public:
    Pedido();

    void agregarProducto(const Producto& producto);
    void eliminarProducto(const std::string& nombre);
    double calcularTotal() const;
    void mostrarPedido() const;
    void pagar();
    void setEstado(const std::string& nuevo_estado);
    std::string getEstado() const;

private:
    void recalcularPrecio();
};

