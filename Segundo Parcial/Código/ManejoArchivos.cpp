#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath> // Para la función round
#include "ManejoArchivos.h"



/*
	Métodos adicionales
*/

float promedio(const float arreglo[], int n){
    float suma = 0.0;
    for (int i = 0; i < n; i++){
        suma = suma + arreglo[i];
    }
    return suma / n;
}

int aprobados(const float arreglo[], int n){
    int contador = 0;
    for (int i = 0; i < n; i++){
        if (arreglo[i] >= 14){
            contador++;
        }
    }
    return contador;
}

int suspensos(const float arreglo[], int n){
    int contador = 0;
    for (int i = 0; i < n; i++){
        if (arreglo[i] >= 9 && arreglo[i] < 14){
            contador++;
        }
    }
    return contador;
}

int reprobados(const float arreglo[], int n){
    int contador = 0;
    for (int i = 0; i < n; i++){
        if (arreglo[i] < 9){
            contador++;
        }
    }
    return contador;
}

/*void redondearArreglo(const float arreglo[], int n){
    for (int i = 0; i < n; i++){
        arreglo[i] = round(arreglo[i] * 100) / 100;
    }
}

void duplicarArreglo(float arrOriginal[], float arrCopia[], int n){
    for (int i = 0; i < n; i++){
        arrCopia[i] = arrOriginal[i];
    }
}
*/
/*
	Métodos para el manejo de archivos
*/

void ManejoArchivos::escribir_Encabezado(const string& materia,const string& nrc,int numNotas){
	        ofstream reporte("Reporte_Calificaciones_2024.txt");
	        string ss="===============";

            if (reporte.is_open()) {
                reporte << internal << setw(70) << "UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE" << endl;
                reporte << internal << setw(60) << "REPORTE DE CALIFICACIONES\n\n" << endl;
                reporte << "		Periodo: Mayo 2024 – Septiembre 2024" << endl;
                reporte << "		Materia: " << materia << endl;
                reporte << "		NRC: " << nrc << endl;
                reporte << endl;
                reporte << left << setw(5) << "N°" << " || " << setw(15) << "Estudiante" << " || " << setw(15) << "Apellido" << " || " << setw(30) << "Correo" << " || ";
                for (int i = 1; i <= numNotas; ++i) {
                    reporte << setw(10) << "Nota " << " || ";
                }
                reporte << left << setw(10) << "Promedio" << endl;
                //reporte << endl;
                for(int j=1;j<numNotas-1;++j){
                	ss=ss+ss;
				}
                reporte <<"====================================================================================="+ss<<endl;
                
                reporte.close();
}
}

void ManejoArchivos::escribir_Info_Alumnos(int i, const string& nombre, const string& apellido, const string& correo, const float notas[], int numNotas, float promedio) { 
	ofstream reporte("Reporte_Calificaciones_2024.txt", std::ios::app); // Abrir el archivo en modo de añadir (append)
    if (reporte.is_open()) {
        reporte << left << setw(5) << i + 1 << " || " << setw(15) << nombre << " || " << setw(15) << apellido << " || " << setw(30) << correo << " || ";
					//poner NumNotas
//					cout<<"num de notas"<<numNotas<<endl;
                    for (int j = 0; j < numNotas; j++) {
//                    	cout<<"lo qe hay en j"<<j<<endl;
                        reporte << left << setw(10) << notas[j] << " || ";
                    }
                    reporte << left << setw(10) << round(promedio* 100) / 100 << endl;
                    /*arrPromedios[i] = promedio(notas, numNotas);
                    redondearArreglo(arrPromedios, numEstudiantes);
                    duplicarArreglo(arrPromedios, copiaPromedios, numEstudiantes);*/
        reporte.close();
    } else {
        // Manejar el error si no se puede abrir el archivo
        std::cerr << "Error al abrir el archivo: Reporte_Calificaciones_2024.txt" << std::endl;
    }                 
}

void ManejoArchivos::escribir_Resumen(const float arrPromedios[],int numEstudiantes,const string nombreDocente, int cedulaDocente){
	ofstream reporte("Reporte_Calificaciones_2024.txt", std::ios::app); // Abrir el archivo en modo de añadir (append)
        if (reporte.is_open()) {
        		reporte << "\n\n\n			RESUMEN\n" << endl;
                reporte << "		|Promedio del curso         : " << promedio(arrPromedios, numEstudiantes) << endl;
                reporte << "		|Aprobados  (14-20)         :  " << aprobados(arrPromedios, numEstudiantes) << endl;
                reporte << "		|Suspenso   (09-13)         :  " << suspensos(arrPromedios, numEstudiantes) << endl;
                reporte << "		|Reprobados (01-08)         :  " << reprobados(arrPromedios, numEstudiantes) << endl;

                reporte << endl;
                reporte << internal << setw(55) << "__________________" << endl;
                reporte << internal << setw(50) << "Docente" << endl;
                reporte << internal << setw(50) << nombreDocente << endl;
                reporte << internal << setw(50) << cedulaDocente << endl;

                reporte.close();
        }else{
        	std::cerr << "Error al abrir el archivo: Reporte_Calificaciones_2024.txt" << std::endl;
		}
}
