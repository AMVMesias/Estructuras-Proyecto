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

    }while(cc<1||cc>2);
}

bool Menu::MenuLogin(){

}
