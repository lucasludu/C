#ifndef ARBOLCONTENIDO_H_INCLUDED
#define ARBOLCONTENIDO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "contenido.h"

#define ARCHIVO_CONTENIDO "contenidos.dat"
#define ARCHIVO_CONT_FAVORITO "contenidoFavorito.dat"

typedef struct {
    stContenido dato;
    struct nodoArbolContenido * izq;
    struct nodoArbolContenido * der;
} nodoArbolContenido;

nodoArbolContenido * inicArbol();
nodoArbolContenido * crearnodoArbolContenido(stContenido contenido);

nodoArbolContenido * rotarIzq(nodoArbolContenido * arbol);
nodoArbolContenido * rotarDer(nodoArbolContenido * arbol);
nodoArbolContenido * balancearArbol(nodoArbolContenido * arbol);

nodoArbolContenido * insertarNodoArbol(nodoArbolContenido * arbol, nodoArbolContenido * nuevo);
nodoArbolContenido * insertarNodoArbolBalanceado(nodoArbolContenido * arbol, nodoArbolContenido * nuevo);

void cargaArbolContenido(nodoArbolContenido * arbol);
void altaContenido(nodoArbolContenido * arbol);

void MostrarArbol(nodoArbolContenido * arbol, int opcion);
void MostrararbolPreorder(nodoArbolContenido * arbol);
void MostrarArbolInorder(nodoArbolContenido * arbol);
void MostrararbolPostorder(nodoArbolContenido * arbol);

nodoArbolContenido * buscarContenidoId(nodoArbolContenido * arbol, int idcontenido);
nodoArbolContenido * buscarContenidoTitulo(nodoArbolContenido * arbol, char titulo[]);

int cuentaNodoArbol(nodoArbolContenido * arbol);
int esHojaArbol(nodoArbolContenido * arbol);
int cuentaHojasArbol(nodoArbolContenido * arbol);
int alturaArbol(nodoArbolContenido * arbol);
int eliminarcontenido(nodoArbolContenido * arbol, int idcontenido);
nodoArbolContenido * NMI(nodoArbolContenido * arbol);
nodoArbolContenido * NMD(nodoArbolContenido * arbol);
nodoArbolContenido * borrarNodoArbol(nodoArbolContenido * arbol, int idcontenido);
nodoArbolContenido * borrarArbol(nodoArbolContenido * arbol);

void arbolContenidoToArchivo(char archivo[], nodoArbolContenido * arbol);
void arbolContenidoToArchivoID(char archivo[], nodoArbolContenido * arbol, int id);
void arbolContenidoToArchivoR(FILE * pArch, nodoArbolContenido * arbol);
nodoArbolContenido * archivoToArbolContenido(char archivo[], nodoArbolContenido * arbol, int balanceado);
int arbolAArreglo(int tipo, nodoArbolContenido * arbol, stContenido contenidos[], int i, int dim, char filtro[], int filtro2);

void calificarContenido(nodoArbolContenido * arbol, int idContenido, int calificacion);
int listarContenidos(int tipo, stContenido contenidos[], int validos, int dim, int lleno, nodoArbolContenido * arbol);
int consultacontenidos(int tipo, char filtro[], int filtro2, stContenido contenidos[], int dim, nodoArbolContenido * arbol);



#endif // ARBOLCONTENIDO_H_INCLUDED
