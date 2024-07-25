#pragma once
#include "MetodosExternos.h"
#include "cmath"

MetodoExterno::MetodoExterno(string str)
{
    this->nombreArchivo = str;
}

MetodoExterno::MetodoExterno()
{
}

// Destructor
MetodoExterno::~MetodoExterno()
{
    delete this;
}

// Setter y getter necesario
void MetodoExterno::setN(float n)
{
    this->N = n;
}

/**
 * Toma una matriz de números enteros y los ordena usando el algoritmo de clasificación por combinación
 */
void MetodoExterno::ordenarPorDirecta()
{
    limpiar();
    int longitud = 1;
    while (longitud < N)
    {
        particiona(longitud);
        fusiona(longitud);
        longitud *= 2;
    }
}

/**
 * Genera números aleatorios y luego los ordena.
 */
void MetodoExterno::ordenarPorNatural()
{
    limpiar();
    particionInicial();
    particionFusion();
}

//! 
/**
 * Metodo para ordenacion natural
 * Abre (o crea) tres archivos para limpiarlos.
 */
void MetodoExterno::limpiar()
{
    fstream F1, F2;
    abrir(&F1, "F1.txt", 3);
    abrir(&F2, "F2.txt", 3);
    cerrar(&F1);
    cerrar(&F2);
}


/**
 * Metodo para ambos
 * Abre un archivo y luego lo cierra.
 */
void MetodoExterno::limpiarArchivo()
{
    fstream F;
    abrir(&F, nombreArchivo, 3);
    cerrar(&F);
}

/**
 * Abre un archivo, lee el primer entero, y si no es -10001, devuelve verdadero, de lo contrario,
 * devuelve falso
 *
 * @return un valor booleano.
 */
bool MetodoExterno::hayDatos()
{

    fstream F;
    F.open(nombreArchivo, ios::in);
    float x = -10001;
    F >> x;
    if (x != -10001)
    {
        F.close();
        return true;
    }
    else
    {
        F.close();
        return false;
    }
}

//! Metodo para ordenacion natural
/**
 * Esta función abre un archivo para leerlo, escribirlo o agregarlo, según el valor del segundo
 * parámetro.
 *
 * @param f es el flujo de archivos
 * @param nom nombre del archivo
 * @param tip 1 = leer, 2 = escribir, 3 = escribir y borrar
 */
void MetodoExterno::abrir(fstream *f, string nom, int tip)
{
    if (tip == 1)
    {                            // LECTURA
        (*f).open(nom, ios::in); //->
        // MODO TEXTO (Acceder a los datos) usaré ">>"
    }
    else if (tip == 2)
    {                                        // ESCRITURA SIN BORRAR
        (*f).open(nom, ios::out | ios::app); //->
        // MODO TEXTO (Colocar datos y no borrará) usaré "<<"
    }
    else
    {                             // ESCRITURA y BORRAR
        (*f).open(nom, ios::out); //->
        // MODO TEXTO (Colocar datos) usaré "<<"
    }
}

//! Metodo para ordenacion natural
/**
 * Esta función cierra el archivo que se abrió en la función abrir().
 *
 * @param f es el archivo que quiero cerrar
 */
void MetodoExterno::cerrar(fstream *f)
{
    (*f).close();
}

//! Metodo para ordenacion natural
/**
 * Genera números aleatorios entre un valor mínimo y máximo y los inserta en un archivo.
 *
 * @param min -250
 * @param max 1000
 */
void MetodoExterno::generarAleatorios(int min, int max)
{

    int RND{0};

    for (int i = 0; i < 5; i++)
    {
        do
        {
            RND = rand() % 1000 - 250;
        } while (RND < min || RND > max);
        // cout<<RND<<" ";
        insertar(RND, nombreArchivo);
    }
}

//! Metodo para ordenacion natural
/**
 * Abre un archivo, escribe un número entero en él y cierra el archivo.
 *
 * @param d Los datos a insertar
 * @param nom nombre del archivo
 */
void MetodoExterno::insertar(float d, string nom)
{
	d=std::floor(d*100)/100;
	fstream F;
    abrir(&F, nom, 2);
    F << d << " ";
    cerrar(&F);
    N++;
    // cout<<"\n";
    // cout << N << " N en insertar"<<endl;
}

//! Metodo para ordenacion natural
void MetodoExterno::insertar_Natural(float d, string nom)
{
	d=std::floor(d*100)/100;
    fstream F;
    abrir(&F, nom, 2);
    F << d << " ";
    cerrar(&F);
}

