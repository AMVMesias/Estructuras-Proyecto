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

	//m.crearCuenta();
	//m.MostrarMenuPrincipal();
	
	Lista<Estudiante> listaEstudiantes;

    cargarEstudiantes(listaEstudiantes);
    listaEstudiantes.imprimirLista();

	
	return 0;
}
