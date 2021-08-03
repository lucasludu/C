#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "registro.h"
#include "variosRegistros.h"
#include "pasajes.h"
#include "listaSimple.h"
#include "listaDoble.h"
#include "Pila.h"
#include "Fila.h"
#include "Arbol.h"

#define ESC 27
#define DIM 50

#define arRegistro "registro.dat"
#define arMayor "mayor.dat"
#define arMenor "menor.dat"
#define arRegistro2 "registro2.dat"

int main() {

    srand(time(NULL));
    char op;
    int cantReg = 0;
    int validos = 0;
    char letra;
    char nombre[20];
    char apellido[20];

    stRegistro registro[DIM];
    stNodoSimple * lista = initListaSimple();
    stNodoDoble * lista2 = initListaDoble();

    stPila pila;
    initPila(&pila);

    stFila fila;
    initFila(&fila);

    stArbol * arbol = initArbol();

    do {
        system("cls");
        menuPrincipal();
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            printf("\n\tIngrese la cantidad de registros a cargar: ");
            scanf("%d", &cantReg);
            cargaArchivoRandom(cantReg);
            break;
        case '2':
            muestraArchivo(arRegistro);
            break;
        case '3':
            lista = archivo_ListaSimple(arRegistro, lista);
            if(lista) {
                muestraListaSimple(lista);
            } else {
                printf("NO hay nada.");
            }
            break;
        case '4':
            lista2 = archivo_ListaDoble(arRegistro, lista2);
            if(lista2) {
                muestraListaDoble(lista2);
            } else {
                printf("NO hay nada");
            }
            break;
        case '5':
            archivo_Pila(arRegistro, &pila);
            muestraPila(&pila);
            break;
        case '6':
            archivo_Fila(arRegistro, &fila);
            muestraFila(&fila);
            break;
        case '7':
            arbol = archivo_Arbol(arRegistro, arbol);
            if(arbol) {
                muestraArbolPostOrder(arbol);
            } else {
                printf("No hay nada");
            }
            break;
        case '8':
            arbol_Archivo(arbol);
            muestraArchivo(arRegistro2);
            break;
        }
        system("pause");
    } while(op != 27);
    return 0;
}

void menuPrincipal() {
    printf("\n\t[ 01 ] - Carga Archivo.\n");
    printf("\n\t[ 02 ] - Muestra Archivo.\n");
    printf("\n\t[ 03 ] - Pasa de Archivo --> Lista Simple.\n");
    printf("\n\t[ 04 ] - Pasa de Archivo --> Lista Doble.\n");
    printf("\n\t[ 05 ] - Pasa de Archivo --> Pila.\n");
    printf("\n\t[ 06 ] - Pasa de Archivo --> Fila.\n");
    printf("\n\t[ 07 ] - Pasa de Archivo --> Arbol.\n");
    printf("\n\t[ 08 ] - .\n");
    printf("\n\t[ 09 ] - .\n");
    printf("\n\t[ 10 ] - .\n");
    printf("\n\t[ 11 ] - .\n");
    printf("\n\n\n\t\t\t\t\t[ ESC ] - SALIR DEL PROGRAMA.\n");
}

