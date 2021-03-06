#include "pilaa.h"

void menu()
{
        printf("\n\t[ 1 ] - Cargar Pila\n");
        printf("\n\t[ 2 ] - Mostrar Pila\n");
        printf("\n\t[ 3 ] - SUMA CUENTA PROMEDIA la Pila\n");
        printf("\n\t[ 4 ] - Encontrar menor elemento de la pila y guardarlo en otra\n");
        printf("\n\t[ 5 ] - Insertar un elemento de la pila en la pila origen\n");
        printf("\n\t[ 6 ] - Ordenar la pila por seleccion\n");
        printf("\n\t[ 7 ] - Buscar un elemento de la pila\n");
        printf("\n\t[ 8 ] - Eliminar un elemento de la pila\n");
        printf("\n\t[ 9 ] - Determinar si la pila es capicua\n");
        printf("\n\t[ 10 ] - Unir pila A y B en la pila C\n");
        printf("\n\t[ 11 ] - Unir pila A y B en la pila C en forma ordenada creciente/decreciente\n");
        printf("\n\t[ 12 ] - Ordenar la pila por el metodo de insercion\n");

        printf("\n\n\t\t\t[ 0 ] - SALIR del menu principal\n");
}

/*******************************
 * \brief EXISTENCIA DE LA PILA
 * \param PILA P *
 * \param DATO
 * \return VOID
 *******************************/

int existenciaPila (Pila p, int dato)
{
    int flag = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p) && flag == 0)
    {
        if (tope(&p) == dato)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(&p));
    }

    return flag;
}

/**************************************
 * \brief CARGAR PILA MANUAL REPETIDAS
 * \param PILA P *
 * \return PILA P
 **************************************/

int cargarPilaManual (Pila *p)
{
    int num;
    char op;

    do
    {
        system("cls");

        printf("\nIngrese entero\n");
        scanf("%d", &num);

        if (!existenciaPila(*p, num))
        {
            apilar(p, num);

        } else {

            printf("\nEl numero esta cargado, ingrese otro\n");
        }

        printf("\nESC para salir.....\n");
        op = getch();

        system("cls");
    } while (op != 27);

    return p;
}

/*******************************************
 * \brief CARGAR PILA MANUAL CON REPETICION
 * \param PILA P *
 * \return PILA P
 *******************************************/

int cargarPilaManualconRepet (Pila *p)
{
    int num;
    char op;

    do
    {
        system("cls");

        printf("\nIngrese entero\n");
        scanf("%d", &num);

        apilar(p, num);

        printf("\nESC para salir.....\n");
        op = getch();

        system("cls");
    } while (op != 27);

    return p;
}

/*****************************
 * \brief CARGAR PILA RANDOM
 * \param PILA P *
 * \return VOID
 *****************************/

void cargarpilaRandom (Pila *p, int cantidad)
{
    int num;

    for (int i = 0; i < cantidad; i++)
    {
        num = rand() % (MAX - MIN + 1) + MIN;
        apilar(p, num);
    }
}

/*****************************
 * \brief FUNCION DE CARGA
 * \param PILA P *
 * \return VOID
 *****************************/

void funcionCarga (Pila *p)
{
    int cant;
    int op;

    do{

    system("cls");
    printf("\n\t[ 1 ] - Carga Manual\n");
    printf("\n\t[ 2 ] - Carga Random\n");
    printf("\n\n\t\t\t[ 0 ] - SALIR de la carga\n");

    printf("\nIngrese tipo de carga:\t");
    scanf("%d", &op);
    system("cls");

    switch (op)
    {
    case 1:

        cargarPilaManual(p);

        break;

    case 2:

        printf("\nIngrese la cantidad de elementos a cargar\n");
        printf("\nIngreso:\t"),
        scanf("%d", &cant);

        cargarpilaRandom(p, cant);

        break;

    default:

        printf("\nFIN de carga\n");
    }
    system("pause");

    } while (op != 0);

}

/*****************************
 * \brief MOSTRAR LA PILA
 * \param PILA P
 * \return VOID
 *****************************/

void mostrarPila (Pila p)
{
    Pila aux;
    inicpila(&aux);
    printf("\n");
    while (!pilavacia(&p))
    {
        printf(" %d |", tope(&p));
        apilar(&aux, desapilar(&p));
    }
    printf("\n\n");
}

/*****************************
 * \brief SUMAR LA PILA
 * \param PILA P
 * \return SUMA
 *****************************/

