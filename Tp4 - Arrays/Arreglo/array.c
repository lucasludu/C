#include "array.h"

void menuCarga()
{
    printf("\n\t[ 1 ] - INT\n");
    printf("\n\t[ 2 ] - FLOAT\n");
    printf("\n\t[ 3 ] - CHAR\n");
    printf("\n\t\t[ ESC ] - SALIR\n");
}

//*************************************************************************//

/***********************************************
 * \brief CARGAR ARREGLO DE ENTERO MANUALMENTE
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

int cargaArregloIntManual (int a[], int v, int dim)
{
    int num;
    char op;

    do
    {
        system("cls");

        printf("\nIngrese entero:\n");
        scanf("%d", &num);
        a[v] = num;

        v++;
        printf("\n\t\tESC para salir......\n");
        op = getch();
        system("cls");

    } while (op != 27);

    return v;
}

/***********************************************
 * \brief CARGAR ARREGLO DE ENTERO RANDOM
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

int cargaArregloIntRandom (int a[], int v, int dim)
{
    dim = rand() % DIM;
    int num;

    printf("\nArreglo cargado\n");

    for (v = 0; v < dim; v++)
    {
        num = rand() % (MAX - MIN + 1) + MIN;
        a[v] = num;
    }
    return v;
}

/***********************************************
 * \brief TIPO DE CARGA DE ENTERO.
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDOS
 ***********************************************/

int tipoCargaInt (int a[], int v, int dim)
{
    char op;
    do {
        system("cls");
        printf("\n\t[ 1 ] - MANUAL\n");
        printf("\n\t[ 2 ] - RANDOM\n");
        printf("\n\t\t[ ESC ] - SALIR\n");

        op = getch();
        system("cls");

        switch (op)
        {
        case '1':

            v = cargaArregloIntManual(a, v, dim);

            break;

        case '2':

            v = cargaArregloIntRandom(a, v, dim);

            break;

        default:

            printf("\nFIN DE CARGA\n");
        }
        system("pause > arch");

    } while (op != 27);

    return v;
}

/***********************************************
 * \brief MUESTRA ARREGLO DE ENTERO
 * \param ARREGLO
 * \param VALIDO
 * \return VOID
 ***********************************************/

void muestraArregloInt (int a[], int v)
{
    int i;

    printf("\n\nArreglo\n");

    for (i = 0; i < v; i++)
    {
        if (i % 15 == 0)
        {
            printf("\n");
        }
        printf(" %3d |", a[i]);
    }
}

//*************************************************************************//

/***********************************************
 * \brief CARGAR ARREGLO REAL MANUALMENTE
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

float cargaArregloFloatManual (float a[], int v, int dim)
{
    char opcion;

    while (v < dim && opcion != 27)
    {
        system("cls");
        printf("\nIngrese el n%cmero REAL: ", 163);
        fflush(stdin);
        scanf("%f", &a[v]);
        v++;

        printf("\n\t\tESC para salir.......\n");
        opcion = getch();
        system("cls");
    }

    return v;

}

/***********************************************
 * \brief CARGAR ARREGLO REAL RANDOM
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

float cargaArregloFloatRandom (float a[], int v, int dim)
{
    float num;
    dim = rand() % DIM;

    printf("\nArreglo cargado\n");

    for (v = 0; v < dim; v++)
    {
        num = (rand() % (MAX - MIN + 1) + MIN);
        a[v] = num/10;
    }
    return v;
}

/***********************************************
 * \brief TIPO DE CARGA DE REALES.
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDOS
 ***********************************************/

float tipoCargaFloat (float a[], int v, int dim)
{
    char op;
    do {
        system("cls");
        printf("\n\t[ 1 ] - MANUAL\n");
        printf("\n\t[ 2 ] - RANDOM\n");
        printf("\n\t\t[ ESC ] - SALIR\n");

        op = getch();
        system("cls");

        switch (op)
        {
        case '1':

            v = cargaArregloFloatManual(a, v, dim);

            break;

        case '2':

            v = cargaArregloFloatRandom(a, v, dim);

            break;

        default:

            printf("\nFIN DE CARGA\n");
        }
        system("pause > arch");

    } while (op != 27);

    return v;
}

