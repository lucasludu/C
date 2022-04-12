#include "funcion.h"

int main()
{
    int num;
    char opcion;
    srand(time(NULL));
    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    do
    {
        system("cls");

        menu();

        printf("\nIngrese ejercicio a realizar\n");
        printf("\nEjercicio:\t");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:

            printf("\nIngrese cantidad de elementos de la pila\n");
            printf("\nSe ingreso:\t");
            scanf("%d", &num);
            cargarPila(&origen, num);

            system("cls");
            system("pause > arch");

            printf("\nPila Origen\n");
            muestraPila(origen);

            break;

        case 2:

            printf("\nPila Origen inicial\n");
            muestraPila(origen);

            pasaPila(&origen, &destino);

            printf("\nPila Origen final\n");
            muestraPila(origen);

            printf("\nPila Destino\n");
            muestraPila(destino);

            break;

        case 3:

            printf("\nPila Origen inicial\n");
            muestraPila(origen);

            pasaPilaMismoOrden(&origen, &destino);

            printf("\nPila Origen final\n");
            muestraPila(origen);

            printf("\nPila Destino\n");
            muestraPila(destino);

            break;

        case 4:

            printf("\nPila Origen inicial\n");
            muestraPila(origen);

            printf("\nEl menor elemento de la pila es: [ %d ]\n", menorElementoPila(&origen));

            printf("\nPila Origen final\n");
            muestraPila(origen);

            break;

        case 5:

            printf("\nPila Origen inicial\n");
            muestraPila(origen);

            ordenarMetodoSeleccion(&origen, &destino);

            printf("\nPila Origen final\n");
            muestraPila(origen);

            break;

        case 6:

            printf("\nIngrese elemento a insertar\n");
            printf("\nSe ingreso:\t");
            scanf("%d", &num);

            insertarElementoPila(&origen, num);

            printf("\nPila Origen\n");
            muestraPila(origen);

            break;

        case 7:

            printf("\nPila Origen inicial\n");
            muestraPila(origen);

            ordenarMetodoInsercion(&origen, &destino);

            printf("\nPila Origen final\n");
            muestraPila(origen);

            break;

        case 8:

            num = sumar2Topes(origen);

            printf("\nLa suma de los dos topes es: [ %d ]\n", num);

            break;

        case 9:

            calculoPilas(origen);

            break;

        case 10:

            num = pilaToDecimal(origen);
            printf("\nDecimal: [ %d ]\n", num);

            break;

        default:

            printf("\n\n\tPROCESO TERMINADO\n\n");

        }
        system("pause > arch");

    } while (opcion != 0);

    return 0;
}
