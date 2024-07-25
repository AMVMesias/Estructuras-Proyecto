#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
    Nodo(const T& valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    void insertarAlFinal(const T& valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }
    
	void insertarOrdenado(const T& valor) {
	        Nodo<T>* nuevo = new Nodo<T>(valor);
	        if (!cabeza || !(valor < cabeza->dato)) {
	            nuevo->siguiente = cabeza;
	            cabeza = nuevo;
	        } else {
	            Nodo<T>* actual = cabeza;
	            while (actual->siguiente && (valor < actual->siguiente->dato)) {
	                actual = actual->siguiente;
	            }
	            nuevo->siguiente = actual->siguiente;
	            actual->siguiente = nuevo;
	        }
	    }

    bool buscar(const T& valor) const {
        Nodo<T>* tmp = cabeza;
        while (tmp) {
            if (tmp->dato == valor) {
                std::cout << "Encontrado: " << valor << std::endl;
                return true;
            }
            tmp = tmp->siguiente;
        }
        std::cout << "No encontrado: " << valor << std::endl;
        return false;
    }

    void imprimirLista() const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    bool esVacia() const {
        return cabeza == nullptr;
    }

    // Método adicional para obtener la cabeza de la lista
    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    ~Lista() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
    }
};

#endif // LISTA_H
