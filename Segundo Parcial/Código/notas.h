#include <iostream>
#include <string>

using namespace std;

class NodoNota{
public:
    string codigoMateria;
    double nota;
    NodoNota* siguiente;

    NodoNota(string codigoMateria,double nota):codigoMateria(codigoMateria),nota(nota),siguiente(nullptr){}
};

class NodoEstudiante{
public:
    string matricula;
    NodoNota* notas;
    NodoEstudiante* siguiente;

    NodoEstudiante(string matricula):matricula(matricula),notas(nullptr),siguiente(nullptr){}
};

class RegistrarNotas{
private:
    NodoEstudiante* estudiantes;

public:
    RegistrarNotas():estudiantes(nullptr){}
    void registrarNota(const string& matricula,const string& codigoMateria,double nota){
        NodoEstudiante* estudiante=buscarEstudiante(matricula);
        if(!estudiante){
            estudiante=new NodoEstudiante(matricula);
            estudiante->siguiente=estudiantes;
            estudiantes=estudiante;
        }

        NodoNota* nuevaNota=new NodoNota(codigoMateria,nota);
        nuevaNota->siguiente=estudiante->notas;
        estudiante->notas=nuevaNota;
    }

    double obtenerNota(const string& matricula,const string& codigoMateria){
        NodoEstudiante* estudiante=buscarEstudiante(matricula);
        if(estudiante){
            NodoNota* nota=buscarNota(estudiante->notas,codigoMateria);
            if(nota){
                return nota->nota;
            }
        }
        return -1;
    }

    void imprimirNotas(const string& matricula){
        NodoEstudiante* estudiante=buscarEstudiante(matricula);
        if(estudiante){
            cout<<"Notas de la matricula "<<matricula<<":"<<endl;
            NodoNota* notaActual=estudiante->notas;
            while(notaActual){
                cout<<"Materia: "<<notaActual->codigoMateria<<"Nota: "<<notaActual->nota<<endl;
                notaActual=notaActual->siguiente;
            }
        }else{
            cout<<"No se encontraron notas para la matricula "<<matricula<<endl;
        }
    }

private:
    NodoEstudiante* buscarEstudiante(const string& matricula){
        NodoEstudiante* actual=estudiantes;
        while(actual){
            if(actual->matricula==matricula){
                return actual;
            }
            actual=actual->siguiente;
        }
        return nullptr;
    }

    NodoNota* buscarNota(NodoNota* notas,const string& codigoMateria){
        NodoNota* actual=notas;
        while(actual){
            if(actual->codigoMateria==codigoMateria){
                return actual;
            }
            actual=actual->siguiente;
        }
        return nullptr;
    }
};
