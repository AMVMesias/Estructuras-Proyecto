#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <cstdlib>


template <typename T>
void intercambiar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Ordenamiento {
public:
    virtual void ordenar(T a[], int n) = 0;
};

template <typename T>
T encontrarMaximo(T a[], int n) {
    T max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

template<typename T>
class QuickSort : public Ordenamiento<T> {
private:
    void quickSort(T a[], int primero, int ultimo) {
        if (primero < ultimo) {
            int i = primero, j = ultimo;
            T pivote = a[(primero + ultimo) / 2];
            while (i <= j) {
                while (a[i] < pivote) i++;
                while (a[j] > pivote) j--;
                if (i <= j) {
                    intercambiar(a[i], a[j]);
                    i++;
                    j--;
                }
            }
            if (primero < j)
                quickSort(a, primero, j);
            if (i < ultimo)
                quickSort(a, i, ultimo);
        }
    }

public:
    void ordenar(T a[], int n) override {
        quickSort(a, 0, n - 1);
    }
};

template <typename T>
class ShellSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        int salto = n / 2;
        while (salto > 0) {
            for (int i = salto; i < n; i++) {
                int j = i - salto;
                while (j >= 0) {
                    int k = j + salto;
                    if (a[j] <= a[k]) {
                        j = -1;
                    } else {
                        intercambiar(a[j], a[k]);
                        j -= salto;
                    }
                }
            }
            salto /= 2;
        }
    }
};

/*template <typename T>
class BucketSort : public Ordenamiento<T> {
private:
    struct Nodo {
        T valor;
        Nodo* siguiente;
        Nodo(T v) : valor(v), siguiente(nullptr) {}
    };

    void agregarEnUrna(Nodo*& urna, T valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!urna) {
            urna = nuevoNodo;
        } else {
            Nodo* temp = urna;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    bool esVacia(Nodo* urna) {
        return urna == nullptr;
    }

    Nodo* encontrarSiguiente(Nodo* actual) {
        return actual ? actual->siguiente : nullptr;
    }

    void combinarUrnas(Nodo* urnas[], int n, T a[]) {
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            Nodo* dir = urnas[i];
            while (dir) {
                a[pos++] = dir->valor;
                Nodo* temp = dir;
                dir = encontrarSiguiente(dir);
                delete temp;
            }
        }
    }

    T encontrarMaximo(T a[], int n) {
        T max = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        return max;
    }

public:
    void ordenar(T a[], int n) override {
        if (n <= 0) return;

        // Encontrar el máximo valor para determinar el número de urnas
        T max = encontrarMaximo(a, n);
        int numUrnas = max + 1;

        // Crear urnas
        Nodo** urnas = new Nodo*[numUrnas];
        for (int i = 0; i < numUrnas; ++i) {
            urnas[i] = nullptr;
        }

        // Distribuir los elementos en las urnas
        for (int i = 0; i < n; ++i) {
            int clave = a[i];
            if (clave >= 0 && clave < numUrnas) {  // Verificar que la clave esté dentro del rango
                agregarEnUrna(urnas[clave], a[i]);
            }
        }

        // Combinar urnas en el arreglo original
        combinarUrnas(urnas, numUrnas, a);

        // Limpiar memoria
        for (int i = 0; i < numUrnas; ++i) {
            Nodo* temp = urnas[i];
            while (temp) {
                Nodo* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
        }
        delete[] urnas;
    }
};*/

template <typename T>
void countingSort(T a[], int n, int exp) {
    T* output = new T[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[static_cast<int>((a[i] / exp)) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[static_cast<int>((a[i] / exp)) % 10] - 1] = a[i];
        count[static_cast<int>((a[i] / exp)) % 10]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];

    delete[] output;
}

template <typename T>
class RadixSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        T maximo = encontrarMaximo(a, n);
        int exp = 1;
        while (maximo / exp >= 1) {
            countingSort(a, n, exp);
            exp *= 10;
        }
    }
};

#endif // ORDENAMIENTO_H
