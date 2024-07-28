#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "ValidacionCedula.h"
#include "Lista.h"
#include "ManejoArchivos.cpp"
#include "IngresoDatos.h"

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
    IngresoDatos crearUsuario;
    int numeroEstudiantes;
    Lista<double> notas;
    Lista<Estudiante>estudiantes;
    int numNotas;
    Profesor profesor;
    
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
    void guardar_informacion();
    float* IngresarNotas();
    void AlmacenarDatos();
    void OrdenarNotas();
    void OrdenamientoExterno();
    void BuscarCalificacion();
    float CalcularPromedio();
    float CalcularPromedio(float*);
};

Menu::Menu() : profesorLogueado(false), materiaIngresada(false), estudiantesIngresados(false), 
               notasIngresadas(false), datosAlmacenados(false), numeroEstudiantes(0), arrPromedios(nullptr) {}

void Menu::MostrarMenuPrincipal() {
    int opcion;
        cout << "           ~ INICIO DE SESION   ~            " << endl;
        //if (!profesorLogueado) {
            cout << "1. Registro de docente" << endl;
            Login();
        
    do {          
    
        cout << "           ~  Menu Principal   ~             " << endl;
        /*if (!materiaIngresada) {
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
        }*/
        cout << "1. Registro de materia y NRC" << endl;
        cout << "2. Registro de número de estudiantes y numero de notas" << endl;
        cout << "3. Ingresar las notas por cada estudiante" << endl;
        cout << "4. Submenu de ordenamientos" << endl;
        cout << "5. Submenu de Busqueda" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                /*if (!profesorLogueado) Login();
                else cout << "Ya ha iniciado sesión." << endl;*/
                PedirMateriaNRC();
                //añadir al array de materias, validar que no sea duplicado
                break;
            case 2:
                /*if (profesorLogueado && !materiaIngresada) {
                    PedirMateriaNRC();
                    materiaIngresada = true;
                }
                else cout << "No puede realizar esta acción ahora." << endl;*/
                    PedirNumeroEstudiantes();
                    estudiantesIngresados = true;
                break;
            case 3:
                if (!estudiantesIngresados) {
					guardar_informacion();
                }
                else cout << "No puede realizar esta acción ahora." << endl;
                
                break;
            case 4:
                /*if (estudiantesIngresados && !notasIngresadas) {
                    IngresarNotas();
                    notasIngresadas = true;
                }
                else cout << "No puede realizar esta acción ahora." << endl;*/
                AlmacenarDatos();
                break;
            case 5:
                /*if (notasIngresadas && !datosAlmacenados) {
                    AlmacenarDatos();
                    datosAlmacenados = true;
                    cout << "El archivo fue creado o modificado exitosamente." << endl;
                }
                else cout << "No puede realizar esta acción ahora." << endl;*/
                OrdenarNotas();
                
                break;
            case 6:
            	BuscarCalificacion();
                /*if (datosAlmacenados) OrdenarNotas();
                else cout << "Debe almacenar los datos primero." << endl;*/
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
    /*cout << "Seleccione el tipo de ordenamiento:" << endl;
    cout << "1. Burbuja" << endl;
    cout << "2. Inserción" << endl;
    cout << "3. Quicksort" << endl;
    int opcion;
    cin >> opcion;
    // Implementar el ordenamiento seleccionado*/
    string ordenamiento="";
    int opcion;

    do {
        cout << "        ~ Submenú de Ordenamiento ~         " << endl;
        cout << ">> 1. BuckertSort" << endl;
        cout << ">> 2. QuickSort" << endl;
        cout << ">> 3. ShellSort" << endl;
        cout << ">> 4. RadixSort" << endl;
        cout << ">> 5. Métodos Externos " << endl;
        cout << ">> 0. Volver al menú principal" << endl;

        cout << "Seleccione una opción de ordenamiento: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
        	ordenamiento=" BuckertSort ";
            //
            break;
        case 2:
        	ordenamiento=" QuickSort";
            //
            break;
        case 3:
        	ordenamiento=" ShellSort";
            //
            break;
        case 4:
        	ordenamiento=" RadixSort";
            //
            break;
        case 5:
        	ordenamiento=" Métodos Externos";
        	//
        	break;
        case 0:
            // Opción para volver al menú principal
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcion != 0);  // Repetir mientras la opción no sea 0
    manejoArchivos.escribir_ResumenOrdenamiento(ordenamiento,estudiantes,profesor);
}

void Menu::OrdenamientoExterno() {
    // Implementar ordenamiento externo
    cout << "Realizando ordenamiento externo..." << endl;
    cout << "Archivos creados: particion1.txt, particion2.txt, OrdenExterno.txt" << endl;
}

void Menu::BuscarCalificacion(){
    /*cout << "Ingrese la calificación a buscar: ";
    float calificacion;
    cin >> calificacion;
    cout << "Seleccione el algoritmo de búsqueda:" << endl;
    cout << "1. Búsqueda lineal" << endl;
    cout << "2. Búsqueda binaria" << endl;
    int opcion;
    cin >> opcion;
    // Implementar la búsqueda seleccionada*/
    
    int opcion;

    do {
        cout << "         ~ Submenú de Búsqueda ~              " << endl;
        cout << ">> 1. Búsqueda Binaria" << endl;
        cout << ">> 2. Busqueda Hash" << endl;
        cout << ">> 0. Volver al menú principal" << endl;

        cout << "Seleccione una opción de búsqueda: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            //Busqueda Binaria
        {
            cout << "               ~ BUSQUEDA BINARIA ~            " << endl;   

            //aqui va el codigo en Binaria
            break;
        }
        case 3: {
            cout << "               ~ BUSQUEDA HASH ~               " << endl;
			//aqui va el codigo hash 
            break;
        }
        case 0:
            // Volver al menú principal
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
        }
    } while (opcion != 0);  // Repetir mientras la opción no sea 0
}

