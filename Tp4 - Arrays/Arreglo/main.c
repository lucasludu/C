#include "array.h"

int main()
{
    srand(time(NULL));
    int opcion;

    int dato;
    float real;
    char letra;

    int arreglo_int[DIM];
    float arreglo_float[DIM];
    char arreglo_char[DIM];
    char arreglo_char1[DIM]; /// ORDENA ALFAVETICAMENTE INTERCALADO **.
    char arreglo_chart[DIM]; /// **

    int validos = 0;
    int validos1 = 0; /// **
    int validost = 0; /// **

    Pila a;
    inicpila(&a);

    do
    {
        system("cls");
        printf("\n\t[ 1 ] - Carga un Arreglo\n");
        printf("\n\t[ 2 ] - Carga dos Arreglos y ordenarlos alfaveticamente e intercalarlos\n");
        printf("\n\t\t[ ESC ] - salir\n");
        opcion = getch();
        system("cls");

        switch (opcion)
        {
        case '1':

            do
            {
                system("cls");

                menuCarga();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case '1':

                    validos = tipoCargaInt(arreglo_int, validos, DIM);

                    do
                    {
                        system("cls");

                        printf("\n\t[ 01 ] - Muestra el arreglo\n");
                        printf("\n\t[ 02 ] - Cantidad de validos\n");
                        printf("\n\t[ 03 ] - Suma de elementos en el arreglo\n");
                        printf("\n\t[ 04 ] - Pasar arreglo a la pila\n");
                        printf("\n\t[ 05 ] - Buscar elemento en el arreglo\n");
                        printf("\n\t[ 06 ] - Insertar elemento en el arreglo\n");
                        printf("\n\t[ 07 ] - Mayor elemento en el arreglo\n");
                        printf("\n\t[ 08 ] - Arreglo capicua\n");
                        printf("\n\t[ 09 ] - Invertir arreglo\n");
                        printf("\n\t[ 10 ] - Ordenar arreglo\n");
                        printf("\n\t\t\t[ 0 ] - SALIR\n");

                        printf("\nEjercicio:\t");
                        scanf("%d", &opcion);

                        system("cls");

                        switch (opcion)
                        {
                        case 1:

                            muestraArregloInt(arreglo_int, validos);

                            break;

                        case 2:

                            printf("\nSe contaron [ %d ] elementos en el arreglo\n", validos);

                            break;

                        case 3:

                            printf("\nLa suma de los elementos es: [ %d ]\n", sumaElementosInt(arreglo_int, validos));

                            break;

                        case 4:

                            arrayIntToPila(arreglo_int, validos, &a);
                            muestroPilaInt(a);

                            system("pause");
                            printf("\n\t Oasi de pila a arreglo\n\n");
                            validos = pilaToArreglo(a, arreglo_int, validos);
                            muestraArregloInt(arreglo_int, validos);

                            break;

                        case 5:

                            funcionBuscarInt(arreglo_int, validos);

                            break;

                        case 6:

                            printf("\nNumero a insertar:\t");
                            scanf("%d", &dato);

                            validos = insertarInt(arreglo_int, validos, dato);
                            ordenaIntInsertado(arreglo_int, validos);

                            muestraArregloInt(arreglo_int, validos);

                            break;

                        case 7:

                            funcionMayorInt(arreglo_int, validos);

                            break;

                        case 8:

                            arregloIntCapicua(arreglo_int, validos);

                            break;

                        case 9:

                            printf("\nArreglo inicial");
                            muestraArregloInt(arreglo_int, validos);

                            invertirArregloInt(arreglo_int, validos);

                            printf("\n\nArreglo invertido");
                            muestraArregloInt(arreglo_int, validos);

                            break;

                        case 10:

                            do
                            {
                                system("cls");

                                printf("\n\t[ 1 ] - Ordeno por seleccion\n");
                                printf("\n\t[ 2 ] - Ordeno por insercion\n");
                                printf("\n\t\t[ ESC ] - SALIR\n");

                                opcion = getch();
                                system("cls");

                                switch (opcion)
                                {
                                case '1':

                                    printf("\n\nArreglo desordenado");
                                    muestraArregloInt(arreglo_int, validos);

                                    ordenaSeleccionInt(arreglo_int, validos);

                                    printf("\n\nArreglo ordenado");
                                    muestraArregloInt(arreglo_int, validos);

                                    break;

                                case '2':

                                    printf("\n\nArreglo desordenado");
                                    muestraArregloInt(arreglo_int, validos);

                                    ordenaInsercionInt(arreglo_int, validos);

                                    printf("\n\nArreglo ordenado");
                                    muestraArregloInt(arreglo_int, validos);

                                    break;
                                }
                                system("pause");

                            }
                            while (opcion != 27);

                            break;

                        default:

                            printf("\nENTERO TERMINADO\n");
                        }
                        system("pause");

                    }
                    while (opcion != 0);

                    break;

                case '2':

                    validos = tipoCargaFloat(arreglo_float, validos, DIM);

                    do
                    {
                        system("cls");

                        printf("\n\t[ 1 ] - Muestra el arreglo\n");
                        printf("\n\t[ 2 ] - Cantidad de validos\n");
                        printf("\n\t[ 3 ] - Suma de elementos en el arreglo\n");
                        printf("\n\t[ 4 ] - Pasar arreglo a la pila ARREGLAR\n");
                        printf("\n\t[ 5 ] - Buscar elemento en el arreglo ARREGLAR\n");
                        printf("\n\t[ 6 ] - Insertar un elemento en el arreglo ordenado ARREGLAR\n");
                        printf("\n\t[ 7 ] - Mayor elemento en el arreglo\n");
                        printf("\n\t\t\t[ ESC ] - SALIR\n");

                        opcion = getch();
                        system("cls");

                        switch (opcion)
                        {
                        case '1':

                            muestraArregloFloat(arreglo_float, validos);

                            break;

                        case '2':

                            printf("\nSe contaron [ %d ] elementos en el arreglo\n", validos);

                            break;

                        case '3':

                            printf("\nLa suma es de: [ %6.2f ]\n", sumaElementosfloat(arreglo_float, validos));

                            break;

                        case '4':

                            arrayRealToPila(arreglo_float, validos, &a);
                            muestroPilaFloat(a);

                            break;

                        case '5':

                            funcionBuscarFloat(arreglo_float, validos);

                            break;

                        case '6':

                            printf("\nIngrese elemento real a ingresar\t");
                            scanf("%f", &real);

                            validos = insertarFloat(arreglo_float, validos, real);
                            ordenaFloatInsertado(arreglo_float, validos);

                            muestraArregloFloat(arreglo_float, validos);

                        case '7':

                            funcionMayorFloat(arreglo_float, validos);

                        default:

                            printf("\nREAL ENTERADO\n");

                        }
                        system("pause");

                    }
                    while (opcion != 27);

                    break;

                case '3':

                    validos = tipoCargaChar(arreglo_char, validos, DIM);

                    do
                    {
                        system("cls");

                        printf("\n\t[ 1 ] - Muestra el arreglo\n");
                        printf("\n\t[ 2 ] - Cantidad de validos\n");
                        printf("\n\t[ 3 ] - Pasar arreglo a la pila\n");
                        printf("\n\t[ 4 ] - Buscar elemento en el arreglo\n");
                        printf("\n\t[ 5 ] - Insertar elemento char en el arreglo ordenado\n");
                        printf("\n\t[ 6 ] - Mayor elemento en el arreglo\n");
                        printf("\n\t[ 7 ] - Arreglo Capicua\n");
                        printf("\n\t[ 8 ] - Invertir arreglo\n");
                        printf("\n\t[ 9 ] - Ordenar arreglo\n");
                        printf("\n\t\t\t[ ESC ] - SALIR\n");

                        opcion = getch();
                        system("cls");

                        switch (opcion)
                        {
                        case '1':

                            muestraArregloChar(arreglo_char, validos);

                            break;

                        case '2':

                            printf("\nSe contaron [ %d ] elementos en el arreglo\n", validos);

                            break;

                        case '3':

                            arrayCharToPila(arreglo_char, validos, &a);
                            muestroPilaChar(a);

                            break;

                        case '4':

                            funcionBuscarChar(arreglo_char, validos);

                            break;

                        case '5':

                            printf("\nIngrese dato a insertar:\t");
                            scanf("%s", &letra);

                            validos = insertarChar(arreglo_char, validos, letra);
                            ordenaCharInsertado(arreglo_char, validos);

                            muestraArregloChar(arreglo_char, validos);

                            break;

                        case '6':

                            funcionMayorChar(arreglo_char, validos);

                            break;

                        case '7':

                            arregloCharCapicua(arreglo_char, validos);

                            break;

                        case '8':

                            printf("\n\nArreglo inicial");
                            muestraArregloChar(arreglo_char, validos);

                            invertirArregloChar(arreglo_char, validos);

                            printf("\n\nArreglo invertido");
                            muestraArregloChar(arreglo_char, validos);

                            break;

                        case '9':

                            do
                            {
                                system("cls");

                                printf("\n\t[ 1 ] - Ordeno por seleccion\n");
                                printf("\n\t[ 2 ] - Ordeno por insercion\n");
                                printf("\n\t\t[ ESC ] - SALIR\n");

                                opcion = getch();
                                system("cls");

                                switch (opcion)
                                {
                                case '1':

                                    printf("\n\nArreglo desordenado");
                                    muestraArregloChar(arreglo_char, validos);

                                    ordenaSeleccionChar(arreglo_char, validos);

                                    printf("\n\nArreglo ordenado");
                                    muestraArregloChar(arreglo_char, validos);

                                    break;

                                case '2':

                                    printf("\n\nArreglo desordenado");
                                    muestraArregloChar(arreglo_char, validos);

                                    ordenaInsercionChar(arreglo_char, validos);

                                    printf("\n\nArreglo ordenado");
                                    muestraArregloChar(arreglo_char, validos);

                                    break;
                                }
                                system("pause");

                            }
                            while (opcion != 27);

                            break;

                        default:

                            printf("\nCARACTER TERMINADO\n");

                        }
                        system("pause");

                    }
                    while (opcion != 27);

                    break;

                default:

                    printf("\nFIN DE LA CARGAAAA\n");
                }
                system("pause > arch");

            }
            while (opcion != 27);

            break;

        case '2':

            printf("\nIngrese el primer arreglo\n");
            validos = cargaArregloCharManual(arreglo_char, validos, DIM);
            ordenaSeleccionChar(arreglo_char, validos);

            system("pause");

            printf("\nIngrese el segundo arreglo\n");
            validos1 = cargaArregloCharManual(arreglo_char1, validos1, DIM);
            ordenaSeleccionChar(arreglo_char1, validos1);

            muestraArregloChar(arreglo_char, validos);
            muestraArregloChar(arreglo_char1, validos1);

            system("pause");

            validost = intercalarArreglos(arreglo_char, arreglo_char1, arreglo_chart, validos, validos1, validost);
            muestraArregloChar(arreglo_chart, validost);

            break;

        default:

            printf("\nFIN DE EJERCICIO\n");
        }
        system("pause > arch");

    }
    while (opcion != 27);

    return 0;
}
