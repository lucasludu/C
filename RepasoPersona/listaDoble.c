#include "listaDoble.h"

/**
 * \brief INICIALIZA EL NODO DOBLE
 * \param SIN PARAMETROS
 * \return NULL
 */

stNodoDoble * initListaDoble() {
    return NULL;
}

/**
 * \brief CREAR EL NODO DOBLE
 * \param REGISTRO
 * \return NUEVO NODO
 */

stNodoDoble * crearNodoDoble(stRegistro r) {
    stNodoDoble * nuevo = (stNodoDoble*) malloc(sizeof(stNodoDoble));
    nuevo->dato = r;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

/**
 * \brief AGREGA NODO DESDE EL PRINCIPIO DE LA LISTA DOBLE (ITERATIVA - PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDoblePpio(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        lista->anterior = nuevo;
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

/**
 * \brief AGREGA NODO DESDE EL PRINCIPIO DE LA LISTA DOBLE (ITERATIVA - PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param PUNTERO LISTA NUEVA
 * \return VOID
 */

void cargaListaDoblePpioPD(stNodoDoble ** lista, stNodoDoble * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        (*lista)->anterior = nuevo;
        nuevo->siguiente = (*lista);
        (*lista) = nuevo;
    }
}

/**
 * \brief AGREGA NODO DESDE EL PRINCIPIO DE LA LISTA DOBLE RECURSIVA
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDoblePpioRecursivo(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        lista->anterior = cargaListaDoblePpioRecursivo(lista->anterior, nuevo);
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}


/**************************************************************************************/


/**
 * \brief BUSCA EL ULTIMO NODO DE LA LISTA DOBLE
 * \param PUNTERO NODO
 * \return ULTIMO NODO
 */

stNodoDoble * buscaUltimoNodoDoble(stNodoDoble * lista) {
    stNodoDoble * seg = lista;
    while(seg->siguiente) {
        seg = seg->siguiente;
    }
    return seg;
}

/**
 * \brief AGREGA NODO DESDE EL FINAL DE LA LISTA DOBLE (PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDobleFinal(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodoDoble * ultimo = buscaUltimoNodoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

/**
 * \brief AGREGA NODO DESDE EL FINAL DE LA LISTA DOBLE (PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param PUNTERO LISTA NUEVA
 * \return VOID
 */

void cargaListaDobleFinalPD(stNodoDoble ** lista, stNodoDoble * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        stNodoDoble * ultimo = buscaUltimoNodoDoble(*lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
}

/**
 * \brief AGREGA NODO DESDE EL FINAL DE LA LISTA DOBLE (RECURSIVO)
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDobleFinalRecursiva(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodoDoble * ultimo = buscaUltimoNodoDoble(lista);
        ultimo->siguiente = cargaListaDobleFinalRecursiva(ultimo->siguiente, nuevo);
        nuevo->anterior = ultimo;
    }
    return lista;
}


/**************************************************************************************/


/**
 * \brief AGREGA NODO ORDENADO POR APELLIDO A LA LISTA DOBLE (ITERATIVO - PUNTERO SIMPLE)
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDobleOrdenadoApellido(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(strcmp(lista->dato.apellido, nuevo->dato.apellido) > 0) {
                lista = cargaListaDoblePpio(lista, nuevo);
        } else {
            stNodoDoble * seg = lista->siguiente;
            while(seg && strcmp(nuevo->dato.apellido, seg->dato.apellido) > 0) {
                seg = seg->siguiente;
            }
            if(seg) {
                stNodoDoble * ante = seg->anterior;
                ante->siguiente = nuevo;
                nuevo->siguiente = seg;
                nuevo->anterior = ante;
                seg->anterior = nuevo;
            } else {
                lista = cargaListaDobleFinal(lista, nuevo);
            }
        }
    }
    return lista;
}

/**
 * \brief AGREGA NODO ORDENADO POR APELLIDO A LA LISTA DOBLE (ITERATIVO - PUNTERO DOBLE)
 * \param PUNTERO DOBLE LISTA
 * \param PUNTERO LISTA NUEVA
 * \return VOID
 */

void cargaListaDobleOrdenadoDniPD(stNodoDoble ** lista, stNodoDoble * nuevo) {
    if((*lista) == NULL) {
        (*lista) = nuevo;
    } else {
        if(atoi((*lista)->dato.dni) > atoi(nuevo->dato.dni)) {
            cargaListaDoblePpioPD(lista, nuevo);
        } else {
            stNodoDoble * seg = (*lista)->siguiente;
            while(seg && atoi(nuevo->dato.dni) > atoi(seg->dato.dni)) {
                seg = seg->siguiente;
            }
            if(seg) {
                stNodoDoble * ante = seg->anterior;
                ante->siguiente = nuevo;
                nuevo->anterior = ante;
                nuevo->siguiente = seg;
                seg->anterior = nuevo;
            } else {
                cargaListaDobleFinalPD(lista, nuevo);
            }
        }
    }
}

/**
 * \brief AGREGA NODO ORDENADO POR APELLIDO A LA LISTA DOBLE (RECURSIVO)
 * \param PUNTERO LISTA
 * \param PUNTERO LISTA NUEVA
 * \return LISTA
 */

stNodoDoble * cargaListaDobleOrdenadoEdadRecursivo(stNodoDoble * lista, stNodoDoble * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(lista->dato.edad > nuevo->dato.edad) {
            lista->anterior = nuevo;
            nuevo->siguiente = lista;
            lista = nuevo;
        } else {
            lista->siguiente = cargaListaDobleOrdenadoEdadRecursivo(lista->siguiente, nuevo);
        }
    }
    return lista;
}


