#include "pi.h"

int main()
{
    srand(time(NULL));
    int num, opcion;

    Pila origen, destino, A, B;

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&A);
    inicpila(&B);

    do
    {
        system("cls");

        menu();

        printf("\nIngrese ejercicio a realizar:\t");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:

            elegirCarga(&origen);

            break;

        case 2:

            mostrarPilaInt(origen);
            break;

        case 3:

            funcionPase(&origen, &destino);

            printf("\nOrigen\n");
            mostrarPilaInt(origen);
            printf("\Destino\n");
            mostrarPilaInt(destino);

            break;

        case 4:

            copiaPila(origen, &destino);

            printf("\nOrigen Final\n");
            mostrarPilaInt(origen);
            printf("\Destino\n");
            mostrarPilaInt(destino);

            break;

        case 5:

            printf("\nPila Origen\n");
            mostrarPilaInt(origen);

            pilaOrigenInverso(&origen);

            printf("\nPila Origen Inverso\n");
            mostrarPilaInt(origen);

        case 6:

            printf("\nPila Origen\n");
            mostrarPilaInt(origen);

            pasaElemento(&origen);

            printf("\nPila Origen Inverso\n");
            mostrarPilaInt(origen);

            break;

        case 7:

            printf("\nPila Origen\n");
            mostrarPilaInt(origen);

            pasaPilaAlternativa(&origen, &A, &B);

            printf("\nPila A\n");
            mostrarPilaInt(A);

            printf("\nPila B\n");
            mostrarPilaInt(B);

            break;

        case 8:

            printf("\nPila A\n");

            cargarPilaInt(&A);

            comparaPila(&origen, &A);

            break;

        case 9:

            printf("\nPila A\n");

            cargarPilaInt(&A);

            mostrarPilaInt(A);

            funcionEliminar(&origen, &A);

            printf("\nPila Origen\n");

            mostrarPilaInt(origen);

            break;

        case 10:

            printf("\nPila Limite:\t");
            scanf("%d", &num);

            pasePilaMayoresMenores(&origen, &A, &B, num);

            printf("\nPila A mayores\n");
            mostrarPilaInt(A);

            printf("\nPila B menores\n");
            mostrarPilaInt(B);

            break;

        case 11:

            PilasParesImpares(&origen, &A, &B);

            printf("\nPila A pares\n");
            mostrarPilaInt(A);

            printf("\nPila B impares\n");
            mostrarPilaInt(B);

            break;

        default:

            printf("\nPROCESO TERMINADO\n\n");

        }
        system("pause");

    } while (opcion != 0);
}
