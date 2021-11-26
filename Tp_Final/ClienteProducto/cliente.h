#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char dni[10];
    char nombre[20];
    char apellido[20];
    char telefono[20];
    char domicilio[30];
    char baja;
} stCliente;

stCliente cargaUnCliente();
void cabeceraClientes();
void muestraUnCliente(stCliente c, int *coordY, int *incY);


#endif // CLIENTE_H_INCLUDED
