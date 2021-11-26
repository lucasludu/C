#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>

#include "registro.h"

#define AR_REGISTRO "registroMedico.dat"

#define ESC 27
#define DIM 50

int main() {
    char op;
    nodoCelda * lista = inicNodoCelda();
    char nombreEspecialidad[30];
    do {
        system("cls");
        menu();
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            lista = cargarCeldasDesdeArchivo(lista, AR_REGISTRO);
            break;
        case '2':
            if(lista) {
                mostrarCeldas(lista);
            } else {
                printf("\n\t La lista se encuentra vacia.");
            }
            break;
        case '3':
            lista = cargarRegistros(lista);
            break;
        case '4':
            if(lista) {
                subProgramaEj5(lista);
            } else {
                printf("\n\t No hay registros.");
            }
            break;
        case '5':
            if(lista) {
                subProgramaEj6(lista);
            } else {
                printf("\n\t No hay registros.");
            }
            break;
        case '6':
            if(lista) {
                subProgramaEj7(lista);
            } else {
                printf("\n\t No hay registros.");
            }
            break;
        case '7':
            if(!lista) {
                printf("Ingrese nombre de la especialidad\n");
                fflush(stdin);
                gets(nombreEspecialidad);
                strcat(nombreEspecialidad, ".dat");
                lista = cargarCeldasDesdeArchivo(lista, nombreEspecialidad);
                mostrarCeldas(lista);
            } else {
                printf("La lista no debe estar cargada previamente\n");
            }
            break;
        }
        getch();
    } while(op != 27);
    return 0;
}

void menu() {
    printf("\n\t 1: Cargar registros desde un archivo\n");
    printf("\n\t 2: Mostrar todos las registros\n");
    printf("\n\t 3: Cargar nuevos registros\n");
    printf("\n\t 4: Saber si un paciente se ha atendido en cierta especialidad\n");
    printf("\n\t 5: Saber que especialidad tiene mas atenciones\n");
    printf("\n\t 6: Guardar especialidad en un archivo\n");
    printf("\n\t 7: Ver registros guardados en el archivo del Ej 6\n");
    printf("\n\n\t\t\t < < ESC > > para salir del programa.");
}
