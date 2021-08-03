#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "registro.h"

typedef struct {
    stRegistro dato;
    struct stNodoSimple * siguiente;
} stNodoSimple;

// CREO E INICIALIZO LA LISTA SIMPLE
stNodoSimple * initListaSimple();
stNodoSimple * crearNodoSimple(stRegistro r);

// AGREGO DESDE EL PRINCIPIO EL NODO SIMPLE
stNodoSimple * cargaListaSimplePpio (stNodoSimple * lista, stNodoSimple * nuevo);
void cargaListaSimplePpioPD(stNodoSimple ** lista, stNodoSimple * nuevo);
stNodoSimple * cargaListaSimplePpioRecursivo(stNodoSimple * lista, stNodoSimple * nuevo);

// AGREGO DESDE EL FINAL EL NODO SIMPLE
stNodoSimple * cargaListaSimpleFinal(stNodoSimple * lista, stNodoSimple * nuevo);
void cargaListaSimpleFinalPD(stNodoSimple ** lista, stNodoSimple * nuevo);
stNodoSimple * cargaListaSimpleFinalRecursivo(stNodoSimple * lista, stNodoSimple * nuevo);

// AGREGO ORDENADO EL NODO SIMPLE
stNodoSimple * cargaListaSimpleOrdenadaApellido(stNodoSimple * lista, stNodoSimple * nuevo);
void cargaListaSimpleOrdenadaDniPD(stNodoSimple ** lista, stNodoSimple * nuevo);
stNodoSimple * cargaListaSimpleOrdenadaEdadRecursivo(stNodoSimple * lista, stNodoSimple * nuevo);

// MUESTRO NODO Y LISTA SIMPLE
void muestraNodoSimple(stNodoSimple * nodo);
void muestraListaSimple(stNodoSimple * lista);
void muestraListaSimplePD(stNodoSimple ** lista);
void muestraListaSimpleRecursivo(stNodoSimple * lista);

// BORRO NODO SIMPLE
stNodoSimple * borrarNodoSimple(stNodoSimple * lista, char nombre[20], char apellido[20]);
void borrarNodoSimplePD(stNodoSimple ** lista, char nombre[20], char apellido[20]);
stNodoSimple * borrarNodoSimpleRecursivo(stNodoSimple * lista, char nombre[20], char apellido[20]);
stNodoSimple * borrarPrimerNodoSimple(stNodoSimple * lista);
stNodoSimple * borrarUltimoNodoSimple(stNodoSimple * lista);

// BUSCA NODO POR NOMBRE Y APELLIDO
stNodoSimple * buscarNodoSimpleApellidoNombre(stNodoSimple * lista, char nombre[20], char apellido[20]);

// SUMA EDADES DE LA LISTA
int sumaEdadesListaSimple(stNodoSimple * lista);
int sumaEdadesListaSimpleRecursiva(stNodoSimple * lista);
int sumaEdadesFiltroListaSimple(stNodoSimple * lista, int limite);

// CUENTA EDADES DE LA LISTA
int cuentaEdadesListaSimple(stNodoSimple * lista);
int cuentaEdadesListaSimpleRecursivo(stNodoSimple * lista);
int sumaEdadesFiltroListaSimpleRecursivo(stNodoSimple * lista);

// BUSCA LA PERSONA MAYOR DE EDAD DE LA LISTA
stNodoSimple * buscaMayorRegistro(stNodoSimple * lista);
stNodoSimple * buscaMayorRegistroRecursivo(stNodoSimple * lista);

// BUSCA LA PERSONA MENOR DE EDAD DE LA LISTA
stNodoSimple * buscaMenorRegistro(stNodoSimple * lista);
stNodoSimple * buscaMenorRegistroRecursivo(stNodoSimple * lista);

#endif // LISTASIMPLE_H_INCLUDED
