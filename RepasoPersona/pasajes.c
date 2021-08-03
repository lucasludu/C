#include "pasajes.h"

/*************************************************************************************************************************************
 *
 *                      ARCHIVO
 *
 *******************************************************/

/**
 * \brief PASO EL ARCHIVO DE REGISTROS AL ARREGLO
 * \param ARCHIVO
 * \param REGISTRO
 * \param VALIDOS
 * \param DIMENCION
 * \return VALIDOS
 */

int archivo_Arreglo(char archivo[], stRegistro r[], int v, int dim) {
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while((v < dim) && fread(&r[v], sizeof(stRegistro), 1, pArch) > 0) {
            v++;
        }
        fclose(pArch);
    }
    return v;
}

/**
 * \brief PASO EL ARCHIVO DE REGISTROS A LA LISTA SIMPLE
 * \param ARCHIVO
 * \param LISTA
 * \return LISTA
 */

stNodoSimple * archivo_ListaSimple(char archivo[], stNodoSimple * lista) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            lista = cargaListaSimpleOrdenadaEdadRecursivo(lista, crearNodoSimple(r));
        }
        fclose(pArch);
    }
    return lista;
}

/**
 * \brief PASO EL ARCHIVO DE REGISTROS A LA LISTA SIMPLE (PUNTERO DOBLE)
 * \param ARCHIVO
 * \param PUNTERO DOBLE LISTA
 * \return VOID
 */

void archivo_ListaSimplePD(char archivo[], stNodoSimple ** lista) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            cargaListaSimplePpioPD(lista, crearNodoSimple(r));
        }
        fclose(pArch);
    }
}

/**
 * \brief PASO EL ARCHIVO DE REGISTROS A LA LISTA DOBLE (PUNTERO SIMPLE)
 * \param ARCHIVO
 * \param PUNTERO LISTA
 * \return LISTA
 */

stNodoDoble * archivo_ListaDoble(char archivo[], stNodoDoble * lista) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            lista = cargaListaDoblePpioRecursivo(lista, crearNodoDoble(r));
        }
        fclose(pArch);
    }
    return lista;
}

/**
 * \brief PASO EL ARCHIVO DE REGISTROS A LA LISTA DOBLE (PUNTERO DOBLE)
 * \param ARCHIVO
 * \param PUNTERO DOBLE LISTA
 * \return VOID
 */

void archivo_ListaDoblePD(char archivo[], stNodoDoble ** lista) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            (*lista) = cargaListaDobleOrdenadoEdadRecursivo((*lista), crearNodoDoble(r));
        }
        fclose(pArch);
    }
}

/**
 * \brief PASO DE ARCHIVO A PILA
 * \param ARCHIVO
 * \param PILA
 * \return VOID
 */

void archivo_Pila(char archivo[], stPila * pila) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            apilarPila(pila, r);
        }
        fclose(pArch);
    }
}


/**
 * \brief PASO DE ARCHIVO A FILA
 * \param ARCHIVO
 * \param FILA
 * \return VOID
 */

void archivo_Fila(char archivo[], stFila * f) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            apilarFila(f, r);
        }
        fclose(pArch);
    }
}

/**
 * \brief PASO DE ARCHIVO AL ARBOL
 * \param ARCHIVO
 * \param ARBOL
 * \return VOID
 */

stArbol * archivo_Arbol(char archivo[], stArbol * arbol) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            arbol = agregaNodoArbol(arbol, crearNodoArbol(r));
        }
        fclose(pArch);
    }
    return arbol;
}

/*************************************************************************************************************************************
 *
 *                      LISTA SIMPLE
 *
 *******************************************************/

/**
 * \brief PASO LA LISTA SIMPLE A LOS ARCHIVOS MAYORES Y MENORES
 * \param PUNTERO LISTA
 * \return LISTA
 */

stNodoSimple * listaSimple_Archivo(stNodoSimple * lista) {
    stRegistro r;
    FILE * pArch = fopen(arRegistro, "ab");
    FILE * pArchMayor = fopen(arMayor, "ab");
    FILE * pArchMenor = fopen(arMenor, "ab");
    stNodoSimple * seg = lista;
    if(pArch && pArchMayor && pArchMenor) {
        while(seg) {
            if(seg->dato.edad > 30) {
                r = seg->dato;
                fwrite(&r, sizeof(stRegistro), 1, pArchMayor);
                seg = seg->siguiente;
            } else {
                r = seg->dato;
                fwrite(&r, sizeof(stRegistro), 1, pArchMenor);
                seg = seg->siguiente;
            }
        }
        fclose(pArchMayor);
        fclose(pArchMenor);
        fclose(pArch);
    }
    return lista;
}

