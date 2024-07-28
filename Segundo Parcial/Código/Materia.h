#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>
#include <string>

using namespace std;

class Materia{
private:
    string nombre;
    string codigo;

public:
	Materia(){};
    void leerDatos(){
        cout<<"Ingrese nombre de la materia: ";
        cin>>ws;
        getline(cin, nombre);
        cout<<"Ingrese codigo de la materia: ";
        cin>>codigo;
        //seleccionada=false;
    }

    string getNombre()const{
        return nombre;
    }

    string getCodigo()const{
        return codigo;
    }
    
};

#endif // MATERIA_H