//! Metodo para ordenacion natural
/**
 * Lee un archivo y escribe la primera mitad del archivo en un archivo y la segunda mitad en otro
 * archivo
 */
void MetodoExterno::particionInicial()
{

    float aux{0}, dato{0}; //?Inizializar siempre es una buena practica
    bool ban = true;

    fstream F, F2, F3;
    abrir(&F, nombreArchivo, 1);
    abrir(&F2, "F2.txt", 3);
    abrir(&F3, "F3.txt", 3);

    F >> aux;
    while (!F.eof() && !F.fail())
    {

        F >> dato;
        if (ban)
        {
            F2 << aux << " ";
            if (aux > dato)
                ban = false;
        }
        else
        {
            F3 << aux << " ";
            if (aux > dato)
                ban = true;
        }

        aux = dato;
    }

    cerrar(&F);
    cerrar(&F2);
    cerrar(&F3);
}

//! Metodo para ordenacion natural
/**
 * Lee el archivo, lo ordena y luego lo escribe en otro archivo
 */
void MetodoExterno::particionFusion()
{
    fstream F1;
    abrir(&F1, "F1.txt", 1);
    float con = 0;
    bool bandera = true;
    do
    {
        // con++;
        if (bandera)
        {
            bandera = false;
            intercalacionDeArchivo("F2.txt", "F3.txt", nombreArchivo, "F1.txt");
        }
        else
        {
            bandera = true;
            intercalacionDeArchivo(nombreArchivo, "F1.txt", "F2.txt", "F3.txt");
        }
        F1 >> con;

    } while (!F1.eof());

    cerrar(&F1);
    // Ya esta ordenado
}

//! Metodo para ordenacion natural
/**
 * Lee dos archivos, compara el primer número de cada archivo y escribe el número más pequeño en un
 * tercer archivo. Luego lee el siguiente número del archivo que contenía el número más pequeño, lo
 * compara con el número en el otro archivo y escribe el número más pequeño en el tercer archivo.
 * Continúa este proceso hasta llegar al final de uno de los archivos. Luego escribe los números
 * restantes del otro archivo al tercer archivo.
 *
 * @param nom1 Nombre del primer archivo.
 * @param nom2 "Fichero2.txt"
 * @param nom3 "Fichero3.txt"
 * @param nom4 "Fichero4.txt"
 */
void MetodoExterno::intercalacionDeArchivo(string nom1, string nom2, string nom3, string nom4)
{

    float aux1{0}, aux2{0}, dato{0}, mayor1{0}, mayor2{0};
    bool bandera1{false}, bandera2{true};

    fstream F1, F2, F3, F4;
    abrir(&F1, nom1, 1);
    abrir(&F2, nom2, 1);
    abrir(&F3, nom3, 3);
    abrir(&F4, nom4, 3);
    //-- Conseguir los primeros numeros --//
    F1 >> aux1;
    F2 >> aux2;
    //-- Asignar los mayores --//
    //(Debe estar ya validados los ficheros que contengan al menos un dato.
    mayor1 = aux1;
    mayor2 = aux2;
    //-- Escribir en orden cuando los dos tengan datos.
    //-- Pero simultaneado los archivos.
    while (!F1.eof() && !F2.eof())
    {

        //-- Cambio de fichero para la Escritura --//
        if (aux2 < mayor2 && aux1 < mayor1)
        {

            if (bandera2)
                bandera2 = false;
            else
                bandera2 = true;

            mayor1 = aux1;
            mayor2 = aux2;
        }
        //----------------------------------------//
        //-- Cambio de fichero para Lectura ------//
        if ((aux1 <= aux2 && aux1 >= mayor1) || aux2 < mayor2)
        {
            bandera1 = true;
            mayor1 = dato = aux1;
        }
        else
        {
            bandera1 = false;
            mayor2 = dato = aux2;
        }
        //---------------------------------------//
        //-- Leer el dato en el fichero tal --//
        if (bandera1)
            F1 >> aux1;
        else
            F2 >> aux2;
        //-------------------------------------//
        //-- Escribir el dato en el fichero tal --//
        if (bandera2)
            F3 << dato << " ";
        else
            F4 << dato << " ";
    }

    //-- Escribir lo sobrante.
    if (!F1.eof())
    {

        while (!F1.eof())
        {
            //-- Cambio de fichero para la Escritura --//
            if (aux1 < mayor1)
            {
                if (bandera2)
                    bandera2 = false;
                else
                    bandera2 = true;
            }
            mayor1 = aux1;
            //---------------------------------------//
            //-- Escribir el dato en el fichero tal --//
            if (bandera2)
                F3 << aux1 << " ";
            else
                F4 << aux1 << " ";

            F1 >> aux1;
        }
    }
    else if (!F2.eof())
    {
        while (!F2.eof())
        {
            //-- Cambio de fichero para la Escritura --//
            if (aux2 < mayor2)
            {
                if (bandera2)
                    bandera2 = false;
                else
                    bandera2 = true;
            }

            mayor2 = aux2;
            //---------------------------------------//
            //-- Escribir el dato en el fichero tal --//
            if (bandera2)
                F3 << aux2 << " ";
            else
                F4 << aux2 << " ";

            F2 >> aux2;
        }
    }

    cerrar(&F1);
    cerrar(&F2);
    cerrar(&F3);
    cerrar(&F4);
}