/**
 * \brief PASO DE LISTA SIMPLE A LISTA DOBLE
 * \param PUNTERO LISTA SIMPLE
 * \param PUNTERO LISTA DOBLE
 * \return LISTA DOBLE
 */

stNodoDoble * listaSimple_listaDoble(stNodoSimple * lista, stNodoDoble * lista2) {
    stNodoSimple * seg = lista;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        lista2 = cargaListaDoblePpio(lista2, crearNodoDoble(r));
        seg = seg->siguiente;
    }
    return lista2;
}

/**
 * \brief PASO DE LISTA SIMPLE A PILA
 * \param PUNTERO LISTA SIMPLE
 * \param PILA
 * \return VOID
 */

void listaSimple_Pila(stNodoSimple * lista, stPila * pila) {
    stNodoSimple * seg = lista;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        apilarPila(pila, r);
        seg = seg->siguiente;
    }
}

/**
 * \brief PASO DE LISTA SIMPLE A FILA
 * \param PUNTERO LISTA SIMPLE
 * \param FILA
 * \return VOID
 */

void listaSimple_Fila(stNodoSimple * lista, stFila * f) {
    stNodoSimple * seg = lista;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        apilarFila(f, r);
        seg = seg->siguiente;
    }
}

/**
 * \brief PASO DE LISTA SIMPLE AL ARBOL
 * \param PUNTERO LISTA SIMPLE
 * \param NODO ARBOL
 * \return ARBOL
 */

stArbol * listaSimple_Arbol(stNodoSimple * lista, stArbol * arbol) {
    stNodoSimple * seg = lista;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        arbol = agregaNodoArbol(arbol, crearNodoArbol(r));
        seg = seg->siguiente;
    }
    return arbol;
}


/*************************************************************************************************************************************
 *
 *                      LISTA DOBLE
 *
 *******************************************************/

/**
 * \brief PASA LA LISTA DOBLE AL ARCHIVO DE EDADES PARES
 * \param PUNTERO LISTA DOBLE
 * \return LISTA DOBLE
 */

stNodoDoble * listaDoble_Archivo(stNodoDoble * lista2) {
    stRegistro r;
    stNodoDoble * seg = lista2;
    FILE * pArch = fopen(arRegistro, "ab");
    FILE * pArch2 = fopen(arRegistro2, "ab");
    if(pArch && pArch2) {
        while(seg) {
            if(seg->dato.edad % 2 == 0) {
                r = seg->dato;
                fwrite(&r, sizeof(stRegistro), 1, pArch2);
                seg = seg->siguiente;
            }
        }
        fclose(pArch2);
        fclose(pArch);
    }
    return lista2;
}

/**
 * \brief PASA LA LISTA DOBLE A LA LISTA SIMPLE
 * \param PUNTERO LISTA DOBLE
 * \param PUNTERO LISTA SIMPLE
 * \return LISTA
 */

stNodoSimple * listaDoble_listaSimple(stNodoDoble * lista2, stNodoDoble * lista) {
    stNodoDoble * seg = lista2;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        lista = cargaListaSimpleFinal(lista, crearNodoSimple(r));
        seg = seg->siguiente;
    }
    return lista;
}

/**
 * \brief PASA LA LISTA DOBLE A LA PILA
 * \param PUNTERO LISTA DOBLE
 * \param PILA
 * \return VOID
 */

void listaDoble_Pila(stNodoDoble * lista2, stPila * p) {
    stNodoDoble * seg = lista2;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        apilarPila(p, r);
        seg = seg->siguiente;
    }
}

/**
 * \brief PASA LA LISTA DOBLE A LA FILA
 * \param PUNTERO LISTA DOBLE
 * \param FILA
 * \return VOID
 */

void listaDoble_Fila(stNodoDoble * lista2, stFila * f) {
    stNodoDoble * seg = lista2;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        apilarFila(f, r);
        seg = seg->siguiente;
    }
}

/**
 * \brief PASA LA LISTA DOBLE AL ARBOL
 * \param PUNTERO LISTA DOBLE
 * \param ARBOL
 * \return VOID
 */

stArbol * listaDoble_Arbol(stNodoDoble * lista2, stArbol * arbol) {
    stNodoDoble * seg = lista2;
    stRegistro r;
    while(seg) {
        r = seg->dato;
        arbol = agregaNodoArbol(arbol, crearNodoArbol(r));
        seg = seg->siguiente;
    }
    return arbol;
}

/*************************************************************************************************************************************
 *
 *                      PILA
 *
 *******************************************************/

/**
 * \brief PASA LA PILA AL ARCHIVO
 * \param PILA
 * \param ARCHIVO
 * \return VOID
 */

