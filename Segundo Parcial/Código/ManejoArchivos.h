
#include <fstream>
#include <iomanip>
#include <math.h>
#include <string>
#include "estudiante.h"
#include "Lista.h"
#include "profesor.h"
//aqui mandar la clase de Estudiante y profesor 

using namespace std;
class ManejoArchivos{
	//private: 
	//ofstream reporte("Reporte_Calificaciones_2024.txt");
	//string nombreArchivo{"Reporte_Calificaciones_2024.txt"};
	
	public:
	ManejoArchivos(){};
	void crear_Reporte_notas(const string&, const string&, int, Lista<Estudiante>,Profesor);
	
	void escribir_Encabezado(const string&,const string&,int);
	void escribir_Info_Alumnos(int, const string&, const string&, const string&,const float[],int,float);
	void escribir_Resumen(const float*,int,const string,const string&);
	void escribir_ResumenOrdenamiento(const string&, Lista <Estudiante>,Profesor);
	void escribir_ResumenBusqueda(const string&,float,Estudiante,Profesor);
};