#include "lista.h"

stNodo * initLista() {
    return NULL;
}

stNodo * crearNodo(stNotaAlumnos dato) {
    stNodo * nuevo = (stNodo *) malloc(sizeof(stNodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

stNodo * agregarPpio(stNodo * lista, stNodo * nuevo) {
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

stNodo * agregarFinal(stNodo * lista, stNodo * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        stNodo * ultimo = buscaUltimoNodo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

stNodo * agregarOrdenado(stNodo * lista, stNodo * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        if(lista->dato.nota > nuevo->dato.nota) {
            lista = agregarPpio(lista, nuevo);
        } else {
            stNodo * seg = lista->siguiente;
            stNodo * ante = lista;
            while(seg && nuevo->dato.nota > seg->dato.nota) {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;
        }
    }
    return lista;
}




stNodo * buscarNodo(stNodo * lista, int nota) {
    stNodo * seg = lista;
    while(seg && seg->dato.nota != nota) {
        seg = seg->siguiente;
    }
    return seg;
}

stNodo * borrarNodoBuscado(stNodo * lista, int nota) {
    if(lista) {
        if(lista->dato.nota == nota) {
            stNodo * aux = lista;
            lista = lista->siguiente;
            free(aux);
        } else {
            stNodo * seg = lista->siguiente;
            stNodo * ante = lista;
            while(seg && seg->dato.nota != nota) {
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

stNodo * borrarListaCompleta(stNodo * lista) {
    stNodo * seg = lista;
    stNodo * prox;
    while(seg) {
        prox = seg->siguiente;
        free(seg);
        seg = prox;
    }
    return seg;
}

stNodo * borrarPrimerNodo(stNodo * lista) {
    stNodo * aux = lista;
    lista = lista->siguiente;
    free(aux);
    return lista;
}

stNodo * borrarUltimoNodo(stNodo * lista) {
    stNodo * seg = lista;
    stNodo * ante;
    while(seg->siguiente) {
        ante = seg;
        seg = seg->siguiente;
    }
    free(seg);
    ante->siguiente = NULL;
    return lista;
}



void muestraUnaNota(stNotaAlumnos nota) {
    printf("\n\t Legajo....: %d", nota.legajo);
    printf("\n\t Alumno....: %s", nota.apeNom);
    printf("\n\t Nota......: %d", nota.nota);
    printf("\n--------------------------------------------\n");
}

void muestraLista(stNodo * lista) {
    stNodo * seg = lista;
    while(seg) {
        muestraUnaNota(seg->dato);
        seg = seg->siguiente;
    }
}



int sumarNotasLista(stNodo * lista) {
    int suma = 0;
    stNodo * seg = lista;
    while(seg) {
        suma += seg->dato.nota;
        seg = seg->siguiente;
    }
    return suma;
}

int cuentaListaRegistros(stNodo * lista) {
    return (lista) ? 1+cuentaListaRegistros(lista->siguiente) : 0;
}

