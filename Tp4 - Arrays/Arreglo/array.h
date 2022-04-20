#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "pila.h"

#define ESC 27
#define DIM 50
#define MAX 60
#define MIN -40

#define CHARMAX 122
#define CHARMIN 97

void menuCarga();

int cargaArregloIntManual (int a[], int v, int dim);
int cargaArregloIntRandom (int a[], int v, int dim);
int tipoCargaInt (int a[], int v, int dim);
void muestraArregloInt (int a[], int v);

float cargaArregloFloatManual (float a[], int v, int dim);
float cargaArregloFloatRandom (float a[], int v, int dim);
float tipoCargaFloat (float a[], int v, int dim);
void muestraArregloFloat (float a[], int v);

char cargaArregloCharManual (char a[], int v, int dim);
char cargaArregloCharRandom (char a[], int v, int dim);
char tipoCargaChar (float a[], int v, int dim);
void muestraArregloChar (char a[], int v);

int sumaElementosInt (int a[], int v);
float sumaElementosfloat (float a[], int v);
char sumaElementoschar (char a[], int v);

int pilaToArreglo (Pila p, int a[], int v);
void arrayIntToPila (int a[], int v, Pila *p);
void arrayRealToPila (float a[], int v, Pila *p);
void arrayCharToPila (char a[], int v, Pila *p);

void muestroPilaInt (Pila p);
void muestroPilaFloat (Pila p);
void muestroPilaChar (Pila p);

int buscaElementoInt (int a[], int v, int dato);
void funcionBuscarInt (int a[], int v);

float buscaElementoFloat (float a[], int v, float dato);
void funcionBuscarFloat (float a[], int v);

char buscaElementoChar (float a[], int v, char dato);
void funcionBuscarChar (char a[], int v);

int insertarInt (int a[], int v, int dato);
void insertarOrdenadoInt (int a[], int pos, int dato);
void ordenaIntInsertado (int a[], int v);

int insertarFloat (float a[], int v, float dato);
void insertarOrdenadoFloat (float a[], int pos, float dato);
void ordenaFloatInsertado (float a[], int v);

int insertarChar (char a[], int v, char dato);
void insertarOrdenadoChar (char a_c[], int v, int caracter);
void ordenaCharInsertado (char a[], int v);

int buscarMayorInt (int a[], int v);
int buscaPosMayorInt (int a[], int v, int c);
void funcionMayorInt (int a[], int v);

float buscarMayorFloat (float a[], int v);
int buscaPosMayorFloat (float a[], int v, int c);
void funcionMayorFloat (float a[], int v);

char buscarMayorChar (char a[], int v);
int buscaPosMayorChar (char a[], int v, int c);
void funcionMayorChar (char a[], int v);








#endif // ARRAY_H_INCLUDED
