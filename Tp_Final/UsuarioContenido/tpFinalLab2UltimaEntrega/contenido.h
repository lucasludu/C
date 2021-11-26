#ifndef CONTENIDO_H_INCLUDED
#define CONTENIDO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define ARCHIVO_CONTENIDO "contenidos.dat"

typedef struct {
    int idContenido;                     // auto incremental
   char titulo[30];
   char descripcion[300];
   char categoria[30];
   int likes;
   int puntosPorCompartir;
   int activo;                          // indica 1 o 0 si el contenido está activo
} stContenido;

stContenido cargaContenido();
void mostrarContenidos(stContenido contenido);
int ultimoIdContenido();
void mostrarArreglocontenidos(stContenido contenidos[], int i, int validos);

int posMenorTitulocontenidos(stContenido contenidos[], int pos, int cant);
int posMenorDescripcioncontenidos(stContenido contenidos[], int pos, int cant);
int posMenorCategoriaContenidos(stContenido contenidos[], int pos, int cant);
int posMayorLikesContenidos(stContenido contenidos[], int pos, int cant);
int posMenorPuntosCompartirContenidos(stContenido contenidos[], int pos, int cant);

void ordenaArreglocontenidosSeleccionTitulo(stContenido contenidos[], int cant);
void ordenaArreglocontenidosSeleccionDescripcion(stContenido contenidos[], int cant);
void ordenaArregloContenidosSeleccionCategoria(stContenido contenidos[], int cant);
void ordenaArregloContenidosSeleccionLikes(stContenido contenidos[], int cant);
void ordenaArregloContenidosSeleccionPuntosCompartir(stContenido contenidos[], int cant);

#endif // CONTENIDO_H_INCLUDED
