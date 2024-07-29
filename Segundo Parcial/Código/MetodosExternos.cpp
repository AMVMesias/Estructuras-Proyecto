#include "MetodosExternos.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>

MetodoExterno::MetodoExterno(const string& archivo) : nombreArchivo(archivo), N(0) {}

MetodoExterno::MetodoExterno() : N(0) {}

MetodoExterno::~MetodoExterno() {}

void MetodoExterno::setN(int n) {
    N = n;
}

void MetodoExterno::abrir(fstream *f, const string& nom, int modo) {
    ios_base::openmode mode = ios::in;
    if (modo == 2) {
        mode = ios::out | ios::app;
    } else if (modo == 3) {
        mode = ios::out;
    }

    f->open(nom, mode);
    if (!f->is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nom);
    }
}

void MetodoExterno::cerrar(fstream *f) {
    f->close();
}

void MetodoExterno::limpiar() {
    fstream F1, F2;
    abrir(&F1, "Particion1.txt", 3);
    abrir(&F2, "Particion2.txt", 3);
    cerrar(&F1);
    cerrar(&F2);
}

void MetodoExterno::ordenarPorDirecta() {
    limpiar();
    int longitud = 1;
    while (longitud < N) {
        particiona(longitud);
        fusiona(longitud);
        longitud *= 2;
    }
}

void MetodoExterno::particiona(int longitud) {
    fstream F, F1, F2;
    float con1, con2, dato;
    abrir(&F, nombreArchivo, 1);
    abrir(&F1, "Particion1.txt", 3);
    abrir(&F2, "Particion2.txt", 3);

    while (!F.eof()) {
        con1 = 0;
        while (con1 < longitud && !F.eof()) {
            F >> dato;
            if (!F.eof())
                F1 << dato << " ";
            con1++;
        }
        con2 = 0;
        while (con2 < longitud && !F.eof()) {
            F >> dato;
            if (!F.eof())
                F2 << dato << " ";
            con2++;
        }
    }

    cerrar(&F);
    cerrar(&F1);
    cerrar(&F2);
}

void MetodoExterno::fusiona(int longitud) {
    fstream F, F1, F2;
    float con1, con2, dato1, dato2;
    bool ban1, ban2;
    abrir(&F, nombreArchivo, 3);
    abrir(&F1, "Particion1.txt", 1);
    abrir(&F2, "Particion2.txt", 1);
    ban1 = ban2 = true;
    if (!F1.eof()) {
        F1 >> dato1;
        ban1 = false;
    }
    if (!F2.eof()) {
        F2 >> dato2;
        ban2 = false;
    }

    while ((!F1.eof() || ban1 == false) && (!F2.eof() || ban2 == false)) {
        con1 = con2 = 0;
        while ((con1 < longitud && ban1 == false) && (con2 < longitud && ban2 == false)) {
            if (dato1 <= dato2) {
                ban1 = true;
                con1++;
                if (!F1.eof()) {
                    F << dato1 << " "; 
                    F1 >> dato1;
                    ban1 = false;
                }
            } else {
                ban2 = true;
                con2++;
                if (!F2.eof()) {
                    F << dato2 << " "; 
                    F2 >> dato2;
                    ban2 = false;
                }
            }
        } 
        if (con1 < longitud) {
            while (con1 < longitud && ban1 == false) {
                ban1 = true;
                con1++;
                if (!F1.eof()) {
                    F << dato1 << " "; 
                    F1 >> dato1;
                    ban1 = false;
                }
            }
        }
        if (con2 < longitud) {
            while (con2 < longitud && ban2 == false) {
                ban2 = true;
                con2++;
                if (!F2.eof()) {
                    F << dato2 << " "; 
                    F2 >> dato2;
                    ban2 = false;
                }
            }
        }
    } 
    while (!F1.eof()) {
        F1 >> dato1;
        if (!F1.eof())
            F << dato1 << " ";
    }
    while (!F2.eof()) {
        F2 >> dato2;
        if (!F2.eof())
            F << dato2 << " ";
    }
    cerrar(&F);
    cerrar(&F1);
    cerrar(&F2);
}

void MetodoExterno::imprimirInterno(const string& nombre) {
    fstream archivo;
    abrir(&archivo, nombre, 1);

    float numero;
    while (archivo >> numero) {
        cout << numero << " ";
    }
    cout << endl;

    cerrar(&archivo);
}

void MetodoExterno::insertar(float d, const string& nom) {
    d = floor(d * 100) / 100;  // Redondeo a dos decimales
    fstream archivo;
    abrir(&archivo, nom, 2);

    archivo << d << " ";

    cerrar(&archivo);
    N++;
}
