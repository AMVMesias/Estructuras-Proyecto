#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Estudiante.h"
#include "Producto.h"
#include <string>

using namespace std;

template<typename T>
struct Nodo {
    int contador;
    T dato;
    Nodo* siguiente;
    Nodo* anterior;
};

template <typename T>
class Lista {
public:
    Nodo<T>* cabeza;

public:
    Lista() : cabeza(nullptr)  {}
    Nodo<T>* getCabeza() const {
        return cabeza;
    }
    void insertarAlFinal(T valor) {
        Nodo<T>* nuevo = new Nodo<T>;
        nuevo->dato = valor;
        nuevo->siguiente = nullptr;
        nuevo->anterior = nullptr;
        nuevo->contador = 1;

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
    void insertarComida(T valor){
        Nodo<T>* actual = cabeza;
        bool repetido = false;
        while(actual != nullptr){
            if(actual->dato == valor){
                actual->contador++;
                repetido = true;
                break;
            }
            actual = actual->siguiente;
        }
        if(!repetido) {
            Nodo<T>* nuevo = new Nodo<T>;
            nuevo->dato = valor;
            nuevo->siguiente = nullptr;
            nuevo->anterior = nullptr;
            nuevo->contador = 1;

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
    }
    void imprimirLista()const{
        Nodo<T>* actual = cabeza;
        while (actual) {
            actual->dato.mostrarDatos();
            //cout<<actual->dato<<endl;
            actual = actual->siguiente;
        }
        cout << endl;
    }

    string imprimirListaComida(float& pago) const {
        Nodo<T>* actual = cabeza;
        string total;
        pago=0;
        while (actual) {
            float precioProducto=actual->dato.getPrecio();
            int cantidad=actual->contador;
            float precio=precioProducto*cantidad;
            cout << "Producto: "+actual->dato.getDescripcion()<<endl;
            cout << "Precio:                           $"+to_string(precioProducto*cantidad)<<endl;
            cout << "Cantidad: "+to_string(cantidad)<<endl;
            pago+=precio;
            actual = actual->siguiente;
        }
        total+="Precio total de la orden:                  $"+to_string(pago);
        return total;
    }
    void imprimirMenu(){
        Nodo<T>* actual=cabeza;
        int cont=1;
        while(actual){
            cout<<cont<<". "<<actual->dato.getDescripcion()<<"........$ "<<actual->dato.getPrecio()<<endl;
            actual=actual->siguiente;
            cont++;
        }
    }
   bool eliminar(T& valor){
        Nodo<T>* actual=cabeza;
        Nodo<T>* anterior=NULL;
        while(actual != NULL && actual -> dato != valor){
            anterior = actual;
            actual = actual->siguiente;
        }
        if(actual==NULL){
            cout<<"El producto ingresado no existe en la carta."<<endl;
            return false;
        }
        if(actual->contador > 1){
                actual->contador--;
        }else {
            Nodo<T>* siguiente = actual->siguiente;
            if (anterior != nullptr) {
                anterior->siguiente = siguiente;
            } else {
                cabeza = siguiente;
            }
            if (siguiente != nullptr) {
                siguiente->anterior = anterior;
            }
            delete actual;
            cout << "Se ha eliminado " << valor.getDescripcion() << endl;
        }
        return true;
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

    //METODOS PARA LISTA ESTUDIANTES- USUARIOS
    void obtenerUserBuscado(Estudiante &aux,int ced){
        Nodo<Estudiante>* tmp = cabeza;
        while (tmp) {
            if (tmp->dato.getUsuario() == ced) {
                aux=tmp->dato;
            }
            tmp = tmp->siguiente;
        }
    }

    ~Lista(){
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
