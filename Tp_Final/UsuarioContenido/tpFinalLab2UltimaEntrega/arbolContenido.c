#include "arbolContenido.h"


/**
 * \brief   INICIALIZA EL ARBOL
 * \param   SIN PARAMETROS
 * \return  NULL
 */

nodoArbolContenido * inicArbol() {
    return NULL;
}


/**
 * \brief   CREA NODO ARBOL
 * \param   CONTENIDO
 * \return  NODO ARBOL
 */

nodoArbolContenido * crearnodoArbolContenido(stContenido contenido) {
    nodoArbolContenido * aux = (nodoArbolContenido *) malloc(sizeof(nodoArbolContenido));
    aux->dato = contenido;
    aux->der=NULL;
    aux->izq=NULL;
    return aux;
}


/**
 * \brief   SE ROTA POR IZQUIERDA EL NODO DEL ARBOL
 * \param   NODO ARBOL
 * \return  ARBOL AUX
 */

nodoArbolContenido * rotarIzq(nodoArbolContenido * arbol) {
    nodoArbolContenido * aux = arbol->der;
    if(arbol->der) {
        arbol->der = aux->izq;
        aux->izq = arbol;
    }
    return aux;
}


/**
 * \brief   SE ROTA POR DERECHA EL NODO DEL ARBOL
 * \param   NODO ARBOL
 * \return  ARBOL AUX
 */

nodoArbolContenido * rotarDer(nodoArbolContenido * arbol) {
    nodoArbolContenido * aux;
    if(arbol->izq) {
        aux = arbol->izq;
        arbol->izq = aux->der;
        aux->der = arbol;
    }
    return aux;
}


/**
 * \brief   SE BALACEA EL ARBOL (SE USA LAS FUNCIONES DE ALTURA DEL ARBOL, ROTAR POR IZQUIERDA Y DERECHA)
 * \param   NODO ARBOL
 * \return  ARBOL
 */

nodoArbolContenido * balancearArbol(nodoArbolContenido * arbol) {
    if(arbol) {
        int alturaizq = alturaArbol(arbol->izq);
        int alturader = alturaArbol(arbol->der);
        if(fabs(alturaizq-alturader) > 1) {
            if(alturaizq > alturader) {
                arbol = rotarDer(arbol);
            } else {
                arbol = rotarIzq(arbol);
            }
            arbol = balancearArbol(arbol);
        }
    }
    return arbol;
}


/**
 * \brief   INSERTA NODO ARBOL EN LA LISTA
 * \param   ARBOL
 * \param   ARBOL NUEVO
 * \return  ARBOL
 */

nodoArbolContenido * insertarNodoArbol(nodoArbolContenido * arbol, nodoArbolContenido * nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(nuevo->dato.idContenido>arbol->dato.idContenido) arbol->der = insertarNodoArbol(arbol->der, nuevo);
        else arbol->izq = insertarNodoArbol(arbol->izq, nuevo);
    }
    return arbol;
}


/**
 * \brief   INSERTA EL NODO DEL ARBOL BALANCEADO
 * \param   NODO ARBOL
 * \param   NUEVO NODO ARBOL
 * \return  ARBOL
 */

nodoArbolContenido * insertarNodoArbolBalanceado(nodoArbolContenido * arbol, nodoArbolContenido * nuevo) {
    if(!arbol) {
        arbol = nuevo;
    } else {
        if(arbol->dato.idContenido < nuevo->dato.idContenido) {
            arbol->der = insertarNodoArbolBalanceado(arbol->der ,nuevo);
        } else {
            arbol->izq = insertarNodoArbolBalanceado(arbol->izq , nuevo);
        }
        arbol = balancearArbol(arbol);
    }
    return arbol;
}


/**
 * \brief   CARGA EL ARBOL DE CONTENIDOS
 * \param   SIN PARAMETROS
 * \return  VOID
 */

void cargaArbolContenido(nodoArbolContenido * arbol) {
    stContenido aux = cargaContenido();
    nodoArbolContenido * nuevo = crearnodoArbolContenido(aux);
    arbol = insertarNodoArbol(arbol,nuevo);

    printf("\nEl contenido se cargo correctamente.\n\n");
    system("pause");
}


