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

template <typename T>
void Lista<T>::borrar(T valor) {
    Nodo<T>* actual = cabeza;

    while (actual != NULL) {
        Nodo<T>* siguiente = actual->siguiente;

        if (actual->dato == valor) {
            Nodo<T>* anterior = actual->anterior;

            if (anterior != NULL) {
                anterior->siguiente = siguiente;
            }
            if (siguiente != NULL) {
                siguiente->anterior = anterior;
            }

            if (actual == cabeza) {
                cabeza = siguiente;
            }

            delete actual;

            actual = siguiente;
        } else {
            actual = siguiente;
        }
    }
}


template<typename T>
bool Lista<T>::buscar(T){
    
    T valor_b;
	bool ext =false;
	if(this->esVacia()){
		cout<<"La lista esta vacia, no se puede buscar"<<endl;
	}
	else{
	valor_b = this->ingresoDatosEnteros();
	Nodo* num = new Nodo(valor_b);
	Nodo* tmp = primero;	
    while (tmp->getSiguiente()){
		if (tmp->getValor() == num->getValor()){
            //cout << "El numero esta en la posicion: "<<count+1<<endl;
			ext  = true;
            break;
        }
		tmp = tmp->getSiguiente();
		//count++;
	}
	if (ext == false){
		cout<<"El numero no esta en la lista: "<<endl;
	}
}
return ext;
}

template<typename T>
bool Lista<T>::esVacia(){
    return cabeza==NULL;
}
