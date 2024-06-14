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

    void imprimirLista() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

	/*void borrar(T valor) {
        Nodo<T>* actual = cabeza;

        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;

            if (actual->dato == valor) {
                Nodo<T>* anterior = actual->anterior;

                if (anterior != nullptr) {
                    anterior->siguiente = siguiente;
                }
                if (siguiente != nullptr) {
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
    }*/

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