/**
 * \brief   SE DA DE ALTA EL CONTENIDO Y SE LO GUARDA EN EL ARCHIVO
 * \param   SIN PARAMETROS
 * \return  VOID
 */

void altaContenido(nodoArbolContenido * arbol) {
    stContenido aux = cargaContenido();
    nodoArbolContenido * nuevo = crearnodoArbolContenido(aux);
    arbol = insertarNodoArbol(arbol,nuevo);
    arbolContenidoToArchivo(ARCHIVO_CONTENIDO,arbol);

    printf("\nEl contenido se guardo correctamente.\n\n");
    system("pause");
}


/**
 * \brief   MUESTRO EL ARBOL DE CONTENIDOS DEL ARBOL (PRE - IN - POST)
 * \param   NODO ARBOL DE CONTENIDOS
 * \param   OPCION
 * \return  VOID
 */

void MostrarArbol(nodoArbolContenido * arbol, int opcion) {
    switch(opcion) {
        case 1:
            MostrararbolPreorder(arbol);
            break;
        case 2:
            MostrarArbolInorder(arbol);
            break;
        case 3:
            MostrararbolPostorder(arbol);
            break;
    }
    getch();
}


/**
 * \brief   MUESTRA EL ARBOL POR (PRE - IN - POST) ORDER
 * \param   NODO ARBOL DE CONTENIDOS
 * \return  VOID
 */

void MostrararbolPreorder(nodoArbolContenido * arbol) {
    if(arbol) {
        printf("\n%d-%s", arbol->dato.idContenido, arbol->dato.titulo);
        MostrararbolPreorder(arbol->izq);
        MostrararbolPreorder(arbol->der);
    }
}

void MostrarArbolInorder(nodoArbolContenido * arbol) {
    if(arbol) {
        MostrarArbolInorder(arbol->izq);
        printf("\n%d-%s", arbol->dato.idContenido, arbol->dato.titulo);
        MostrarArbolInorder(arbol->der);
    }
}

void MostrararbolPostorder(nodoArbolContenido * arbol) {
    if(arbol) {
        MostrararbolPostorder(arbol->izq);
        MostrararbolPostorder(arbol->der);
        printf("\n%d-%s", arbol->dato.idContenido, arbol->dato.titulo);
    }
}


/**
 * \brief   BUSCO EL CONTIDO EN EL ARBOL POR ID
 * \param   NODO ARBOL
 * \param   ID CONTENIDO
 * \return  RTA ( 1 | 0 )
 */

nodoArbolContenido * buscarContenidoId(nodoArbolContenido * arbol, int idcontenido) {
    nodoArbolContenido * rta = NULL;
    if(arbol) {
        if(idcontenido == arbol->dato.idContenido) {
            rta = arbol;
        } else if(idcontenido > arbol->dato.idContenido) {
            rta = buscarContenidoId(arbol->der, idcontenido);
        } else {
            rta = buscarContenidoId(arbol->izq, idcontenido);
        }
    }
    return rta;
}


/**
 * \brief   BUSCAR EL CONTEIDO EN EL ARBOL POR TITULO
 * \param   NODO ARBOL
 * \param   TITULO
 * \return  RTA ( 1 | 0 )
 */

nodoArbolContenido * buscarContenidoTitulo(nodoArbolContenido * arbol, char titulo[]) {
    nodoArbolContenido * rta=NULL;
    if(arbol) {
        if(strcmp(titulo,arbol->dato.titulo) == 0) {
            rta = arbol;
        } else {
            rta = buscarContenidoTitulo(arbol->izq, titulo);
            if(!rta) rta = buscarContenidoTitulo(arbol->der, titulo);
        }
    }
    return rta;
}


/**
 * \brief   CUENTA LOS NODOS DEL ARBOL
 * \param   NODO ARBOL
 * \return  RTA
 */

