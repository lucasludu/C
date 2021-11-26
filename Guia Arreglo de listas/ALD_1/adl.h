#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "registro.h"
#include "lista.h"

#define arRegistro "registroArchivo.dat"
#define arRegAprob "aprobados.dat"
#define arRegDesaprob "desaprobados.dat"

typedef struct {
    int idMateria;
    char materia[40];
} stMateria;

typedef struct {
    stMateria dato;
    stNodo * listaNotas;
} stCelda;

int buscaPosMateria(stCelda adl[], stMateria materia, int v);
int agregar(stCelda adl[], stMateria materia, int v);
int alta (stCelda adl[], stMateria materia, stNotaAlumnos nota, int v);
int archToAdl(stCelda adl[], int v, int dim);
void muestraAdl(stCelda adl[], int v);
void guardarAprobadosDesaprobados(stCelda adl[], int v);

#endif // ADL_H_INCLUDED
