#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

typedef struct {
    int year;
    int month;
    int day;
} stFecha;

typedef struct {
    int idProducto;
    int idCliente;
    stFecha fecha;
    char producto[20];
    float precio;
    int stock;
//    char baja;
} stProducto;

stProducto cargaUnProducto(int id);
void cabeceraUnProducto();
void muestraProducto(stProducto p, int * coordy, int * incy);



#endif // PRODUCTO_H_INCLUDED