/**************************************************************************************/


/**
 * \brief MUESTRA NODO DE LA LISTA DOBLE
 * \param PUNTERO NODO
 * \return VOID
 */

void muestraNodoDoble(stNodoDoble * nodo) {
    printf("\nNodo Anterior: %d   Nodo: %d   Nodo Siguiente: %d\n", nodo->anterior, nodo, nodo->siguiente);
    muestraUnRegistro(nodo->dato);
}

/**
 * \brief MUESTRA LISTA DOBLE
 * \param PUNTERO LISTA
 * \return VOID
 */

void muestraListaDoble(stNodoDoble * lista) {
    stNodoDoble * seg = lista;
    while(seg) {
        muestraNodoDoble(seg);
        seg = seg->siguiente;
    }
}

/**
 * \brief MUESTRA LISTA DOBLE RECURSIVA
 * \param PUNTERO LISTA
 * \return VOID
 */

void muestraListaDobleRecusiva(stNodoDoble * lista) {
    if(lista) {
        muestraNodoDoble(lista);
        muestraListaDobleRecusiva(lista->siguiente);
    }
}

/**
 * \brief MUESTRA PRIMER REGISTRO DE LA LISTA DOBLE
 * \param PUNTERO NODO
 * \return REGISTRO
 */

stRegistro muestraPrimerNodoDoble(stNodoDoble * lista) {
    stRegistro r;
    if(lista) {
        r = lista->dato;
    }
    return r;
}


/***************************************************************************************/


/**
 * \brief ELIMINA NODO DOBLE DE LA LISTA (ITERATIVO - PUNTERO SIMPLE)
 * \param PUNTERO NODO
 * \param APELLIDO
 * \param NOMBRE
 * \return LISTA
 */

stNodoDoble * eliminaNodoDoble(stNodoDoble * lista, char apellido[20], char nombre[20]) {
    if(lista) {
        if(strcmp(nombre, lista->dato.nombre) == 0 && strcmp(apellido, lista->dato.apellido) == 0) {
            stNodoDoble * aux = lista;
            lista = lista->siguiente;
            if(lista) {
                lista->anterior = NULL;
            }
            free(aux);
        } else {
            stNodoDoble * seg = lista->siguiente;
            while(seg && strcmp(nombre, seg->dato.nombre) != 0 && strcmp(apellido, seg->dato.apellido) != 0) {
                seg = seg->siguiente;
            }
            if(seg) {
                stNodoDoble * ante = seg->anterior;
                stNodoDoble * prox = seg->siguiente;
                ante->siguiente = seg->siguiente;
                if(prox) {
                    prox->anterior = ante;
                }
                free(seg);
            }
        }
    }
    return lista;
}

/**
 * \brief ELIMINA NODO DOBLE DE LA LISTA (ITERATIVO - PUNTERO DOBLE)
 * \param PUNTERO DOBLE NODO
 * \param APELLIDO                  (NO ANDA)
 * \param NOMBRE
 * \return VOID
 */

void eliminaNodoDoblePD(stNodoDoble ** lista, char apellido[], char nombre[]){
    if(*lista){
        if(strcmp((*lista)->dato.apellido, apellido) == 0 && strcmp((*lista)->dato.nombre, nombre) == 0){
            stNodoDoble * aux = (*lista);
            (*lista) = (*lista)->siguiente;
            if(*lista){
                (*lista)->anterior = NULL;
            }
            free(aux);
        } else {
            stNodoDoble * seg = (*lista)->siguiente;
            while(seg && strcmp(seg->dato.apellido, apellido) != 0 && strcmp(seg->dato.nombre, nombre) != 0){
                seg = seg->siguiente;
            }
            if(seg){
                stNodoDoble * ante = seg->anterior;
                stNodoDoble * prox = seg->siguiente;
                ante->siguiente = seg->siguiente;
                if(prox){
                    prox->anterior = ante;
                }
                free(seg);
            }
        }
    }
}

/**
 * \brief ELIMINA NODO DOBLE DE LA LISTA (RECURSIVO)
 * \param PUNTERO NODO
 * \param APELLIDO
 * \param NOMBRE
 * \return LISTA
 */

stNodoDoble * eliminaNodoDobleRecursivo(stNodoDoble * lista, char apellido[], char nombre[]) {
    if(lista){
        if(strcmp(lista->dato.apellido, apellido) == 0 && strcmp(lista->dato.nombre, nombre) == 0){
            stNodoDoble * aux = lista;
            lista = lista->siguiente;
            if(lista){
                lista->anterior = NULL;
            }
            free(aux);
        } else {
            lista->siguiente = eliminaNodoDobleRecursivo(lista->siguiente, apellido, nombre);
        }
    }
    return lista;
}

/**
 * \brief ELIMINA PRIMER NODO DOBLE DE LA LISTA.
 * \param PUNTERO NODO
 * \return LISTA
 */

stNodoDoble * eliminaPrimerNodoDoble(stNodoDoble * lista) {
    stNodoDoble * aux = lista;
    lista = lista->siguiente;
    if(lista) {
        lista->anterior = NULL;
    }
    free(aux);
    return lista;
}



