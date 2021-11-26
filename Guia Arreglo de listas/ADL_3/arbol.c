#include "arbol.h"

//******************************* INICIO EL ARBOL.

stNodoArbol * inicTree(){
    return NULL;
}

//************************************************** CREO EL NODO ARBOL DE PERSONA.

stNodoArbol * crearNodoTree(stAnimal datos){
    stNodoArbol * nuevo = (stNodoArbol*) malloc(sizeof(stNodoArbol));
    nuevo->dato = datos;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    return nuevo;
}

//******************************************************* INGRESAR NODOS NUEVOS ORDENADOS POR LEGAJO.

stNodoArbol * insertarArbol (stNodoArbol * arbol, stNodoArbol * nuevo){
    if(!arbol){
        arbol = nuevo;
    } else {
        if(arbol->dato.cantidad > nuevo->dato.cantidad){
            arbol->der = insertarArbol(arbol->der, nuevo);
        } else {
            arbol->izq = insertarArbol(arbol->izq, nuevo);
        }
    }
    return arbol;
}

//************************************************************************** MUESTRA NODOS DEL ARBOL.

void mostrarUnAnimal(stAnimal a){
    char habitat[10];
    getHabitatChar(a.habitat,habitat);
    printf("\nAnimal..............: %s",a.animal);
    printf("\nCantidad............: %d",a.cantidad);
    printf("\nHabitat.............: %d - %s\n",a.habitat,habitat);
    replicante(205,50);
}


void muestraArbol(stNodoArbol * arbol){
    mostrarUnAnimal(arbol->dato);
}

//************************************************************ MUESTRA PRE ORDEN (RAIZ - IZQUIERDA - DERECHA)

void preOrder(stNodoArbol * arbol){
    if(arbol){
        mostrarUnAnimal(arbol->dato);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

//*************************************************** MUESTRA IN ORDER (IZQUIERDA - RAIZ - DERECHA)

void inOrder(stNodoArbol * arbol){
    if(arbol){
        inOrder(arbol->izq);
        mostrarUnAnimal(arbol->dato);
        inOrder(arbol->der);
    }
}

//********************************************* MUESTRA POST ORDER (IZQUIERDA - DERECHA - RAIZ)

void postOrder(stNodoArbol * arbol){
    if(arbol){
        postOrder(arbol->izq);
        postOrder(arbol->der);
        mostrarUnAnimal(arbol->dato);
    }
}

//************************************************************************** BUSCA NODO POR LEGAJO.

stNodoArbol * buscarNombreAnimal(stNodoArbol * arbol, char nombre[20]){
    stNodoArbol * rta;
    if(arbol){
        if(strcmp(arbol->dato.animal, nombre)==0){
            rta = arbol;
        } else {
            rta = buscarNombreAnimal(arbol->izq, nombre);
            if(!rta){
                rta = buscarNombreAnimal(arbol->der, nombre);
            }
        }
    }
    return rta;
}

//*********************************************************** ALTURA DEL ARBOL.

int mayorAltura(int izquierdo, int derecho){
    int rta = 0;
    if(izquierdo > derecho){
        rta = izquierdo;
    } else {
        rta = derecho;
    }
    return rta;
}


int alturaDelArbol(stNodoArbol * arbol){
    int resp;
    if(!arbol){
        resp = 0;
    } else {
        if(esHoja(arbol)){
            resp = 1;
        } else {
            resp = 1 + mayorAltura(alturaDelArbol(arbol->izq), alturaDelArbol(arbol->der));
        }
    }
    return resp;
}

//***************************************************************** CALCULA CANTIDAD DE NODOS DEL ARBOL.

int cuentaCantidadNodosArbol(stNodoArbol * arbol){
    int rta;
    if(!arbol){
        rta = 0;
    } else {
        rta = 1 + cuentaCantidadNodosArbol(arbol->izq) + cuentaCantidadNodosArbol(arbol->der);
    }
    return rta;
}

int cuentaCantidadAnimalesArbol(stNodoArbol * arbol){
    return (arbol)?arbol->dato.cantidad + cuentaCantidadAnimalesArbol(arbol->izq) + cuentaCantidadAnimalesArbol(arbol->der):0;
}

//************************************************* DETERMINA SI ES O NO HOJA EN EL ARBOL DE PERSONAS.

int esHoja(stNodoArbol * arbol){
    int rta = 0;
    if(arbol){
        if((!arbol->izq)&&(!arbol->der)){
            rta = 1;
        }
    }
    return rta;
}

//*********************************************** CUENTA LA CANTIDAD DE HOJAS DEL ARBOL DE PERSONAS.

int cuentaHojas(stNodoArbol * arbol){
    int rta;
    if(!arbol){
        rta = 0;
    } else {
        if(esHoja(arbol)){
            rta = 1;
        } else {
            rta = cuentaHojas(arbol->izq) + cuentaHojas(arbol->der);
        }
    }
    return rta;
}

