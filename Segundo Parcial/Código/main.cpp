#include <iostream>
//#include "MetodosExternos.cpp"
#include "Lista.h"
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
    
     /*Estudiante(string nombre,string apellid, float *notas_,
	 string corre,float prome):nombre(nombre),apellido(apellid),notas(notas_),correo(corre),promedio(prome){}*/
	float notas[]={12.4,12.8,15};
	float notas1[]={12.4,14.8,15};
	float notas2[]={13.4,12.8,19};
    ManejoArchivos manejo;
    Estudiante estudiante1("Denise","Rea",notas,"dnrea@espe.edu.ec",14.5);
    Estudiante estudiante2("7dfghj","ghj",notas2,"fgh@espe.edu.ec",17.5);
    Estudiante estudiante3("cvbn","74411",notas2,"dnrea@vbn.edu.ec",19.5);
    Profesor profe("Chimuelo","1478541", "DCCO");
    
    //manejo.escribir_ResumenBusqueda("Quicksort",14.5,estudiante,1,profe);
    
    Lista<Estudiante> lista;
    lista.insertarAlFinal(estudiante1);
    lista.insertarAlFinal(estudiante2);
    lista.insertarAlFinal(estudiante3);
    
    //manejo.escribir_ResumenOrdenamiento("Shellsort",lista,profe);
    manejo.crear_Reporte_notas("EDO","12345",3,lista,profe);
    return 0;
}