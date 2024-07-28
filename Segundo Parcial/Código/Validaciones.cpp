#include "Validaciones.h"

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <ios>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;
int Validaciones::ingresar_enteros(const char* msj) {
    char* datos = new char[10];
	    char c;
	    int i = 0;
	
	    while (true) {
	        i = 0;
	        printf("%s", msj);
	        printf("\n");
	
	        while ((c = getch()) != 13 && i < 9) {
	            if ((c >= '0' && c <= '9') || c == 8) {
	                if (c == 8) {
	                    i = borrar(datos, i);
	                } else {
	                    printf("%c", c);
	                    datos[i++] = c;
	                }
	            }
	        }
	        datos[i] = '\0';
	
	        if (i > 0) {
	            return atoi(datos);
	        } else {
	            printf("\nEntrada no v�lida. Por favor, ingrese un n�mero.\n");
	        }
	    }
	}

float Validaciones::ingresar_reales(const char* msj) {
    char* datos = new char[12];
    char c;
    int i = 0;
    bool hay_punto = false;
    int posicion_punto;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 11) {
        if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto)|| c == 8 || c == '-') {
            if(!((c == '.')&& i == 0)){
                if(!((c == '-') && i != 0)){
                    if (c == 8) {
                        i = borrar(datos, i);
                        if((i+1) == posicion_punto){
                            hay_punto = false;
                        }
                    }
                    else {
                        printf("%c", c);
                        datos[i++] = c;

                        if (c == '.') {
                            posicion_punto = i;
                            hay_punto = true;
                        }
                    }
                }
            }
        }
    }
    datos[i] = '\0';
    return atof(datos);
}

int Validaciones:: ingresar_diaMes(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf(" - ");
    while ((c = getch()) != 13 && i < 2) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}
int Validaciones:: ingresar_anio(const char* msj) {
    char* datos = new char[10];
    char c;
    int i = 0;

    printf("%s", msj);
    printf(" - ");
    while ((c = getch()) != 13 && i < 4) {
        if ((c >= '0' && c <= '9')|| c == 8) {
            if(c == 8){
                i = borrar(datos,i);
            }else{
                printf("%c", c);
                datos[i++] = c;
            }

        }
    }
    datos[i] = '\0';
    return atoi(datos);
}
std::string Validaciones::ingresar_alfabetico(const char* msj) {
    char datos[21];
    char c;
    int i = 0;

    printf("%s", msj);
    printf("\n");

    while ((c = getch()) != 13 && i < 20) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| c == 32||c == 8) {
            if (c == 8) {
                i = borrar(datos, i);
            } else {
                printf("%c", c);
                datos[i++] = c;
            }
        }
    }
    datos[i] = '\0';
    return std::string(datos);
}


int Validaciones::borrar(char* datos, int& i) {
    if (i > 0) {
        printf("\b \b");
        i--;
        datos[i] = '\0';
        return i;
    }
    return 0;
}

 std::string Validaciones::ingresar_numeros_como_string(const char* msj) {
  std::string datos = "";
  char c;

  printf("%s", msj);
  printf("\n");

  while ((c = getch()) != 13 && datos.length() < 10) {
    if ((c >= '0' && c <= '9') || c == 8) {
      if (c == 8) {
        // Borrar �ltimo caracter si la entrada es retroceso
        if (!datos.empty()) {
          datos.pop_back();
          cout << "\b \b";  // Mover el cursor y borrar visualmente
        }
      } else {
        cout << c;  // Mostrar el caracter ingresado
        datos += c;  // A�adir al string
      }
    }
  }

  return datos;
}

bool Validaciones::validarCedula(std::string cedula) {
    // Verificar que tenga 10 d�gitos
    if (cedula.length() != 10) {
        return false;
    }
    // Verificar que los primeros dos d�gitos sean v�lidos (provincia)
    int provincia = std::stoi(cedula.substr(0, 2));
    if (provincia < 1 || provincia > 24) {
        return false;
    }
    // Verificar que los d�gitos intermedios sean v�lidos
    for (int i = 2; i < 9; i++) {
        if (cedula[i] < '0' || cedula[i] > '9') {
            return false;
        }
    }
    // Verificar que el �ltimo d�gito sea v�lido
    if (cedula[9] < '0' || cedula[9] > '9') {
        return false;
    }

    // Verificar el d�gito verificador
    int suma = 0;
    for (int i = 0; i < 9; i++) {
        int digito = cedula[i] - '0';
        if (i % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito -= 9;
            }
        }
        suma += digito;
    }
    int digitoVerificador = (suma % 10 == 0) ? 0 : 10 - (suma % 10);

    return digitoVerificador == (cedula[9] - '0');
}

std::string Validaciones::ingresar_alfabetico_con_un_espacio(const char* msj) {
  char datos[21];
  char c;
  int i = 0;
  bool espacio_ingresado = false;

  printf("%s", msj);
  printf("\n");

  while ((c = getch()) != 13 && i < 20) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 32 || c == 8) {
      if (c == 8) {
        i = borrar(datos, i);
        espacio_ingresado = false; // Reiniciar la bandera si se borra un car�cter
      } else if (c == 32 && !espacio_ingresado) {
        printf("%c", c);
        datos[i++] = c;
        espacio_ingresado = true;
      } else if (c != 32) {
        printf("%c", c);
        datos[i++] = c;
      }
    }
  }
  datos[i] = '\0';
  return std::string(datos);
}
std::string Validaciones::mayusculas_primeras(const std::string& cadena) {
  std::string resultado;

  for (int i = 0; i < cadena.size(); i++) {
    if (i == 0 || cadena[i - 1] == ' ') {
      resultado += toupper(cadena[i]);
    } else {
      resultado += tolower(cadena[i]);
    }
  }

  return resultado;
}

 std::string Validaciones::leerArchivoTxt()  {
        std:: string texto;
         std::string lectura;
      std::ifstream archivo;
       archivo.open("Personas.txt", std::ios::in);

        if (archivo.fail())
        {
             std:: cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }

std::string Validaciones::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first) {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

 std::string Validaciones::leerArchivoTxtCuenta()  {
        std:: string texto;
         std::string lectura;
      std::ifstream archivo;
       archivo.open("Usuarios.txt", std::ios::in);

        if (archivo.fail())
        {
             std:: cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof())
        {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }
