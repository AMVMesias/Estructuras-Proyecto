#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "ValidacionCedula.h"
#include "Lista.h"
#include "ManejoArchivos.cpp"
#include "IngresoDatos.h"
#include "Materia.h"
#include "busquedaBinaria.h"
#include "TablaHash.h"

using namespace std;
long long int validar(long long int &x);

class Menu {
public:
    Menu();
    void MostrarMenuPrincipal();
	void MostrarMenuInicioSesion();

private:
    int numNotas;
    int numeroEstudiantes;
    TablaHash<float, Estudiante> tablaHash; 
    ManejoArchivos manejoArchivos;
    string nombreDocente;
    string cedulaDocente;
    string materia;
    string NRC;
    IngresoDatos crearUsuario;
    Lista<double> notas;
    Lista<Estudiante>estudiantes;
    Profesor profesor;
    Materia materia1;
    
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

void Menu::MostrarMenuInicioSesion() {
    int opcion;
    cout << "           ~ INICIO DE SESION   ~            " << endl;
    if (!profesorLogueado) {
        cout << "1. Registro de docente" << endl;
        Login();
    }
    MostrarMenuPrincipal();
}

void Menu::MostrarMenuPrincipal() {
    int opcion;	    
    do {
        system("cls");         
    
        cout << "           ~  Menu Principal   ~             " << endl;
        cout << "1. Registro de materia y NRC" << endl;
        cout << "2. Registro de número de estudiantes y numero de notas" << endl;
        cout << "3. Ingresar las notas por cada estudiante" << endl;
        cout << "4. Almacenar datos" << endl;
        cout << "5. Ordenar notas" << endl;
        cout << "6. Buscar calificación" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                PedirMateriaNRC();
                system("pause");
                break;
            case 2:
                PedirNumeroEstudiantes();
                system("pause");
                break;
            case 3:
                if (estudiantesIngresados) {
                    guardar_informacion();
                } else {
                    cout << "No puede realizar esta acción ahora." << endl;
                }
                system("pause");
                break;
            case 4:
                AlmacenarDatos();
                system("pause");
                break;
            case 5:
                OrdenarNotas();
                system("pause");
                break;
            case 6:
                BuscarCalificacion();
                system("pause");
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                system("pause");
                break;
            default:
                cout << "Opción inválida, por favor intente nuevamente." << endl;
                system("pause");
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
		system("cls");

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
			system("pause");
            //
            break;
        case 2:
        	ordenamiento=" QuickSort";
        	system("pause");
            //
            break;
        case 3:
        	ordenamiento=" ShellSort";
        	system("pause");
            //
            break;
        case 4:
        	ordenamiento=" RadixSort";
        	system("pause");
            //
            break;
        case 5:
        	ordenamiento=" Métodos Externos";
        	system("pause");
        	//
        	break;
        case 0:
			MostrarMenuPrincipal();
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            system("pause");
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
    	system("cls");
        cout << "         ~ Submenú de Búsqueda ~              " << endl;
        cout << ">> 1. Búsqueda Binaria" << endl;
        cout << ">> 2. Busqueda Hash" << endl;
        cout << ">> 0. Volver al menú principal" << endl;

        cout << "Seleccione una opción de búsqueda: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "               ~ BUSQUEDA BINARIA ~            " << endl;
            cout << "Ingrese el promedio a buscar: ";
   
			float promedioBuscado;
			cin >> promedioBuscado;
			busquedaBinaria(estudiantes, promedioBuscado);
			system("pause");
            break;
        }
        case 2: {
		   
		    int opcionBusqueda;
		    cout << "               ~ BUSQUEDA HASH ~               " << endl;
		    cout << "Seleccione el criterio de busqueda:\n";
		    cout << "1. Buscar por promedio\n";
		    cout << "2. Buscar por nombre\n";
		    cout << "Opcion: ";
		    cin >> opcionBusqueda;
		
		    if (opcionBusqueda == 1) {
		        float promedioBuscado;
		        cout << "Ingrese el promedio a buscar: ";
		        cin >> promedioBuscado;
		        try {
		            tablaHash.buscarPorPromedio(promedioBuscado);
		        } catch (const runtime_error& e) {
		            cout << e.what() << endl;
		        }
		    } else if (opcionBusqueda == 2) {
		        string nombreBuscado;
		        cout << "Ingrese el nombre a buscar: ";
		        cin.ignore(); // Para ignorar el carácter de nueva línea pendiente
		        getline(cin, nombreBuscado);
		        try {
		            tablaHash.buscarPorNombre(nombreBuscado);
		        } catch (const runtime_error& e) {
		            cout << e.what() << endl;
		        }
		    } else {
		        cout << "Opcion no valida. Intente de nuevo." << endl;
		    }
		
		    system("pause");
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
	this->profesor.registrarMateria();
}

void Menu::PedirNumeroEstudiantes() {
    cout << "Ingrese el numero de estudiantes: "<<endl;
    numeroEstudiantes=crearUsuario.IngresoEnteros("Numero alumnos: ");
    cout << "Ingrese el numero de notas a registrar: "<<endl;
    this->numNotas=crearUsuario.IngresoEnteros("Numero notas: ");
    notas.clear();
    delete[] arrPromedios;
    arrPromedios = new float[numeroEstudiantes];
    estudiantesIngresados = true;

}

void Menu::guardar_informacion(){
	string nombre,apellido,cedula;
	float *notas_= new float(this->numNotas);
	float prom=0;
	materia1=profesor.seleccionarMateria();
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
        this->estudiantes.insertarAlFinal(estudiante);
        this->tablaHash.insertar(prom, estudiante); // Insertar en la tabla hash

	}
}


float* Menu::IngresarNotas() {
	float *notas=new float(this->numNotas);
	float suma=0;
	float val=0;
        for(int i=0; i<this->numNotas; i++){
        cout<<"Nota "<<i+1<<" : ";
        //val=this->crearUsuario.leerFlotantes();
        cin>>val;
        while(val>20 || val< 0){
        	cout<<" Fuera de rango, admite valores entre 1-20"<<endl;
        	//val=this->crearUsuario.leerFlotantes();
        	cout<<"Nota "<<i+1<<" : ";
        	cin>>val;
		}
			notas[i]=val;
		}
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
    manejoArchivos.crear_Reporte_notas(this->materia1.getNombre(),this->materia1.getCodigo(),this->numNotas,this->estudiantes,this->profesor);
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
