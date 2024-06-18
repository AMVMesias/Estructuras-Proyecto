#ifndef RECIBO_H
#define RECIBO_H

#include <iostream>
#include "Estudiante.h"
#include "Pedido.h"
#include "Historial.h"
#include "Lista.h"

class Recibo {
private:
    int idPedido;
    double totalPagado;
    Estudiante estudiante;
    Pedido pedido;

public:
    Recibo() : idPedido(0), totalPagado(0.0), estudiante(Estudiante()), pedido(Pedido()) {} 
    Recibo(int idPedido, double totalPagado, const Estudiante& estudiante, const Pedido& pedido)
        : idPedido(idPedido), totalPagado(totalPagado), estudiante(estudiante), pedido(pedido) {}

    void mostrarRecibo() const {
        std::cout << "Recibo del Pedido #" << idPedido << std::endl;
        std::cout << "Total pagado: $" << totalPagado << std::endl;
        std::cout << "Estudiante: " << estudiante.getNombre() << std::endl;
        pedido.mostrarPedido();
    }
};
#endif // RECIBO_H


