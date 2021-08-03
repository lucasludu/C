#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "registro.h"
#include "variosRegistros.h"
#include "listaSimple.h"

#define stPila stNodoSimple*

void initPila(stPila * pila);
stRegistro topePila(stPila * pila);
int pilaVacia(stPila * pila);
void apilarPila(stPila * pila, stRegistro r);
stRegistro desapilarPila(stPila * pila);
void muestraPila(stPila * pila);

#endif // PILA_H_INCLUDED
