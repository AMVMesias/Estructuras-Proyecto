#include <iostream>
#include "Menu.h"
#include "windows.h"

//#include "Ingreso"
using namespace std;

int main(){
	system("color 9");
	SetConsoleOutputCP(CP_UTF8);
	Menu menu;
	menu.MostrarMenuInicioSesion();
 	return 0;
}
