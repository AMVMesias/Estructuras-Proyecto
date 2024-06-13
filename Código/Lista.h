#include<iostream>

using namespace std;

template<typename T>
struct Nodo{
	public:
		T dato;
		Nodo* siguiente;
		Nodo* anterior;		
};
template <typename T>
class Lista
{
private:
    Nodo<T>* cabeza;

public:
    Lista(){};
    //Funciones Básicas
    void insertarAlFinal(T){};
    void imprimirLista(){};
    void borrar(T){};
    bool buscar(T){};
    bool esVacia(){};
    //metodos para Lista Pedidos

    //metodos para Lista Productos
    //agregar, borrar, modificar pero solo para el admin
    void modificarListaProductos(){}


    //metodos para Lista Estudiantes
    void cargarEstudiantes(){};
        //todas las validaciones de un login y de un crear cuenta
};
