#include "Pila.h"

/**
 * \brief INICIALIZA LA PILA
 * \param PILA
 * \return VOID
 */

void initPila(stPila * pila) {
    (*pila) = initListaSimple();
}

/**
 * \brief TOPE DE LA PILA
 * \param PILA
 * \return PRIMER REGISTRO DE LA PILA
 */

stRegistro topePila(stPila * pila) {
    return (*pila)->dato;
}

/**
 * \brief INDICA SI LA PILA ESTA O NO VACIA
 * \param PILA
 * \return DEVUELVE 1 SI ESTA LLENA Y 0 SI ESTA VACIA
 */

int pilaVacia(stPila * pila) {
    return ((*pila) == NULL) ? 1 : 0;
}

/**
 * \brief APILA LA PILA
 * \param PILA
 * \param REGISTRO
 * \return VOID
 */

void apilarPila(stPila * pila, stRegistro r) {
    (*pila) = cargaListaSimplePpio((*pila), crearNodoSimple(r));
}

/**
 * \brief DESAPILA LA PILA
 * \param PILA
 * \return REGISTRO
 */

stRegistro desapilarPila(stPila * pila) {
    stRegistro r = (*pila)->dato;
    (*pila) = borrarPrimerNodoSimple(*pila);
    return r;
}

/**
 * \brief MUESTRA LA PILA
 * \param PILA
 * \return VOID
 */

void muestraPila(stPila * pila) {
    printf("\n\t TOPE \n\n");
    muestraListaSimple(*pila);
    printf("\n\n\t BASE \n");
}


