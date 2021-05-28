#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ESC 27

// M E N U ! ! !

void guia_0()
{
    printf("\n\n");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\t                              GUIA 0                             \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\t1 - Problemas Secuenciales.                                      \t||\n");
    linea_separadora();
    printf("\t||\t2 - Problemas Condicionales Selectivos Simples.                  \t||\n");
    linea_separadora();
    printf("\t||\t3 - Problemas Condicionales Selectivos Compuestos.               \t||\n");
    linea_separadora();
    printf("\t||\t4 - Problemas con repeticiones                                   \t||\n");
    linea_separadora();
    printf("\t||\t0- Salir                                                        \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
}


void problemas_secuenciales()
{
    printf("\n\n");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\t                       Problemas Secuenciales.                   \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\ta - Invierto capital en un banco. Cuanto gano despues de un mes  \t||\n");
    printf("\t||\t    si el pago paga un 2% mensual.                               \t\t||\n");
    linea_separadora();
    printf("\t||\tb - Una tienda ofrece un descuento del 15 porc sobre el total de la  \t||\n");
    printf("\t||\t    compra y un cliente desea saber cuanto debera pagar por el   \t||\n");
    printf("\t||\t    total de su compra.                                          \t||\n");
    linea_separadora();
    printf("\t||\tc - Un maestro desea saber que porcentaje de hombres y que       \t||\n");
    printf("\t||\t    porcentaje de mujeres hay en un grupo de estudiantes.        \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
}

void problemas_cond_select_simples()
{
    printf("\n\n");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||              Problemas Condicionales Selectivos Simples                \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\ta - Determinar si un alumno aprueba o no el curso, sabiendo que  \t||\n");
    printf("\t||\t    se aprueba con un promedio mayor o igual a 7, caso contrario   \t||\n");
    printf("\t||\t    desaprueba                                                    \t||\n");
    linea_separadora();
    printf("\t||\tb - En un almacen se hace un 20 porc de descuento a quien supere los \t||\n");
    printf("\t||\t    $5000. Cual sera la cantidad que pagara por la compra?       \t||\n");
    linea_separadora();
    printf("\t||\tc - Un obrero quiere calcular su salario semanal, el cual si     \t||\n");
    printf("\t||\t    trabaja 40 horas o menos se le paga $300 por hora.           \t||\n");
    printf("\t||\t    Si supera las 40 horas se le paga los $300 por las           \t||\n");
    printf("\t||\t    primeras 40 horas y $400 por cada hora extra.                \t||\n");
    linea_separadora();
    printf("\t||\td - Desarrolle un algoritmo que lea dos numeros y los imprima    \t||\n");
    printf("\t||\t    en forma ascendente.                                         \t||\n");
    linea_separadora();
    printf("\t||\te - Calcular el total a pagar por la compra de camisas. Si se    \t||\n");
    printf("\t||\t    compran 3 o mas se aplica el 20 porc sobre el total de la        \t||\n");
    printf("\t||\t    compra y son menos se aplica el 10 porc.                         \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
}

void problemas_cond_select_compuestos()
{
    printf("\n\n");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||           Problemas Condicionales Selectivos Compuestos                \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\ta - Leer 2 numeros, si son iguales que los multiplique, si el    \t||\n");
    printf("\t||\t    primero es mayor que el segundo que los reste y sino que     \t||\n");
    printf("\t||\t    los sume.                                                    \t||\n");
    linea_separadora();
    printf("\t||\tb - Leer 3 numeros diferentes e imprimir el mayor de los 3.      \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
}

void problemas_repeticiones()
{
    printf("\n\n");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||                      Problemas con Repeticiones                      \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
    printf("\t||\t                                                                 \t||\n");
    printf("\t||\ta - Calcular le promedio de un alumno que tiene 7 calificaciones \t||\n");
    printf("\t||\t    en la materia de programacion 1.                             \t||\n");
    linea_separadora();
    printf("\t||\tb - Leer 10 numeros y obtener su cubo y su cuarta.               \t||\n");
    linea_separadora();
    printf("\t||\tc - Leer 10 numeros e imprimir los numeros positivos.            \t||\n");
    linea_separadora();
    printf("\t||\td - Leer 15 numeros negativos y convertirlos a positivos e       \t||\n");
    printf("\t||\t    imprimir dichos numeros.                                     \t||\n");
    linea_separadora();
    printf("\t||\te - Suponga que un conjunto de calificaciones de 40 alumnos.     \t||\n");
    printf("\t||\t    Calcular la calificacion media y la calificacion mas         \t||\n");
    printf("\t||\t    baja de todo el grupo              .                         \t||\n");
    linea_separadora();
    printf("\t||\tf - Calcular e imprimir la tabla de multiplicar de un numero     \t||\n");
    printf("\t||\t    cualquiera. Imprimir multiplicando, multiplicador y el       \t||\n");
    printf("\t||\t    producto.                                                    \t||\n");
    printf("\t||\t                                                                 \t||");
    linea_menu();
}



void linea_menu()
{
    int i;
    printf("\n\t||");
    for (i = 4; i < 82; i++)
    {
        printf("X");
    }
    printf("||\n");
}

void linea_separadora()
{
    printf("\t||");
    for (int i = 2; i < 80; i++)
    {
        printf("-");
    }
    printf("||\n");
}



