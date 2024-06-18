#ifndef MANEJOJSON_H
#define MANEJOJSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include "nlohmann/json.hpp"
#include "Lista.h"
#include "Estudiante.h"
#include "Producto.h"

using namespace std;
using json = nlohmann::json;

const string CARPETA_USUARIOS = "Usuarios"; 
const string CARPETA_PRODUCTOS = "Productos";  

bool estudianteExiste(int usuario) {
    string nombreArchivo = CARPETA_USUARIOS + "/usuario_" + to_string(usuario) + ".json";
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

void crearNuevoUsuario_BBD(int usuario, const string& contrasenia, const string& nombre) {
    if (estudianteExiste(usuario)) {
        cout << "Error: El estudiante con usuario '" << usuario << "' ya existe." << endl;
        return;
    }

    string nombreArchivo = CARPETA_USUARIOS + "/usuario_" + to_string(usuario) + ".json";

    json j;
    j["ci"] = usuario;
    j["contrasena"] = contrasenia;
    j["nombres"] = nombre;

    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << j.dump(4);
        archivo.close();
        cout << "Estudiante creado exitosamente: " << nombre << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escribir: " << nombreArchivo << endl;
    }
}

void cargarEstudiantes(Lista<Estudiante>& listaEstudiantes) {
    DIR* dir;
    struct dirent* ent;

    if ((dir = opendir(CARPETA_USUARIOS.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            string nombreArchivo = ent->d_name;
            if (nombreArchivo.find(".json") != string::npos) {
                string rutaArchivo = CARPETA_USUARIOS + "/" + nombreArchivo;
                ifstream archivo(rutaArchivo);
                if (archivo.is_open()) {
                    json j;
                    try {
                        archivo >> j;
                        archivo.close();

                        if (j.contains("ci") && j["ci"].is_number_integer() &&
                            j.contains("contrasena") && j["contrasena"].is_string() &&
                            j.contains("nombres") && j["nombres"].is_string()) {

                            Estudiante estudiante(
                                j["nombres"].get<string>(),
                                j["ci"].get<int>(),
                                j["contrasena"].get<string>()
                            );

                            listaEstudiantes.insertarAlFinal(estudiante);
                        } else {
                            cerr << "El archivo " << rutaArchivo << " no contiene los campos necesarios o algunos tienen tipos incorrectos." << endl;
                        }
                    } catch (const json::parse_error& e) {
                        cerr << "Error de parseo en el archivo JSON " << rutaArchivo << ": " << e.what() << endl;
                    } catch (const json::type_error& e) {
                        cerr << "Error de tipo en el archivo JSON " << rutaArchivo << ": " << e.what() << endl;
                    } catch (const std::exception& e) {
                        cerr << "Error al procesar el archivo JSON " << rutaArchivo << ": " << e.what() << endl;
                    }
                } else {
                    cerr << "No se pudo abrir el archivo: " << rutaArchivo << endl;
                }
            }
        }
        closedir(dir);
    } else {
        cerr << "No se pudo abrir el directorio: " << CARPETA_USUARIOS << endl;
    }
}


bool productoExiste(int id) {
    string nombreArchivo = CARPETA_PRODUCTOS + "/producto_" + to_string(id) + ".json";
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

void crearNuevoProducto(int id, const string& descripcion, float precio, int cantidad) {
    if (productoExiste(id)) {
        cout << "Error: El producto con ID '" << id << "' ya existe." << endl;
        return;
    }

    string nombreArchivo = CARPETA_PRODUCTOS + "/producto_" + to_string(id) + ".json";

    json j;
    j["id"] = id;
    j["descripcion"] = descripcion;
    j["precio"] = precio;
    j["cantidad"] = cantidad;

    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << j.dump(4);
        archivo.close();
        cout << "Producto creado exitosamente: " << descripcion << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escribir: " << nombreArchivo << endl;
    }
}






#endif 
