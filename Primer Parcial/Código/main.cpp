#include <iostream>
#include "Pedido.h"
#include "Lista.h"
#include  "Menu.h"
#include "Estudiante.h"
#include <windows.h>
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(0)));
	SetConsoleOutputCP(CP_UTF8);
	Menu m;
	m.MostrarMenuPrincipal();
    return 0;
}


