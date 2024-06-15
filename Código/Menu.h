#include <iostream>
#include <string>
#include "IngresoDatos.h"

using namespace std;
class Menu
{
public:
    Menu(){};
    void MostrarMenuPrincipal();
    bool MenuLogin();
    int obtenerIS_CC();
};

int Menu::obtenerIS_CC(){
    int cc=0;
    IngresoDatos i;
    do{
    cout<<"BIENVENIDOS A ESPExpress"<<endl;
    cout<<"Usted desea..."<<endl;
    cout<<"1. Iniciar Sesion"<<endl;
    cout<<"2. Crear Cuenta"<<endl;
    cc=i.IngresoEnteros("Opcion>>");
    }while(cc<1||cc>2);
    return cc;
}

bool Menu::MenuLogin(){
return false;
}
