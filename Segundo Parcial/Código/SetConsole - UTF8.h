#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

class BucketSort {
public:
    void ordenar(double arr[], int n) {
        if (n <= 0) return;

        // Encuentra el rango máximo y mínimo
        double max = arr[0];
        double min = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }

        // Número de cubos
        int numBuckets = n;
        std::vector<std::vector<double>> buckets(numBuckets);

        // Distribuye los elementos en los cubos
        for (int i = 0; i < n; ++i) {
            int index = static_cast<int>(((arr[i] - min) / (max - min)) * (numBuckets - 1));
            buckets[index].push_back(arr[i]);
        }

        // Ordena los elementos en cada cubo y los concatena
        int index = 0;
        for (auto& bucket : buckets) {
            std::sort(bucket.begin(), bucket.end());
            for (const auto& elem : bucket) {
                arr[index++] = elem;
            }
        }
    }
};

// Función para imprimir el arreglo ordenado
void imprimirNotasOrdenadas(double arr[], int n) {
    std::cout << "Notas ordenadas: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Función para escribir el arreglo ordenado en un archivo
void escribirNotasOrdenadasEnArchivo(double arr[], int n, const std::string& metodo) {
    std::ofstream archivo("Notas_Ordenadas_" + metodo + ".txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }
    archivo << "Notas ordenadas usando " << metodo << ":" << std::endl;
    for (int i = 0; i < n; ++i) {
        archivo << arr[i] << std::endl;
    }
    archivo.close();
}

