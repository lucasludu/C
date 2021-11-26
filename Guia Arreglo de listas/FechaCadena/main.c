#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "cadena.h"
#include "fecha.h"

#define ESC 27
#define DIM 50

int main(){
    int opcion = 0;

    char frase[] = "    texto para probar AAAA.      ";
    char frase1[] = "esto es una prueba JeJe";

    int validos = 0;
    int pos = 0;
    int e = 0;

    char date[128];
    int anio, mes, dia;

    do{
        system("cls");
        menuPrincipal();
        opcion = getch();
        system("cls");
        switch(opcion){
        case '1':
            do{
                system("cls");
                menuCadena();
                printf("\n\tEjercicio: ");
                scanf("%d", &opcion);
                system("cls");
                switch(opcion){
                case 1:
                    printf("\n\tPosicion a eliminar: ");
                    scanf("%d", &pos);
                    printf("\n\tSe elimina: %c", frase[pos]);
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    fStrDelPosChar(frase, pos);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    break;
                case 2:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    fStrLTrim(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    break;
                case 3:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    printf("Genga.");
                    fStrRTrim(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    printf("Genga.");
                    break;
                case 4:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    printf("Genga.");
                    fStrAllTrim(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    printf("Genga.");
                    break;
                case 5:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    fStrDelete(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    break;
                case 6:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    fStrToUpper(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    break;
                case 7:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    fStrToLower(frase);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    break;
                case 8:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrToUpperFirst(frase1);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 9:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrToUpperAllFirstLetters(frase1);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 10:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrFirstCharReplace(frase1, 'A', 'z');
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 11:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrAllCharReplace(frase1, 'A', 'z');
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 12:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    printf("\n\n");
                    e = fStrFindChar(frase1, 'x');
                    if(e){
                        printf("\n\tLa letra %c se encuentra en la posicion %d", 'x', e);
                    } else {
                        printf("\n\tNo se encontro una mierda.");
                    }
                    break;
                case 13:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrDelFirstChar(frase1, 'a');
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 14:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrDelAllChar(frase1, 'a');
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 15:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase1);
                    fStrReplace(frase1, 'a', 1);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase1);
                    break;
                case 16:
                    printf("\n\n\tTexto Original........:");
                    printf("%s", frase);
                    printf("%s", frase1);
                    fStrStr(frase, frase1, 5, 5);
                    printf("\n\tTexto Modificado .....:");
                    printf("%s", frase);
                    printf("%s", frase1);
                    break;
                }
                getch();
            } while(opcion!=0);
            break;
        case '2':
            do{
                system("cls");
                menuTiempo();
                printf("\n\tEjercicio: ");
                scanf("%d", &opcion);
                system("cls");
                switch(opcion){
                case 1:
                    fGetNow(date);
                    printf("\n\tFuncion fGetNow te muestra fecha y hora de hoy: %s", date);
                    break;
                case 2:
                    anio = fGetAnioLarge(date);
                    printf("\n\t La funcion fGetAnioLarge devuelve el anio: %d", anio);
                    break;
                }
                getch();
            } while(opcion!=0);
            break;
        }
        getch();
    } while(opcion!=27);
    return 0;
}

void menuPrincipal(){
    printf("\n\t\t< < < MENU PRINCIPAL > > >\n");
    printf("\n\t[ 1 ] - Cadena.\n");
    printf("\n\t[ 2 ] - Tiempo.\n");
    printf("\n\n\t\t\t\t[ ESC ] - SALIR.\n");
}

void menuCadena(){
    printf("\n\t\t< < < MENU DE CADENA > > >\n");
    printf("\n\t[ 01 ] - Elimina el carácter ubicado en la posicion dada.\n");
    printf("\n\t[ 02 ] - Elimina espacios en blanco a la izquiera de la cadena.\n");
    printf("\n\t[ 03 ] - Elimina espacios en blanco a la derecha de la cadena.\n");
    printf("\n\t[ 04 ] - Elimina todos los espacios en blanco de la cadena.\n");
    printf("\n\t[ 05 ] - Elimina el contenido de la cadena.\n");
    printf("\n\t[ 06 ] - Convierte la cadena en mayuscula.\n");
    printf("\n\t[ 07 ] - Convierte la cadena en minuscula.\n");
    printf("\n\t[ 08 ] - Convierte la la primera letra de la cadena en mayuscula.\n");
    printf("\n\t[ 09 ] - Convierte la primera letra de cada palabra en mayuscula.\n");
    printf("\n\t[ 10 ] - Reemplaza la primer ocurrencia de un caracter dado por otro.\n");
    printf("\n\t[ 11 ] - Reemplaza todas las ocurrencias de un caracter dado por otro.\n");
    printf("\n\t[ 12 ] - Busca un caracter en la cadena, retorna la posicion.\n");
    printf("\n\t[ 13 ] - Elimina la primer ocurrencia de un char.\n");
    printf("\n\t[ 14 ] - Elimina todas las ocurrencias de un char.\n");
    printf("\n\t[ 15 ] - Reemplaza un caracter en una posicion dada por otro.\n");
    printf("\n\n\t\t\t\t[ 00 ] - SALIR.\n");
}

void menuTiempo(){
    printf("\n\t\t< < < MENU DE TIEMPO > > >\n");
    printf("\n\t[ 01 ] - Muestra el tiempo de ahora.\n");
}
