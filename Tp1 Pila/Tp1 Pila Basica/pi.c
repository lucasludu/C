#include "pi.h"

void menu()
{
    printf("\n\t[ 01 ] - Cargar Pila\n");
    printf("\n\t[ 02 ] - Mostrar Pila\n");
    printf("\n\t[ 03 ] - Pasar Pila\n");
    printf("\n\t[ 04 ] - Copiar Pila\n");
    printf("\n\t[ 05 ] - Pila Origen en orden inverso\n");
    printf("\n\t[ 06 ] - Pasa elemento de la pila\n");
    printf("\n\t[ 07 ] - Pasa pila a otras 2 en forma alternativa\n");
    printf("\n\t[ 08 ] - Compara pilas\n");
    printf("\n\t[ 09 ] - Elimina elemento de la pila origen\n");
    printf("\n\t[ 10 ] - Pasar elementos a la pila menores y mayores al limite\n");
    printf("\n\t[ 11 ] - Pasar elementos a la pila pares e impares\n");
    printf("\n\t[ 00 ] - Salir\n");
}

/*****************************************
 * \brief VERIFICAR EXISTENCIA DE LA PILA
 * \param PILA P *
 * \param DATO
 * \return PILA P
 *****************************************/

int existencia (Pila p, int dato)
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

/*****************************
 * \brief CARGAR PILA MANUAL
 * \param PILA P *
 * \return PILA P
 *****************************/

int cargarPilaInt(Pila *p)
{
    char opcion;
    int num;

    do
    {
        system("cls");
        printf("\nIngrese valores a la pila\t");

        scanf("%d", &num);

        if(!existencia(*p, num)){

        apilar(p, num);

        } else {

            printf("\nEl numero existe, ingrese otro\n");
        }

        printf("\n\n\tESC para terminar con la carga...\n");

        opcion = getch();
        system("cls");

    } while (opcion != 27);

    return p;
}

/*****************************
 * \brief CARGAR PILA RANDOM
 * \param PILA P *
 * \param CANTIDAD
 * \return VOID
 *****************************/

void cargarPilaIntRandom (Pila *p, int cantidad)
{
    int num;

    for (int i = 0; i < cantidad; i++)
    {
        num = rand() % (MIN - MAX + 1) + MAX;

        if (num % 2 == 0){

        apilar(p, num);

        }
    }
}

/*******************************
 * \brief ELEGIR TIPO DE CARGA
 * \param PILA P *
 * \return VOID
 *******************************/

void elegirCarga (Pila *p)
{
    int op;
    int cant;

    do{

    system("cls");
    printf("\n\t[ 1 ] - Carga Manual\n");
    printf("\n\t[ 2 ] - Carga Random\n");
    printf("\n\n\t\t\t\t[ 0 ] - SALIR\n");

    printf("\nIngrese tipo de carga:\t");
    scanf("%d", &op);
    system("cls");

    switch (op)
    {
    case 1:

        cargarPilaInt(p);

        break;

    case 2:

        printf("\nIngrese la cantidad que desea cargar\n");
        scanf("%d", &cant);

        cargarPilaIntRandom(p, cant);

        break;
    }
    system("pause");

    } while (op != 0);

}

/*****************************
 * \brief MOSTRAR PILA
 * \param PILA P
 * \return VOID
 *****************************/

void mostrarPilaInt (Pila p)
{
    Pila aux;
    inicpila(&aux);

    printf("\nMuestro Pila\n\n");

    printf("Tope\t");
    while (!pilavacia(&p))
    {
        printf(" %d |", tope(&p));
        apilar(&aux, desapilar(&p));
    }
    printf("\tBase");
    printf("\n\n\n");
}

/*****************************
 * \brief PASA PILA
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 *****************************/

void pasaPila (Pila *p, Pila *q)
{
    while (!pilavacia(p))
    {
        apilar(q, desapilar(p));
    }
}

/*************************************
 * \brief PASA PILA CONSERVANDO ORDEN
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ************************************/

void PasaPilaMismoOrden (Pila *p, Pila *q)
{
    Pila aux;
    inicpila(&aux);

    pasaPila(p, &aux);
    pasaPila(&aux, q);
}

/*************************************
 * \brief FUNCION DE PASE DE PILA
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ************************************/

