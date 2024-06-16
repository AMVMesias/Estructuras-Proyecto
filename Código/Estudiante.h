#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>

using namespace std;

class Estudiante{
    private:
        string nombre;
        int usuario;
        string contrasenia;
    public:
        //Estudiante ():nombre(" "), usuario(0),contrasenia(" "){}
        Estudiante (string _nombre=" ", int _usuario =0, string _contrasenia=" ") :nombre(_nombre), usuario(_usuario),contrasenia(_contrasenia){}
        
        int getUsuario(){
            return usuario;
        }

        string getPswd(){
            return contrasenia;
        }

		string getNombre(){
			return nombre;
		}
		
    void ingresarDatos() {
        cout<<"Ingrese el usuario: ";
        cin>>usuario;
        cout<<"Ingrese la contrasenia: ";
        getline(cin,contrasenia);
    }
    void mostrarDatos(){
        cout<<"Usuario: "<<usuario<<endl;
        cout<<"Contrasenia: "<<contrasenia<<endl;
        cout<<"Nombres: "<<nombre<<endl;
    }

    bool validarPersona_userPswd(Estudiante aux, Estudiante aux1){
    bool a = false;
    if (aux.getUsuario() == aux1.getUsuario() && aux.getPswd() == aux1.getPswd())
    {
    	
        a = true;
    }
    return a;
	}
	
	bool validar_DatosVacios(string nom, int ced, string passw){
	bool vDV=false;
    if(nom.empty()||ced==0||passw.empty())
    {
        vDV=true;
    }
    return vDV;
	}
	
	bool CrearCuenta(Estudiante persona)
{
       bool cc= false;
    if(this->validar_DatosVacios(persona.getNombre(),persona.getUsuario(),persona.getPswd()))
    {
        cout<<"No puede existir un campo vacío\n";
    }
    else
    {
        /*if(this->validarDuplicados(persona.getCedula()))
        {
            cout<<"Se ha detectado un ID duplicado, por favor vuelva a intentarlo\n";
        }
        else
        {
            cc=true;
        }*/
        cc=true;
    }
    return cc;

}
};
#endif