#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string apellido
    string matricula;
    string carrera;
    float promedio;

public:
    Estudiante(string nombre,string matricula,string carrera,float prome):nombre(nombre),matricula(matricula),carrera(carrera),promedio(prome){}

    string getNombre()const{return nombre;}
    string getApellido()const{return apellido;}
    string getMatricula()const{return matricula;}
    string getCarrera()const{return carrera;}

    void mostrarInformacion()const{
        cout<<"Nombre: "<<nombre<<endl<<"Matricula: "<<matricula<<endl<<"Carrera: "<<carrera<<endl;
    }
    
    float get_Promedio(){
    	return this->promedio;
	}
};
