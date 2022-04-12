#include "pilaa.h"

int main()
{
    srand(time(NULL));
    int op;
    Pila origen, destino;

    int dato;

    inicpila(&origen);
    inicpila(&destino);

    do
    {
        system("cls");

        menu();

        printf("\nIngrese ejercicio a realizar:\t");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:

            funcionCarga(&origen);

            break;

        case 2:

            mostrarPila(origen);

            break;

        case 3:

            calculoPilas(origen);

            break;

        case 4:

            mostrarPila(origen);
            BuscaMenorElemento(origen);

            break;

        case 5:

            insertarElemento(origen);

            printf("\nPila Origen insertada\n");
            mostrarPila(origen);

            break;

        case 6:

            ordenarSeleccion(origen);

            printf("\nPila Origen ordenada\n");
            mostrarPila(origen);

            break;

        case 7:

            printf("\nIngrese el dato a buscar\t");
            scanf("%d", &dato);

            buscarElemento(origen, dato);

            break;

        case 8:

            printf("\nIngrese el dato a eliminar\t");
            scanf("%d", &dato);

            eliminarElemento(origen, dato);

            break;

        case 9:

            pilaCapicua(origen);

            break;

        case 10:

            unir3pilas(&origen, &destino);

            break;

        case 11:

            Unir2pilasOrdenadas(&origen, &destino);

            break;

        case 12:

            ordenaInsercion(origen);


        default:

            printf("\nProceso Terminado\n");

        }
        system("pause > arch");

    } while (op != 0);

    return 0;
}