void pila_Archivo(stPila p, char archivo[]) {
    stRegistro r;
    stPila aux;
    initPila(&aux);
    FILE * pArch = fopen(arRegistro, "ab");
    FILE * pArch2 = fopen(arRegistro2, "ab");
    if(pArch && pArch2) {
        while(!pilaVacia(&p)) {
            r = topePila(&p);
            fwrite(&r, sizeof(stRegistro), 1, pArch2);
            apilarPila(&aux, desapilarPila(&p));
        }
        while(!pilaVacia(&aux)) {
            apilarPila(&p, desapilarPila(&aux));
        }
        fclose(pArch);
        fclose(pArch2);
    }
}

/**
 * \brief PASA LA PILA A LA LISTA SIMPLE
 * \param PILA
 * \param LISTA SIMPLE
 * \return LISTA
 */

stNodoSimple * pila_ListaSimple(stPila p, stNodoSimple * lista) {
    stPila aux;
    initPila(&aux);
    stRegistro r;
    while(!pilaVacia(&p)) {
        r = topePila(&p);
        lista = cargaListaSimplePpio(lista, crearNodoSimple(r));
        apilarPila(&aux, desapilarPila(&p));
    }
    while(!pilaVacia(&aux)) {
        apilarPila(&p, desapilarPila(&aux));
    }
    return lista;
}

/**
 * \brief PASA LA PILA A LA LISTA DOBLE
 * \param PILA
 * \param LISTA DOBLE
 * \return LISTA
 */

stNodoDoble * pila_ListaDoble(stPila p, stNodoDoble * lista2) {
    stPila aux;
    initPila(&aux);
    stRegistro r;
    while(!pilaVacia(&p)) {
        r = topePila(&p);
        lista2 = cargaListaDoblePpio(lista2, crearNodoDoble(r));
        apilarPila(&aux, desapilarPila(&p));
    }
    while(!pilaVacia(&aux)) {
        apilarPila(&p, desapilarPila(&aux));
    }
    return lista2;
}

/**
 * \brief PASA LA PILA A LA FILA
 * \param PILA
 * \param FILA
 * \return VOID
 */

void pila_Fila(stPila p, stFila * f) {
    stPila aux;
    initPila(&aux);
    stRegistro r;
    while(!pilaVacia(&p)) {
        r = topePila(&p);
        apilarFila(f, r);
        apilarPila(&aux, desapilarPila(&p));
    }
    while(!pilaVacia(&aux)) {
        apilarPila(&p, desapilarPila(&aux));
    }
}

/**
 * \brief PASA LA PILA AL ARBOL
 * \param PILA
 * \param ARBOL
 * \return ARBOL
 */

stArbol * pila_Arbol(stPila p, stArbol * arbol) {
    stPila aux;
    initPila(&aux);
    stRegistro r;
    while(!pilaVacia(&p)) {
        r = topePila(&p);
        arbol = agregaNodoArbol(arbol, crearNodoArbol(r));
        apilarPila(&aux, desapilarPila(&p));
    }
    while(!pilaVacia(&aux)) {
        apilarPila(&p, desapilarPila(&aux));
    }
    return arbol;
}

/*************************************************************************************************************************************
 *
 *                      FILA
 *
 *******************************************************/

/**
 * \brief PASA LA FILA AL ARCHIVO
 * \param FILA
 * \param ARCHIVO
 * \return VOID
 */

void fila_Archivo(stFila f) {
    stRegistro r;
    stFila aux;
    initFila(&aux);
    FILE * pArch = fopen(arRegistro, "ab");
    FILE * pArch2 = fopen(arRegistro2, "ab");
    if(pArch && pArch2) {
        while(!filaVacia(&f)) {
            r = topeFila(&f);
            fwrite(&r, sizeof(stRegistro), 1, pArch2);
            apilarFila(&aux, desapilarFila(&f));
        }
        while(!filaVacia(&aux)) {
            apilarFila(&f, desapilarFila(&aux));
        }
        fclose(pArch);
        fclose(pArch2);
    }
}

/**
 * \brief PASA LA FILA A LA LISTA SIMPLE
 * \param FILA
 * \param LISTA SIMPLE
 * \return LISTA
 */

stNodoSimple * fila_ListaSimple(stFila f, stNodoSimple * lista) {
    stRegistro r;
    stFila aux;
    initFila(&aux);
    while(!filaVacia(&f)) {
        r = topeFila(&f);
        lista = cargaListaSimpleFinal(lista, crearNodoSimple(r));
        apilarFila(&aux, desapilarFila(&f));
    }
    while(!filaVacia(&aux)) {
        apilarFila(&f, desapilarFila(&aux));
    }
    return lista;
}