int cuentaNodoArbol(nodoArbolContenido * arbol) {
    int rta = 0;
    if(arbol) rta = 1 + cuentaNodoArbol(arbol->izq) + cuentaNodoArbol(arbol->der);
    return rta;
}


/**
 * \brief   DETERMINA SI EL NODO DEL ARBOL ES O NO HOJA
 * \param   NODO ARBOL
 * \return  RTA
 */

int esHojaArbol(nodoArbolContenido * arbol) {
    return (!(arbol->der) && !(arbol->izq));
}


/**
 * \brief   CUENTA LAS HOJAS QUE SE ENCUENTRAN EN EL ARBOL
 * \param   NODO ARBOL
 * \return  RTA
 */

int cuentaHojasArbol(nodoArbolContenido * arbol) {
    int rta = 0;
    if(arbol) {
        if(esHojaArbol(arbol)) rta = 1 + cuentaHojasArbol(arbol->izq) + cuentaHojasArbol(arbol->der);
        else rta = cuentaHojasArbol(arbol->izq) + cuentaHojasArbol(arbol->der);
    }
    return rta;
}


/**
 * \brief   ALTURA DEL ARBOL
 * \param   NODO ARBOL
 * \return  RTA
 */

int alturaArbol(nodoArbolContenido * arbol) {
    int rta = 0;
    if(arbol) {
        int izq = alturaArbol(arbol->izq);
        int der = alturaArbol(arbol->der);
        if(izq > der) {
            rta = 1 + izq;
        } else {
            rta = 1 + der;
        }
    }
    return rta;
}


/**
 * \brief   ELIMINA EL CONTENIDO DEL ARBOL POR ID
 * \param   NODO ARBOL
 * \param   ID CONTENIDO
 * \return  RTA
 */

int eliminarcontenido(nodoArbolContenido * arbol, int idcontenido) {
    int rta = 0;
    if(arbol) {
        if(idcontenido == arbol->dato.idContenido) {
            arbol->dato.activo = 1;
            rta = 1;
        } else if(idcontenido > arbol->dato.idContenido) {
            rta = eliminarcontenido(arbol->der, idcontenido);
        } else {
            rta = eliminarcontenido(arbol->izq, idcontenido);
        }
    }
    return rta;
}


/**
 * \brief   NODO DEL EXTREMO IZQUIERDO DEL ARBOL, SE USA PRA LA FUNCION DE BORRAR NODO ARBOL
 * \param   NODO ARBOL
 * \return  ARBOL
 */

nodoArbolContenido * NMI(nodoArbolContenido * arbol) {
    nodoArbolContenido * rta = NULL;
    if(arbol) {
        if(arbol->izq) rta = NMI(arbol->izq);
        else rta = arbol;
    }
    return rta;
}


/**
 * \brief   NODO DEL EXTREMO DERECHO DEL ARBOL, SE USA PARA LA FUNCION DE BORRAR NODO ARBOL
 * \param   NODO ARBOL
 * \return  ARBOL
 */

nodoArbolContenido * NMD(nodoArbolContenido * arbol) {
    nodoArbolContenido * rta = NULL;
    if(arbol) {
        if(arbol->der) rta = NMD(arbol->der);
        else rta = arbol;
    }
    return rta;
}


/**
 * \brief   BORRA EL NODO ARBOL POR ID
 * \param   NODO ARBOL
 * \param   ID CONTENIDO
 * \return  ARBOL
 */

nodoArbolContenido * borrarNodoArbol(nodoArbolContenido * arbol, int idcontenido) {
    if(arbol) {
        if(idcontenido == arbol->dato.idContenido) {
            if(arbol->izq != NULL) {
                nodoArbolContenido * nmd = NMD(arbol->izq);
                arbol->dato = nmd->dato;
                arbol->izq = borrarNodoArbol(arbol->izq, nmd->dato.idContenido);
            } else if(arbol->der != NULL) {
                nodoArbolContenido * nmi = NMI(arbol->der);
                arbol->dato = nmi->dato;
                arbol->der = borrarNodoArbol(arbol->der,nmi->dato.idContenido);
            } else {
                free(arbol);
                arbol = NULL;
            }
        } else if(idcontenido>arbol->dato.idContenido) {
            arbol->der = borrarNodoArbol(arbol->der, idcontenido);
        } else {
            arbol->izq = borrarNodoArbol(arbol->izq, idcontenido);
        }
    }
    return arbol;
}


