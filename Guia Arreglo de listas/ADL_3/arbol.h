#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Estructuras.h"

stNodoArbol * inicTree();
stNodoArbol * crearNodoTree(stAnimal datos);
stNodoArbol * insertarArbol (stNodoArbol * arbol, stNodoArbol * nuevo);
void mostrarUnAnimal(stAnimal a);
void muestraArbol(stNodoArbol * arbol);
void preOrder(stNodoArbol * arbol);
void inOrder(stNodoArbol * arbol);
void postOrder(stNodoArbol * arbol);
stNodoArbol * buscarNombreAnimal(stNodoArbol * arbol, char nombre[20]);
int mayorAltura(int izquierdo, int derecho);
int alturaDelArbol(stNodoArbol * arbol);
int cuentaCantidadNodosArbol(stNodoArbol * arbol);
int esHoja(stNodoArbol * arbol);
int cuentaHojas(stNodoArbol * arbol);

#endif // ARBOL_H_INCLUDED