/**
 * \brief PASA LA FILA A LA LISTA DOBLE
 * \param FILA
 * \param LISTA DOBLE
 * \return LISTA
 */

stNodoDoble * fila_ListaDoble(stFila f, stNodoDoble * lista) {
    stRegistro r;
    stFila aux;
    initFila(&aux);
    while(!filaVacia(&f)) {
        r = topeFila(&f);
        lista = cargaListaDobleFinal(lista, crearNodoDoble(r));
        apilarFila(&aux, desapilarFila(&f));
    }
    while(!filaVacia(&aux)) {
        apilarFila(&f, desapilarFila(&aux));
    }
    return lista;
}

/**
 * \brief PASA LA FILA A LA PILA
 * \param FILA
 * \param PILA
 * \return VOID
 */

void fila_Pila(stFila f, stPila * p) {
    stRegistro r;
    stFila aux;
    initFila(&aux);
    while(!filaVacia(&f)) {
        r = topeFila(&f);
        apilarPila(p, r);
        apilarFila(&aux, desapilarFila(&f));
    }
    while(!filaVacia(&aux)) {
        apilarFila(&f, desapilarFila(&aux));
    }
}

/**
 * \brief PASA LA FILA AL ARBOL
 * \param FILA
 * \param ARBOL
 * \return VOID
 */

stArbol * fila_Arbol(stFila f, stArbol * arbol) {
    stRegistro r;
    stFila aux;
    initFila(&aux);
    while(!filaVacia(&f)) {
        r = topeFila(&f);
        arbol = agregaNodoArbol(arbol, crearNodoArbol(r));
        apilarFila(&aux, desapilarFila(&f));
    }
    while(!filaVacia(&aux)) {
        apilarFila(&f, desapilarFila(&aux));
    }
    return arbol;
}

/*************************************************************************************************************************************
 *
 *                      ARBOL
 *
 *******************************************************/

/**
 * \brief PASA DEL ARBOL AL ARCHIVO
 * \param ARBOL
 * \param ARCHIVO
 * \return VOID
 */

 // NO ANDA!
void arbol_Archivo(stArbol * arbol) {
    stRegistro r;
    stArbol * seg = arbol;
    FILE * pArch = fopen(arRegistro, "ab");
    FILE * pArch2 = fopen(arRegistro2, "ab");
    if(pArch && pArch2) {
        while(seg) {
            r = seg->dato;
            arbol_Archivo(seg->izquierda);
            fwrite(&r, sizeof(stRegistro), 1, pArch2);
            arbol_Archivo(seg->derecha);
        }
        fclose(pArch);
        fclose(pArch2);
    }
}

/**
 * \brief PASA DEL ARBOL A LA LISTA SIMPLE
 * \param ARBOL
 * \param LISTA
 * \return LISTA
 */

stNodoSimple * arbol_ListaSimple(stArbol * arbol, stNodoSimple * lista) {
    stArbol * seg = arbol;
    if(seg) {
        lista = arbol_ListaSimple(seg->izquierda, lista);
        stNodoSimple * aux = crearNodoSimple(seg->dato);
        lista = cargaListaSimplePpio(lista, aux);
        lista = arbol_ListaSimple(seg->derecha, lista);
    }
    return lista;
}

/**
 * \brief PASA DEL ARBOL A LA LISTA DOBLE
 * \param ARBOL
 * \param LISTA
 * \return LISTA
 */

stNodoDoble * arbol_ListaDoble(stArbol * arbol, stNodoDoble * lista2) {
    stArbol * seg = arbol;
    if(seg) {
        lista2 = arbol_ListaDoble(seg->izquierda, lista2);
        lista2 = cargaListaDobleFinal(lista2, crearNodoDoble(seg->dato));
        lista2 = arbol_ListaDoble(seg->derecha, lista2);
    }
    return lista2;
}

/**
 * \brief PASA DEL ARBOL A LA PILA
 * \param ARBOL
 * \param PILA
 * \return VOID
 */

void arbol_Pila(stArbol * arbol, stPila * p) {
    stArbol * seg = arbol;
    if(seg) {
        arbol_Pila(seg->izquierda, p);
        apilarPila(p, seg->dato);
        arbol_Pila(seg->derecha, p);
    }
}

/**
 * \brief PASA DEL ARBOL A LA FILA
 * \param ARBOL
 * \param FILA
 * \return VOID
 */

void arbol_Fila(stArbol * arbol, stFila * f) {
    stArbol * seg = arbol;
    if(seg) {
        arbol_Fila(seg->izquierda, f);
        apilarFila(f, seg->dato);
        arbol_Fila(seg->derecha, f);
    }
}