/***********************************************
 * \brief MUESTRA ARREGLO REAL
 * \param ARREGLO
 * \param VALIDO
 * \return VOID
 ***********************************************/

void muestraArregloFloat (float a[], int v)
{
    int i;
    printf("\nArreglo\n");

    for (i = 0; i < v; i++)
    {
        if (i % 15 == 0)
        {
            printf("\n");
        }
        printf(" %5.2f |", a[i]);
    }
}

//*************************************************************************//

/***********************************************
 * \brief CARGAR ARREGLO CHAR MANUALMENTE
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

char cargaArregloCharManual (char a[], int v, int dim)
{
    char op;
    char letra;

    while (op != 27)
    {
        system("cls");
        printf("\nIngrese letra\n");
        fflush(stdin);
        scanf("%c", &letra);
        a[v] = letra;

        v++;
        printf("\n\t\tESC para salir......\n");
        op = getch();
        system("cls");
    }
    return v;
}

/***********************************************
 * \brief CARGAR ARREGLO CHAR RANDOM
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDO
 ***********************************************/

char cargaArregloCharRandom (char a[], int v, int dim)
{
    char letra;
    dim = rand() % DIM;

    printf("\nArreglo cargado\n");

    for (v = 0; v < dim; v++)
    {
        letra = rand() % (CHARMAX - CHARMIN + 1) + CHARMIN;
        a[v] = letra;
    }
    return v;
}

/***********************************************
 * \brief TIPO DE CARGA DE CARACTERES.
 * \param ARREGLO
 * \param VALIDO
 * \param DIMENCION
 * \return VALIDOS
 ***********************************************/

char tipoCargaChar (float a[], int v, int dim)
{
    char op;
    do {
        system("cls");
        printf("\n\t[ 1 ] - MANUAL\n");
        printf("\n\t[ 2 ] - RANDOM\n");
        printf("\n\t\t[ ESC ] - SALIR\n");

        op = getch();
        system("cls");

        switch (op)
        {
        case '1':

            v = cargaArregloCharManual(a, v, dim);

            break;

        case '2':

            v = cargaArregloCharRandom(a, v, dim);

            break;

        default:

            printf("\nFIN DE CARGA\n");
        }
        system("pause > arch");

    } while (op != 27);

    return v;
}

/***********************************************
 * \brief MUESTRA ARREGLO REAL
 * \param ARREGLO
 * \param VALIDO
 * \return VOID
 ***********************************************/

void muestraArregloChar (char a[], int v)
{
    int i;
    printf("\nArreglo\n");

    for (i = 0; i < v; i++)
    {
        if (i % 15 == 0)
        {
            printf("\n");
        }
        printf(" %c |", a[i]);
    }
}

//*************************************************************************//

/***************************************************
 * \brief SUMA DE LOS ELEMENTOS ENTEROS DEL ARREGLO
 * \param ARREGLO
 * \param VALIDO
 * \return SUMA
 ***************************************************/

int sumaElementosInt (int a[], int v)
{
    int suma = 0;

    for (int i = 0; i < v; i++)
    {
        suma = suma + a[i];
    }
    return suma;
}

/**************************************************
 * \brief SUMA DE LOS ELEMENTOS REALES DEL ARREGLO
 * \param ARREGLO
 * \param VALIDO
 * \return SUMA
 **************************************************/

float sumaElementosfloat (float a[], int v)
{
    int i;
    float suma = 0;

    for (i = 0; i < v; i++)
    {
        suma = suma + a[i];
    }

    return suma;
}

//*************************************************************************//


int pilaToArreglo (Pila p, int a[], int v){
    Pila aux;
    inicpila(&aux);
    int num = 0;
    while(!pilavacia(&p)){
        num = tope(&p);
        a[v] = num;
        apilar(&aux, desapilar(&p));
    }
    while(!pilavacia(&aux)){
        apilar(&p, desapilar(&aux));
    }
    return v;
}

