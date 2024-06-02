#include <iostream>
#include "Login.cpp"
//#include "Persona.cpp"

int main()
{
	Persona p;
	Login* l=new Login(&p);
	l->login();
	return 0;
}