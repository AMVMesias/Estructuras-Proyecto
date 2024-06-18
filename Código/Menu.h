#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "IngresoDatos.h"
#include "ValidacionCedula.h"
#include "Estudiante.h"
#include "ManejoJson.h"
#include "Lista.h"
using namespace std;
class Menu
{
private:
    Lista<string> pedido;
    //capaz de poner aqui las listas 
    //Lista Estudiantes
    //Lista Pedido
    //Lista productos
public:
    Menu(){};
    void MostrarMenuPrincipal();
    bool MenuLogin();
    int obtenerIS_CC();
    void crearCuenta();
    void mostrarMenuFunciones();
    void mostrarMenuCarta();
    void mostrarCanasta();
    void pagarPedido();
};

int Menu::obtenerIS_CC(){
	//aqui se debería cargar los datos 
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
            mostrarMenuFunciones();
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
    cout<<"Contrasenia: ";
    getline(cin,contrasenia);
    Estudiante aux(" ",ced,contrasenia);
    //aqui debemos obtener el objeto de la lista , método buscar y que me retorne un objeto EStudiante
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
    string contrasenia, nombre;
    long long int cedula;
    cout<<"Usted a seleccionado creación de cuenta, su cédula se convertirá en su usuario para iniciar Sesión."<<endl;
    cout<<"Por favor, ingrese los siguiente sdatos."<<endl;
    cout<<"Nombre:  ";
    getline(cin,nombre);
    cedula=datosCrear.IngresoEnteros("Cédula de identidad: ");
    validar(cedula);
    cout<<"Por favor cree su contrasenia (Debe contener minimo 8 digitos): ";
    getline(cin,contrasenia);
    Estudiante aux(nombre,cedula,contrasenia);
    fflush(stdin);
    if(aux.CrearCuenta(aux)){
    	//conexión a Json usado como base de datos
        crearNuevoUsuario_BBD(aux.getUsuario(), aux.getPswd(), aux.getNombre());

    }else{
        cout<<"Vuelva a intentarlo";
    }


}
void Menu::mostrarMenuFunciones(){
    int cc=0;
    IngresoDatos i;
    do{
    cout<<"ESPExpress"<<endl;
    cout<<"Usted desea..."<<endl;
    cout<<"1. Iniciar orden."<<endl;
    cout<<"2. Canasta de compras."<<endl;
    cout<<"3. Ver comprobante de pago."<<endl;
    cout<<"4. Salir."<<endl;
    cc=i.IngresoEnteros("Opcion: ");
    switch(cc){
    case 1:
        mostrarMenuCarta();
        break;
    case 2:
        mostrarCanasta();
        pagarPedido();
        break;
    case 3:

        break;
    case 4:
        exit(0);
        break;
    default:
        cout<<"La opcion no existe.";
    }
    }while(cc!=3);
}

void Menu::mostrarMenuCarta() {
	//aquí se debería imprimir la lista de productos
    IngresoDatos orden;
    int opcion;
    do {
        cout <<"Menu de comida: " << endl;
        cout <<"1. Pizza" << endl;
        cout <<"2. Salchipapa" << endl;
        cout <<"3. Agua" << endl;
        cout <<"4. Hamburguesa" << endl;
        cout <<"5. Refresco" << endl;
        cout <<"6. Regresar" << endl;
        opcion = orden.IngresoEnteros("Ingrese las opciones que desee: ");
        cout << endl;
        switch(opcion){
            case 1:
                pedido.insertarComida("Pizza");
                cout <<"Pizza agregada." << endl;
                break;
            case 2:
                pedido.insertarComida("Salchipapa");
                cout <<"Salchipapa agregada." << endl;
                break;
            case 3:
                pedido.insertarComida("Agua");
                cout <<"Agua agregada." << endl;
                break;
            case 4:
                pedido.insertarComida("Hamburguesa");
                cout <<"Hamburguesa agregada." << endl;
                break;
            case 5:
                pedido.insertarComida("Refresco");
                cout <<"Refresco agregada." << endl;
                break;
            case 6:
                mostrarMenuFunciones();
                break;
        }
    }while(opcion != 6);
}

void Menu::mostrarCanasta() {
    cout<<"Su pedido por ahora es: "<<endl;
    pedido.imprimirListaComida();
}
void Menu::pagarPedido(){
    IngresoDatos orden;
    int opcion;
    cout<<"1. Pagar"<<endl;
    cout<<"2. Regresar al menu de comida"<<endl;
    opcion = orden.IngresoEnteros("Elija una opcion: ");
    switch(opcion){
    case 1:
        cout<<"Pedido cancelado exitosamente."<<endl;
        break;
    case 2:
        mostrarMenuFunciones();
        break;
    }
}
#endif
