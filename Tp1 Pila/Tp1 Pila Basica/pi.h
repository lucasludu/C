#ifndef PI_H_INCLUDED
#define PI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

#define ESC 27

#define MAX -10
#define MIN 50

void menu();

int existencia (Pila p, int dato);

int cargarPilaInt (Pila *p);
void cargarPilaIntRandom (Pila *p, int cantidad);
void elegirCarga (Pila *p);

void mostrarPilaInt (Pila p);

void pasaPila (Pila *p, Pila *q);
void PasaPilaMismoOrden (Pila *p, Pila *q);
void funcionPase (Pila *p, Pila *q);

void copiaPila (Pila p, Pila *q);

void pilaOrigenInverso (Pila *p);
void baseTotope (Pila *p);
void topeToBase (Pila *p);
void pasaElemento (Pila *p);
void pasaPilaAlternativa (Pila *p, Pila *a, Pila *b);

void comparaCant (Pila *p, Pila *q);
void comparaSimilitud (Pila *p, Pila *q);
void comparaPila (Pila *p, Pila *q);

void eliminarElemiguales (Pila *p, Pila *q);
void eliminaTodo (Pila *p, Pila *q);
void funcionEliminar (Pila *p, Pila *q);

void pasePilaMayoresMenores (Pila *p, Pila *a, Pila *b, int limite);
void PilasParesImpares (Pila *p, Pila *a, Pila *b);

#endif // PI_H_INCLUDED
