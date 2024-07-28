#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include <iostream>
#include <stdexcept>
#include "Lista.h" 
#include "Estudiante.h"

using namespace std;

template<typename K, typename V>
class TablaHash {
private:
    struct Entrada {
        K clave;
        V valor;
        bool operator>(const Entrada& other) const {
            return clave > other.clave;
        }
        
        bool operator<(const Entrada& other) const {
	        return clave < other.clave;
	    }
	    
        Entrada(const K& k, const V& v) : clave(k), valor(v) {}
    };

    Lista<Entrada>* tabla;
    int capacidad;

    int funcionHash(const K& clave) const {
        return static_cast<int>(clave) % capacidad;
    }

public:
    TablaHash(int initial_capacity = 10) : capacidad(initial_capacity) {
        tabla = new Lista<Entrada>[capacidad];
    }

    void insertar(const K& clave, const V& valor) {
        int indice = funcionHash(clave);
        Entrada nuevaEntrada(clave, valor);
        tabla[indice].insertarOrdenado(nuevaEntrada); 
    }

    void buscar(const K& clave) const {
        int indice = funcionHash(clave);
        Nodo<Entrada>* tmp = tabla[indice].getCabeza();
        while (tmp) {
            if (tmp->dato.clave == clave) {
                tmp->dato.valor.mostrarInformacion(); 
                return;
            }
            tmp = tmp->siguiente;
        }
        throw runtime_error("Clave no encontrada en la tabla hash.");
    }

    void imprimirTabla() const {
        for (int i = 0; i < capacidad; ++i) {
            cout << "Lista " << i << ": ";
            Nodo<Entrada>* actual = tabla[i].getCabeza();
            while (actual) {
                cout << "{" << actual->dato.clave << ": " << actual->dato.valor.getNombre() << "} ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
    }

    bool esVacia(int indice) const {
        return tabla[indice].esVacia();
    }

    ~TablaHash() {
        delete[] tabla;
    }
};

#endif 