#ifndef PASAJES_H_INCLUDED
#define PASAJES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "variosRegistros.h"
#include "listaSimple.h"
#include "listaDoble.h"
#include "Pila.h"
#include "Fila.h"
#include "Arbol.h"

/*************************************************************************************************************************************
 *
 *      ARCHIVO
 *
 ***/

// ARCHIVO --> ARREGLO
int archivo_Arreglo(char archivo[], stRegistro r[], int v, int dim);

// ARCHIVO --> LISTA SIMPLE
stNodoSimple * archivo_ListaSimple(char archivo[], stNodoSimple * lista);
void archivo_ListaSimplePD(char archivo[], stNodoSimple ** lista);

// ARCHIVO --> LISTA DOBLE
stNodoDoble * archivo_ListaDoble(char archivo[], stNodoDoble * lista);
void archivo_ListaDoblePD(char archivo[], stNodoDoble ** lista);

// ARCHIVO --> PILA
void archivo_Pila(char archivo[], stPila * pila);

// ARCHIVO --> FILA
void archivo_Fila(char archivo[], stFila * f);

// ARCHIVO --> ARBOL
stArbol * archivo_Arbol(char archivo[], stArbol * arbol);

/*************************************************************************************************************************************
 *
 *      LISTA SIMPLE
 *
 ***/

// LISTA SIMLE --> ARREGLO


// LISTA SIMPLE --> ARCHIVO
stNodoSimple * listaSimple_Archivo(stNodoSimple * lista);

// LISTA SIMPLE --> LISTA DOBLE
stNodoDoble * listaSimple_listaDoble(stNodoSimple * lista, stNodoDoble * lista2);

// LISTA SIMPLE --> PILA
void listaSimple_Pila(stNodoSimple * lista, stPila * pila);

// LISTA SIMPLE --> FILA
void listaSimple_Fila(stNodoSimple * lista, stFila * f);

// LISTA SIMPLE --> ARBOL
stArbol * listaSimple_Arbol(stNodoSimple * lista, stArbol * arbol);

/*************************************************************************************************************************************
 *
 *      LISTA DOBLE
 *
 ***/

// LISTA DOBLE --> ARREGLO


// LISTA DOBLE --> ARCHIVO
stNodoDoble * listaDoble_Archivo(stNodoDoble * lista2);

// LISTA DOBLE --> LISTA SIMPLE
stNodoSimple * listaDoble_listaSimple(stNodoDoble * lista2, stNodoDoble * lista);

// LISTA DOBLE --> PILA
void listaDoble_Pila(stNodoDoble * lista2, stPila * p);

// LISTA DOBLE --> FILA
void listaDoble_Fila(stNodoDoble * lista2, stFila * f);

// LISTA DOBLE --> ARBOL
stArbol * listaDoble_Arbol(stNodoDoble * lista2, stArbol * arbol);

/*************************************************************************************************************************************
 *
 *      PILA
 *
 ***/

// PILA --> ARREGLO


// PILA --> ARCHIVO
void pila_Archivo(stPila p, char archivo[]);

// PILA --> LISTA SIMPLE
stNodoSimple * pila_ListaSimple(stPila p, stNodoSimple * lista);

// PILA --> LISTA DOBLE
stNodoDoble * pila_ListaDoble(stPila p, stNodoDoble * lista2);

// PILA --> FILA
void pila_Fila(stPila p, stFila * f);

// PILA --> ARBOL
stArbol * pila_Arbol(stPila p, stArbol * arbol);

/*************************************************************************************************************************************
 *
 *      FILA
 *
 ***/

// FILA --> ARREGLO


// FILA --> ARCHIVO
void fila_Archivo(stFila f);

// FILA --> LISTA SIMPLE
stNodoSimple * fila_ListaSimple(stFila f, stNodoSimple * lista);

// FILA --> LISTA DOBLE
stNodoDoble * fila_ListaDoble(stFila f, stNodoDoble * lista);

// FILA --> PILA
void fila_Pila(stFila f, stPila * p);

// FILA --> ARBOL
stArbol * fila_Arbol(stFila f, stArbol * arbol);

/*************************************************************************************************************************************
 *
 *      ARBOL
 *
 ***/

// ARBOL --> ARREGLO


// ARBOL --> ARCHIVO
void arbol_Archivo(stArbol * arbol);

// ARBOL --> LISTA SIMPLE
stNodoSimple * arbol_ListaSimple(stArbol * arbol, stNodoSimple * lista);

// ARBOL --> LISTA DOBLE
stNodoDoble * arbol_ListaDoble(stArbol * arbol, stNodoDoble * lista2);

// ARBOL --> PILA
void arbol_Pila(stArbol * arbol, stPila * p);

// ARBOL --> FILA
void arbol_Fila(stArbol * arbol, stFila * f);

#endif // PASAJES_H_INCLUDED
