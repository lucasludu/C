#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

typedef struct {
    stRegistro dato;
    struct stNodoDoble * siguiente;
    struct stNodoDoble * anterior;
} stNodoDoble;

// INICIALIZA Y CREA LA LISTA DOBLE
stNodoDoble * initListaDoble();
stNodoDoble * crearNodoDoble(stRegistro r);

// CARGA LA LISTA DOBLE DESDE EL PRINCIPIO
stNodoDoble * cargaListaDoblePpio(stNodoDoble * lista, stNodoDoble * nuevo);
void cargaListaDoblePpioPD(stNodoDoble ** lista, stNodoDoble * nuevo);
stNodoDoble * cargaListaDoblePpioRecursivo(stNodoDoble * lista, stNodoDoble * nuevo);

// CARGA LA LISTA DOBLE DESDE EL PRINCIPIO
stNodoDoble * buscaUltimoNodoDoble(stNodoDoble * lista);
stNodoDoble * cargaListaDobleFinal(stNodoDoble * lista, stNodoDoble * nuevo);
void cargaListaDobleFinalPD(stNodoDoble ** lista, stNodoDoble * nuevo);
stNodoDoble * cargaListaDobleFinalRecursiva(stNodoDoble * lista, stNodoDoble * nuevo);

// CARGA LA LISTA DOBLE ORDENADA
stNodoDoble * cargaListaDobleOrdenadoApellido(stNodoDoble * lista, stNodoDoble * nuevo);
void cargaListaDobleOrdenadoDniPD(stNodoDoble ** lista, stNodoDoble * nuevo);
stNodoDoble * cargaListaDobleOrdenadoEdadRecursivo(stNodoDoble * lista, stNodoDoble * nuevo);

// MUESTRA NODO Y LISTA DOBLE
void muestraNodoDoble(stNodoDoble * nodo);
void muestraListaDoble(stNodoDoble * lista);
void muestraListaDobleRecusiva(stNodoDoble * lista);
stRegistro muestraPrimerNodoDoble(stNodoDoble * lista);

// ELIMINA NODO DE LA LISTA DOBLE
stNodoDoble * eliminaNodoDoble(stNodoDoble * lista, char apellido[20], char nombre[20]);
void eliminaNodoDoblePD(stNodoDoble ** lista, char apellido[], char nombre[]);
stNodoDoble * eliminaNodoDobleRecursivo(stNodoDoble * lista, char apellido[], char nombre[]);
stNodoDoble * eliminaPrimerNodoDoble(stNodoDoble * lista);


#endif // LISTADOBLE_H_INCLUDED
