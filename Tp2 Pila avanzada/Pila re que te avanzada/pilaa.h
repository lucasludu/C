#ifndef PILAA_H_INCLUDED
#define PILAA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "pila.h"

#define ESC 27

#define MAX 50
#define MIN 0

void menu();
int existenciaPila (Pila p, int dato);
int cargarPilaManual (Pila *p);
int cargarPilaManualconRepet (Pila *p);
void cargarpilaRandom (Pila *p, int cantidad);
void funcionCarga (Pila *p);
void mostrarPila (Pila p);
int sumarPila (Pila p);
int cuentaPila (Pila p);
float divPilas (int a, int b);
float promedioPila (Pila p);
void calculoPilas (Pila p);
void BuscaMenorElemento (Pila p);
void insertarElemento (Pila p);
void ordenarSeleccion (Pila p);
void  buscarElemento (Pila p, int elemento);
void eliminarElemento (Pila p, int elemento);
void copiaPila (Pila p, Pila *q);
void pilaCapicua (Pila p);
void unir3pilas (Pila *p, Pila *q);
void Unir2pilasOrdenadas (Pila *p, Pila *q);
void ordenaInsercion (Pila p);



#endif // PILAA_H_INCLUDED
