#include "listaSimple.h"

/**
 * \brief INICIALIZA EL NODO SIMPLE
 * \param SIN PARAMETROS
 * \return NULL
 */

stNodoSimple * initListaSimple() {
    return NULL;
}

/**
 * \brief CREA LISTA SIMPLE
 * \param REGISTRO
 * \return NUEVO NODO SIMPLE
 */

stNodoSimple * crearNodoSimple(stRegistro r) {
    stNodoSimple * nuevo = (stNodoSimple*) malloc(sizeof(stNodoSimple));
    nuevo->dato = r;
    nuevo->siguiente = NULL;
    return nuevo;
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL PRINCIPIO (ITERATIVA PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return LISTA
 */

stNodoSimple * cargaListaSimplePpio (stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL PRINCIPIO (ITERATIVA PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param PUNTERO NUEVO
 * \return VOID
 */

void cargaListaSimplePpioPD(stNodoSimple ** lista, stNodoSimple * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        nuevo->siguiente = (*lista);
        (*lista) = nuevo;
    }
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL PRINCIPIO (RECURSIVO)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return LISTA
 */

stNodoSimple * cargaListaSimplePpioRecursivo(stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        lista->siguiente = cargaListaSimplePpioRecursivo(lista->siguiente, nuevo);
    }
    return lista;
}


/*************************************************************************************************/


/**
 * \brief BUSCA EL ULTIMO NODO DE LA LISTA
 * \param PUNTERO LISTA
 * \return ULTIMO NODO
 */

stNodoSimple * buscaUltimoNodoSimple(stNodoSimple * lista) {
    stNodoSimple * seg = lista;
    while(seg->siguiente) {
        seg = seg->siguiente;
    }
    return seg;
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL FINAL DE LA LISTA (ITERATIVO - PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return LISTA
 */

stNodoSimple * cargaListaSimpleFinal(stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodoSimple * ultimo = buscaUltimoNodoSimple(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL FINAL DE LA LISTA (ITERATIVO - PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param PUNTERO NUEVO
 * \return VOID
 */

void cargaListaSimpleFinalPD(stNodoSimple ** lista, stNodoSimple * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        stNodoSimple * ultimo = buscaUltimoNodoSimple(*lista);
        ultimo->siguiente = nuevo;
    }
}

/**
 * \brief CREA LISTA SIMPLE DESDE EL FINAL DE LA LISTA (RECURSIVO)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return LISTA
 */

stNodoSimple * cargaListaSimpleFinalRecursivo(stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodoSimple * ultimo = buscaUltimoNodoSimple(lista);
        ultimo->siguiente = cargaListaSimpleFinalRecursivo(ultimo->siguiente, nuevo);
    }
    return lista;
}


/*************************************************************************************************/


/**
 * \brief CREA LISTA SIMPLE ORDENADA POR APELLIDO (ITERATIVO - PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return LISTA
 */

stNodoSimple * cargaListaSimpleOrdenadaApellido(stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(strcmp(lista->dato.apellido, nuevo->dato.apellido) > 0) {
            lista = cargaListaSimplePpio(lista, nuevo);
        } else {
            stNodoSimple * seg = lista->siguiente;
            stNodoSimple * ante = lista;
            while(seg && strcmp(nuevo->dato.apellido, seg->dato.apellido) > 0) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;
        }
    }
    return lista;
}

/**
 * \brief CREA LISTA SIMPLE ORDENADA POR DNI (ITERATIVO - PUNTERO DOBLE)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return VOID
 */

void cargaListaSimpleOrdenadaDniPD(stNodoSimple ** lista, stNodoSimple * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        if(atoi((*lista)->dato.dni) > (atoi(nuevo->dato.dni))) {
            cargaListaSimplePpioPD(lista, nuevo);
        } else {
            stNodoSimple * seg = (*lista)->siguiente;
            stNodoSimple * ante = (*lista);
            while(seg && atoi(nuevo->dato.dni) > atoi(seg->dato.dni)) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;
        }
    }
}

/**
 * \brief CREA LISTA SIMPLE ORDENADA POR DNI (RECURSIVO)
 * \param PUNTERO LISTA
 * \param PUNTERO NUEVO
 * \return VOID
 */

stNodoSimple * cargaListaSimpleOrdenadaEdadRecursivo(stNodoSimple * lista, stNodoSimple * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(lista->dato.edad > nuevo->dato.edad) {
            nuevo->siguiente = lista;
            lista = nuevo;
        } else {
            lista->siguiente = cargaListaSimpleOrdenadaEdadRecursivo(lista->siguiente, nuevo);
        }
    }
    return lista;
}

/*************************************************************************************************/


/**
 * \brief MUESTRA NODO SIMPLE
 * \param PUNTERO NODO
 * \return VOID
 */

void muestraNodoSimple(stNodoSimple * nodo) {
    printf("\n\tNodo: %p   Nodo Siguiente: %p", nodo, nodo->siguiente);
    muestraUnRegistro(nodo->dato);
}

/**
 * \brief MUESTRA LISTA SIMPLE (ITERATIVO - PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \return VOID
 */

void muestraListaSimple(stNodoSimple * lista) {
    stNodoSimple * seg = lista;
    while(seg) {
        muestraNodoSimple(seg);
        seg = seg->siguiente;
    }
}

/**
 * \brief MUESTRA LISTA SIMPLE (ITERATIVO - PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \return VOID
 */

void muestraListaSimplePD(stNodoSimple ** lista) {
    stNodoSimple * seg = (*lista);
    while(seg) {
        muestraNodoSimple(seg);
        seg = seg->siguiente;
    }
}

/**
 * \brief MUESTRA LISTA SIMPLE (RECURSIVO)
 * \param PUNTERO LISTA
 * \return VOID
 */

void muestraListaSimpleRecursivo(stNodoSimple * lista) {
    if(lista) {
        muestraNodoSimple(lista);
        muestraListaSimpleRecursivo(lista->siguiente);
    }
}

/*****************************************************************************************/

/**
 * \brief BORRA NODO EN LA LISTA SIMPLE
 * \param PUNTERO LISTA
 * \param NOMBRE
 * \param APELLIDO
 * \return LISTA
 */

stNodoSimple * borrarNodoSimple(stNodoSimple * lista, char nombre[20], char apellido[20]) {
    stNodoSimple * seg;
    stNodoSimple * ante;
    if(lista) {
        if(strcmp(nombre, lista->dato.nombre) == 0 && strcmp(apellido, lista->dato.apellido) == 0) {
            stNodoSimple * aux = lista;
            lista = lista->siguiente;
            free(aux);
        } else {
            seg = lista;
            while(seg && strcmp(nombre, seg->dato.nombre) != 0 && strcmp(apellido, seg->dato.apellido) != 0) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

/**
 * \brief BORRA NODO EN LA LISTA SIMPLE (PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param NOMBRE
 * \param APELLIDO
 * \return VOID
 */

void borrarNodoSimplePD(stNodoSimple ** lista, char nombre[20], char apellido[20]) {
    stNodoSimple * seg;
    stNodoSimple * ante;
    if(*lista) {
        if(strcmp(nombre, (*lista)->dato.nombre) == 0 && strcmp(apellido, (*lista)->dato.apellido) == 0) {
            stNodoSimple * aux = (*lista);
            (*lista) = (*lista)->siguiente;
            free(aux);
        } else {
            seg = (*lista);
            while(seg && strcmp(nombre, seg->dato.nombre) != 0 && strcmp(apellido, seg->dato.apellido) != 0) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
}

/**
 * \brief BORRA NODO EN LA LISTA SIMPLE EN FORMA RECURSIVA
 * \param PUNTERO LISTA
 * \param NOMBRE
 * \param APELLIDO
 * \return LISTA
 */

stNodoSimple * borrarNodoSimpleRecursivo(stNodoSimple * lista, char nombre[20], char apellido[20]) {
    stNodoSimple * seg;
    stNodoSimple * ante;
    if(lista) {
        if(strcmp(nombre, lista->dato.nombre) == 0 && strcmp(apellido, lista->dato.apellido) == 0) {
            stNodoSimple * aux = lista;
            lista = lista->siguiente;
            free(aux);
        } else {
            lista->siguiente = borrarNodoSimpleRecursivo(lista->siguiente, nombre, apellido);
        }
    }
    return lista;
}

/**
 * \brief BORRA PRIMER NODO DE LA LISTA SIMPLE
 * \param PUNTERO LISTA
 * \return LISTA
 */

stNodoSimple * borrarPrimerNodoSimple(stNodoSimple * lista) {
    stNodoSimple * aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

/**
 * \brief BORRA ULTIMO NODO DE LA LISTA SIMPLE
 * \param PUNTERO LISTA
 * \return LISTA
 */

stNodoSimple * borrarUltimoNodoSimple(stNodoSimple * lista) {
    stNodoSimple * aux = lista;
    stNodoSimple * ante;
    while(aux->siguiente) {
        ante = aux;
        aux = aux->siguiente;
    }
    free(aux);
    ante->siguiente = NULL;
    return lista;
}


/******************************************************************************************************/


/**
 * \brief BUSCA LA PERSONA POR NOMBRE Y APELLIDO.
 * \param PUNTERO LISTA
 * \param NOMBRE
 * \param APELLIDO
 * \return LISTA
 */

stNodoSimple * buscarNodoSimpleApellidoNombre(stNodoSimple * lista, char nombre[20], char apellido[20]) {
    stNodoSimple * seg = lista;
    while(seg && strcmp(nombre, seg->dato.nombre) != 0 && strcmp(apellido, seg->dato.apellido) != 0) {
        seg = seg->siguiente;
    }
    return seg;
}


/******************************************************************************************************/


/**
 * \brief SUMA LAS EDADES DE LA LISTA SIMPLE.
 * \param PUNTERO LISTA
 * \return SUMA
 */

int sumaEdadesListaSimple(stNodoSimple * lista) {
    stNodoSimple * seg = lista;
    int suma = 0;
    while(seg) {
        suma += seg->dato.edad;
        seg = seg->siguiente;
    }
    return suma;
}

/**
 * \brief SUMA LAS EDADES DE LA LISTA SIMPLE CON FILTRO.
 * \param PUNTERO LISTA
 * \return SUMA
 */

int sumaEdadesFiltroListaSimple(stNodoSimple * lista, int limite) {
    int suma = 0;
    stNodoSimple * seg = lista;
    while(seg && seg->dato.edad > limite) {
        suma += seg->dato.edad;
        seg = seg->siguiente;
    }
    return suma;
}

/**
 * \brief SUMA LAS EDADES DE LA LISTA SIMPLE RECURSIVA.
 * \param PUNTERO LISTA
 * \return RTA
 */

int sumaEdadesListaSimpleRecursiva(stNodoSimple * lista) {
    int rta;
    if(!lista) {
        rta = 0;
    } else {
        rta = lista->dato.edad + sumaEdadesListaSimpleRecursiva(lista->siguiente);
    }
    return rta;
}

/**
 * \brief SUMA LAS EDADES DE LA LISTA SIMPLE RECURSIVA CON FILTRO.
 * \param PUNTERO LISTA
 * \return RTA
 */

int sumaEdadesFiltroListaSimpleRecursivo(stNodoSimple * lista) {
    int rta;
    if(!lista) {
        rta = 0;
    } else {
        if(lista->dato.edad > 10 && lista->dato.edad < 60) {
            rta = lista->dato.edad + sumaEdadesFiltroListaSimpleRecursivo(lista->siguiente);
        } else {
            rta = sumaEdadesFiltroListaSimpleRecursivo(lista->siguiente);
        }
    }
}

/**
 * \brief CUENTA LAS EDADES DE LA LISTA SIMPLE.
 * \param PUNTERO LISTA
 * \return CONTADOR
 */


int cuentaEdadesListaSimple(stNodoSimple * lista) {
    stNodoSimple * seg = lista;
    int i = 0;
    while(seg) {
        i++;
        seg = seg->siguiente;
    }
    return i;
}

/**
 * \brief CUENTA LAS EDADES DE LA LISTA SIMPLE RECURSIVA.
 * \param PUNTERO LISTA
 * \return CONTADOR
 */

int cuentaEdadesListaSimpleRecursivo(stNodoSimple * lista) {
    int rta;
    if(!lista) {
        rta = 0;
    } else {
        rta = 1 + cuentaEdadesListaSimpleRecursivo(lista->siguiente);
    }
    return rta;
}


/********************************************************************************************************/


/**
 * \brief BUSCA MAYOR EDAD DEL REGISTRO DE LA LISTA.
 * \param PUNTERO LISTA
 * \return MAYOR
 */

stNodoSimple * buscaMayorRegistro(stNodoSimple * lista) {
    stNodoSimple * maximo;
    stNodoSimple * seg;
    if(lista) {
        maximo = lista;
        seg = lista->siguiente;
        while(seg) {
            if(seg->dato.edad > maximo->dato.edad) {
                maximo = seg;
            }
            seg = seg->siguiente;
        }
    }
    return maximo;
}

/**
 * \brief BUSCA MAYOR EDAD DEL REGISTRO DE LA LISTA RECURSIVA.
 * \param PUNTERO LISTA
 * \return MAYOR
 */

stNodoSimple * buscaMayorRegistroRecursivo(stNodoSimple * lista) {
    stNodoSimple * mayor;
    if(!lista->siguiente) {
        mayor = lista;
    } else {
        mayor = buscaMayorRegistroRecursivo(lista->siguiente);
        if(lista->dato.edad > mayor->dato.edad) {
            mayor = lista;
        }
    }
    return mayor;
}

/**
 * \brief BUSCA MENOR EDAD DEL REGISTRO DE LA LISTA.
 * \param PUNTERO LISTA
 * \return MAYOR
 */

stNodoSimple * buscaMenorRegistro(stNodoSimple * lista) {
    stNodoSimple * minimo;
    stNodoSimple * seg;
    if(lista) {
        minimo = lista;
        seg = lista->siguiente;
        while(seg) {
            if(seg->dato.edad < minimo->dato.edad) {
                minimo = seg;
            }
            seg = seg->siguiente;
        }
    }
    return minimo;
}

/**
 * \brief BUSCA MENOR EDAD DEL REGISTRO DE LA LISTA RECURSIVA.
 * \param PUNTERO LISTA
 * \return MAYOR
 */

stNodoSimple * buscaMenorRegistroRecursivo(stNodoSimple * lista) {
    stNodoSimple * menor;
    if(!lista->siguiente) {
        menor = lista;
    } else {
        menor = buscaMenorRegistroRecursivo(lista->siguiente);
        if(lista->dato.edad <  menor->dato.edad) {
            menor = lista;
        }
    }
    return menor;
}







