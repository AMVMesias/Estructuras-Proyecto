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

           /* void backspace(int* i, char* c,string dato){

                if((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z')){
                if(*i != 0) --*i;
                }else{ 
                    system("CLS"); //Limpio pantalla
                    for(int p = 0; p < *i-1; p++){
                        printf("%c", dato[p]); //Imprimo de nuevo hasta el penultimo
                    }

                    if(*i != 0){ 
                        dato[--*i]='\0'; //Borro valor
                        --*i; //Disminuto iterador
                    }
                }
            }*/
            
void backspace(int* i, char* c, std::string* dato) {
    if (!dato->empty()) {
        std::cout << "\b \b"; // Borra el último carácter impreso
        dato->pop_back(); // Borra el último carácter de la cadena
        (*i)--; // Decrementa el índice
    }
}

std::string leerLetras() {
    std::string dato;
    char c = 0; // Inicializa c

    while (c != 13) { // Bucle hasta que se presiona la tecla ENTER
        c = _getch(); // Recibo el dato por teclado

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ') {
            printf("%c", c); // Imprimo el valor
            dato.push_back(c); // Añadir el carácter a la cadena
        } else if (c == 8) { // Si el input es un backspace
            backspace(nullptr, &c, &dato); // Llamar a la función backspace
        }
    }

    return dato;
}

	   


/*float funcionPrincipalFlotantes(){
                char *aux = leerDatos();
                if(aux[0] != '\0' && aux[0] != 46){
                    return this -> conversion.numFloat(aux);
                }else if(aux[0] == 46){
                    cout<<"\n~~ Un flotante no inicia con un punto solo ~~\n"<<endl;
                    return -1;
                }else{
                    cout<<"\n~~ Datos vacios ~~\n"<<endl;
                    return -1;
                }
              
} */

float leerFlotantes() {
    std::string dato;
    char c = 0;  // Inicializa c
    bool decimalPointUsed = false; // Variable para permitir solo un punto decimal
    bool negativeSignUsed = false; // Variable para permitir solo un signo negativo al principio

    while (c != 13) { // Bucle hasta que se presiona la tecla ENTER
        c = _getch(); // Recibo el dato por teclado (usa _getch() en lugar de getch() en algunos compiladores)

        if (c >= '0' && c <= '9') {
            printf("%c", c); // Imprimo el valor
            dato.push_back(c); // Añadir el carácter a la cadena
        } else if (c == '.' && !decimalPointUsed) { // Permitir solo un punto decimal
            printf("%c", c); // Imprimo el valor
            dato.push_back(c); // Añadir el carácter a la cadena
            decimalPointUsed = true; // Marcar que el punto decimal ha sido usado
        } else if (c == '-' && !negativeSignUsed && dato.empty()) { // Permitir el signo negativo solo al principio
            printf("%c", c); // Imprimo el valor
            dato.push_back(c); // Añadir el carácter a la cadena
            negativeSignUsed = true; // Marcar que el signo negativo ha sido usado
        } else if (c == 8 && !dato.empty()) { // Si el input es un backspace y hay caracteres para borrar
            if (dato.back() == '.') {
                decimalPointUsed = false; // Permitir usar el punto decimal nuevamente si se borra
            } else if (dato.back() == '-') {
                negativeSignUsed = false; // Permitir usar el signo negativo nuevamente si se borra
            }
            std::cout << "\b \b"; // Borra el último carácter impreso
            dato.pop_back(); // Borra el último carácter de la cadena
        }
    }

    return std::stof(dato); // Convertir la cadena a float y retornarla
}
};
#endif
