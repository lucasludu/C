
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"




int main()
{
    Pila mazo, puntosjug1, puntosjug2;
    inicpila(&mazo);
    inicpila(&puntosjug1);
    inicpila(&puntosjug2);
    int puntos, puntos1 = 0, puntos2 = 0, rondas = 0, rondas1 = 0, rondas2 = 0;
    int i, ganador, carta = 0, jugador1 = 0, jugador2 = 0;
    char control;

    system("title Juego de Cartas");


    do
    {
        system("cls");

        printf("Mezclando cartas...\n\n");
        system("pause");
        printf("\nCartas mezcladas.\n");

        srand(time(NULL));
        for (i = 0; i < 4; i++)
        {
            carta = (rand() % 10) + 1;
            apilar(&mazo, carta);
        }

        mostrar(&mazo);


        printf("\nRepartiendo cartas...\n\n");
        system("pause");

        while(!pilavacia(&mazo))
        {
            apilar(&puntosjug1, desapilar(&mazo));
            apilar(&puntosjug2, desapilar(&mazo));
        }
        printf("\n--------------------------------------\n");
        printf("\nCartas repartidas.\n\n");

        printf("\nCartas del jugador 1\n");
        mostrar(&puntosjug1);

        printf("\nCartas del jugador 2\n");
        mostrar(&puntosjug2);

        printf("\n--------------------------------------\n");
        printf("Contando los puntos...\n\n");
        system("pause");

        while(!pilavacia(&puntosjug1) && !pilavacia(&puntosjug2))
        {
            jugador1 = jugador1 + desapilar(&puntosjug1);
            jugador2 = jugador2 + desapilar(&puntosjug2);
        }

        if(jugador1 >= jugador2)
        {
            ganador = 1;
            rondas1++;
            puntos1 = puntos1 + jugador1 + jugador2;
        }
        else
        {
            ganador = 2;
            rondas2++;
            puntos2 = puntos2 + jugador1 + jugador2;
        }

        puntos = jugador1 + jugador2;

        system("cls");
        printf("\n--------------------------------------\n");
        if(ganador == 1)
        {

            printf("\nJugador 1 ");

            printf("ha ganado esta ronda con %i puntos\n", puntos);
        }
        else
        {

            printf("\nJugador 2 ");

            printf("ha ganado esta ronda con %i puntos\n", puntos);
        }

        printf("\nEn total el ");

        printf("jugador 1");

        printf(" lleva %i puntos\n", puntos1);

        printf("\nY el ");

        printf("jugador 2");

        printf(" lleva %i puntos\n", puntos2);
        printf("\n--------------------------------------\n");

        printf("\nQuieren jugar otra ronda? s/n\n");
        fflush(stdin);
        scanf("%c", &control);

        jugador1 = 0;
        jugador2 = 0;
        rondas++;
    }
    while(control == 's');

    system("cls");
    printf("\n--------------------------------------\n");

    printf("\nHan jugado %i ronda/s\n", rondas);

    printf("\nEl ");

    printf("jugador 1");

    printf(" ha ganado %i ronda/s y ha hecho %i puntos\n", rondas1, puntos1);
    printf("\nEl ");

    printf("jugador 2");

    printf(" ha ganado %i ronda/s y ha hecho %i puntos\n", rondas2, puntos2);

    if(puntos1 > puntos2)
    {
        printf("\nEl ganador es el ");

        printf("jugador 1\n");

    }
    else if(puntos1 == puntos2)
    {
        printf("\nHa habido un empate\n");
    }
    else
    {
        printf("\nEl ganador es el ");

        printf("jugador 2\n");

    }

    printf("\n--------------------------------------\n");

    return 0;
}
