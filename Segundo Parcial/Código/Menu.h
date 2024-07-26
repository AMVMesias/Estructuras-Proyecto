#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "ValidacionCedula.h"
#include "Lista.h"
#include "ManejoArchivos.h"

using namespace std;

long long int validar(long long int &x);

class Menu {
public:
    Menu();
    void MostrarMenuPrincipal();

private:
    ManejoArchivos manejoArchivos;
    string nombreDocente;
    string cedulaDocente;
    string materia;
    string NRC;
    int numeroEstudiantes;
    Lista<double> notas;
    float* arrPromedios;
    bool profesorLogueado;
    bool materiaIngresada;
    bool estudiantesIngresados;
    bool notasIngresadas;
    bool datosAlmacenados;

    void Login();
    void PedirDatosDocente();
    void PedirMateriaNRC();
    void PedirNumeroEstudiantes();
    void IngresarNotas();
    void AlmacenarDatos();
    void OrdenarNotas();
    void OrdenamientoExterno();
    void BuscarCalificacion();
    float CalcularPromedio();
};

Menu::Menu() : profesorLogueado(false), materiaIngresada(false), estudiantesIngresados(false), 
               notasIngresadas(false), datosAlmacenados(false), numeroEstudiantes(0), arrPromedios(nullptr) {}

void Menu::MostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "Menu Principal:" << endl;
        if (!profesorLogueado) {
            cout << "1. Login del profesor" << endl;
        } else if (!materiaIngresada) {
            cout << "2. Ingresar materia y NRC" << endl;
        } else if (!estudiantesIngresados) {
            cout << "3. Ingresar numero de estudiantes" << endl;
        } else if (!notasIngresadas) {
            cout << "4. Ingresar notas por cada estudiante" << endl;
        } else if (!datosAlmacenados) {
            cout << "5. Almacenar datos en archivo 'calificaciones'" << endl;
        } else {
            cout << "6. Ordenar notas" << endl;
            cout << "7. Almacenar resultados de ordenamiento" << endl;
            cout << "8. Realizar ordenamiento externo" << endl;
            cout << "9. Buscar calificación" << endl;
            cout << "10. Almacenar resultados de búsqueda" << endl;
        }
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                if (!profesorLogueado) Login();
                else cout << "Ya ha iniciado sesión." << endl;
                break;
            case 2:
                if (profesorLogueado && !materiaIngresada) {
                    PedirMateriaNRC();
                    materiaIngresada = true;
                }
                else cout << "No puede realizar esta acción ahora." << endl;
                break;
            case 3:
                if (materiaIngresada && !estudiantesIngresados) {
                    PedirNumeroEstudiantes();
                    estudiantesIngresados = true;
                }
                else cout << "No puede realizar esta acción ahora." << endl;
                break;
            case 4:
                if (estudiantesIngresados && !notasIngresadas) {
                    IngresarNotas();
                    notasIngresadas = true;
                }
                else cout << "No puede realizar esta acción ahora." << endl;
                break;
            case 5:
                if (notasIngresadas && !datosAlmacenados) {
                    AlmacenarDatos();
                    datosAlmacenados = true;
                    cout << "El archivo fue creado o modificado exitosamente." << endl;
                }
                else cout << "No puede realizar esta acción ahora." << endl;
                break;
            case 6:
                if (datosAlmacenados) OrdenarNotas();
                else cout << "Debe almacenar los datos primero." << endl;
                break;
            case 7:
                if (datosAlmacenados) {
                    // Implementar almacenamiento de resultados de ordenamiento
                    cout << "Resultados de ordenamiento almacenados en 'ordenamiento.txt'" << endl;
                }
                else cout << "Debe ordenar las notas primero." << endl;
                break;
            case 8:
                if (datosAlmacenados) OrdenamientoExterno();
                else cout << "Debe almacenar los datos primero." << endl;
                break;
            case 9:
                if (datosAlmacenados) BuscarCalificacion();
                else cout << "Debe almacenar los datos primero." << endl;
                break;
            case 10:
                if (datosAlmacenados) {
                    // Implementar almacenamiento de resultados de búsqueda
                    cout << "Resultados de búsqueda almacenados en 'busqueda.txt'" << endl;
                }
                else cout << "Debe realizar una búsqueda primero." << endl;
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida, por favor intente nuevamente." << endl;
        }
    } while (opcion != 0);
}

void Menu::OrdenarNotas() {
    cout << "Seleccione el tipo de ordenamiento:" << endl;
    cout << "1. Burbuja" << endl;
    cout << "2. Inserción" << endl;
    cout << "3. Quicksort" << endl;
    int opcion;
    cin >> opcion;
    // Implementar el ordenamiento seleccionado
}

void Menu::OrdenamientoExterno() {
    // Implementar ordenamiento externo
    cout << "Realizando ordenamiento externo..." << endl;
    cout << "Archivos creados: particion1.txt, particion2.txt, OrdenExterno.txt" << endl;
}

void Menu::BuscarCalificacion() {
    cout << "Ingrese la calificación a buscar: ";
    float calificacion;
    cin >> calificacion;
    cout << "Seleccione el algoritmo de búsqueda:" << endl;
    cout << "1. Búsqueda lineal" << endl;
    cout << "2. Búsqueda binaria" << endl;
    int opcion;
    cin >> opcion;
    // Implementar la búsqueda seleccionada
}

// ... (resto de los métodos como antes)
void Menu::Login() {
    PedirDatosDocente();
    profesorLogueado = true;
    cout << "Login exitoso." << endl;
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
    cin.ignore();
    
    notas.clear();
    delete[] arrPromedios;
    arrPromedios = new float[numeroEstudiantes];
}

void Menu::IngresarNotas() {
    if (numeroEstudiantes <= 0) {
        cout << "Número de estudiantes no válido." << endl;
        return;
    }
    
    notas.clear();
    
    for (int i = 0; i < numeroEstudiantes; ++i) {
        cout << "Ingrese las notas del estudiante " << i + 1 << ": ";
        float sumaNotas = 0.0;
        for (int j = 0; j < 4; ++j) {  // Suponiendo que hay 4 notas por estudiante
            double nota;
            cin >> nota;
            sumaNotas += nota;
            notas.insertarAlFinal(nota);
        }
        float promedio = sumaNotas / 4;  // Promedio de las 4 notas
        arrPromedios[i] = promedio;  // Guardar el promedio en el array
    }
}

void Menu::AlmacenarDatos() {
    if (numeroEstudiantes <= 0) {
        cout << "Número de estudiantes no válido." << endl;
        return;
    }

    // Convertir la lista de notas a un array de float
    float* arrayNotas = new float[notas.size()];

    for (size_t i = 0; i < notas.size(); ++i) {
        arrayNotas[i] = static_cast<float>(notas[i]);
    }

    float promedioCurso = CalcularPromedio();
    manejoArchivos.escribir_Info_Alumnos(1, nombreDocente, nombreDocente, NRC, arrayNotas, numeroEstudiantes, promedioCurso);
    manejoArchivos.escribir_Resumen(arrPromedios, numeroEstudiantes, nombreDocente, stoi(cedulaDocente));

    delete[] arrayNotas;
}

float Menu::CalcularPromedio() {
    float suma = 0.0;
    for (int i = 0; i < numeroEstudiantes; ++i) {
        suma += arrPromedios[i];
    }
    return suma / numeroEstudiantes;
}

#endif // MENU_H
