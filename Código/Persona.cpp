#include <iostream>
#include "Persona.h"

Persona::Persona()
{
}

Persona::Persona(string nom, string ced, string pass)
{
    this->nombre = nom;
    this->cedula = ced;
    this->pswd = pass;
}

string Persona::getNombre()
{
    return this->nombre;
}

string Persona::getCedula()
{
    return this->cedula;
}

string Persona::getContras()
{
    return this->pswd;
}

Persona Persona::buscarPersona(string nombre)
{
}

bool Persona::validarPersona_userPswd(Persona aux, Persona aux1)
{
    bool a = false;
    if (aux.getCedula() == aux1.getCedula() && aux.getContras() == aux1.getContras())
    {  
        a = true;
    }
    return a;
}

//validamos que no ingresen 2 veces uns misma cedula, en este caso cumple rol de id.
bool Persona::validarDuplicados(Persona& auxP, Persona& auxP2)
{
	bool dup=false;
	if(auxP.getCedula()==auxP2.getCedula())
	{
		dup=true;
	}
	return dup;
}

//validar los datos vacios
bool Persona::validarDatosVacios(Persona& auxP)
{
	bool dV=false;
	if(auxP.getNombre().empty()||auxP.getCedula().empty()||auxP.getContras().empty()){
		dV=true;
	}
	return dV;
}

bool Persona::crearCuenta(Persona& auxP)
{
	bool Cc=false;
	if(validarDatosVacios(auxP)){
		cout<<"No puede existir datos vacios "<<endl;
	}
	else{
		if(obtenerDatos(2,auxP))
		{
			cout<<"Se ha encontrado un ID duplicado, vuelva a intentarlo "<<endl;
		}else{
			Cc=true;
		}
	}
	return Cc;
}

void Persona::verPersonas()
{
}

bool Persona::obtenerDatos(int val, Persona& auxP)
{
    Persona per;
    bool ab=false;
    char *sep;
    int n = 0;
    char temp[100];
    FILE *fichero;
    string ss;
    fichero = fopen("DatosPersonas.txt", "r");
    if (fichero == NULL)
    {
        cout << "Error al abrir el archivo \n";
        exit(EXIT_FAILURE);
    }
    else
    {
        while (!feof(fichero))
        {
            fgets(temp, 100, fichero);
            sep = strtok(temp, " ");
            while (sep != NULL)
            {
                if (n == 0)
                {
                    per.setNombre(sep);
                }
                else if (n == 1)
                {
                    per.setCedula(sep);
                }else if (n == 2)
                {
                    per.setPswd(sep);
                    if(ab==false && val==1){
                    	ab = validarPersona_userPswd(auxP, per);
                    	
					}  
					
					else if (val==2)
                    {
                    	ab= validarDuplicados(auxP,per);
					}
					
                }

                /*if (n == 2 && val == 1)
                {
                    cout << "entra aqui" << endl;
                    ab = validarPersona_userPswd(auxP, per);
                }
                else if (n == 2 && val == 2)
                {
                }*/
                       // printf( " %s\n", sep );
                sep = strtok(NULL, " ");
                // printf( " ciclo %d\n", n );
                n++; 
               
            }
             n = 0;
        }
		rewind(fichero);
            fclose(fichero); 
	}
	return ab;
}

void Persona::actualizarDatos(Persona p)
{
    FILE *fichero;
    fichero = fopen("DatosPersonas.txt", "a+");
    if (fichero == NULL)
    {
        cout << "Error al abrir el archivo \n";
        exit(EXIT_FAILURE);
    }
    else
    {
        fprintf(fichero, "\n");
        fprintf(fichero, "%s %s %s ", p.getNombre().c_str(), p.getCedula().c_str(), p.getContras().c_str());
    }
}

void Persona::setNombre(string nom)
{
    this->nombre = nom;
}

void Persona::setCedula(string ced)
{
    this->cedula = ced;
}

void Persona::setPswd(string pasw)
{
    this->pswd = pasw;
}
