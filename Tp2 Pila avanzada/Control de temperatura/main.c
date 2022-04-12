#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "pila.h"

#define ESC 27

#define MAX 30
#define MIN 10

int main()
{
    Pila temperatura;

    inicpila(&temperatura);

    // INICIO.

    cargaTemperatura(&temperatura);
    cargando();
    mostrarTemperatura(temperatura);

    // FIN.
}

void cargaTemperatura (Pila *T)
{
    int temp;

    for (int i = 0; i < 24; i++)
    {
        temp = rand() % (MAX - MIN + 1) + MIN;
        printf("\nLa temperatura de las %d horas es de: [ %d ] grados\n", i, temp);
        Sleep(200);
        apilar(T, temp);
        system("cls");
    }
}

void mostrarTemperatura (Pila T)
{
    Pila aux;
    inicpila(&aux);

    printf("\n\n");
    while (!pilavacia(&T))
    {
        printf(" %d |", tope(&T));
        apilar(&aux, desapilar(&T));
    }
    printf("\n\n");
}

void cargando ()
{
    printf("\nCARGANDO: ");
    for (int i = 0; i < 20; i++)
    {
        Sleep(300);
        printf("%c", 219);
    }
    system("cls");
}
