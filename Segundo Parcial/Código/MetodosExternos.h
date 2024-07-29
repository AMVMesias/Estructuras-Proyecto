#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace std;

class MetodoExterno {
public:
    MetodoExterno(const string& archivo);
    MetodoExterno();
    ~MetodoExterno();
    
    void setN(int n);
    void ordenarPorDirecta();
    void imprimirInterno(const string& nombre);
    void insertar(float d, const string& nom);
    void limpiar();
    
private:
    void abrir(fstream *f, const string& nom, int modo);
    void cerrar(fstream *f);
    void particiona(int longitud);
    void fusiona(int longitud);
    
    string nombreArchivo{"ordenada.txt"}; //Por default
    int N;
};
