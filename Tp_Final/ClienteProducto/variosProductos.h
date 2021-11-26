#ifndef VARIOSPRODUCTOS_H_INCLUDED
#define VARIOSPRODUCTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"
#include "variosClientes.h"
#include "producto.h"

#define ARPRODUCTO "productos.dat"


int validaFecha(int anio, int mes, int dia);
int buscaUltimoIDConsumo();

void muestraArregloProducto (stProducto p[], int v);

void archivarConsumo (stProducto p);
void cargaArchivoProducto(stCliente c);
void cargaProdcuto_SegunCliente();

#endif // VARIOSPRODUCTOS_H_INCLUDED
