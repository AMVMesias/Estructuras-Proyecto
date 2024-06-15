#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "IngresoDatos.h"
#include "ValidacionCedula.h"
#include "Estudiante.h"
using namespace std;
class Menu
{
public:
    Menu(){};
    void MostrarMenuPrincipal();
    bool MenuLogin();
    int obtenerIS_CC();
    void crearCuenta();
};

int Menu::obtenerIS_CC(){
    int cc=0;
    IngresoDatos i;
    do{
    cout<<"BIENVENIDOS A ESPExpress"<<endl;
    cout<<"Usted desea..."<<endl;
    cout<<"1. Iniciar Sesion"<<endl;
    cout<<"2. Crear Cuenta"<<endl;
    cc=i.IngresoEnteros("Opcion: ");
    switch(cc){
    case 1:
        if(MenuLogin()){
            cout<<"funciona?"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        break;
    case 2:
        crearCuenta();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout<<"La opcion no existe.";
    }
    }while(cc!=3);
    return cc;
}

bool Menu::MenuLogin(){
    IngresoDatos datosDelUsuario;
    string contrasenia;
    int ced;
    ced=datosDelUsuario.IngresoEnteros("Cedula: ");
    cout<<"Contrasenia: "<<endl;
    getline(cin,contrasenia);
    Estudiante aux(" ",ced,contrasenia);
    Estudiante aux1(" ",1756177935,"Chimuelo");
    if(aux.validarPersona_userPswd(aux,aux1)){
        return true;
    }else{
        cout<<"Claves invalidas"<<endl;
        return false;
    }
//return true;
}
void Menu::MostrarMenuPrincipal(){
    obtenerIS_CC();
}
void Menu::crearCuenta(){
    IngresoDatos datosCrear;
    string contrasenia;
    long long int cedula;
    cout<<"Usteda a seleccionado creacion de cuenta, su cedula va ser su usuario."<<endl;
    cedula=datosCrear.IngresoEnteros("Por favor ingrese su cedula de identidad: ");
    validar(cedula);
    fflush(stdin);
    cout<<"Por favor cree su contrasenia (Debe contener minimo 8 digitos): ";
    getline(cin,contrasenia);
    cout<<"Su cuenta se ha creado exitosamente."<<endl;
}
#endif