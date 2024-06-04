#include <iostream>
#include <cstring>
#include <ctype.h>
#define NODO struct nodo
using namespace std;

NODO{
    char dato;
    NODO *antes, *despues;
};
NODO *inicio = NULL;
NODO *final = NULL;

void insertar(char dato){
    NODO *nuevo = new NODO;
    if(nuevo){
        nuevo->dato=dato;
        nuevo->despues=NULL;
        if(inicio){
        nuevo->antes=final;
        final->despues=nuevo;
        }else{
            inicio=nuevo;
            nuevo->antes=NULL;
        }
        final=nuevo;
    }else{
        cout<<"No se pudo conseguir mas memoria para otro Nodo.";
        exit(1);
    }

}
void agregar(void){
    char letra;
    cout<<"Ingresa un dato: ";
    letra=getchar();
    insertar(letra);
}
NODO *buscarDato(char dato){
    NODO *p=inicio;
    while(p){
        if(dato==p->dato){
            return p;
        }
        p=p->despues;
    }
    return NULL;
}

void buscar(void){
    char letra;
    cout<<"Ingresa el dato a buscar: ";
    letra=getchar();
    NODO *resultado=buscarDato(letra);
    if(resultado){
        cout<<"Se encontro el dato, es: "<<resultado->dato<<endl;
    }else{
        cout<<"No se encontro el dato que busca."<<endl;
    }
}
void recorrer(void){
    cout<<"Contenido de la lista: "<<endl;
    NODO *p=inicio;
    while(p){
     cout<<"-"<<(p->dato);
     p=p->despues;
    }
    cout<<endl;

}
int main(int argc,char **args){
    int opcion;
    do{
        cout<<"Menu de opciones: "<<endl;
        cout<<"1. Agregar. "<<endl;
        cout<<"2. Buscar. "<<endl;
        cout<<"3. Elminar. "<<endl;
        cout<<"4. Recorrer. "<<endl;
        cout<<"5. Salir. "<<endl;
        cin>>opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            agregar();
            break;
        case 2:
            buscar();
            break;
        case 3:
            break;
        case 4:
            recorrer();
            break;
        case 5:
            exit(0);
            break;



        }

    }while(opcion!=5);

    return 0;
}
