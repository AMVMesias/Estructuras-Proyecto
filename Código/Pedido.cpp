#include "Pedido.h"
#include <iostream>
#include <cstdlib>  


Pedido::Pedido() : precio(0.0), estado("Pendiente") {
    srand(time(0));
    id = rand();
}

void Pedido::agregarProducto(const Producto& producto) {
    productos.agregar(producto);
    precio += producto.cantidad * producto.precio_unitario;
}

void Pedido::eliminarProducto(const std::string& nombre) {
    Producto temp(nombre, 0, 0.0); // Producto temporal para buscar por nombre
    productos.eliminar(temp);

    recalcularPrecio();
}

double Pedido::calcularTotal() const {
    return precio;
}

void Pedido::mostrarPedido() const {
    std::cout << "Pedido ID: " << id << "\n";
    std::cout << "Estado: " << estado << "\n";
    std::cout << "Productos:\n";
    auto elementos = productos.obtenerElementos();
    for (const auto& producto : elementos) {
        std::cout << " - " << producto.nombre << ": " << producto.cantidad 
                  << " unidades a $" << producto.precio_unitario << " c/u\n";
    }
    std::cout << "Total: $" << calcularTotal() << "\n";
}

void Pedido::pagar() {
    estado = "Pagado";
}

void Pedido::setEstado(const std::string& nuevo_estado) {
    estado = nuevo_estado;
}

std::string Pedido::getEstado() const {
    return estado;
}

void Pedido::recalcularPrecio() {
    precio = 0.0;
    auto elementos = productos.obtenerElementos();
    for (const auto& producto : elementos) {
        precio += producto.cantidad * producto.precio_unitario;
    }
}
