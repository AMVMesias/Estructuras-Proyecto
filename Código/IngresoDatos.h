#ifndef INGRESODATOS_H
#define INGRESODATOS_H
#include <iostream>
#include <conio.h>
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

};
#endif
