#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "IngresoDatos.h"
#include "ValidacionCedula.h"
#include "Estudiante.h"
#include "Pedido.h"
#include "Producto.h"
#include "ManejoJson.h"
#include "Lista.h"
using namespace std;
class Menu
{
private:
    Lista<Producto> pedido;
    Lista<Estudiante> Listausuarios;
    Lista<Pedido> Listapedidos;
    Lista<Producto> ListaProductos;
public:
    Menu(){
        ListaProductos.insertarAlFinal(Producto("Pizza", 1.00,0));
        ListaProductos.insertarAlFinal(Producto("Salchipapa", 1.50,0));
        ListaProductos.insertarAlFinal(Producto("Agua", 0.50,0));
        ListaProductos.insertarAlFinal(Producto("Hamburguesa", 2.00,0));
        ListaProductos.insertarAlFinal(Producto("Refresco", 0.40,0));
    };
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
    cargarEstudiantes(this->Listausuarios);
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
    Estudiante aux1;
    Listausuarios.obtenerUserBuscado(aux1,ced);
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
	//cargar la Lista de Productos
    //aquí se debería imprimir la lista de productos

    IngresoDatos orden;
    int opcion;
    do {
        cout <<"Menu de comida: " << endl;
        ListaProductos.imprimirMenu();
        cout <<"6. Regresar" << endl;
        opcion = orden.IngresoEnteros("Ingrese las opciones que desee: ");
        cout << endl;
        switch(opcion){
            case 1:
                pedido.insertarComida(Producto("Pizza",1.00,0));
                cout <<"Pizza agregada." << endl;
                break;
            case 2:
                pedido.insertarComida(Producto("Salchipapa",1.50,0));
                cout <<"Salchipapa agregada." << endl;
                break;
            case 3:
                pedido.insertarComida(Producto("Agua",0.50,0));
                cout <<"Agua agregada." << endl;
                break;
            case 4:
                pedido.insertarComida(Producto("Hamburguesa",2.00,0));
                cout <<"Hamburguesa agregada." << endl;
                break;
            case 5:
                pedido.insertarComida(Producto("Refresco",0.40,0));
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
