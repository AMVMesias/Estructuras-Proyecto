#include <iostream>
#include "Menu.h"
//#include "MetodosExternos.cpp"
#include "ManejoArchivos.cpp"
//using namespace std;
/*void ingresarExternos(string,string);

MetodoExterno *directa = new MetodoExterno("OrdenamientoDirecto.txt");
MetodoExterno *natural = new MetodoExterno("OrdenamientoNatural.txt");

void ingresarExternos(string nom1, string nom2)
{
    float num;
    directa->setN(0);
    for (int i = 0; i < 10; i++)
    {
        cout << "Ingrese un numero: ";
        cin >> num;
        natural->insertar_Natural(num, nom1);
        directa->insertar(num, nom2);
    }
}*/

int main(){
	
	Menu menu;
	    menu.MostrarMenuPrincipal();
	
    /*int opc;
    cout << "Metodos Externos" << endl;
    cout << "1) Ordenamiento Directo" << endl;
    cout << "2) Ordenamiento Natural" << endl;
    cout << "3) Salir" << endl;
    cout << "Escoja una opcion: " << endl;
    cin >> opc;
    if (opc == 1)
    {
        directa->limpiarArchivo();
        ingresarExternos("OrdenamientoNatural.txt", "OrdenamientoDirecto.txt");
        directa->imprimirInterno("OrdenamientoDirecto.txt");
        cout << "\n~~~ Datos ingresados con exito ~~~" << endl;
        cout << "\n~~~ Datos ordenados ~~~" << endl;
        directa->ordenarPorDirecta();
        directa->imprimirInterno("OrdenamientoDirecto.txt");
        cout<<"\n";
        system("pause");
    }
    else if (opc == 2)
    {
        natural->limpiarArchivo();
        ingresarExternos("OrdenamientoNatural.txt", "OrdenamientoDirecto.txt");
        natural->imprimirInterno("OrdenamientoNatural.txt");
        cout << "\n~~~ Datos ingresados con exito ~~~" << endl;
        cout << "\n~~~ Datos ordenados ~~~" << endl;
        natural->ordenarPorNatural();
        natural->imprimirInterno("OrdenamientoNatural.txt");
        cout<<"\n";
        system("pause");
    }
    else if (opc == 3)
    {
        cout<<"Gracias por usar nuestro programa..";
        return 0;
    }*/
    
    ManejoArchivos manejo;
    string nombre="Denise";
    string apellido="Rea";
    string correo="dnrea@espe.edu.ec";
    float notas[]={2.3,2.8,4.3,9.6};
    float notasAlumnos[]={19.2,20,13.2,9,5,1};
    float prom=3.6;
    manejo.escribir_Encabezado("EDO","123456",4);
    manejo.escribir_Info_Alumnos(1,nombre,apellido,correo,notas,4,prom);
    manejo.escribir_Info_Alumnos(2,"jajasdfgh",apellido,correo,notas,4,prom);
    manejo.escribir_Resumen(notasAlumnos,5,"Chimuelo ",1752245198);
    return 0;
}
