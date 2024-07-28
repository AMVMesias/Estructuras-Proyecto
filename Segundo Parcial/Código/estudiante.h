#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string apellido;
    int numNotas;
    //const float notas[numNotas];
    float *notas;
    string correo;
    float promedio;

public:
    Estudiante(string nombre,string apellid, float *notas_,
	 string corre,float prome):nombre(nombre),apellido(apellid),notas(notas_),correo(corre),promedio(prome){}

    string getNombre()const{return nombre;}
    string getApellido()const{return apellido;}
    //string getMatricula()const{return matricula;}
    string getCorreo()const{return correo;}

    /*void mostrarInformacion()const{
        cout<<"Nombre: "<<nombre<<endl<<"Matricula: "<<matricula<<endl<<"Carrera: "<<carrera<<endl;
    }*/
    
    float get_Promedio(){
    	return this->promedio;
	}
	
	float* get_notas(){
		return notas;
	}
};
