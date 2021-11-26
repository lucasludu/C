#ifndef VARIOSCLIENTES_H_INCLUDED
#define VARIOSCLIENTES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

#define ARCLIENTE "clientes.dat"

//******************************* VALIDACIONES
int buscaUltimoID();
int existeDNICliente(char dni[]);

//******************************* ARCHIVOS
void archivarClientes (stCliente c);
void cargaArchivoClientes();
void muestraArchivoClientes(char archivo[]);

//******************************* ORDENACIONES POR SELECCION
int buscaPosMenorDNI (stCliente c[], int v, int inicio);
int buscaPosMenorApellido(stCliente c[], int v, int inicio);
void intercambioClientes (stCliente *a, stCliente *b);
void ordenaSeleccionDNI (stCliente c[], int v);
void ordenaSeleccionApellido (stCliente c[], int v);

//******************************* BUSQUEDA
int buscaPosId (int id);
stCliente buscaClienteApellido (char apellido[]);
stCliente buscaClienteDni (char dni[]);


#endif // VARIOSCLIENTES_H_INCLUDED
