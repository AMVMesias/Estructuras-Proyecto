#include "Persona.cpp"

#include <iostream>

using namespace std;
class Login{
	private:
	Persona persona;
	
	public: 
	Login(Persona*);
	
	void llenarpersonas();
	
	void iniciarSesion();
	
	void crearCuenta();
	
	void login();
};