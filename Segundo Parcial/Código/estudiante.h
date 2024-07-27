#include <iostream>
#include <string>

using namespace std;

class Estudiante{
private:
    string nombre;
    string matricula;
    string carrera;

public:
    Estudiante(string nombre,string matricula,string carrera):nombre(nombre),matricula(matricula),carrera(carrera){}

    string getNombre()const{return nombre;}
    string getMatricula()const{return matricula;}
    string getCarrera()const{return carrera;}

    void mostrarInformacion()const{
        cout<<"Nombre: "<<nombre<<endl<<"Matricula: "<<matricula<<endl<<"Carrera: "<<carrera<<endl;
    }
};
