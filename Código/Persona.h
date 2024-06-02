#include <iostream>
#include <string>

using namespace std; 

class Persona{
	private:
		string nombre;
		string cedula;
		string pswd;
		
	public:
		Persona ();
		Persona(string, string, string);
		
		string getNombre();
		string getCedula();
		string getContras();
		void setNombre(string);
		void setCedula(string);
		void setPswd(string);
		
	Persona buscarPersona(string);
    bool validarPersona_userPswd(Persona, Persona);
    bool validarDuplicados(Persona&,Persona&);
    bool validarDatosVacios(Persona&);
    bool crearCuenta(Persona&);
    void verPersonas();
    bool obtenerDatos(int, Persona&);
    void actualizarDatos(Persona);
};