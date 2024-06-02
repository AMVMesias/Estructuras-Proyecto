#include "Login.h"

Login::Login(Persona* p){
	this->persona = *p;
}

void Login::login(){
		int opcion=0;
		do{
			system("cls");
			cout<<"Escoja la opcion a realizar "<<endl;
			cout<<"1. Iniciar Sesion "<<endl;
			cout<<"2. Crear Cuenta "<<endl;
			cout<<"3. Salir "<<endl;
			cin>>opcion;
		}while(opcion<=0 || opcion>3);
		if(opcion==1){
			iniciarSesion();
		}else if(opcion==2){
			crearCuenta();
		}
		else{
			exit(0);
		}
	}


void Login::crearCuenta(){
	int item=0;
	string cad="";
	Persona aux;
	cout<<"Ingrese los siguientes datos: "<<endl;
	cout<<"Nombre: ";
	cin.ignore();
	getline(cin,cad);
	aux.setNombre(cad);
	cout<<"Cedula : ";
	getline(cin,cad);
	aux.setCedula(cad);
	cout<<"Clave : ";
	getline(cin,cad);
	aux.setPswd(cad);
	if(aux.crearCuenta(aux))
	{
		aux.actualizarDatos(aux);
	}
	else{
		cout<<"ERROR INTENTE NUEVAMENTE"<<endl;
	}	
	
}

void Login::iniciarSesion(){
	string c;
	cout<<"Ingrese sus datos"<<endl;
	cin.ignore();
	cout<<"Usuario: ";
	getline(cin,c);
	persona.setCedula(c);
	cout<<"Clave: ";
	getline(cin,c);
	persona.setPswd(c);
	if(persona.obtenerDatos(1,persona)){
		cout<<"Ha iniciado sesion"<<endl;
	}
	else{
		cout<<"Credenciales Incorrectas "<<endl;
	}
	
}