#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"
#include "listaDoble.h"

typedef struct {
    stNodoDoble * inicio;
    stNodoDoble * fin;
} stFila;

void initFila(stFila * f);
stRegistro topeFila(stFila * f);
int filaVacia(stFila * f);
void apilarFila(stFila * f, stRegistro r);
stRegistro desapilarFila(stFila * f);
void muestraFila(stFila * f);

#endif // FILA_H_INCLUDED
