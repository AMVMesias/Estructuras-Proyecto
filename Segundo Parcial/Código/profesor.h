#ifndef PROFESOR_H
#define PROFESOR_H
#include <iostream>
#include <string>
#include "Materia.h"
#include "ValidacionCedula.h"
#define numMateriasMax 5
using namespace std;

class Profesor{
private:
    string nombre;
    long long int cedula;
    Materia materias[numMateriasMax];
    int numMaterias;

public:
    Profesor():numMaterias(0){}
    void leerDatosProfesor(){
        cout << "Ingrese nombre del docente: ";
        cin >> ws;
        getline(cin, nombre);
        cout << "Ingrese cedula del docente: ";
        cin >> cedula;
        validar(cedula);

    }

    string getNombre() const {
        return nombre;
    }

    long long int getCedula() const {
        return cedula;
    }

    void registrarMateria(){
        if(numMaterias>=numMateriasMax){
            cout<<"No se pueden registrar mas materias."<<endl;
            return;
        }
    Materia nuevaMateria;
    nuevaMateria.leerDatos();
    for(int i=0;i<numMaterias;i++){
        if(materias[i].getCodigo()==nuevaMateria.getCodigo()){
            cout<<"La materia con nrc "<<materias[i].getCodigo()<<" ya esta registrado";
            return;
        }

        }
        materias[numMaterias++]=nuevaMateria;
        cout<<"Materia registrada exitosamente."<<endl;
    }
};

#endif // PROFESOR_H
