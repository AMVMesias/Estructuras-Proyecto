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
    int tamano;  // Variable para llevar el conteo de elementos

public:
    Lista() : cabeza(nullptr), tamano(0) {}

    // Inserta un nuevo elemento al final de la lista
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
        tamano++;
    }

    // Inserta un nuevo elemento en la lista en orden
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
        tamano++;
    }

    // Busca un elemento en la lista
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

    // Imprime todos los elementos de la lista
    void imprimirLista() const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Verifica si la lista está vacía
    bool estaVacia() const {
        return cabeza == nullptr;
    }

    // Limpia todos los elementos de la lista
    void clear() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        tamano = 0;
    }

    // Devuelve el tamaño de la lista
    int size() const {
        return tamano;
    }

    // Acceso por índice
    T& operator[](int index) {
        if (index < 0 || index >= tamano) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Nodo<T>* actual = cabeza;
        for (int i = 0; i < index; ++i) {
            actual = actual->siguiente;
        }
        return actual->dato;
    }

    // Método adicional para obtener la cabeza de la lista
    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    // Destructor para liberar memoria
    ~Lista() {
        clear();
    }

};

#endif // LISTA_H
