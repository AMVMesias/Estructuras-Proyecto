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
	int a=0;
	Estudiante e("Denise",0,"aa");
	//m.crearCuenta();
	m.MostrarMenuPrincipal();
	return 0;
}
