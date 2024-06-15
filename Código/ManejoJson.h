#ifndef MANEJOJSON_H
#define MANEJOJSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

const string carpetaUsuarios = "Usuarios"; 

bool usuarioExiste(const string& ci) {
    string nombreArchivo = carpetaUsuarios + "/usuario_" + ci + ".json";
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

void crearNuevoUsuario_BBD(int ci, const string& contrasena, const string& nombres) {
    string ci_str = to_string(ci);

    if (usuarioExiste(ci_str)) {
        cout << "Error: El usuario con CI '" << ci_str << "' ya existe." << endl;
        return;
    }

    string nombreArchivo = carpetaUsuarios + "/usuario_" + ci_str + ".json";

    json j;
    j["ci"] = ci_str;
    j["contrasena"] = contrasena;
    j["nombres"] = nombres;

    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        archivo << j.dump(4);
        archivo.close();
        cout << "Usuario creado exitosamente: " << nombres << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escribir: " << nombreArchivo << endl;
    }
}


#endif 
