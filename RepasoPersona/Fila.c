#include "Fila.h"

/**
 * \brief INICIALIZA LA FILA
 * \param FILA
 * \return VOID
 */

void initFila(stFila * f) {
    f->inicio = initListaDoble();
    f->fin = initListaDoble();
}

/**
 * \brief TOPE DE LA FILA
 * \param FILA
 * \return REGISTRO (1RO)
 */

stRegistro topeFila(stFila * f) {
    stRegistro r;
    if(f->inicio) {
        r = muestraPrimerNodoDoble(f->inicio);
    }
    return r;
}

/**
 * \brief MUESTRA QUE LA FILA ESTA O NO VACIA
 * \param FILA
 * \return 1 / 0 (NO ESTA VACIA / SI ESTA VACIA)
 */

int filaVacia(stFila * f) {
    int rta = 0;
    if(!f->inicio) {
        rta = 1;
    }
    return rta;
}

/**
 * \brief AGREGA EL ELEMENTO A LA FILA
 * \param FILA
 * \param REGISTRO NUEVO
 * \return VOID
 */

void apilarFila(stFila * f, stRegistro r) {
    stNodoDoble * nuevo = crearNodoDoble(r);
    f->inicio = cargaListaDobleFinal(f->inicio, nuevo);
    if(!f->inicio) {
        f->inicio = f->fin;
    }
    f->fin = nuevo;
}

/**
 * \brief DESAPILA LA FILA
 * \param FILA
 * \return REGISTRO (1RO)
 */

stRegistro desapilarFila(stFila * f) {
    stRegistro r;
    if(f->inicio) {
        r = muestraPrimerNodoDoble(f->inicio);
        f->inicio = eliminaPrimerNodoDoble(f->inicio);
        if(!f->inicio) {
            f->fin = initListaDoble();
        }
    }
    return r;
}

/**
 * \brief MUESTRA LA FILA
 * \param FILA
 * \return VOID
 */

void muestraFila(stFila * f) {
    muestraListaDoble(f->inicio);
}
