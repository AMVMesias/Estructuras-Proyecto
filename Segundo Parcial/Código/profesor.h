#include <iostream>
#include <string>

using namespace std;

class Profesor{
private:
    string nombre;
    string id;
    string departamento;

public:
    Profesor(string nombre,string id,string departamento):nombre(nombre),id(id),departamento(departamento){}

    string getNombre()const{return nombre;}
    string getId()const{return id;}
    string getDepartamento()const{return departamento;}

    void mostrarInformacion()const{
        cout<<"Nombre: "<<nombre<<endl<<"ID: "<<id<<endl<<"Departamento: "<<departamento<<endl;
    }
};
