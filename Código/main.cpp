#include <iostream>
#include "Pedido.h"
#include "Lista.h"
#include  "Menu.h"
#include "Estudiante.h"
#include <windows.h>
using namespace std;

int main(){
SetConsoleOutputCP(CP_UTF8);
	Menu m;
	//	m.MenuLogin();
	//m.crearCuenta();
	m.MostrarMenuPrincipal();
	
	/*Lista<Estudiante> listaEstudiantes;

    cargarEstudiantes(listaEstudiantes);
    listaEstudiantes.imprimirLista();
	Estudiante e;
	//listaEstudiantes.obtenerUserBuscado(e,1750573733);
	//cout<<e.getUsuario()<<"  "<<e.getNombre()<<endl;*/
	
	return 0;
}
