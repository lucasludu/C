#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char animal[30];
    int cantidad;
    int habitat;            // Selva - Savana- Bosque - Mar
    int idEspecie;
    char especie[30];       // Mamiferos - Aves - Reptiles - Peces
} stRegistro;

typedef struct {
    char animal[30];
    int cantidad;
    int habitat;
} stAnimal;

typedef struct {
    int idEspecie;
    char especie[30];
} stEspecie;

typedef struct {
    stAnimal dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} stNodoArbol;

typedef struct {
    stEspecie dato;
    stNodoArbol * arbolAnimales;
} stCelda;

#endif // ESTRUCTURAS_H_INCLUDED
