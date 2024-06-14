#include <iostream>

using namespace std;

class Estudiante{
    private:
        string usuario;
        string contrasenia;
    public:
        Estudiante (string _usuario=" ", string _contrasenia=" ") : usuario(_usuario),contrasenia(_contrasenia){}
    void ingresarDatos() {
        cout<<"Ingrese el usuario: ";
        getline(cin,usuario);
        cout<<"Ingrese la contrasenia: ";
        getline(cin,contrasenia);
    }
    void mostrarDatos(){
        cout<<"Usuario: "<<usuario<<endl;
        cout<<"Contrasenia: "<<contrasenia<<endl;
    }
};
