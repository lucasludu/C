#include "Arbol.h"

/**
 * \brief INICIALIZA EL ARBOL
 * \param SIN PARAMETROS
 * \return NULL
 */

stArbol * initArbol() {
    return NULL;
}

/**
 * \brief CREA NODO ARBOL
 * \param REGISTRO
 * \return NUEVO NODO
 */

stArbol * crearNodoArbol(stRegistro r) {
    stArbol * nuevo = (stArbol *) malloc(sizeof(stArbol));
    nuevo->derecha = NULL;
    nuevo->izquierda = NULL;
    nuevo->dato = r;
    return nuevo;
}

/**
 * \brief AGREGA NODO ARBOL
 * \param NODO ARBOL
 * \param NUEVO NODO ARBOL
 * \return NODO ARBOL
 */

stArbol * agregaNodoArbol(stArbol * arbol, stArbol * nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(strcmp(arbol->dato.apellido, nuevo->dato.apellido) > 0) {
            arbol->izquierda = agregaNodoArbol(arbol->izquierda, nuevo);
        } else {
            arbol->derecha = agregaNodoArbol(arbol->derecha, nuevo);
        }
    }
    return arbol;
}

/**
 * \brief MUESTRA ARBOL PRE ORDER
 * \param NODO ARBOL
 * \return VOID
 */

void muestraArbolPreOrder(stArbol * arbol) {
    if(arbol) {
        muestraUnRegistro(arbol->dato);
        muestraArbolPreOrder(arbol->izquierda);
        muestraArbolPreOrder(arbol->derecha);
    }
}

/**
 * \brief MUESTRA ARBOL IN ORDER
 * \param NODO ARBOL
 * \return VOID
 */

void muestraArbolInOrder(stArbol * arbol) {
    if(arbol) {
        muestraArbolInOrder(arbol->izquierda);
        muestraUnRegistro(arbol->dato);
        muestraArbolInOrder(arbol->derecha);
    }
}

/**
 * \brief MUESTRA ARBOL PRE ORDER
 * \param NODO ARBOL
 * \return VOID
 */

void muestraArbolPostOrder(stArbol * arbol) {
    if(arbol) {
        muestraArbolPostOrder(arbol->izquierda);
        muestraArbolPostOrder(arbol->derecha);
        muestraUnRegistro(arbol->dato);
    }
}

/**
 * \brief DETERMINA LA MAYOR ALTURA DEL ARBOL
 * \param CANTIDAD IZQ.
 * \param CANTIDAD DER.
 * \return RTA
 */

int mayorAlturaArbol(int izq, int der) {
    int rta = 0;
    if(izq > der) {
        rta = izq;
    } else {
        rta = der;
    }
    return rta;
}

/**
 * \brief DETERMINA SI ES O NO UNA HOJA DEL ARBOL
 * \param NODO ARBOL
 * \return RTA
 */

int esHoja(stArbol * arbol) {
    int rta = 0;
    if(arbol) {
        if(!arbol->izquierda && !arbol->derecha) {
            rta = 1;
        }
    }
    return rta;
}

/**
 * \brief CALCULA LA ALTURA DEL ARBOL
 * \param NODO ARBOL
 * \return RTA
 */

int alturaArbol(stArbol * arbol) {
    int rta;
    if(!arbol) {
        rta = 0;
    } else {
        if(esHoja(arbol)) {
            rta = 1;
        } else {
            rta = 1 + mayorAlturaArbol(alturaArbol(arbol->izquierda), alturaArbol(arbol->derecha));
        }
    }
    return rta;
}

/**
 * \brief NODO ARBOL QUE SE ENCUENTRA EN EL EXTREMO DERECHO
 * \param NODO ARBOL
 * \return NODO ARBOL
 */

stArbol * arbolMasDerecha(stArbol * arbol) {
    stArbol * seg = arbol;
    while(seg->derecha) {
        seg = seg->derecha;
    }
    return seg;
}

/**
 * \brief NODO ARBOL QUE SE ENCUENTRA EN EL EXTREMO IZQUIERDO
 * \param NODO ARBOL
 * \return NODO ARBOL
 */

stArbol * arbolMasIzquierdo(stArbol * arbol) {
    stArbol * seg = arbol;
    while(seg->izquierda) {
        seg = seg->izquierda;
    }
    return seg;
}

/**
 * \brief ELIMINA EL NODO ARBOL
 * \param NODO ARBOL
 * \param NOMBRE
 * \param APELLIDO
 * \return NODO ARBOL
 */

stArbol * eliminaNodoArbol(stArbol * arbol, char nombre[], char apellido[]) {
    stArbol * aux = arbol;
    if(aux) {
        if(strcmp(nombre, aux->dato.nombre) == 0 && strcmp(apellido, aux->dato.apellido) == 0) {
            if(aux->izquierda) {
                stArbol * masIzq = arbolMasDerecha(aux->izquierda);
                aux->dato = masIzq->dato;
                aux->izquierda = eliminaNodoArbol(aux->izquierda, nombre, apellido);
            } else if (aux->derecha) {
                stArbol * masDer = arbolMasIzquierdo(aux->derecha);
                aux->dato = masDer->dato;
                aux->derecha = eliminaNodoArbol(aux->derecha, nombre, apellido);
            } else if (esHoja(aux)) {
                free(aux);
            }
        } else {
            aux->izquierda = eliminaNodoArbol(aux->izquierda, nombre, apellido);
            if(!aux->izquierda) {
                aux->derecha = eliminaNodoArbol(aux->derecha, nombre, apellido);
            }
        }
    }
    return arbol;
}


/**
 * \brief CUENTA LA CANTIDAD DE NODOS DEL ARBOL
 * \param NODO ARBOL
 * \return RTA
 */

int cuentaTotalNodoArbol(stArbol * arbol) {
    int rta;
    if(!arbol) {
        rta = 0;
    } else {
        rta = 1 + cuentaTotalNodoArbol(arbol->izquierda) + cuentaTotalNodoArbol(arbol->derecha);
    }
    return rta;
}

/**
 * \brief CUENTA LA CANTIDAD DE HOJAS DEL ARBOL
 * \param NODO ARBOL
 * \return RTA
 */

int cuentaHojaArbol(stArbol * arbol) {
    int rta;
    if(!arbol) {
        rta = 0;
    } else {
        if(esHoja(arbol)) {
            rta = 1 + cuentaHojaArbol(arbol->izquierda) + cuentaHojaArbol(arbol->derecha);
        } else {
            rta = cuentaHojaArbol(arbol->izquierda) + cuentaHojaArbol(arbol->derecha);
        }
    }
    return rta;
}
