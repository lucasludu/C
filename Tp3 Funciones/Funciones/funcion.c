#include "funcion.h"

void menu(){
    printf("\n\t[ 01 ] - Cargar pila y mostrarla\n");
    printf("\n\t[ 02 ] - Pasar una pila a otra\n");
    printf("\n\t[ 03 ] - Pasar pila a otra con el mismo orden\n");
    printf("\n\t[ 04 ] - Encontrar el menor elemento de la pila y eliminarlo\n");
    printf("\n\t[ 05 ] - Ordenar por el meto de seleccion\n");
    printf("\n\t[ 06 ] - Insertar elemento en la pila\n");
    printf("\n\t[ 07 ] - Ordenar el ejercicio anterior por metodo de insercion\n");
    printf("\n\t[ 08 ] - Sumar los primeros dos topes de la pila.\n");
    printf("\n\t[ 09 ] - Hacer suma cuenta div y promedio de la pila\n");
    printf("\n\t[ 10 ] - Transformar los elementos de la pila en numero decimal\n");
    printf("\n\n\t\t\t[ 0 ] - SALIR\n");
}

/****************************************
 * \brief CARGA PILA RANDOM
 * \param PILA P *
 * \param INT CANTIDAD (LIMITE DE CARGA)
 * \return VOID
 ****************************************/

void cargarPila (Pila *p, int cant)
{
    int num;

    for (int i = 0; i < cant; i++)
    {
        num = rand() % (MAX - MIN + 1) + MIN;

        if (!ExistenciaPila(*p, num)){
        apilar(p, num);
        }
    }
}

/****************************************
 * \brief VALIDACION DE CARGA (NO REPETIR)
 * \param PILA P
 * \param INT DATO
 * \return FLAG
 ****************************************/

int ExistenciaPila (Pila p, int dato)
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

/****************************************
 * \brief MUESTRO LA PILA
 * \param PILA P
 * \return VOID
 ****************************************/

void muestraPila (Pila p)
{
    Pila aux;
    inicpila(&aux);

    printf("\n\n\t");
    while (!pilavacia(&p))
    {
        printf(" %d |", tope(&p));

        apilar(&aux, desapilar(&p));
    }
    printf("\n\n");
}

/****************************************
 * \brief PASO DE UNA PILA A OTRA
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ****************************************/

void pasaPila (Pila *p, Pila *q)
{
    while (!pilavacia(p))
    {
        apilar(q, desapilar(p));
    }
}

/***************************************************
 * \brief PASO DE UNA PILA A OTRA EN EL MISMO ORDEN
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 ***************************************************/

void pasaPilaMismoOrden (Pila *p, Pila *q)
{
    Pila aux;
    inicpila(&aux);

    pasaPila(p,&aux);
    pasaPila(&aux, q);
}

/**************************************************************
 * \brief ENCONTRAR EL MENOR ELEMENTO DE LA PILA E ELIMINARLA.
 * \param PILA P * (Con puntero puedo eliminar el menor).
 * \return MENOR
 **************************************************************/

int menorElementoPila (Pila *p)
{
    Pila aux;
    inicpila(&aux);
    int menor;

    if (!pilavacia(p))
    {
        menor = desapilar(p);

        while (!pilavacia(p))
        {
            if (tope(p) < menor)
            {
                apilar(&aux, menor);
                menor = desapilar(p);

            } else {

                apilar(&aux, desapilar(p));
            }
        }

        pasaPila(&aux, p);
    }

    return menor;
}

/**************************************************************
 * \brief ORDENO EL PUNTO ANTERIOR CON EL METODO DE SELECCION.
 * \param PILA P *
 * \return VOID
 **************************************************************/

void ordenarMetodoSeleccion (Pila *p, Pila *q)
{
    int menor;

    while (!pilavacia(p))
    {
        menor = menorElementoPila(p);
        apilar(q, menor);
    }

    pasaPila(q, p);
}

/*****************************************
 * \brief INSERTAR UN ELEMENTO EN LA PILA
 * \param PILA P *
 * \param ELEMENTO A INSERTAR.
 * \return VOID
 *****************************************/

void insertarElementoPila (Pila *p, int elemento)
{
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(p) && tope(p) < elemento)
    {
        apilar(&aux, desapilar(p));
    }

    apilar(p, elemento);

    pasaPila(&aux, p);
}

/*****************************************
 * \brief ORDENAR POR METODO DE INSERCION.
 * \param PILA P *
 * \param PILA Q *
 * \return VOID
 *****************************************/

void ordenarMetodoInsercion (Pila *p, Pila *q)
{
    int elemento;

    while (!pilavacia(p))
    {
        elemento = desapilar(p);
        insertarElementoPila(q, elemento);
    }

    pasaPila(q, p);
}

/*************************************************
 * \brief SUMAR LOS PRIMEROS DOS TOPES DE LA PILA.
 * \param PILA P *
 * \return SUMA
 *************************************************/

int sumar2Topes (Pila p)
{
    int suma = 0;

    suma = desapilar(&p);

    if (!pilavacia(&p))
    {
        suma = suma + tope(&p);
    }

    return suma;
}

/*************************************************
 * \brief SUMAR ELEMENTOS DE LA PILA.
 * \param PILA P
 * \return SUMA
 *************************************************/

int sumaPila (Pila p)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        suma += tope(&p);
        apilar(&aux, desapilar(&p));
    }
    return suma;
}

 /*************************************************
 * \brief CUENTA ELEMENTOS DE LA PILA.
 * \param PILA P
 * \return CONT
 *************************************************/

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

 /*************************************************
 * \brief DIVIDE DOS NUMEROS ENTEROS.
 * \param INT A.
 * \param INT B.
 * \return DIV
 *************************************************/

float division (int a, int b)
{
    float div;

    if (b > 0)
    {
        div = (float) a/b;
    }
    return div;
}

 /*************************************************
 * \brief PROMEDIA ELEMENTOS DE LA PILA.
 * \param PILA P
 * \return PROM
 *************************************************/

float promedio (Pila p)
{
    float prom = 0;

    int suma = sumaPila(p);
    int cont = cuentaPila(p);

    if (cont > 0)
    {
        prom = division(suma, cont);
    }
    return prom;
}

 /*************************************************
 * \brief CALCULO DE LA PILA.
 * \param PILA P
 * \return VOID.
 *************************************************/

void calculoPilas (Pila p)
{
    printf("\nLa suma de los elementos es: [ %d ]\n", sumaPila(p));
    printf("\nSe contaron: [ %d ] elementos en la pila\n", cuentaPila(p));
    printf("\nEl promedio de la pila es: [ %.2f ]\n", promedio(p));
}

 /*************************************************
 * \brief PASAR DE PILA A NUMERO DECIMAL.
 * \param PILA P
 * \return RESULTADO.
 *************************************************/

int pilaToDecimal (Pila p)
{
    int multiplicador = 1;
    int resultado = 0;

    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        resultado += tope(&p) * multiplicador; /// a += 10 --> a = a + 10.
        apilar(&aux, desapilar(&p));
        multiplicador *= 10;  /// a *= 10 --> a = a * 10.
    }

    pasaPila(&aux, &p);

    return resultado;
}


