/**
 * \brief   BORRA EL ARBOL
 * \param   NODO ARBOL
 * \return  ARBOL
 */

nodoArbolContenido * borrarArbol(nodoArbolContenido * arbol) {
    int cant = cuentaNodoArbol(arbol);
    for(int i = 0; i < cant+1; i++) {
        arbol = borrarNodoArbol(arbol,i);
    }
    return arbol;
}


/**
 * \brief   SE PASA EL ARBOL DE CONTENIDOS AL ARCHIVO
 * \param   ARCHIVO
 * \param   NODO ARBOL
 * \return  VOID
 */

void arbolContenidoToArchivo(char archivo[], nodoArbolContenido * arbol) {
    FILE * pArch = fopen(archivo,"wb");
    if(pArch) {
        arbolContenidoToArchivoR(pArch, arbol);
        fclose(pArch);
    }
}

void arbolContenidoToArchivoID(char archivo[], nodoArbolContenido * arbol, int id) {
    FILE * pArch = fopen(archivo,"wb");
    if(pArch) {
        arbolContenidoToArchivoR(pArch, arbol);
        fclose(pArch);
    }
}

void arbolContenidoToArchivoR(FILE * pArch, nodoArbolContenido * arbol) {
    if(arbol) {
        arbolContenidoToArchivoR(pArch, arbol->izq);
        fwrite(&arbol->dato,sizeof(stContenido),1,pArch);
        arbolContenidoToArchivoR(pArch, arbol->der);
    }
}

/**
 * \brief   SE PASA EL ARCHIVO AL ARBOL DE CONTENIDOS BALANCEADO
 * \param   ARCHIVO
 * \param   NODO ARBOL
 * \param   BALANCEO ( 1 = BALANCEADO | 0 = NO ESTA BALANCEADO )
 * \return
 */

nodoArbolContenido * archivoToArbolContenido(char archivo[], nodoArbolContenido * arbol, int balanceado) {
    FILE * archi = fopen(archivo,"rb");
    if(archi != NULL) {
        stContenido aux;
        while(fread(&aux, sizeof(stContenido), 1, archi) > 0 && !(aux.activo)) { //recorro el archivo de contenidos
            nodoArbolContenido * nuevo = crearnodoArbolContenido(aux);
            if(balanceado) {
                arbol = insertarNodoArbolBalanceado(arbol,nuevo);
            } else {
                arbol = insertarNodoArbol(arbol,nuevo);
            }
        }
        fclose(archi);
    }
    return arbol;
}


/**
 * \brief   SE PASA LOS CONTENIDOS DEL ARBOL AL ARREGLO
 * \param   TIPO (TITULO - DESCRIPCION - CATEGORIA - LIKES - PUNTOS POR COMPARTIR)
 * \param   NODO ARBOL DE CONTENIDO
 * \param   ARREGLO DE CONTENIDO
 * \param   POSICION
 * \param   DIMENSION
 * \param   SE USA PARA LAS BUSQUEDAS POR STRING
 * \param   SE USA PARA LAS BUSQUEDAS POR NUMERICAS
 * \return  POSICION
 */

