#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include "windows.h"



class Validaciones {
public:
    int ingresar_enteros(const char* msj) {
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
                int resultado = atoi(datos);
                delete[] datos;
                return resultado;
            } else {
                printf("\nEntrada no válida. Por favor, ingrese un número.\n");
            }
        }
    }

    float ingresar_reales(const char* msj) {
        char* datos = new char[12];
        char c;
        int i = 0;
        bool hay_punto = false;
        int posicion_punto;

        printf("%s", msj);
        printf("\n");

        while ((c = getch()) != 13 && i < 11) {
            if ((c >= '0' && c <= '9') || (c == '.' && !hay_punto) || c == 8 || c == '-') {
                if (!((c == '.') && i == 0)) {
                    if (!((c == '-') && i != 0)) {
                        if (c == 8) {
                            i = borrar(datos, i);
                            if ((i + 1) == posicion_punto) {
                                hay_punto = false;
                            }
                        } else {
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
        float resultado = atof(datos);
        delete[] datos;
        return resultado;
    }

    int ingresar_diaMes(const char* msj) {
        char* datos = new char[10];
        char c;
        int i = 0;

        printf("%s", msj);
        printf(" - ");
        while ((c = getch()) != 13 && i < 2) {
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
        int resultado = atoi(datos);
        delete[] datos;
        return resultado;
    }

    int ingresar_anio(const char* msj) {
        char* datos = new char[10];
        char c;
        int i = 0;

        printf("%s", msj);
        printf(" - ");
        while ((c = getch()) != 13 && i < 4) {
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
        int resultado = atoi(datos);
        delete[] datos;
        return resultado;
    }

    std::string ingresar_alfabetico(const char* msj) {
        char datos[21];
        char c;
        int i = 0;

        printf("%s", msj);
        printf("\n");

        while ((c = getch()) != 13 && i < 20) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == 32 || c == 8) {
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

    int borrar(char* datos, int& i) {
        if (i > 0) {
            printf("\b \b");
            i--;
            datos[i] = '\0';
            return i;
        }
        return 0;
    }

    std::string ingresar_numeros_como_string(const char* msj) {
        std::string datos = "";
        char c;

        printf("%s", msj);
        printf("\n");

        while ((c = getch()) != 13 && datos.length() < 10) {
            if ((c >= '0' && c <= '9') || c == 8) {
                if (c == 8) {
                    if (!datos.empty()) {
                        datos.pop_back();
                        std::cout << "\b \b";
                    }
                } else {
                    std::cout << c;
                    datos += c;
                }
            }
        }
        return datos;
    }

    bool validarCedula(std::string cedula) {
        if (cedula.length() != 10) {
            return false;
        }

        int provincia = std::stoi(cedula.substr(0, 2));
        if (provincia < 1 || provincia > 24) {
            return false;
        }

        for (int i = 2; i < 9; i++) {
            if (cedula[i] < '0' || cedula[i] > '9') {
                return false;
            }
        }

        if (cedula[9] < '0' || cedula[9] > '9') {
            return false;
        }

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

    std::string ingresar_alfabetico_con_un_espacio(const char* msj) {
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
                    espacio_ingresado = false;
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

    std::string mayusculas_primeras(const std::string& cadena) {
        std::string resultado;

        for (size_t i = 0; i < cadena.size(); i++) {
            if (i == 0 || cadena[i - 1] == ' ') {
                resultado += toupper(cadena[i]);
            } else {
                resultado += tolower(cadena[i]);
            }
        }

        return resultado;
    }

    std::string leerArchivoTxt() {
        std::string texto;
        std::string lectura;
        std::ifstream archivo("Personas.txt", std::ios::in);

        if (archivo.fail()) {
            std::cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof()) {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }

    std::string trim(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        if (std::string::npos == first) {
            return str;
        }
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    std::string leerArchivoTxtCuenta() {
        std::string texto;
        std::string lectura;
        std::ifstream archivo("Usuarios.txt", std::ios::in);

        if (archivo.fail()) {
            std::cout << "No se pudo abrir el archivo";
            exit(1);
        }
        while (!archivo.eof()) {
            getline(archivo, texto, ' ');
            lectura += texto + " ";
        }
        archivo.close();
        return lectura;
    }

    

    bool buscar_cedula_en_archivo(const std::string& nombre_archivo, const std::string& cedula) {
        std::ifstream archivo(nombre_archivo);
        if (!archivo.is_open()) {
            return false;
        }

        std::string linea;
        while (getline(archivo, linea)) {
            if (linea.find(cedula) != std::string::npos) {
                archivo.close();
                return true;
            }
        }

        archivo.close();
        return false;
    }

    int leerArchivoBinarioCedula(const std::string& cedula) {
        std::ifstream archivo("Personas.dat", std::ios::binary);

        if (archivo.fail()) {
            std::cout << "No se pudo abrir el archivo";
            return -1;
        }
        std::string cedula_archivo;
        while (archivo.read(reinterpret_cast<char*>(&cedula_archivo), sizeof(cedula_archivo))) {
            if (cedula_archivo == cedula) {
                return 1; // La cédula fue encontrada en el archivo
            }
        }
        archivo.close();
        return 0; // La cédula no fue encontrada en el archivo
    }
};

#endif // VALIDACIONES_H
