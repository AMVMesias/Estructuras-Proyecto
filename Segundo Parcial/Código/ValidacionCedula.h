#ifndef VALIDACIONCEDULA_H
#define VALIDACIONCEDULA_H

#include <iostream>
#include <string>


//#define dim 10
using namespace std;

long long int validarr(long long int &x) {
    while (x < 100000000 || x > 3999999999) {
        cout<<"Error, Ingrese de nuevo la cedula consta de 10 digitos: ";
        cin>>x;
    }

    return x;

}
long long int validar(long long int &x) {
    long long int A[10]={0};
    int i = 9, sumapares = 0, sumaimpares = 0, sumat, res, mul, a;
    long long int coc;
    long long int aux = x;
    x = validarr(x);
        A[0] = 0;
        do {
            coc = aux / 10;
            res = aux % 10;
            A[i] = res;
            aux = coc;
            i--;
        } while (coc != 0);

        for (int j = 0; j < 10; j += 2) {
            mul = A[j] * 2;
            if (mul > 9)
                mul -= 9;
            sumapares += mul;
        }
        for (int j = 1; j < 10 - 1; j += 2)
            sumaimpares += A[j];
        sumat = sumapares + sumaimpares;
        res = 10 - (sumat % 10);
        if (res == 10)
            res = 0;
        if (res == A[9]) {
            return x;
        }
        else {
            cout<<"Cedula no valida, ingrese de nuevo: ";
            cin>>x;
            return validar(x);
        }


}


#endif // VALIDACIONCEDULA_H
