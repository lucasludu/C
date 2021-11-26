#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED

#include "Estructuras.h"
#define AR_ANIMALES "animales.dat"

int buscaPosEspecie(stCelda ada[], stEspecie e, int v);
int agregar(stCelda ada[], stEspecie e, int v);
int alta(stCelda ada[], stEspecie e, stAnimal a, int v);
int archToAda(stCelda ada[], int v, int dim);
void mostrarADA(stCelda ada[], int v);
void guardarEspecies(stCelda ada[],int v);
void guardarArbol(FILE* pf, stNodoArbol* arbol);
void mostrarAnimales(char archivo[]);

#endif // ADL_H_INCLUDED
