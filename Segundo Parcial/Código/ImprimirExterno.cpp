#include "ImprimirExterno.h"

//! FUNCION IMPRIMIR
void ImprimirExterno::imprimir(string nombre)
{
  fstream F;
  F.open(nombre, ios::in);
  int dato{0};
  F >> dato;

  while (!F.eof())
  {
    cout << dato << " ";
    F >> dato;
  }

  F.close();
}