int sumarPila (Pila p)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        suma = suma + tope(&p);
        apilar(&aux, desapilar(&p));
    }
    return suma;
}

/*****************************
 * \brief CONTAR LA PILA
 * \param PILA P
 * \return VOID
 *****************************/

int cuentaPila (Pila p)
{
    int cont = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        cont++;
        apilar(&aux, desapilar(&p));
    }
    return cont;
}


/*****************************
 * \brief DIVIDIR 2 ENTEROS
 * \param INT A
 * \param INT B
 * \return VOID
 *****************************/

float divPilas (int a, int b)
{
    float div;

    if (b > 0)
    {
        div = (float) a/b;
    }
    return div;
}

/*****************************
 * \brief PROMEDIO DE LA PILA
 * \param PILA P
 * \return VOID
 *****************************/

float promedioPila (Pila p)
{
    float promedio = 0;

    int suma = sumarPila(p);
    int cont = cuentaPila(p);

    if (cont > 0)
    {
        promedio = divPilas(suma, cont);
    }
    return promedio;
}

/***********************************************************
 * \brief FUNCION QUE CALCULA SUMA CUENTA PROMEDIO DE PILAS
 * \param PILA P
 * \return VOID
 ***********************************************************/

void calculoPilas (Pila p)
{
    printf("\nLa suma de las pilas es de: [ %d ]\n", sumarPila(p));
    printf("\nSe contaron [ %d ] elementos en la pila\n", cuentaPila(p));
    printf("\nEl promedio de la pila es de: [ %.2f ]\n", promedioPila(p));
}

/***********************************
 * \brief MENOR ELEMETNO DE LA PILA
 * \param PILA P
 * \return VOID
 ***********************************/

void BuscaMenorElemento (Pila p)
{
    Pila aux, menor;
    inicpila(&aux);
    inicpila(&menor);

    if (!pilavacia(&p))
    {
        apilar(&menor, desapilar(&p));

        while(!pilavacia(&p))
        {
            if (tope(&p) < tope(&menor))
            {
                apilar(&aux, desapilar(&menor));
                apilar(&menor, desapilar(&p));

            } else {

                apilar(&aux, desapilar(&p));
            }
        }

        while (!pilavacia(&aux))
        {
            apilar(&p, desapilar(&aux));
        }
    }
    printf("\nEl menor elemento es: [ %d ]\n", tope(&menor));
}

/***************************************************************************
 * \brief INSERTAR ELEMENTO EN UNA PILA ORDENADA DE MENOR TOPE A MAYOR BASE
 * \param PILA P
 * \return VOID
 ***************************************************************************/

void insertarElemento (Pila p)
{
    Pila i, aux;
    inicpila(&i);
    inicpila(&aux);
    int num;

    printf("\nIngrese elemento en la pila a insertar\n");
    scanf("%d", &num);

    apilar(&i, num);

    while (!pilavacia(&p) && tope(&p) > tope(&i))
    {
        apilar(&aux, desapilar(&p));
    }

    apilar(&p, desapilar(&i));

    while (!pilavacia(&aux))
    {
        apilar(&p, desapilar(&aux));
    }
}

/***********************************
 * \brief ORDENAR LA PILA INSERTADA
 * \param PILA P
 * \return VOID
 ***********************************/

void ordenarSeleccion (Pila p)
{
    Pila aux,aux1;
    inicpila(&aux);
    inicpila(&aux1);

    while (!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));

        while (!pilavacia(&p))
        {
            if (tope(&p) < tope(&aux))
            {
                apilar(&aux1, desapilar(&aux));
                apilar(&aux, desapilar(&p));

            } else {

                apilar(&aux1, desapilar(&p));
            }
        }

        while (!pilavacia(&aux1))
        {
           apilar(&p, desapilar(&aux1));
        }
    }

    while (!pilavacia(&aux))
    {
        apilar(&p, desapilar(&aux));
    }
}


/***********************************
 * \brief BUSCAR ELEMENTO EN LA PILA
 * \param PILA P
 * \param INT ELEMENTO A BUSCAR
 * \return VOID
 ***********************************/

void  buscarElemento (Pila p, int elemento)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p) && tope(&p) != elemento)
    {
        apilar(&aux, desapilar(&p));
    }

    if (!pilavacia(&p))
    {
        printf("\nEl elemento buscado se encuentra en la pila\n");

    } else {

        printf("\nEl elemento buscado no se encuentra en la pila\n");
    }

}