/**
 * Lee un archivo y escribe la primera mitad del archivo en un archivo y la segunda mitad en otro
 * archivo
 *
 * @param longitud la longitud de la matriz
 */
void MetodoExterno::particiona(int longitud)
{
    fstream F, F1, F2;
    float con1, con2, dato;
    abrir(&F, nombreArchivo, 1);
    abrir(&F1, "F1.txt", 3);
    abrir(&F2, "F2.txt", 3);

    while (!F.eof())
    {
        con1 = 0;
        while (con1 < longitud && !F.eof())
        {
            F >> dato;
            if (!F.eof())
                F1 << dato << " ";
            con1++;
        }
        con2 = 0;
        while (con2 < longitud && !F.eof())
        {
            F >> dato;
            if (!F.eof())
                F2 << dato << " ";
            con2++;
        }
    }

    cerrar(&F);
    cerrar(&F1);
    cerrar(&F2);
}

/**
 * Toma dos archivos, F1 y F2, y los fusiona en un tercer archivo, F
 *
 * @param longitud La longitud de la matriz
 */
void MetodoExterno::fusiona(int longitud)
{
    fstream F, F1, F2;
    float con1, con2, dato1, dato2;
    bool ban1, ban2;
    abrir(&F, nombreArchivo, 3);
    abrir(&F1, "F1.txt", 1);
    abrir(&F2, "F2.txt", 1);
    ban1 = ban2 = true;
    if (!F1.eof())
    {
        F1 >> dato1;
        ban1 = false;
    }
    if (!F2.eof())
    {
        F2 >> dato2;
        ban2 = false;
    }

    while ((!F1.eof() || ban1 == false) && (!F2.eof() || ban2 == false))
    {
        con1 = con2 = 0;
        while ((con1 < longitud && ban1 == false) && (con2 < longitud && ban2 == false))
        {
            if (dato1 <= dato2)
            {
                ban1 = true;
                con1++;
                if (!F1.eof())
                {
                    F << dato1 << " "; // Cambio
                    F1 >> dato1;
                    ban1 = false;
                }
            }
            else
            {
                ban2 = true;
                con2++;
                if (!F2.eof())
                {
                    F << dato2 << " "; // Cambio
                    F2 >> dato2;
                    ban2 = false;
                }
            }

        } // Fin del segundo while
        if (con1 < longitud)
        {
            while (con1 < longitud && ban1 == false)
            {
                ban1 = true;
                con1++;
                if (!F1.eof())
                {
                    F << dato1 << " "; // Cambio
                    F1 >> dato1;
                    ban1 = false;
                }
            }
        }
        if (con2 < longitud)
        {
            while (con2 < longitud && ban2 == false)
            {
                ban2 = true;
                con2++;
                if (!F2.eof())
                {
                    F << dato2 << " "; // Cambio
                    F2 >> dato2;
                    ban2 = false;
                }
            }
        }
    } // fin del primer while
    // Cambios
    while (!F1.eof())
    {
        F1 >> dato1;
        if (!F1.eof())
            F << dato1 << " ";
    }
    while (!F2.eof())
    {
        F2 >> dato2;
        if (!F2.eof())
            F << dato2 << " ";
    }
    cerrar(&F);
    cerrar(&F1);
    cerrar(&F2);
}

void MetodoExterno::imprimirInterno(string nombre)
{
    fstream F;
    F.open(nombre, ios::in);
    float dato{0};
    F >> dato;

    while (!F.eof())
    {
        cout << dato << " ";
        F >> dato;
    }

    F.close();
}
