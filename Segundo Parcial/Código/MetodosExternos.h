#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
   
class MetodoExterno{

    private:
        string nombreArchivo{"ordenada.txt"};
        int N{0};

        /*
        	Métodos para ambas funciones
        */

        void abrir(fstream *f, string nom, int tip);
        void cerrar(fstream *f);

        /*
			Métodos usados para Ordenación Natural
		*/
        void generarAleatorios(int min, int max);
        void particionInicial();
        void particionFusion();
        void limpiar();
        void intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4);

        /*
			Métodos para Ordenación Directa
		*/

        void particiona(int l);
        void fusiona(int l);


    public:
    
        MetodoExterno(string);
        ~MetodoExterno();
        MetodoExterno();
        
        /*
			Métodos para Ordenación Directa
		*/
        void ordenarPorDirecta();
        void insertar(float d, string nom);

        /*
			Métodos para Ordenación Natural
		*/
        void ordenarPorNatural();
        bool hayDatos();
        void limpiarArchivo();
        void insertar_Natural(float d, string nom);
        void setN(float n);
        void imprimirInterno(string nombre);

};