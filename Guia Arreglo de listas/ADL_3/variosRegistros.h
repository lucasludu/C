#ifndef VARIOSREGISTROS_H_INCLUDED
#define VARIOSREGISTROS_H_INCLUDED

#include "Estructuras.h"
#include "registro.h"
#define AR_ANIMALES "animales.dat"

int cargaArregloManual(stRegistro c[], int v, int dim);
int cargaArregloRandom(stRegistro c[], int v, int dim);
void muestraArreglo(stRegistro c[], int v);
void guardaArchivo(stRegistro c);
void cargaArchivoManual();
void cargaArchivoRandom(int cant);
void muestraArchivo(char archivo[]);
int cuentaCantidadRegistros(char archivo[], int bytes);
int archivoTOarreglo(char archivo[], stRegistro c[], int v, int dim);

#endif // VARIOSREGISTROS_H_INCLUDED
