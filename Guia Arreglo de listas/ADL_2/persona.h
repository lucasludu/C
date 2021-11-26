#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int nroCliente;
    char nombre[30];
    int cantProductos;
} stPersona;

stPersona cargaUnaPersona();
void muestraPersona(stPersona p);

#endif // PERSONA_H_INCLUDED
