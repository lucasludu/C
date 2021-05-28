#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ESC 27

int main()
{
    srand(time(NULL));

    // MENU.
    char opcion, continuar = 's';

    // SECUENCIALES.
    float capital, cap_final;
    float gane;
    float descuento, pagar;
    int compra;
    float interes = 0.02, desc = 0.15;
    int hombre, mujer, total;
    float porc_h, porc_m;

    // CONDICIONALES SIMPLES Y COMPUESTAS.

    int parc_1, parc_2,parc_3, suma_parc;
    float promedio;

    int precio = 300, precio_extra = 400;
    int hora_trab, hora = 40, salario = 0;

    int n1,n2,n3;

    int cant, cant_cam = 3;
    float desc_mas = 0.2, desc_menos = 0.1;

    // CONDICIONALES CON REPETICION.

    int calificaciones, suma = 0;
    int cubo, cuarta, num;
    int i, nota_mayor, nota_menor;

    do
    {
        system("cls");

        guia_0();

        printf("\n\tIngrese ejercicio a realizar\t");
        scanf("%d", &opcion);
        system("cls");

        switch (opcion)
        {
        case 1:
            do
            {
                system("cls");

                problemas_secuenciales();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case 'a':

                    printf("\nIngresar el capital a invertir\n");
                    scanf("%f", &capital);

                    gane = capital * interes;
                    cap_final = capital + gane;

                    printf("\nGane: < %.2f >\n", gane);
                    printf("\n");
                    printf("\Capital final: < %.2f >\n", cap_final);

                    break;

                case 'b':

                    printf("\nIngrese el total de la compra\t");
                    scanf("%d", &compra);

                    descuento = compra * desc;
                    pagar = compra - descuento;

                    printf("\nSe hizo un descuento de: < %.2f >", descuento);
                    printf("\n");
                    printf("\nEl total de la compra fue de: < %.2f >", pagar);

                    break;

                case 'c':

                    printf("\nIngrese el total de hombres\t");
                    scanf("%d", &hombre);

                    printf("\nIngrese el total de mujeres\t");
                    scanf("%d", &mujer);

                    total = hombre + mujer;

                    porc_h = (float) hombre / total * 100;

                    porc_m = (float) mujer / total * 100;

                    printf("\nTotal en el salon: < %d >", total);
                    printf("\n");
                    printf("\nPromedio de hombres: < %.2f >", porc_h);
                    printf("\n");
                    printf("\nPromedio de muejeres: < %.2f >", porc_m);

                    break;
                }
                system("pause");

                printf("\nDesea continuar con la operacion de problemas secuenciales? s = si / n = no\n");
                fflush(stdin);
                scanf("%c", &continuar);

            }
            while (continuar == 's');

            break;

        case 2:

            do
            {
                system("cls");

                problemas_cond_select_simples();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case 'a':

                    parc_1 = rand() % 8 + 1;
                    parc_2 = rand() % 8 + 1;
                    parc_3 = rand() % 8 + 1;

                    suma_parc = parc_1 + parc_2 + parc_3;
                    promedio = (float) suma_parc / 3;

                    if (promedio > 7)
                    {
                        printf("\nAprobo el curso\n");

                    }
                    else
                    {

                        printf("\nBurro Desaprobaste\n");
                    }

                    printf("\nEl primer parcial fue de: < %d >\t", parc_1);
                    printf("\nEl segundo parcial fue de: < %d >\t", parc_2);
                    printf("\nEl tercero parcial fue de: < %d >\t\n", parc_3);

                    printf("\nLa suma de los 3 parciales: < %d >\t\n", suma_parc);
                    printf("\nEl promedio de los 3 parciales: < %.2f >\t\n\n", promedio);

                    break;

                case 'b':

                    printf("\nIngrese el precio de la compra\t");
                    scanf("%d", &compra);

                    if (compra > 5000)
                    {
                        printf("\nSe hace el descuento del 20 porc\n");

                        descuento = compra * desc;
                        pagar = compra - descuento;

                        printf("\nSe hizo un descuento de: < %.2f >", descuento);
                        printf("\nSe pago: < %.2f >", pagar);
                        printf("\n");

                    }
                    else
                    {

                        printf("\nNo se descuenta un pingo\n");

                        pagar = compra;

                        printf("\nSe pago: < %.2f >", pagar);
                        printf("\n");
                    }

                    break;

                case 'c':

                    printf("\nIngrese la cantidad de horas que trabajo\t");
                    scanf("%d", &hora_trab);

                    if (hora_trab <= hora)  /// hora = 40
                    {
                        printf("\nNo tiene horas extras\n");

                        salario = precio * hora_trab;

                        printf("\nEl salario del trabajador es de: < %d >\n", salario);

                    }
                    else
                    {

                        printf("\nTiene horas extras\n");

                        salario = precio * hora + precio_extra * (hora_trab - hora);

                        printf("\nEl salario del trabajador es de: < %d >\n", salario);

                    }

                    break;

                case 'd':

                    printf("\nIngrese el primer numero\n");
                    n1 = rand() % 9 + 1;

                    printf("\nIngrese el segundo numero\n");
                    n2 = rand() % 9 + 1;

                    total = n1 - n2;

                    if (n1 > n2)
                    {
                        printf("\nEl total es ascendente\n");

                    }
                    else
                    {

                        printf("\nEl total es descendente\n");
                    }

                    printf("\nNum 1 es: < %d >\n", n1);
                    printf("\nNum 2 es: < %d >\n", n2);
                    printf("\nEl total es: < %d >\n", total);

                    break;

                case 'e':

                    printf("\nIngrese la cantidad de camisas que compro\n");
                    cant = rand() % 9 +1;

                    printf("\nCantidad de camisas: < %d >\n", cant);

                    if (cant_cam <= cant)
                    {
                        printf("\nSe hace un descuento del 20 porc\n");

                        descuento = precio * cant * desc_mas;
                        pagar = precio - descuento;

                    }
                    else
                    {

                        printf("\nSe hace un descuento del 10 porc\n");

                        descuento = precio * cant * desc_menos;
                        pagar = precio - descuento;

                    }

                    printf("\nEl descuento es de: < %.2f >\n", descuento);
                    printf("\nSe pago: < %.2f >\n", pagar);

                    break;

                }
                system("pause");

                printf("\nDesea continuar con las operaciones de condicionales simples? s = si / n = no\n");
                fflush(stdin);
                scanf("%c", &continuar);

            }
            while (continuar == 's');

            break;

        case 3:

            do
            {
                system("cls");

                problemas_cond_select_compuestos();

                opcion = getch();
                system("cls");

                switch (opcion)
                {
                case 'a':

                    printf("\nIngrese el primer numero\n");
                    n1 = rand() % 9 + 1;

                    printf("\nNum 1 es: < %d >\n", n1);

                    printf("\nIngrese el segundo numero\n");
                    n2 = rand() % 9 + 1;

                    printf("\nNum 2 es: < %d >\n", n2);

                    if (n1 == n2)
                    {
                        printf("\nSe multiplican\n");

                        total = n1 * n2;

                    }
                    else if (n1 > n2)
                    {

                        printf("\nSe restan\n");

                        total = n1 - n2;

                    }
                    else
                    {

                        printf("\nSe suman\n");

                        total = n1 + n2;
                    }

                    printf("\nEl total es de: < %d >\n", total);

                    break;


                case 'b':

                    printf("\nIngrese el primer numero\n");
                    n1 = rand() % 9 + 1;
                    printf("\nNum 1 es: < %d >\n", n1);

                    printf("\nIngrese el segundo numero\n");
                    n2 = rand() % 9 + 1;
                    printf("\nNum 2 es: < %d >\n", n2);

                    printf("\nIngrese el tercer numero\n");
                    n3 = rand() % 9 + 1;
                    printf("\nNum 3 es: < %d >\n", n3);

                    if (n1 > n2)
                    {

                        if (n1 > n3)
                        {

                            printf("\nEl primer numero es mayor\n");

                        }
                        else
                        {

                            printf("\nEl tercer numero es mayor\n");
                        }

                    }
                    else if (n1 < n2)
                    {

                        printf("\nEl segundo numero es mayor\n");

                    }

                    break;


                }
                system("pause");

                printf("\nDesea continuar con las operaciones de condicionales compuestas? s = si / n = no\n");
                fflush(stdin);
                scanf("%c", &continuar);

            }
            while (continuar == 's');

            break;


        case 4:

            do
            {
                system("cls");

                problemas_repeticiones();

                opcion = getch();
                system("cls");

                switch (opcion)
                {

                case 'a':  // REVISAR!

                    for (int i = 1; i <= 7; i++)
                    {
                        calificaciones = rand() % 9 + 1;
                        printf("\nCalif Num %d : %d\n", i, calificaciones);
                        suma += calificaciones;

                    }
                    printf("\n");

                    promedio = (float) suma / 7;

                    printf("\nLa suma de todas las calificaciones es: < %d >\n", suma);
                    printf("\nEl promedio es: < %.2f >\n", promedio);

                    break;

                case 'b':

                    for (int i = 1; i <= 10; i++)
                    {
                        num = rand() & 9 + 1;

                        cubo = num * num * num;
                        cuarta = cubo * num;

                        printf("\nNumero %d: <%d>. Su cubo es: <%d> y su cuarta <%d>\n", i, num, cubo, cuarta);
                    }
                    printf("\n");

                    break;

                case 'c':

                    for (i = 1; i <= 10; i++)
                    {
                        printf("\nIngrese los numeros\t");

                        scanf("%d", &num);


                        if (num > 0)
                        {
                            printf("\nEs positivo\n");

                            printf("NUM %d: %d",i, num);

                        }
                        else
                        {

                            printf("\nEs negativo\n");
                        }
                    }
                    break;

                case 'd':

                    for (i = 1; i <= 15; i++)
                    {
                        printf("\nIngrese los numeros negativos\t");

                        scanf("%d", &num);

                        if (num < 0)
                        {
                            printf("\nEs negativo, pasarlo a positivo\n");

                            n1 = num * (-1);

                            printf("\nAhora es positivo: %d\n", n1);

                        }
                        else
                        {

                            printf("\nEs positivo\n");
                        }
                    }
                    break;

                case 'e':

                    printf("\nIngresar las calificaciones\n");

                    for (i = 1; i <= 40; i++)
                    {
                        calificaciones = rand() % 9 + 1;

                        printf("\n|Calif. %d: %d |\n",i, calificaciones);

                        if (calificaciones < nota_menor)
                        {
                            nota_menor = calificaciones;

                        }
                        else if (calificaciones > nota_mayor)
                        {

                            nota_mayor = calificaciones;
                        }

                        suma = suma + calificaciones;
                    }

                    promedio = (float) suma / 40;

                    printf("\nLa menor nota es: < %d >\n", nota_menor);

                    printf("\nLa mayor nota es: < %d >\n", nota_mayor);

                    printf("\nLa suma de las calificaciones es: < %d >\n", suma);

                    printf("\nEl promedio es: < %.2f >\n", promedio);

                    break;

                case 'f':

                    printf("\nIngrese el numero de tabla\n\t");
                    num = rand() & 9;

                    printf("\nHacemos la tabla del %d\n", num);

                    for (i = 1; i <= 9; i++)
                    {
                        printf("\n\t%d * %d = %d\n",num,i,num * i);
                    }
                    break;




                }
                system("pause");

                printf("\nDesea continuar con las operaciones con repeticion? s = si / n = no\n");
                fflush(stdin);
                scanf("%c", &continuar);

            }
            while (continuar == 's');

            break;

                default:

                    printf("\nFIN\n");

        }
        system("pause");

    } while (opcion != 0);
}
