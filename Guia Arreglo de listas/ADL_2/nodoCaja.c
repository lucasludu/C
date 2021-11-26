#include "nodoCaja.h"

stNodoCaja * inicListaCaja() {
    return NULL;
}

stNodoCaja * crearNodoCaja(stCaja dato) {
    stNodoCaja * nuevo = (stNodoCaja *) malloc(sizeof(stNodoCaja));
    nuevo->dato = dato;
    nuevo->listaCliente = initListaCliente();
    nuevo->siguiente = NULL;
    return nuevo;
}

stNodoCaja * agregarPpioCaja(stNodoCaja * lista, stNodoCaja * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

stNodoCaja * buscarCaja(stNodoCaja * lista, int nroCaja) {
    stNodoCaja * seg = lista;
    stNodoCaja * cajaEncontrada = NULL;
    int flag = 0;
    while(seg && flag == 0) {
        if(seg->dato.nroCaja == nroCaja) {
            cajaEncontrada = seg;
            flag = 1;
        }
        seg = seg->siguiente;
    }
    return cajaEncontrada;
}

stCaja ingresarCaja(int nroCaja) {
    stCaja caja;
    caja.nroCaja = nroCaja;
    printf("\n\t Ingresar medio de pago: ");
    fflush(stdin);
    gets(caja.medioPago);
    return caja;
}

stNodoCaja * alta(stNodoCaja * listaCaja, stNodo * nuevoCliente, int nroCaja) {
    stNodoCaja * cajaEncontrada = buscarCaja(listaCaja, nroCaja);
    if(!cajaEncontrada) {
        stCaja c = ingresarCaja(nroCaja);
        stNodoCaja * nuevaCaja = crearNodoCaja(c);
        listaCaja = agregarPpioCaja(listaCaja, nuevaCaja);
        listaCaja->listaCliente = agregarListaClienteFinal(listaCaja->listaCliente, nuevoCliente);
    } else {
        cajaEncontrada->listaCliente = agregarListaClienteFinal(listaCaja->listaCliente, nuevoCliente);
    }
    return listaCaja;
}

void muestraNodoCaja(stNodoCaja * caja) {
    printf("\n\t Nro de Caja......: %d", caja->dato.nroCaja);
    printf("\n\t Medio de Pago....: %s", caja->dato.medioPago);
}

void muestraListaCajaClientes(stNodoCaja * lista) {
    stNodoCaja * seg = lista;
    while(seg->siguiente) {
        muestraNodoCaja(seg);
        muestraListaCliente(seg->listaCliente);
        seg = seg->siguiente;
    }
}












