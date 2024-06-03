#include "Node.h"
#include "List.h"


class Persona {
public:
    Persona(const std::string& nombre, int edad, const std::string& cedula) 
        : nombre(nombre), edad(edad), cedula(cedula) {}

    std::string getNombre() const { return nombre; }
    int getEdad() const { return edad; }
    std::string getCedula() const { return cedula; }

    friend std::ostream& operator<<(std::ostream& os, const Persona& persona) {
        os << "\nNombre: " << persona.nombre << "\nEdad: " << persona.edad << "\nCedula: " << persona.cedula;
        return os;
    }

private:
    std::string nombre;
    int edad;
    std::string cedula;
};


int main(){
	
	List<Persona> lista;

    Persona personas[] = {
        Persona("Juan", 30, "1726885050"),
        Persona("Ana", 25, "1788895956"),
        Persona("Luis", 40, "1097846528")
    };

    lista.insertList(personas);
    std::cout << lista;

	
	return 0;
}