#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[20];
    char apellido[20];
    char dni[9];
    int edad;
} stRegistro;

void getNombre(char n[]);
void getApellido(char a[]);
void getDNI(char dni[]);
int randomRango(int min, int max);

/*******************************************/

stRegistro cargaUnRegistroManual();
stRegistro cargaUnRegistroRandom();
void muestraUnRegistro(stRegistro r);


#endif // REGISTRO_H_INCLUDED
