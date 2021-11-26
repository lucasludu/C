#ifndef NODOCAJA_H_INCLUDED
#define NODOCAJA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "persona.h"
#include "listaCliente.h"

typedef struct {
    int nroCaja;
    char medioPago[30];
} stCaja;

typedef struct {
    stCaja dato;
    stNodo * listaCliente;
    struct stNodoCaja * siguiente;
} stNodoCaja;

stNodoCaja * inicListaCaja();
stNodoCaja * crearNodoCaja(stCaja dato);
stNodoCaja * agregarPpioCaja(stNodoCaja * lista, stNodoCaja * nuevo);
stNodoCaja * buscarCaja(stNodoCaja * lista, int nroCaja);
stCaja ingresarCaja(int nroCaja);
stNodoCaja * alta(stNodoCaja * listaCaja, stNodo * nuevoCliente, int nroCaja);
void muestraNodoCaja(stNodoCaja * caja);
void muestraListaCajaClientes(stNodoCaja * lista);


#endif // NODOCAJA_H_INCLUDED
