#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

typedef struct {
    stRegistro dato;
    struct stArbol * izquierda;
    struct stArbol * derecha;
} stArbol;

stArbol * initArbol();
stArbol * crearNodoArbol(stRegistro r);
stArbol * agregaNodoArbol(stArbol * arbol, stArbol * nuevo);

void muestraArbolPreOrder(stArbol * arbol);
void muestraArbolInOrder(stArbol * arbol);
void muestraArbolPostOrder(stArbol * arbol);

int mayorAlturaArbol(int izq, int der);
int esHoja(stArbol * arbol);
int alturaArbol(stArbol * arbol);
stArbol * arbolMasDerecha(stArbol * arbol);
stArbol * arbolMasIzquierdo(stArbol * arbol);

stArbol * eliminaNodoArbol(stArbol * arbol, char nombre[], char apellido[]);

int cuentaTotalNodoArbol(stArbol * arbol);
int cuentaHojaArbol(stArbol * arbol);

#endif // ARBOL_H_INCLUDED
