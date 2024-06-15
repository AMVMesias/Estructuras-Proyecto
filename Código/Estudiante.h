#include <iostream>

using namespace std;

class Estudiante{
    private:
        string nombre;
        string usuario;
        string contrasenia;
    public:
        Estudiante(){};
        Estudiante (string _nombre=" ", string _usuario=" ", string _contrasenia=" ") :nombre(_nombre), usuario(_usuario),contrasenia(_contrasenia){}
        
        string getUsuario(){
            return usuario;
        }

        string getPswd(){
            return contrasenia;
        }


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

    bool validarPersona_userPswd(Estudiante aux, Estudiante aux1){
    bool a = false;
    if (aux.getUsuario() == aux1.getUsuario() && aux.getPswd() == aux1.getPswd())
    {
    	
        a = true;
    }
    return a;
	}
	
	bool validar_DatosVacios(){
		
	}
};
