#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "Estructuras.h"

int getEspecie(char e[]);
void getAnimal(char a[], int idEspecie);
int getHabitat(int idEspecie);
int getCantidad();
void getHabitatChar(int n, char h[]);

stRegistro cargaUnRegistroManual();
stRegistro cargaUnRegistroRandom();
void muestraUnRegistro(stRegistro r);

#endif // REGISTRO_H_INCLUDED
