#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

#define arRegistro "registroArchivo.dat"

typedef struct {
    int legajo;
    char apeNom[40];
    int nota;
} stNotaAlumnos;

typedef struct {
    stNotaAlumnos dato;
    struct stNodo * siguiente;
} stNodo;

stNodo * initLista();
stNodo * crearNodo(stNotaAlumnos dato);
stNodo * agregarPpio(stNodo * lista, stNodo * nuevo);
stNodo * buscaUltimoNodo(stNodo * lista);
stNodo * agregarFinal(stNodo * lista, stNodo * nuevo);
stNodo * agregarOrdenado(stNodo * lista, stNodo * nuevo);

stNodo * buscarNodo(stNodo * lista, int nota);
stNodo * borrarNodoBuscado(stNodo * lista, int nota);
stNodo * borrarListaCompleta(stNodo * lista);
stNodo * borrarPrimerNodo(stNodo * lista);
stNodo * borrarUltimoNodo(stNodo * lista);

void muestraUnaNota(stNotaAlumnos nota);
void muestraLista(stNodo * lista);

int sumarNotasLista(stNodo * lista);
int cuentaListaRegistros(stNodo * lista);


#endif // LISTA_H_INCLUDED
