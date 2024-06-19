#ifndef INGRESODATOS_H
#define INGRESODATOS_H
#include <iostream>
#include <conio.h>
#include <cctype>
#include <string>

using namespace std;

class IngresoDatos{
	public:
	IngresoDatos(){};

	int IngresoEnteros(string mensaje){
	char *dato=new char[10],c;
	int i=0;
	cout<<mensaje;
	while((c=_getch())!=13){
		if(c>='0'&& c<='9'){
			printf("%c",c);
			dato[i++]=c;
				}
		else if(c==8||c==127){
			printf("\b \b");
			dato[i--]=0;
		}
	}
	dato[i]='\0';
    cout<<"\n ";
	return atoi(dato);
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

    // Limpiando espacios en blanco al final de la cadena
    while (!password.empty() && password.back() == SPACE_KEY) {
        password.pop_back();
    }

    cout << '\n';

    return password;
}


};
#endif