void funcionPase (Pila *p, Pila *q)
{
    int op;

    do{

    system("cls");
    printf("\n\t[ 1 ] - Pasa Pila\n");
    printf("\n\t[ 2 ] - Pasa Pila mismo orden\n");
    printf("\n\n\t\t\t\t[ 0 ] - SALIR");
    printf("\nIngrese ejercicio a realizar:\t");
    scanf("%d", &op);
    system("cls");

    switch (op)
    {
    case 1:

        pasaPila(p, q);

        break;

    case 2:

        PasaPilaMismoOrden(p, q);

        break;

    }
    system("pause");

    } while (op != 0);
}

/*****************************
 * \brief COPIA PILA
 * \param PILA P
 * \param PILA Q *
 * \return VOID
 ******************************/

void copiaPila (Pila p, Pila *q)
{
    while (!pilavacia(&p))
    {
        apilar(q, desapilar(&p));
    }
}

/*************************************************************
 * \brief PONER ELEMENTOS DE LA PILA ORIGEN EN ORDEN INVERSO.
 * \param PILA P *
 * \return VOID
 *************************************************************/

void pilaOrigenInverso (Pila *p)
{
    Pila aux, aux1;

    inicpila(&aux);
    inicpila(&aux1);

    pasaPila(p, &aux);
    pasaPila(&aux, &aux1);
    pasaPila(&aux1, p);
}

/*************************************************************
 * \brief BASE DE LA PILA AL TOPE DE LA PILA.
 * \param PILA P *
 * \return VOID
 *************************************************************/

void baseTotope (Pila *p)
{
    Pila aux, d;
    inicpila(&aux);
    inicpila(&d);

    apilar(&d, desapilar(p));

    pasaPila(p, &aux);

    apilar(p, desapilar(&d));

    pasaPila(&aux, p);
}

/*************************************************************
 * \brief TOPE DE LA PILA A LA BASE DE LA PILA.
 * \param PILA P *
 * \return VOID
 *************************************************************/

void topeToBase (Pila *p)
{
    Pila aux,d;

    inicpila(&aux);
    inicpila(&d);

    pasaPila(p, &aux);

    apilar(&d, desapilar(&aux));

    pasaPila(&aux, p);

    apilar(p, desapilar(&d));
}

/*************************************************************
 * \brief PASA ELEMENTO DE LA PILA.
 * \param PILA P *
 * \return VOID
 *************************************************************/

void pasaElemento (Pila *p)
{
    int op;

    do{

    system("cls");
    printf("\n\t[ 1 ] - Base To Tope de la Pila\n");
    printf("\n\t[ 2 ] - Tope To Base de la Pila\n");
    printf("\n\n\t\t\t[ 0 ] - SALIR\n");

    printf("\nIngrese ejercicio a realizar:\t");
    scanf("%d", &op);
    system("cls");

    switch(op)
    {
    case 1:

        baseTotope(p);

        break;

    case 2:

        topeToBase(p);

        break;
    }
    system("pause");

    } while (op != 0);
}

/*******************************************************************************
 * \brief PASAR LOS ELEMENTOS DE LA PILA EN FORMA ALTERNATIVA EN LA PILA A Y B.
 * \param PILA P *
 * \param PILA A *
 * \param PILA B *
 * \return VOID
 *******************************************************************************/

void pasaPilaAlternativa (Pila *p, Pila *a, Pila *b)
{
    while (!pilavacia(p))
    {
        apilar(a, desapilar(p));

        if (!pilavacia(p))
        {
            apilar(b, desapilar(p));
        }
    }
}

/**********************************************
 * \brief COMPARAR CANTIDADES ENTRE DOS PILAS.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 **********************************************/

void comparaCant (Pila *p, Pila *q)
{
    Pila auxp, auxq;

    inicpila(&auxp);
    inicpila(&auxq);

    while (!pilavacia(p) && !pilavacia(q))
    {
        apilar(&auxp, desapilar(p));
        apilar(&auxq, desapilar(q));
    }

    if (pilavacia(p) && pilavacia(q))
    {
        printf("\nTienen las mismas cantidades\n");

    } else {

        printf("\nNo tienen las mismas cantidades\n");
    }
}

/**********************************************
 * \brief COMPARAR SIMILITUD ENTRE DOS PILAS.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 **********************************************/

