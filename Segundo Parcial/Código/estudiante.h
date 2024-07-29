#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string apellido;
    int numNotas;

    float *notas;
    string correo;
    float promedio;

public:
    Estudiante(string nombre,string apellid, float *notas_,
	 string corre,float prome):nombre(nombre),apellido(apellid),notas(notas_),correo(corre),promedio(prome){}
	 Estudiante(){};
    string getNombre()const{return nombre;}
    string getApellido()const{return apellido;}
    //string getMatricula()const{return matricula;}
    string getCorreo()const{return correo;}
    string getNombreCompleto() const { return nombre + " " + apellido; }

    
    
    float get_Promedio(){
    	return this->promedio;
	}
	
	float* get_notas(){
		return notas;
	}
	
	void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl
             << "Apellido: " << apellido << endl
             << "Correo: " << correo << endl
             << "Promedio: " << promedio << endl;
    }
    
	
};
#endif