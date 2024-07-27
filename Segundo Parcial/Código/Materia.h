#include <iostream>
#include <string>

using namespace std;

class Materia{
private:
    string nombre;
    string codigo;
    int creditos;

public:
    Materia(string nombre,string codigo,int creditos):nombre(nombre),codigo(codigo),creditos(creditos){}

    string getNombre()const{return nombre;}
    string getCodigo()const{return codigo;}
    int getCreditos()const{return creditos;}

    void mostrarInformacion() const {
        cout<< "Nombre: "<<nombre<<endl<<"Codigo: "<<codigo<<endl<<"Creditos: "<<creditos<<endl;
    }
};