/**************************************
 * \brief ELIMINAR ELEMENTO DE LA PILA
 * \param PILA P
 * \param INT ELEMENTO A ELIMINAR
 * \return VOID
 **************************************/

void eliminarElemento (Pila p, int elemento)
{
    Pila aux, basura;
    inicpila(&aux);
    inicpila(&basura);

    while (!pilavacia(&p) && tope(&p) != elemento)
    {
        apilar(&aux, desapilar(&p));
    }

    if (!pilavacia(&p))
    {
        apilar(&basura, desapilar(&p));

        printf("\nPila Eliminada\n");
        mostrarPila(basura);

    } else {

        printf("\nNo se encontro el elemento a eliminar\n");
    }

    while(!pilavacia(&aux))
    {
        apilar(&p, desapilar(&aux));
    }

    printf("\nPila final\n");
    mostrarPila(p);
}

/**************************************
 * \brief COPIA PILA
 * \param PILA P
 * \param PILA Q *
 * \return VOID
 **************************************/

void copiaPila (Pila p, Pila *q)
{
    while (!pilavacia(&p))
    {
        apilar(q, desapilar(&p));
    }
}

/**************************************
 * \brief PILA CAPICUA
 * \param PILA P
 * \param PILA Q *
 * \return VOID
 **************************************/

void pilaCapicua (Pila p)
{
    Pila aux, aux1, copia;
    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&copia);

    copiaPila(p, &copia);

    while (!pilavacia(&p) && !pilavacia(&copia) && tope(&p) == tope(&copia))
    {
        apilar(&aux, desapilar(&p)),
        apilar(&aux1, desapilar(&copia));
    }

    if (pilavacia(&p) && pilavacia(&copia))
    {
        printf("\nLa pila es capicua\n");

    } else {

        printf("\nLa pila no es capicua\n");
    }
}


/**************************************
 * \brief UNIR PILA A Y B EN LA PILA C
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 **************************************/

void unir3pilas (Pila *p, Pila *q)
{
    Pila r;
    inicpila(&r);

    printf("\nPila A\n");
    cargarPilaManual(p);

    printf("\nPila B\n");
    cargarPilaManual(q);

    system("cls");

    printf("\nPila A\n");
    mostrarPila(*p);

    printf("\nPila B\n");
    mostrarPila(*q);

    while (!pilavacia(p) && !pilavacia(q) && tope(p) != tope(q))
    {
        apilar(&r, desapilar(p));
        apilar(&r, desapilar(q));
    }

    printf("\nPila C\n");
    mostrarPila(r);
}


/******************************************************************
 * \brief UNIR PILA A Y B EN LA PILA C EN FORMA ORDENADA CRECIENTE
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ******************************************************************/

void Unir2pilasOrdenadas (Pila *p, Pila *q)
{
    Pila r;
    inicpila(&r);

    printf("\nPila A\n");
    cargarPilaManual(p);
    printf("\nPila B\n");
    cargarPilaManual(q);

    system("cls");

    printf("\nPila A\n");
    mostrarPila(*p);
    printf("\nPila B\n");
    mostrarPila(*q);

    while (!pilavacia(p) && !pilavacia(q) && tope(p) != tope(q))
    {
        apilar(&r, desapilar(p));
        apilar(&r, desapilar(q));
    }

    ordenarSeleccion(r);

    printf("\nPila C ordenada\n");
    mostrarPila(r);
}

/******************************************************************
 * \brief ORDENAR LA PILA POR EL METODO DE INSERCION.
 * \param PILA P *
 * \return VOID
 ******************************************************************/

void ordenaInsercion (Pila p)
{
    Pila aux, aux1, orden;

    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&orden);

    while (!pilavacia(&p)) {

        apilar(&aux, desapilar(&p));

        while (!pilavacia(&p)) {

            if (tope(&p) > tope(&aux)) {

                apilar(&aux1, desapilar(&aux));
                apilar(&aux, desapilar(&p));

            } else {

                apilar(&aux1, desapilar(&p));
            }
        }

        apilar(&orden, desapilar(&aux));

        while (!pilavacia(&aux1)) {

            apilar(&p, desapilar(&aux1));
        }
    }

    while (!pilavacia(&orden)) {

        apilar(&p, desapilar(&orden));
    }

    printf("\nMuestro Pila ordenada\n");
    mostrarPila(p);

}












