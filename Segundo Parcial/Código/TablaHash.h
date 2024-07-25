#ifndef TABLA_HASH_H
#define TABLA_HASH_H

#include "Lista.h" 

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

    V buscar(const K& clave) const {
        int indice = funcionHash(clave);
        Nodo<Entrada>* tmp = tabla[indice].getCabeza();
        while (tmp) {
            if (tmp->dato.clave == clave) {
                return tmp->dato.valor; 
            }
            tmp = tmp->siguiente;
        }
        throw std::runtime_error("Clave no encontrada en la tabla hash.");
    }

    void imprimirTabla() const {
        for (int i = 0; i < capacidad; ++i) {
            std::cout << "Lista " << i << ": ";
            Nodo<Entrada>* actual = tabla[i].getCabeza();
            while (actual) {
                std::cout << "{" << actual->dato.clave << ": " << actual->dato.valor << "} ";
                actual = actual->siguiente;
            }
            std::cout << std::endl;
        }
    }

    bool esVacia(int indice) const {
        return tabla[indice].esVacia();
    }

    ~TablaHash() {
        delete[] tabla;
    }
};

#endif // TABLA_HASH_H
