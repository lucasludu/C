#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

#include "registro.h"
#include "lista.h"
#include "adl.h"

#define arRegistro "registroArchivo.dat"
#define arRegAprob "aprobados.dat"
#define arRegDesaprob "desaprobados.dat"

#define ESC 27
#define DIM 50

int main() {
    char op;
    stCelda adl[DIM];
    int validos = 0;
    int total;
    do {
        system("cls");
        printf("\n\t [ 01 ] - Muestra Archivo de Registros.");
        printf("\n\t [ 02 ] - Archivo ---> ADL.");
        printf("\n\t [ 03 ] - Archivo de Aprobados/Desaprobados.");
        printf("\n\n\t\t\t< < ESC > > para salir del programa.");
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            mostrarRegistros(arRegistro);
            break;
        case '2':
            validos = archToAdl(adl, validos, DIM);
            if(validos) {
                muestraAdl(adl, validos);
            } else {
                printf("\n\t No hay lista.");
            }
            break;
        case '3':
            guardarAprobadosDesaprobados(adl, validos);
            do {
                system("cls");
                printf("\n\t[ 01 ] - Aprobados");
                printf("\n\t[ 02 ] - Desaprobados");
                op = getch();
                system("cls");
                switch(op) {
                case '1':
                    printf("\n\t Total de Alumnos Aprobados: %d", cuentaRegistros(arRegAprob, sizeof(stRegistroArchivo)));
                    mostrarRegistros(arRegAprob);
                    break;
                case '2':
                    printf("\n\t Total de Alumnos Desaprobados: %d", cuentaRegistros(arRegDesaprob, sizeof(stRegistroArchivo)));
                    mostrarRegistros(arRegDesaprob);
                    break;
                }
                getch();
            } while(op != 27);
            break;
        }
        getch();
    } while(op != 27);
    return 0;
}


