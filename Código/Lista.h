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
    Lista() : cabeza(nullptr) {}
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
            actual = actual->siguiente;
        }
        cout << endl;
    }

    void imprimirListaComida() const {
        Nodo<T>* actual = cabeza;
        float pago=0;
        while (actual) {
            float precioProducto=actual->dato.getPrecio();
            int cantidad=actual->contador;
            float precio=precioProducto*cantidad;
            cout << "Producto: " << actual->dato.getDescripcion() << endl;
            cout << "Precio unitario:                           $" << actual->dato.getPrecio() << endl;
            cout << "Cantidad: " << actual->contador << endl;
            pago+=precio;
            actual = actual->siguiente;
        }
        cout<<"Precio total de la orden:                  $"<<pago<<endl;
        cout << endl;
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
};

#endif // LISTA_H
