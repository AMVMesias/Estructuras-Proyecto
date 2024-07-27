#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>

using namespace std;

class Estudiante {
private:
    string nombre;
    string apellido;
    int numNotas;
    float *notas;
    string correo;
    float promedio;

public:
    Estudiante(string nombre, string apellid, float *notas_, int numNotas_, string corre, float prome)
        : nombre(nombre), apellido(apellid), numNotas(numNotas_), correo(corre), promedio(prome) {
        notas = new float[numNotas];
        for (int i = 0; i < numNotas; ++i) {
            notas[i] = notas_[i];
        }
    }

    ~Estudiante() {
        delete[] notas;
    }

    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    string getCorreo() const { return correo; }
    float getPromedio() const { return promedio; }

    float* getNotas() const { return notas; }
    int getNumNotas() const { return numNotas; }

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl
             << "Apellido: " << apellido << endl
             << "Correo: " << correo << endl
             << "Promedio: " << promedio << endl;
    }
};

#endif // ESTUDIANTE_H
