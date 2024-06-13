#include "Lista.h"


using namespace std;

template<typename T>
void Lista<T>:: insertarAlFinal(T valor){
	Nodo<T>* nuevoNodo = new Nodo<T>(valor);
	if (cabeza == NULL) {
		cabeza = nuevoNodo;
		} else {
			Nodo<T>* actual = cabeza;
			while (actual->siguiente != NULL) { actual = actual->siguiente;
			}
			actual->siguiente = nuevoNodo;
			nuevoNodo->anterior = actual;
}  
}

template<typename T>
void Lista<T>::imprimirLista(){
	Nodo<T>* actual = cabeza;
	while (actual != NULL) {
		cout << actual->dato << " ";
		actual= actual->siguiente;
}
	cout<<endl;
}

template<typename T>
void Lista<T>::borrar(T valor){
    //codigo
    //To do
}

template<typename T>
bool Lista<T>::buscar(T){
    //codigo
    //To do
}

template<typename T>
bool Lista<T>::esVacia(){
    //codigo
    //To do
}
