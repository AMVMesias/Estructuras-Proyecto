#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "ValidacionCedula.h"
#include <fstream>
#include <iomanip>
//#include "Estudiante.h"
#include "Lista.h"


using namespace std;

long long int validar(long long int &x);

class Menu {
public:
    void MostrarMenuPrincipal();
    void PedirDatosDocente();
    void PedirMateriaNRC();
    void PedirNumeroEstudiantes();
    void IngresarNotas();
    void AlmacenarDatos();

private:
    string nombreDocente;
    string cedulaDocente;
    string materia;
    string NRC;
    int numeroEstudiantes;
    Lista<double> notas;
    double promedio;

    bool ValidarCedula(const string& cedula);
    void CalcularPromedio();
};

void Menu::MostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "Menu Principal:" << endl;
        cout << "1. Ingresar nombre y cedula del docente" << endl;
        cout << "2. Ingresar materia y NRC" << endl;
        cout << "3. Ingresar numero de estudiantes y notas" << endl;
        cout << "4. Ingresar notas por cada estudiante" << endl;
        cout << "5. Almacenar datos en archivo 'calificaciones'" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                PedirDatosDocente();
                break;
            case 2:
                PedirMateriaNRC();
                break;
            case 3:
                PedirNumeroEstudiantes();
                break;
            case 4:
                IngresarNotas();
                break;
            case 5:
                AlmacenarDatos();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, por favor intente nuevamente." << endl;
        }
    } while (opcion != 6);
}

void Menu::PedirDatosDocente() {
    cout << "Ingrese el nombre del docente: ";
    getline(cin, nombreDocente);
    
    IngresoDatos crearUsuario;
    long long int cedula;
    do {
        cedula = crearUsuario.IngresoEnteros("Ingrese la cedula del docente: ");
        cedula = validar(cedula);
    } while (cedula == 0);
    
    cedulaDocente = to_string(cedula);
}

void Menu::PedirMateriaNRC() {
    cout << "Ingrese la materia: ";
    getline(cin, materia);
    cout << "Ingrese el NRC: ";
    getline(cin, NRC);
}

void Menu::PedirNumeroEstudiantes() {
    cout << "Ingrese el numero de estudiantes: ";
    cin >> numeroEstudiantes;
    cin.ignore(); // Ignorar el salto de línea restante en el buffer
}

void Menu::IngresarNotas() {
    double nota;
    for (int i = 0; i < numeroEstudiantes; ++i) {
        do {
            cout << "Ingrese la nota del estudiante " << i + 1 << " (0 a 20): ";
            cin >> nota;
        } while (nota < 0 || nota > 20);
        notas.insertarAlFinal(nota);
    }
    CalcularPromedio();
}

void Menu::AlmacenarDatos() {
    ofstream archivo("calificaciones.txt");
    if (archivo.is_open()) {
        archivo << "Docente: " << nombreDocente << ", Cedula: " << cedulaDocente << endl;
        archivo << "Materia: " << materia << ", NRC: " << NRC << endl;
        archivo << "Numero de Estudiantes: " << numeroEstudiantes << endl;
        archivo << "Notas: ";
        Nodo<double>* actual = notas.getCabeza();
        while (actual) {
            archivo << fixed << setprecision(2) << actual->dato << " ";
            actual = actual->siguiente;
        }
        archivo << endl;
        archivo << "Promedio: " << fixed << setprecision(2) << promedio << endl;
        archivo.close();
        cout << "Datos almacenados correctamente en 'calificaciones.txt'" << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

bool Menu::ValidarCedula(const string& cedula) {
    long long int cedulaNum = stoll(cedula);
    return validar(cedulaNum) != 0;
}

void Menu::CalcularPromedio() {
    double suma = 0;
    Nodo<double>* actual = notas.getCabeza();
    while (actual) {
        suma += actual->dato;
        actual = actual->siguiente;
    }
    promedio = suma / numeroEstudiantes;
}


#endif
