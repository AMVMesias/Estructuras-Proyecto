#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

template <typename T>
void intercambiar(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Ordenamiento {
	
protected:
    struct Node {
        T data;
        Node* next;
    };

    bool esVacia(Node* head) {
        return head == nullptr;
    }
	
	
public:
    virtual void ordenar(T a[], int n) = 0;
    void medirTiempoOrdenamiento(T a[], int n) {
        auto inicio = std::chrono::high_resolution_clock::now();
        ordenar(a, n);
        auto fin = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duracion = fin - inicio;
        std::cout << "Tiempo de ordenamiento: " << std::fixed << std::setprecision(4) 
                  << duracion.count() << " milisegundos" << std::endl;
    }

protected:
    int obtenerTamanio(T a[]) {
        return sizeof(a) / sizeof(a[0]);
    }
};

template <typename T>
int encontrarMaximo(T a[], int n) {
    T max = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

template <typename T>
class BucketSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        if (n <= 0) return;

        T maxValue = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] > maxValue) {
                maxValue = a[i];
            }
        }

        std::vector<std::list<T>> Urnas(n);

        for (int j = 0; j < n; ++j) {
            int bucketIndex = static_cast<int>(static_cast<double>(a[j]) / maxValue * (n - 1));
            Urnas[bucketIndex].push_back(a[j]);
        }

        for (int i = 0; i < n; ++i) {
            Urnas[i].sort();
        }

        int index = 0;
        for (int i = 0; i < n; ++i) {
            for (auto it = Urnas[i].begin(); it != Urnas[i].end(); ++it) {
                a[index++] = *it;
            }
        }
    }
};

/* 
template <typename T>
class BucketSort : public Ordenamiento<T> {
private:
    typename Ordenamiento<T>::Node** Urnas;

    void agregarEnUrna(typename Ordenamiento<T>::Node*& head, T value) {
        typename Ordenamiento<T>::Node* newNode = new typename Ordenamiento<T>::Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            typename Ordenamiento<T>::Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void enlazarUrnas(typename Ordenamiento<T>::Node*& urna1, typename Ordenamiento<T>::Node*& urna2) {
        if (!urna1) {
            urna1 = urna2;
        } else {
            typename Ordenamiento<T>::Node* temp = urna1;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = urna2;
        }
        urna2 = nullptr;
    }

public:
    void ordenar(T a[], int n) override {
        if (n <= 0) return;

        Urnas = new typename Ordenamiento<T>::Node*[n](); // Arreglo de punteros a Node*, inicializados a nullptr

        for (int i = 0; i < n; ++i) {
            Urnas[i] = nullptr; // Inicializa cada urna como vacía
        }

        T maxValue = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] > maxValue) {
                maxValue = a[i];
            }
        }

        for (int j = 0; j < n; ++j) {
            int bucketIndex = static_cast<int>(static_cast<double>(a[j]) * n / (maxValue + 1));
            agregarEnUrna(Urnas[bucketIndex], a[j]);
        }

        int i = 0;
        while (i < n && this->esVacia(Urnas[i])) {
            ++i;
        }

        for (int j = i + 1; j < n; ++j) {
            if (!this->esVacia(Urnas[j])) {
                enlazarUrnas(Urnas[i], Urnas[j]);
            }
        }

        int index = 0;
        typename Ordenamiento<T>::Node* dir = Urnas[i];
        while (dir != nullptr) {
            a[index++] = dir->data;
            typename Ordenamiento<T>::Node* temp = dir;
            dir = dir->next;
            delete temp;
        }

        delete[] Urnas; // Libera la memoria del arreglo de punteros
    }

    ~BucketSort() {
        delete[] Urnas; // Destructor para liberar la memoria del arreglo de punteros
    }
};
*/


template <typename T>
void countingSort(T a[], int n, T exp1) {
    T* output = new T[n];

    // Encontrar el valor máximo en el arreglo (no usar std::max_element)
    T maximo = encontrarMaximo(a, n);

    // Array count para almacenar la cuenta de cada elemento
    int count[10] = {0};

    // Contar la frecuencia de cada elemento
    for (int i = 0; i < n; ++i) {
        int index = (a[i] / exp1) % 10;
        count[index]++;
    }

    // Calcular las posiciones finales de cada elemento en el output
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Construir el output array usando el array count
    for (int i = n - 1; i >= 0; --i) {
        int index = (a[i] / exp1) % 10;
        output[count[index] - 1] = a[i];
        count[index]--;
    }

    // Copiar el output array al array original a[]
    for (int i = 0; i < n; ++i) {
        a[i] = output[i];
    }

    delete[] output;
}

// Clase CountingSort como una clase template heredada de Ordenamiento
template <typename T>
class CountingSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        T maximo = encontrarMaximo(a, n);

        // Llamar a countingSort para ordenar el arreglo a[]
        countingSort(a, n, maximo);
    }
};

// Clase RadixSort como una clase template heredada de Ordenamiento
template <typename T>
class RadixSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        T maximo = encontrarMaximo(a, n);

        // Aplicar Counting Sort para cada dígito. Se comienza por el dígito menos significativo hasta el más significativo.
        for (T exp = 1; maximo / exp > 0; exp *= 10) {
            countingSort(a, n, exp);
        }
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
                    if (a[j] <= a[j + salto]) {
                        break;
                    } else {
                        intercambiar(a[j], a[j + salto]);
                        j -= salto;
                    }
                }
            }
            salto /= 2;
        }
    }
};

template<typename T>
class QuickSort : public Ordenamiento<T> {
private:
    void quickSort(T a[], int primero, int ultimo) {
        if (primero < ultimo) {
            int i, j, central;
            T pivote;

            central = (primero + ultimo) / 2;
            pivote = a[central];
            i = primero;
            j = ultimo;

            do {
                while (a[i] < pivote) {
                    i++;
                }
                while (a[j] > pivote) {
                    j--;
                }
                if (i <= j) {
                    intercambiar(a[i], a[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            if (primero < j) {
                quickSort(a, primero, j);
            }
            if (i < ultimo) {
                quickSort(a, i, ultimo);
            }
        }
    }

public:
    void ordenar(T a[], int size) override {
        quickSort(a, 0, size - 1);
    }
};

template <typename T>
void ingresarDatos(T a[], int n) {
    std::cout << "Ingrese " << n << " numeros:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Ingrese el numero " << (i + 1) << ": ";
        std::cin >> a[i];
    }
}

template <typename T>
void generarAleatorios(T a[], int n) {
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        if (std::is_integral<T>::value) {
            a[i] = rand() % 1000;
        } else {
            a[i] = (rand() % 1000) + static_cast<double>(rand()) / RAND_MAX;
        }
    }
}

template <typename T>
void mostrarArreglo(T a[], int n) {
    std::cout << "Arreglo: ";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

#endif // ORDENAMIENTO_H