// ... (resto de los métodos como antes)
/*void Menu::Login() {
    PedirDatosDocente();
    profesorLogueado = true;
    cout << "Login exitoso." << endl;
}*/
void Menu::Login() {
    /*cout << "Ingrese el nombre del docente: ";
    cin.ignore();
    nombreDocente=crearUsuario.leerLetras();
    
    long long int cedula;
    do {
        cedula = crearUsuario.IngresoEnteros("Ingrese la cedula del docente: ");
        //cedula = validar(cedula);
    } while (cedula == 0);
    
    cedulaDocente = to_string(cedula);*/
    profesor.leerDatosProfesor();
    profesorLogueado = true;
}

void Menu::PedirMateriaNRC() {
    cout << "Ingrese la materia: ";
    cin.ignore();
    materia= crearUsuario.leerLetras();
    //cout << "Ingrese el NRC: ";
    NRC=std::to_string(crearUsuario.IngresoEnteros("Ingrese el NRC:"));
}

void Menu::PedirNumeroEstudiantes() {
    cout << "Ingrese el numero de estudiantes: "<<endl;
    numeroEstudiantes=crearUsuario.IngresoEnteros("Numero alumnos: ");
    cin.ignore();
    
    notas.clear();
    delete[] arrPromedios;
    arrPromedios = new float[numeroEstudiantes];
}

void Menu::guardar_informacion(){
	string nombre,apellido,cedula;
	float *notas_= new float(this->numNotas);
	float prom=0;
	for(int i=0; i< this->numeroEstudiantes;i++){
		cout<<"Registre: "<<endl;
		cout<<"Nombre: ";
		nombre=this->crearUsuario.leerLetras();
		cout<<"Apellido: ";
		apellido=this->crearUsuario.leerLetras();
		//puedo poner que ingrese su correo
		notas_=IngresarNotas();
        //arrPromedios[i] = promedio;
        prom=this->CalcularPromedio(notas_);
        Estudiante estudiante(nombre,apellido,notas_,"generar_correo",prom);
	}
}


float* Menu::IngresarNotas() {
	float *notas=new float(this->numNotas);
	float suma=0;
    /*if (numeroEstudiantes <= 0) {
        cout << "Número de estudiantes no válido." << endl;
        return ;
    }
    
    notas.clear();*/
    
    /*for (int i = 0; i < numeroEstudiantes; ++i) {
        cout << "Ingrese las notas del estudiante " << i + 1 << ": ";
        float sumaNotas = 0.0;
        for (int j = 0; j < 4; ++j) {  // Suponiendo que hay 4 notas por estudiante
            double nota;
            cin >> nota;
            sumaNotas += nota;
            notas.insertarAlFinal(nota);
        }
        float promedio = sumaNotas / 4;  // Promedio de las 4 notas
        arrPromedios[i] = promedio;  // Guardar el promedio en el array*/
        for(int i=0; i<this->numNotas; i++){
        cout<<"Nota "<<i+1<<" : ";
        notas[i]=this->crearUsuario.leerFlotantes();
        //suma=suma+notas[i];
		}
		
    //}
    return notas;
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
    manejoArchivos.crear_Reporte_notas(this->materia,this->NRC,this->numNotas,this->estudiantes,this->profesor);
    //manejoArchivos.escribir_Info_Alumnos(1, nombreDocente, nombreDocente, NRC, arrayNotas, numeroEstudiantes, promedioCurso);
    //manejoArchivos.escribir_Resumen(arrPromedios, numeroEstudiantes, nombreDocente, stoi(cedulaDocente));

    delete[] arrayNotas;
}

float Menu::CalcularPromedio() {
    float suma = 0.0;
    for (int i = 0; i < numeroEstudiantes; ++i) {
        suma += arrPromedios[i];
    }
    return suma / numeroEstudiantes;
}

float Menu::CalcularPromedio(float* n){
	    float suma = 0.0;
    for (int i = 0; i < this->numNotas; ++i) {
        suma += n[i];
    }
    return suma / numNotas;
}

#endif // MENU_H
