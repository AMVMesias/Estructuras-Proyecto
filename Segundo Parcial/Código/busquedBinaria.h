bool busquedBinaria(int A[], int n, int num) {
    int primero = 0, ultimo = n - 1, medio;
    
    while (primero <= ultimo) {
        medio = (primero + ultimo) / 2;
        
        if (A[medio] < num) {
            primero = medio + 1;
        } else if (A[medio] == num) {
            return true; 
        } else {
            ultimo = medio - 1;
        }
    }
    return false; 