#ifndef VARIOSREGISTROS_H_INCLUDED
#define VARIOSREGISTROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "registro.h"
#define arRegistro "registro.dat"
#define arMayor "mayor.dat"
#define arMenor "menor.dat"
#define arRegistro2 "registro2.dat"


int cargaArregloManual(stRegistro r[], int v, int dim);
int cargaArregloRandom(stRegistro r[], int v, int dim);
void muestraArreglo(stRegistro r[], int v);
void guardarArchivo(stRegistro r);
void cargaArchivoManual();
void cargaArchivoRandom(int cantidad);
void muestraArchivo(char archivo[]);
int cuentaCantidadRegistros(char archivo[], int bytes);

#endif // VARIOSREGISTROS_H_INCLUDED