void comparaSimilitud (Pila *p, Pila *q)
{
    Pila auxp, auxq;

    inicpila(&auxp);
    inicpila(&auxq);

    while (!pilavacia(p) && !pilavacia(q) && tope(p) == tope(q))
    {
        apilar(&auxp, desapilar(p));
        apilar(&auxq, desapilar(q));
    }

    if (pilavacia(p) && pilavacia(q))
    {
        printf("\nSon iguales\n");

    } else {

        printf("\nSon distintas\n");
    }
}

/**********************************************
 * \brief COMPARAR PILAS.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 **********************************************/

void comparaPila (Pila *p, Pila *q)
{
    int op;

    do{

    printf("\n\t[ 1 ] - Comparar Cantidades\n");
    printf("\n\t[ 2 ] - Comparar Similitudes\n");
    printf("\n\n\t\t\t[ 0 ] - SALIR\n");

    printf("\nIngrese ejercicio a realizar:\t");
    scanf("%d", &op);

    switch (op)
    {
    case 1:

        comparaCant(p, q);

        break;

    case 2:

        comparaSimilitud(p, q);

        break;
    }
    system("pause");

    } while (op != 0);
}

/*************************************************************************************
 * \brief ELIMINAR DE LA PILA ORIGEN LOS ELEMENTOS IGUALES AL TOPE DE LA PILA MODELO.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 *************************************************************************************/

void eliminarElemiguales (Pila *p, Pila *q)
{
    Pila aux, descarte;

    inicpila(&aux);
    inicpila(&descarte);

    if (!pilavacia(q)) {

        while (!pilavacia(p))
        {
            if (tope(p) == tope(q))
            {
                apilar(&descarte, desapilar(p));

            } else {

                apilar(&aux, desapilar(p));
            }
        }

        pasaPila(&aux, p);
    }
}

/*************************************************************************************
 * \brief ELIMINAR DE LA PILA ORIGEN TODOS LOS ELEMENTOS IGUALES A LA PILA MODELO.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 *************************************************************************************/

void eliminaTodo (Pila *p, Pila *q)
{
    Pila aux, aux1, basura;
    inicpila(&aux);
    inicpila(&aux1);
    inicpila(&basura);

    while (!pilavacia(q))
    {
        while (!pilavacia(p))
        {
            if (tope(p) == tope(q))
            {
                apilar(&basura, desapilar(p));

            } else {

                apilar(&aux, desapilar(p));
            }
        }

        pasaPila(&aux, p);

        apilar(&aux1, desapilar(q));
    }
}

/***************************
 * \brief FUNCION ELIMINAR
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ***************************/

void funcionEliminar (Pila *p, Pila *q)
{
    int op;

    do {

    system("cls");
    printf("\n\t[ 1 ] - Eliminar Origen = tope de modelo\n");
    printf("\n\t[ 2 ] - Eliminar Origen = modelo\n");
    printf("\n\t[ 0 ] - SALIR\n");

    printf("\nIngrese ejercicio a realizar:\t");
    scanf("%d", &op);
    system("cls");

    switch(op)
    {
    case 1:

        eliminarElemiguales(p, q);

        break;

    case 2:

        eliminaTodo(p, q);

        break;
    }
    system("pause");

    } while (op != 0);
}

/*******************************************************************************
 * \brief PASAR LA PILA -A- PILAS MAYORES AL LIMITE Y AL -B- LAS MENORES.
 * \param PILA P *
 * \param PILA A * MAYOR AL LIMITE
 * \param PILA B * MENOR AL LIMITE
 * \return VOID
 *******************************************************************************/

void pasePilaMayoresMenores (Pila *p, Pila *a, Pila *b, int limite)
{
    Pila lim;
    inicpila(&lim);

    apilar(&lim, limite);

    while (!pilavacia(p))
    {
        if(tope(p) >= tope(&lim))
        {
            apilar(b, desapilar(p));

        } else {

            apilar(a, desapilar(p));
        }
    }
}

/*******************************************************************************
 * \brief PASAR LA PILA -A- PILAS PARES AL LIMITE Y AL -B- LAS IMPARES.
 * \param PILA P *
 * \param PILA A * PARES
 * \param PILA B * IMPARES
 * \return VOID
 *******************************************************************************/

void PilasParesImpares (Pila *p, Pila *a, Pila *b)
{
    while (!pilavacia(p))
    {
        if(tope(p) % 2 == 0)
        {
            apilar(a, desapilar(p));

        } else {

            apilar(b, desapilar(p));
        }
    }
}





































