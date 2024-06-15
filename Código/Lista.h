#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo* anterior;
};

template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    void insertarAlFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;

        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
            nuevo->anterior = actual;
        }
    }

    void imprimirLista()const{
        Nodo<T>* actual = cabeza;
        while (actual) {
            actual->dato.mostrarDatos();
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void imprimirListaComida() const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout<<actual->dato<<" \n";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void eliminar(T& valor){
    Nodo<T>* actual=cabeza;
    Nodo<T>* anterior=NULL;
    while(actual != NULL && actual -> dato != valor){
        anterior = actual;
        actual = actual->siguiente;
    }
    if(actual != NULL){
        Nodo<T>* siguiente = actual->siguiente;
        if (anterior != NULL){
            anterior->siguiente = siguiente;
        }else{
            cabeza = siguiente;
        }
        if (siguiente != NULL){
            siguiente->anterior = anterior;
        }
        delete actual;
    }
}

    bool buscar(T valor) {
        if (esVacia()) {
            cout << "La lista está vacía, no se puede buscar" << endl;
            return false;
        }

        Nodo<T>* tmp = cabeza;
        while (tmp) {
            if (tmp->dato == valor) {
                return true;
            }
            tmp = tmp->siguiente;
        }

        cout << "El número no está en la lista" << endl;
        return false;
    }

    bool esVacia() {
        return cabeza == nullptr;
    }

    // Métodos adicionales según necesidad
    // Ejemplo: Obtener elementos de la lista

};

#endif // LISTA_H