int arbolAArreglo(int tipo, nodoArbolContenido * arbol, stContenido contenidos[], int i, int dim, char filtro[], int filtro2) {
    if(arbol && i < dim) {
        i = arbolAArreglo(tipo,arbol->izq,contenidos,i,dim,filtro,filtro2);
        int flag = 0;
        switch(tipo) {
        case 0:
            flag = 1;
            break;
        case 1:
            if(strstr(arbol->dato.titulo,filtro) != NULL) flag = 1; // (STRSTR = BUSCA UNA SUBCADENA DENTRO DE UA CADENA DE TEXTO)
            break;
        case 2:
            if(strstr(arbol->dato.descripcion,filtro) != NULL) flag = 1;
            break;
        case 3:
            if(strstr(arbol->dato.categoria,filtro) != NULL) flag = 1;
            break;
        case 4:
            if(arbol->dato.likes == filtro2) flag = 1;
            break;
        case 5:
            if(arbol->dato.puntosPorCompartir == filtro2) flag = 1;
            break;
        }
        if(flag) {
            contenidos[i] = arbol->dato;
            i++;
        }
        i = arbolAArreglo(tipo,arbol->der,contenidos,i,dim,filtro,filtro2);
    }
    return i;
}



/**
 * \brief   SE CALIFICA EL CONTENIDO (SE USA LA FUNCION DE BUSCAR EL CONTENIDO, SI LO ENCUENTRA LO CALIFICA)
 * \param   ID CONTENIDO
 * \param   CALIFICACION
 * \return  VOID
 */

void calificarContenido(nodoArbolContenido * arbol, int idContenido, int calificacion) {
    nodoArbolContenido * buscado = buscarContenidoId(arbol, idContenido);
    if(buscado) {
        buscado->dato.likes += calificacion;
        buscado->dato.puntosPorCompartir++;
    }
}




/**
 * \brief   LISTA LOS CONTENIDOS DEL ARREGLO
 * \param   TIPO DE LISTA QUE SE QUIERE
 * \param   ARREGLO DE CONENIDOS
 * \param   VALIDOS
 * \param   DIMENSION
 * \param   LLENO (INDICA SI EL ARREGLO YA TIENE LOS DATOS)
 * \return
 */

int listarContenidos(int tipo, stContenido contenidos[], int validos, int dim, int lleno, nodoArbolContenido * arbol) {
    int i = 0;
    if(!lleno) {
        i = arbolAArreglo(0,arbol,contenidos,0,dim,"",0);
    } else {
        i = validos;
    }
    switch(tipo) {
    case 1:
        ordenaArreglocontenidosSeleccionTitulo(contenidos,dim); // TITULO
        break;
    case 2:
        ordenaArreglocontenidosSeleccionDescripcion(contenidos,dim); // DESCRIPCION
        break;
    case 3:
        ordenaArregloContenidosSeleccionCategoria(contenidos,dim);  // CATEGORIA
        break;
    case 4:
        ordenaArregloContenidosSeleccionLikes(contenidos,dim);  // LIKES
        break;
    case 5:
        ordenaArregloContenidosSeleccionPuntosCompartir(contenidos,dim);  // PUNTOS POR COMPARTIR
        break;
    }
    return i;
}


/**
 * \brief   BUSCA EN EL ARCHIVO LOS CONTENIDOS QUE COINCIDEN CON LOS PARAMETROS ESTABLECIDOS, MODIFICA ARREGLO CONTENIDOS CON LAS DE CONTENIDOS ENCONTRADOS
 * \param   TIPO (TIPO DE BUSQUEDA QUE SE QUIERE REALIZAR)
 * \param   FILTRO (FILTRA LA BUSQUEDA POR STRING)
 * \param   FILTRO2 (FILTRA LA BUSQUEDA NUMERICA)
 * \param   ARREGLO DE CONTENIDO DONDE SE GUARDAN LOS ID DE LOS CONTENIDOS ENCONTRADOS
 * \param   DIM (CANTIDAD DE CONTENIDOS QUE PODEMOS BUSCAR)
 * \return  >0 CANTIDAD DE CONTENIDOS ENCONTRADOS QUE COINCIDEN CON LA BUSQUEDA
 * \return  =0 SI NO SE ENCUENTRA CONTENIDOS.
 */

int consultacontenidos(int tipo, char filtro[], int filtro2, stContenido contenidos[], int dim, nodoArbolContenido * arbol) {
    int i = 0;
    if(arbol != NULL) {
        i = arbolAArreglo(tipo,arbol,contenidos,i,dim,filtro,filtro2);
    }
    return i;
}




