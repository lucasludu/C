#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

#define MAX 9
#define MIN 0

void menu();
void cargarPila (Pila *p, int cant);
int ExistenciaPila (Pila p, int dato);
void muestraPila (Pila p);
void pasaPila (Pila *p, Pila *q);
void pasaPilaMismoOrden (Pila *p, Pila *q);
int menorElementoPila (Pila *p);
void ordenarMetodoSeleccion (Pila *p, Pila *q);
void insertarElementoPila (Pila *p, int elemento);
void ordenarMetodoInsercion (Pila *p, Pila *q);
int sumar2Topes (Pila p);
int sumaPila (Pila p);
int cuentaPila (Pila p);
float division (int a, int b);
float promedio (Pila p);
void calculoPilas (Pila p);
int pilaToDecimal (Pila p);

#endif // FUNCION_H_INCLUDED
