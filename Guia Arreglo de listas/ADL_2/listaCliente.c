#include "listaCliente.h"

stNodo * initListaCliente() {
    return NULL;
}

stNodo * crearNodoCliente(stPersona dato) {
    stNodo * nuevo = (stNodo *) malloc(sizeof(stNodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

stNodo * agregarListaClientePpio(stNodo * lista, stNodo * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

stNodo * buscaUltimoNodo(stNodo * lista) {
    stNodo * seg = lista;
    while(seg->siguiente) {
        seg = seg->siguiente;
    }
    return seg;
}

stNodo * agregarListaClienteFinal(stNodo * lista, stNodo * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodo * ultimo = buscaUltimoNodo(lista);
        ultimo->siguiente = lista;
    }
    return lista;
}

stNodo * agregarListaClienteOrdenado(stNodo * lista, stNodo * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(strcmp(lista->dato.nombre, nuevo->dato.nombre) > 0) {
            lista = agregarListaClientePpio(lista, nuevo);
        } else {
            stNodo * seg = lista->siguiente;
            stNodo * ante = lista;
            while(seg && strcmp(nuevo->dato.nombre, seg->dato.nombre) > 0) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;
        }
    }
    return lista;
}



void muestraNodoCliente(stNodo * nodo) {
    printf("\n\t Nodo: %p   Nodo Siguiente: %p", nodo, nodo->siguiente);
    muestraPersona(nodo->dato);
}

void muestraListaCliente(stNodo * lista) {
    stNodo * seg = lista;
    while(seg) {
        muestraNodoCliente(seg);
        seg = seg->siguiente;
    }
}


stNodo * buscaListaCliente_Nombre(stNodo * lista, char nombre[20]) {
    stNodo * seg = lista;
    while(seg && strcmp(seg->dato.nombre, nombre) != 0) {
        seg = seg->siguiente;
    }
    return seg;
}

stNodo * borraNodoCliente_Nombre(stNodo * lista, char nombre[20]) {
    if(lista) {
        if(strcmp(lista->dato.nombre, nombre) == 0) {
            stNodo * aux = lista;
            lista = lista->siguiente;
            free(aux);
        } else {
            stNodo * seg = lista->siguiente;
            stNodo * ante = lista;
            while(seg && strcmp(seg->dato.nombre, nombre) != 0) {
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg) {
                ante->siguiente = seg->siguiente;
                free(seg);
            }
        }
    }
    return lista;
}

stNodo * borrarPrimerNodoCliente(stNodo * lista) {
    if(lista) {
        stNodo * aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}

stNodo * borrarUltimoNodoCliente(stNodo * lista) {
    if(lista) {
        stNodo * seg = lista->siguiente;
        stNodo * ante = lista;
        while(seg->siguiente) {
            ante = seg;
            seg = seg->siguiente;
        }
        if(seg) {
            ante->siguiente = seg->siguiente;
            free(seg);
        }
    }
    return lista;
}

stNodo * borrarListaClientesCompleta(stNodo * lista) {
    stNodo * prox;
    stNodo * seg = lista;
    while(seg) {
        prox = seg->siguiente;
        free(seg);
        seg = prox;
    }
    return seg;
}
