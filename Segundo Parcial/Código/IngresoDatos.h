#ifndef INGRESODATOS_H
#define INGRESODATOS_H

#include <iostream>
#include <string>
#include <conio.h>  
#include <cstdlib>  

using namespace std;

class IngresoDatos {
public:
    IngresoDatos() {};

    int IngresoEnteros(string mensaje) {
        char* dato = new char[10];
        char c;
        int i = 0;
        cout << mensaje;
        while (true) {
            c = _getch();
            if (c == 13) { // ENTER key
                break;
            }
            if (c >= '0' && c <= '9') {
                printf("%c", c);
                dato[i++] = c;
            } else if (c == 8 && i > 0) { // Backspace key
                printf("\b \b");
                i--;
            }
        }
        dato[i] = '\0';
        cout << "\n";
        int result = atoi(dato);
        delete[] dato; // Liberar la memoria
        return result;
    }

    string ingresoContra(short minimo, short maximo) {
        const char ENTER_KEY = 13;
        const char BACKSPACE_KEY = 8;
        const char SPACE_KEY = 32;

        string password;
        char keyPressed;

        while (true) {
            keyPressed = _getch();

            if (keyPressed == ENTER_KEY && password.size() >= minimo) {
                break;
            } else if (keyPressed == SPACE_KEY || isalnum(keyPressed)) {
                if (password.size() < maximo) {
                    cout << '*';
                    password.push_back(keyPressed);
                }
            } else if (keyPressed == BACKSPACE_KEY && !password.empty()) {
                cout << "\b \b";
                password.pop_back();
            }
        }

        while (!password.empty() && password.back() == SPACE_KEY) {
            password.pop_back();
        }

        cout << '\n';

        return password;
    }

    string leerLetras() {
        string dato;
        char c = 0;

        while (true) {
            c = _getch();
            if (c == 13) { // ENTER key
                break;
            } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
                printf("%c", c);
                dato.push_back(c);
            } else if (c == 8 && !dato.empty()) { // Backspace key
                printf("\b \b");
                dato.pop_back();
            }
        }

        cout << '\n';
        return dato;
    }

/*    float leerFlotantes() {
    std::string dato;
    char c = 0;
    bool decimalPointUsed = false;
    bool negativeSignUsed = false;

    while (true) {
        c = _getch();
        if (c == 13) { // Tecla ENTER
            break;
        } else if (c >= '0' && c <= '9') {
            printf("%c", c);
            dato.push_back(c);
        } else if (c == '.' && !decimalPointUsed) {
            printf("%c", c);
            dato.push_back(c);
            decimalPointUsed = true;
        } else if (c == '-' && !negativeSignUsed && dato.empty()) {
            printf("%c", c);
            dato.push_back(c);
            negativeSignUsed = true;
        } else if (c == 8 && !dato.empty()) { // Tecla Backspace
            if (dato.back() == '.') {
                decimalPointUsed = false;
            } else if (dato.back() == '-') {
                negativeSignUsed = false;
            }
            printf("\b \b");
            dato.pop_back();
        }
    }

    std::cout << '\n';
    return std::stof(dato);
}*/
};

#endif
