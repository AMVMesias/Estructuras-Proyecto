#include <iostream>
#include "Pedido.h"
#include "Lista.h"
#include  "Menu.h"
#include "Estudiante.h"
using namespace std;

int main(){

	/*Producto p1("pan", 1.5, 2);
	Producto p2(" Salchipapa", 1.5, 1);
	Producto p3(" Manzana", 1, 3);
	Pedido v1;
	v1.agregarProducto(p1);
	v1.agregarProducto(p2);
	v1.agregarProducto(p3);
	
	v1.mostrarPedido();
	cout<<endl;
	v1.pagar();
	v1.mostrarPedido();*/
/*	Menu m;
	int a=0;
	a=m.obtenerIS_CC();
	cout<<a<<endl;*/

	Estudiante p("Denise",0,"chimuelo");
	//Estudiante p1;
	if(p.CrearCuenta(p)){
		cout<<"Funca"<<endl;
	}else{
		cout<<"Negao"<<endl;
	}
	
	
	
	/*Lista<int> producto1, producto2;
	producto1.insertarAlFinal(5);
	producto1.insertarAlFinal(6);
	producto1.imprimirLista();
	producto2.insertarAlFinal(4);
	producto2.imprimirLista();
	
	producto1.borrar(6);
	
	producto1.imprimirLista();
	producto2.imprimirLista();
	
	if(producto1.buscar(5)){
		cout<<" Se encontro el valor";
		
	}*/

	return 0;
}