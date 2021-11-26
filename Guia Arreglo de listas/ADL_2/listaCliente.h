#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

typedef struct {
    stPersona dato;
    struct stNodo * siguiente;
} stNodo;

stNodo * initListaCliente();
stNodo * crearNodoCliente(stPersona dato);
stNodo * agregarListaClientePpio(stNodo * lista, stNodo * nuevo);
stNodo * buscaUltimoNodo(stNodo * lista);
stNodo * agregarListaClienteFinal(stNodo * lista, stNodo * nuevo);
stNodo * agregarListaClienteOrdenado(stNodo * lista, stNodo * nuevo);

void muestraNodoCliente(stNodo * nodo);
void muestraListaCliente(stNodo * lista);

stNodo * buscaListaCliente_Nombre(stNodo * lista, char nombre[20]);
stNodo * borraNodoCliente_Nombre(stNodo * lista, char nombre[20]);
stNodo * borrarPrimerNodoCliente(stNodo * lista);
stNodo * borrarUltimoNodoCliente(stNodo * lista);
stNodo * borrarListaClientesCompleta(stNodo * lista);

#endif // LISTACLIENTE_H_INCLUDED
