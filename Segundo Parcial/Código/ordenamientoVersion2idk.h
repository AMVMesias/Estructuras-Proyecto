#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

template <typename T>
void intercambiar(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
class Ordenamiento{
public:
    virtual void ordenar(T a[], int n) = 0;
};

template <typename T>
int encontrarMaximo(T a[], int n){
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
        if (primero<ultimo) {
        int i=primero,j=ultimo;
        int central=(primero+ultimo)/2;
        int pivote=a[central];
        do {
            while(a[i]<pivote) i++;
            while(a[j]>pivote) j--;
            if (i<=j){
                intercambio(a[i],a[j]);
                i++;
                j--;
            }
        }while(i<=j);
        if(primero<j)
            quicksort(a,primero,j);
        if(i<ultimo)
            quicksort(a,i,ultimo);
    }
    }

public:
    void ordenar(T a[], int size) override {
        quickSort(a, 0, size - 1);
    }
};

template <typename T>
class ShellSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        int salto=n/2;
        while(salto>0){
            for(int i=salto;i<n;i++){
                int j=i-salto;
                while(j>=0){
                    int k=j+salto;
                    if (a[j]<=a[k]){
                        j=-1;
                    }else{
                        intercambio(a[j],a[j+1]);
                        j-=salto;
                    }
                }
            }
        salto/=2;
        }
    }
};

template <typename T>
class BucketSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        //TODO xdxd
    }
};

template <typename T>
void countingSort(T a[], int n, T exp1) {
    T* output = new T[n];

    int count[10]={0};
    for (int i=0;i<n;i++)
        count[(arr[i]/exp)%10]++;

    for (int i=1;i<10;i++)
        count[i]+=count[i-1];

    for (int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

    delete[] output;
}

template <typename T>
class CountingSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        T maximo = encontrarMaximo(a, n);
        countingSort(a, n, maximo);
    }
};

template <typename T>
class RadixSort : public Ordenamiento<T> {
public:
    void ordenar(T a[], int n) override {
        T maximo = a[0];
        for (int i=1;i<n;i++){
        if (arr[i]>max1)
            max1=arr[i];
        }
        int exp=1;
        while(max1/exp>=1){
            countingSort(arr,n,exp);
            exp*=10;
        }
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