/***********************************************
 * \brief PASO ARREGLO ENTERO A LA PILA
 * \param ARREGLO
 * \param VALIDO
 * \param PILA P *
 * \return VOID
 ***********************************************/

void arrayIntToPila (int a[], int v, Pila *p)
{
    int i;

    for (i = 0; i < v; i++)
    {
        apilar(p, a[i]);
    }
}

/***********************************************
 * \brief PASO ARREGLO REAL A LA PILA
 * \param ARREGLO
 * \param VALIDO
 * \param PILA P *
 * \return VOID
 ***********************************************/

void arrayRealToPila (float a[], int v, Pila *p)
{
    int i;

    for (i = 0; i < v; i++)
    {
        apilar(p, a[i]);
    }
}

/***********************************************
 * \brief PASO ARREGLO CHAR A LA PILA
 * \param ARREGLO
 * \param VALIDO
 * \param PILA P *
 * \return VOID
 ***********************************************/

void arrayCharToPila (char a[], int v, Pila *p)
{
    int i;

    for (i = 0; i < v; i++)
    {
        apilar(p, a[i]);
    }
}

/***********************************************
 * \brief MOSTRAR PILA ENTERA
 * \param PILA P *
 * \return VOID
 ***********************************************/

void muestroPilaInt (Pila p)
{
    Pila aux;
    inicpila(&aux);

    int i = 0;

    while(!pilavacia(&p))
    {
        if(i % 10 == 0)
        {
            printf("\n\t");
        }
        printf(" %3d |", tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
    printf("\n");
}

/***********************************************
 * \brief MOSTRAR PILA REAL
 * \param PILA P *
 * \return VOID
 ***********************************************/

void muestroPilaFloat (Pila p)
{
    Pila aux;
    inicpila(&aux);

    int i = 0;

    while(!pilavacia(&p))
    {
        if(i % 10 == 0)
        {
            printf("\n\t");
        }
        printf(" %6.2f |", tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
    printf("\n");
}

/***********************************************
 * \brief MOSTRAR PILA CHAR
 * \param PILA P *
 * \return VOID
 ***********************************************/

void muestroPilaChar (Pila p)
{
    Pila aux;
    inicpila(&aux);

    int i = 0;

    while(!pilavacia(&p))
    {
        if(i % 10 == 0)
        {
            printf("\n\t");
        }
        printf(" %c |", tope(&p));
        apilar(&aux, desapilar(&p));
        i++;
    }
    printf("\n");
}

//*************************************************************************//

/***********************************************
 * \brief BUSCAR ELEMENTO ENTERO EN EL ARREGLO
 * \param ARREGLO
 * \param VALIDO
 * \param INT DATO
 * \return FLAG
 ***********************************************/

int buscaElementoInt (int a[], int v, int dato)
{
    int flag = 0;
    int i;

    while (i < v && flag == 0)
    {
        if (a[i] == dato)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

void funcionBuscarInt (int a[], int v)
{
    int dato;
    int encontrado;

    printf("\nIngrese el dato a buscar\n");
    printf("\nSe ingreso:\t");
    scanf("%d", &dato);

    encontrado = buscaElementoInt(a, v, dato);

    if (encontrado)
    {
        printf("\nEl elemento [ %d ] se encuentra en el arreglo\n", dato);

    } else {

        printf("\nEl elemento [ %d ] no se encuentra en el arreglo\n", dato);
    }
}

/***********************************************
 * \brief BUSCAR ELEMENTO REAL EN EL ARREGLO
 * \param ARREGLO
 * \param VALIDO
 * \param INT DATO
 * \return FLAG
 ***********************************************/

float buscaElementoFloat (float a[], int v, float dato)
{
    int i = 0;
    int flag = 0;

    while (i < v && flag == 0)
    {
        if (a[i] == dato)
        {
            flag = 1;
        }
        i++;
    }
    return flag;
}

void funcionBuscarFloat (float a[], int v)
{
    float dato;
    int encontrado;

    printf("\nIngrese el dato a buscar\n");
    printf("\nSe ingreso:\t");
    scanf("%f", &dato);

    encontrado = buscaElementoInt(a, v, dato);

    if (encontrado)
    {
        printf("\nEl elemento [ %.2f ] se encuentra en el arreglo\n", dato);

    } else {

        printf("\nEl elemento [ %.2f ] no se encuentra en el arreglo\n", dato);
    }
}

/***********************************************
 * \brief BUSCAR ELEMENTO CHAR EN EL ARREGLO
 * \param ARREGLO
 * \param VALIDO
 * \param CHAR DATO
 * \return FLAG
 ***********************************************/

char buscaElementoChar (float a[], int v, char dato)
{
    int i = 0;
    int flag = -1;

    while (i < v && flag == -1)
    {
        if (a[i] == dato)
        {
            flag = i;
        }
        i++;
    }
    return flag;
}

void funcionBuscarChar (char a[], int v)
{
    char encontrado;
    char dato;

    printf("\nBUSCAR CARACTER\n");
    printf("\nIngrese el caractre a buscar\n");
    scanf ("%s", &dato);

    encontrado = buscaElementoChar(a, v, dato);

    if (encontrado)
    {
        printf("\nEl caracter [ %c ] se encuentra en el arreglo\n", dato);
    }
    else
    {
        printf("\nEl caracter [ %c ] NO se encuentra en el arreglo\n", dato);
    }
}

//******************************************************************************************//

/***************************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO INT.
 * \brief La responsailidad del programador verificar que hay un espacio en el arreglo.
 * \param ARREGLO.
 * \param VALIDO.
 * \param DATO A INSERTAR.
 * \return VALIDOS.
 ***************************************************************************************/

int insertarInt (int a[], int v, int dato)
{
    int i = v - 1;

    while (i >= v && a[i] > dato)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;

    return v + 1;
}

/******************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO INT.
 * \brief PARA SER USADA CON EL ALGORITMO DE ORDENACION POR INSERCION.
 * \param ARREGLO.
 * \param ULTIMA POSICION.
 * \param DATO A INSERTAR.
 * \return VOID.
 *******************************************************************************/

void insertarOrdenadoInt (int a[], int pos, int dato)
{
    int i = pos;

    while (i >= 0 && a[i] > dato)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
}

/*******************************************************************
 * \brief FUNCION QUE ORDENA POR INSERCION UN ARREGLO DE TIPO INT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *******************************************************************/

void ordenaIntInsertado (int a[], int v)
{
    int i = 0;

    while (i < v - 1)
    {
        insertarOrdenadoInt(a, i, a[i+1]);
        i++;
    }
}

//******************************************************************************************//

/***************************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO FLOAT.
 * \brief La responsailidad del programador verificar que hay un espacio en el arreglo.
 * \param ARREGLO.
 * \param VALIDO.
 * \param DATO A INSERTAR.
 * \return VALIDOS.
 ***************************************************************************************/

int insertarFloat (float a[], int v, float dato)
{
    int i = v - 1;

    while (i >= v && a[i] > dato)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;

    return v + 1;
}

/******************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO INT.
 * \brief PARA SER USADA CON EL ALGORITMO DE ORDENACION POR INSERCION.
 * \param ARREGLO.
 * \param ULTIMA POSICION.
 * \param DATO A INSERTAR.
 * \return VOID.
 *******************************************************************************/

void insertarOrdenadoFloat (float a[], int pos, float dato)
{
    int i = pos;

    while (i >= 0 && a[i] > dato)
    {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = dato;
}

/*******************************************************************
 * \brief FUNCION QUE ORDENA POR INSERCION UN ARREGLO DE TIPO INT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *******************************************************************/

void ordenaFloatInsertado (float a[], int v)
{
    int i = 0;

    while (i < v - 1)
    {
        insertarOrdenadoFloat(a, i, a[i+1]);
        i++;
    }
}

//******************************************************************************************//

/***************************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO CHAR.
 * \brief La responsailidad del programador verificar que hay un espacio en el arreglo.
 * \param ARREGLO.
 * \param VALIDO.
 * \param DATO A INSERTAR.
 * \return VALIDOS.
 ***************************************************************************************/

int insertarChar (char a[], int v, char dato)
{
    int i = v - 1;

    while (i >= v && a[i] > dato) ///mayor o igual porque tengo que contar al cero tmb.
    {
        a[i+1] = a[i];
        i--; /// i = i - 1
    }
    a[i+1] =  dato;

    return v + 1; /// i
}

/******************************************************************************
 * \brief FUNCION QUE INSERTA UN ELEMENTO EN UN ARREGLO ORDENADO DE TIPO CHAR.
 * \brief PARA SER USADA CON EL ALGORITMO DE ORDENACION POR INSERCION..
 * \param ARREGLO.
 * \param ULTIMA POSICION.
 * \param DATO A INSERTAR.
 * \return VOID.
 *******************************************************************************/

void insertarOrdenadoChar (char a_c[], int v, int caracter)
{
    int i = v;

    while (i >= 0 && a_c[i] > caracter)
    {
        a_c[i+1] = a_c[i];
        i--;
    }
    a_c[i+1] = caracter;
}

/*******************************************************************
 * \brief FUNCION QUE ORDENA POR INSERCION UN ARREGLO DE TIPO CHAR.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *******************************************************************/

void ordenaCharInsertado (char a[], int v)
{
    int i = 0;

    while (i < v - 1)
    {
        insertarOrdenadoChar(a, i, a[i+1]);   /// mi arregñp termina en i.
        i++;

    }
}

//******************************************************************************************//

/*******************************************************************
 * \brief FUNCION QUE BUSCA EL MAYOR ELEMENTO DEL ARREGLO DE ENTERO.
 * \param ARREGLO.
 * \param VALIDO.
 * \return INT MAYOR.
 *******************************************************************/

int buscarMayorInt (int a[], int v)
{
    int i = 0;
    int mayor = a[i];

    while (i < v)
    {
        if (a[i] > mayor)
        {
            mayor = a[i];
        }
        i++;
    }
    return mayor;
}

/*********************************************************************************
 * \brief FUNCION QUE BUSCA LA POSICION DEL MAYOR ELEMENTO DEL ARREGLO DE ENTERO.
 * \param ARREGLO.
 * \param VALIDO.
 * \param COMIENZO.
 * \return POSICION DEL MAYOR ELEMENTO.
 *********************************************************************************/

int buscaPosMayorInt (int a[], int v, int c)
{
    int i = c;
    int posMayor = i;
    i++;

    while (i < v)
    {
        if (a[i] > a[posMayor])
        {
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

/*********************************************************************************
 * \brief MUESTRA EL MAYOR ELEMENTO Y SU POSICION EN EL ARREGLO.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *********************************************************************************/

void funcionMayorInt (int a[], int v)
{
    printf("\nArreglo de entero buscando Mayor y posicion mayor\n");
    printf("\n[ %d ] es el mayor elemento en el arreglo de entero\n", buscarMayorInt(a, v));
    printf("\nSe encuentra en la posicion [ %d ]\n", buscaPosMayorInt(a, v, 0));
}

//******************************************************************************************//

/*******************************************************************
 * \brief FUNCION QUE BUSCA EL MAYOR ELEMENTO DEL ARREGLO DE FLOAT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return INT MAYOR.
 *******************************************************************/

float buscarMayorFloat (float a[], int v)
{
    int i = 0;
    float mayor = a[i];

    while (i < v)
    {
        if (a[i] > mayor)
        {
            mayor = a[i];
        }
        i++;
    }
    return mayor;
}

/*********************************************************************************
 * \brief FUNCION QUE BUSCA LA POSICION DEL MAYOR ELEMENTO DEL ARREGLO DE FLOAT.
 * \param ARREGLO.
 * \param VALIDO.
 * \param COMIENZO.
 * \return POSICION DEL MAYOR ELEMENTO.
 *********************************************************************************/

int buscaPosMayorFloat (float a[], int v, int c)
{
    int i = c;
    int posMayor = i;
    i++;

    while (i < v)
    {
        if (a[i] > a[posMayor])
        {
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

/*********************************************************************************
 * \brief MUESTRA EL MAYOR ELEMENTO Y SU POSICION EN EL ARREGLO FLOAT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *********************************************************************************/

void funcionMayorFloat (float a[], int v)
{
    printf("\nArreglo float buscando Mayor y posicion mayor\n");
    printf("\n[ %.2f ] es el mayor elemento del arreglo\n", buscarMayorFloat(a, v));
    printf("\nEl mayor se encuentra en la posicion [ %d ]\n", buscaPosMayorFloat(a, v, 0));
}

//******************************************************************************************//

/*******************************************************************
 * \brief FUNCION QUE BUSCA EL MAYOR ELEMENTO DEL ARREGLO DE ENTERO.
 * \param ARREGLO.
 * \param VALIDO.
 * \return INT MAYOR.
 *******************************************************************/

char buscarMayorChar (char a[], int v)
{
    int i = 0;
    char mayor = a[i];

    while (i < v)
    {
        if (mayor < a[i])
        {
            mayor = a[i];
        }
        i++;
    }
    return mayor;
}

/*********************************************************************************
 * \brief FUNCION QUE BUSCA LA POSICION DEL MAYOR ELEMENTO DEL ARREGLO DE FLOAT.
 * \param ARREGLO.
 * \param VALIDO.
 * \param COMIENZO.
 * \return POSICION DEL MAYOR ELEMENTO.
 *********************************************************************************/

int buscaPosMayorChar (char a[], int v, int c)
{
    int i = c;
    int posMayor = i;
    i++;

    while (i < v)
    {
        if (a[i] > a[posMayor])
        {
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

/*********************************************************************************
 * \brief MUESTRA EL MAYOR ELEMENTO Y SU POSICION EN EL ARREGLO FLOAT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *********************************************************************************/

void funcionMayorChar (char a[], int v)
{
    printf("\nArreglo float buscando Mayor y posicion mayor\n");
    printf("\n[ %c ] es el mayor elemento del arreglo\n", buscarMayorChar(a, v));
    printf("\nEl mayor se encuentra en la posicion [ %d ]\n", buscaPosMayorChar(a, v, 0));
}

//******************************************************************************************//

/*********************************************************************************
 * \brief DETERMINA SI EL ARREGLO DE ENTERO ES CAPICUA O NO.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 *********************************************************************************/

void arregloIntCapicua (int a[], int v)
{
    int i = 0;
    int capicua = 1;

    while (i < v)
    {
        if (a[i] != a[v-1-i])
        {
            capicua = 0;
        }
        i++;
    }

    if (capicua == 1)
    {
        printf("\nEs capicua\n");

    } else {

        printf("\nNo es capicua\n");
    }
}

void arregloCharCapicua (char a[], int v)
{
    int i = 0;
    int capicua = 1;

    while (i < v)
    {
        if (a[i] != a[v-1-i])
        {
            capicua = 0;
        }
        i++;
    }

    if (capicua == 1)
    {
        printf("\nEs CAPICUA\n");

    } else {

        printf("\nNo es NADAAAA\n");
    }
}

//******************************************************************************************//

/*******************************
 * \brief INVERTIR ARREGLO.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID
 *******************************/

/**************************************
*
* a[i] = 1  2  3  4  5  6
* i    = 0  1  2  3  4  5
*
* v = 6
* v-1-i --> i = 0 / v-1-i = 5 // 6
*           i = 1 / v-1-i = 4 // 5
*           i = 2 / v-1-i = 3 // 4
*           i = 3 / v-1-i = 2 // 3
*           i = 4 / v-1-i = 1 // 2
*           i = 5 / v-1-i = 0 // 1
*
***************************************/

void invertirArregloInt (int a[], int v)
{
    int aux;
    int i;

    for (i = 0; i < (v/2); i++)
    {
        aux = a[i];
        a[i] = a[v-1-i];
        a[v-1-i] = aux;
    }
}

void invertirArregloChar (char a[], int v)
{
    char aux;
    int i;

    for (i = 0; i < (v/2); i++)
    {
        aux = a[i];
        a[i] = a[v-1-i];
        a[v-1-i] = aux;
    }
}

//******************************************************************************************//

/**************************************
 * \brief ORDENA ARREGLO POR SELECCION.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID
 **************************************/

/********************************************
*
* a[i] = 5  7  3  2  8
* i    = 0  1  2  3  4
*
* i = 0 --> j = 1 --> a[j] = 7 / a[min] = 5
* i = 1 --> j = 2 --> a[j] = 3 / a[min] = 7
*
* a[i] = 5  3  7  2  8
* i    = 0  1  2  3  4
*
* i = 0 --> j = 1 --> a[j] = 3 / a[min] = 5
*
* a[i] = 3  5  7  2  8
* i    = 0  1  2  3  4
*
*********************************************/

void ordenaSeleccionInt (int a[], int v)
{
    int i, j, aux, min;

    for (i = 0; i < v; i++)
    {
        min = i;

        for (j = i + 1; j < v; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
}

/**************************************************
 * \brief ORDENAR ARREGLO POR INSERCION TIPO INT.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 **************************************************/

/*******************************************************
 *
 * a[i] = 5  9  2  4  7
 * i    = 0  1  2  3  4
 *
 * i = 0 --> pos = 0 --> a[i] = 5
 *
 *
 *******************************************************/

void ordenaInsercionInt (int a[], int v)
{
    int i, pos, aux;

    for (i = 0; i < v; i++)
    {
        pos = i;
        aux = a[i];

        while (pos > 0 && (a[pos - 1] > aux))
        {
            a[pos] = a[pos - 1];
            pos--;
        }

        a[pos] = aux;
    }

}

//******************************************************************************************//

/**************************************
 * \brief ORDENA ARREGLO POR SELECCION.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID
 **************************************/

void ordenaSeleccionChar (char a[], int v)
{
    int i, j, aux, min;

    for (i = 0; i < v; i++)
    {
        min = i;

        for (j = i + 1; j < v; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }

        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
}

/**************************************************
 * \brief ORDENAR ARREGLO POR INSERCION TIPO CHAR.
 * \param ARREGLO.
 * \param VALIDO.
 * \return VOID.
 **************************************************/

void ordenaInsercionChar (char a[], int v)
{
    int i, pos;
    char aux;

    for (i = 0; i < v; i++)
    {
        pos = i;
        aux = a[i];

        while (pos > 0 && (a[pos - 1] > aux))
        {
            a[pos] = a[pos - 1];
            pos--;
        }

        a[pos] = aux;
    }
}

//******************************************************************************************//

/********************************************************************************
 * \brief FUNCION QUE PASA LOS ELEMENTOS DE LOS ARREGLOS A Y B a C INTERCALADOS.
 * \param A, A1, A2.
 * \param V, V1, V2.
 * \return V2
 ********************************************************************************/


int intercalarArreglos (char a[], char a1[], char at[], int v, int v1, int vt)
{
    int i = 0, j = 0, t = 0;

    while (i < v && j < v1)
    {
        if (a[i] < a1[j])
        {
            at[t] = a[i];
            t++;
            i++;
            at[t] = a1[j];
            j++;
            t++;

        } else {

            at[t] = a1[j];
            t++;
            j++;
            at[t] = a[i];
            i++;
            t++;
        }

    }
    while (i < v)
    {
        at[t] = a[i];
        t++;
        i++;
    }

    while (j < v1)
    {
        at[t] = a1[j];
        t++;
        j++;
    }

    return t;
}

























