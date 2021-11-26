#include "contenido.h"

/**
 * \brief   CARGA UN CONTENIDO
 * \param   SIN PARAMETROS
 * \return  CONTENIDO
 */

stContenido cargaContenido() {
    stContenido aux;

    aux.idContenido = ultimoIdContenido()+1;

    do {
        printf("\n\t Titulo: ");
        fflush(stdin);
        gets(aux.titulo);
    } while(strlen(aux.titulo) == 0);

    do {
        printf("\n\t Descripcion: ");
        fflush(stdin);
        gets(aux.descripcion);
    } while(strlen(aux.descripcion) == 0);

    do {
        printf("\n\t Categoria: ");
        fflush(stdin);
        gets(aux.categoria);
    } while(strlen(aux.categoria) == 0);

    printf("\n\t Likes: ");
    scanf("%d", &aux.likes);

    printf("\n\t Puntos por compartir: ");
    scanf("%d", &aux.puntosPorCompartir);

    aux.activo = 0;
    return aux;
}

/**
 * \brief   MUESTRA NODO DE LA LISTA
 * \param   CONTENIDO
 * \return  VOID
 */

void mostrarContenidos(stContenido contenido) {
    printf("\n\t ID.......................: %d", contenido.idContenido);
    printf("\n\t Titulo...................: %s", contenido.titulo);
    printf("\n\t Descripcion..............: %s", contenido.descripcion);
    printf("\n\t Categoria................: %s", contenido.categoria);
    printf("\n\t Likes....................: %d", contenido.likes);
    printf("\n\t Puntos por compartir.....: %d", contenido.puntosPorCompartir);
    printf("\n\t Activo...................: %s", (contenido.activo)?"SI":"NO");
    printf("\n-----------------------------------------------------------------------\n");
}

/*****************************************
* \brief BUSCA EL ULTIMO ID DEL CLIENTE
* \param SIN PARAMETROS
* \return ULTIMO ID
******************************************/

int ultimoIdContenido() {
    stContenido contenido;
    int ultimoId =0;
    FILE * pArch = fopen(ARCHIVO_CONTENIDO, "rb");
    if (pArch) {
        fseek(pArch, (-1) * sizeof(stContenido), SEEK_END);
        if (fread(&contenido, sizeof (stContenido), 1, pArch)>0) {
            ultimoId = contenido.idContenido;
        }
    }
    return ultimoId;
}

/**
 * \brief   SE MUESTRA EL ARREGLO DE CONTENIDOS
 * \param   ARREGLO DE CONTENIDO
 * \param   POSICION
 * \param   VALIDOS
 * \return  VOID
 */


void mostrarArreglocontenidos(stContenido contenidos[], int i, int validos) {
    if(i < validos) {
    while(i < validos) {
            mostrarContenidos(contenidos[i]);
            i++;
        }
    }
}


/**
 * \brief   BUSCA LA POSICION DEL MENOR (TITULO)
 * \param   ARREGLO DE CONTENIDOS
 * \param   POSICION
 * \param   CANTIDAD
 * \return  POSICION DEL MENOR
 */

int posMenorTitulocontenidos(stContenido contenidos[], int pos, int cant) {
    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, contenidos[pos].titulo);

    while(i < cant) {
        if(strcmp(menor, contenidos[i].titulo) > 0) {
            strcpy(menor, contenidos[i].titulo);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief   ORDENA POR SELECCION EL ARREGLO DE CONTENIDOS POR TITULO. SE USA LA FUNCION ANTERIOR
 * \param   ARREGLO DE CONTENIDOS
 * \param   CANTIDAD
 * \return  VOID
 */

void ordenaArreglocontenidosSeleccionTitulo(stContenido contenidos[], int cant) {
    int i = 0;
    int menor;
    stContenido aux;

    while(i < cant) {
        menor = posMenorTitulocontenidos(contenidos, i, cant);
        aux = contenidos[menor];
        contenidos[menor] = contenidos[i];
        contenidos[i] = aux;
        i++;
    }
}

/**
 * \brief   BUSCA LA POSICION DEL MENOR (DESCRIPCION)
 * \param   ARREGLO DE CONTENIDOS
 * \param   POSICION
 * \param   CANTIDAD
 * \return  POSICION DEL MENOR
 */

int posMenorDescripcioncontenidos(stContenido contenidos[], int pos, int cant) {
    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, contenidos[pos].descripcion);

    while(i < cant) {
        if(strcmp(menor, contenidos[i].descripcion) > 0) {
            strcpy(menor, contenidos[i].descripcion);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief   ORDENA POR SELECCION EL ARREGLO DE CONTENIDOS POR DESCRIPCION. SE USA LA FUNCION ANTERIOR
 * \param   ARREGLO DE CONTENIDOS
 * \param   CANTIDAD
 * \return  VOID
 */

void ordenaArreglocontenidosSeleccionDescripcion(stContenido contenidos[], int cant) {
    int i = 0;
    int menor;
    stContenido aux;

    while(i < cant) {
        menor = posMenorDescripcioncontenidos(contenidos, i, cant);
        aux = contenidos[menor];
        contenidos[menor] = contenidos[i];
        contenidos[i] = aux;
        i++;
    }
}

/**
 * \brief   BUSCA LA POSICION DEL MENOR (CATEGORIA)
 * \param   ARREGLO DE CONTENIDOS
 * \param   POSICION
 * \param   CANTIDAD
 * \return  POSICION DEL MENOR
 */

int posMenorCategoriaContenidos(stContenido contenidos[], int pos, int cant) {
    int i = pos+1;
    int posMenor = pos;
    char menor[30];
    strcpy(menor, contenidos[pos].categoria);

    while(i < cant) {
        if(strcmp(menor, contenidos[i].categoria) > 0) {
            strcpy(menor, contenidos[i].categoria);
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief   ORDENA POR SELECCION EL ARREGLO DE CONTENIDOS POR CATEGORIA. SE USA LA FUNCION ANTERIOR
 * \param   ARREGLO DE CONTENIDOS
 * \param   CANTIDAD
 * \return  VOID
 */

void ordenaArregloContenidosSeleccionCategoria(stContenido contenidos[], int cant) {
    int i = 0;
    int menor;
    stContenido aux;

    while(i < cant) {
        menor = posMenorCategoriaContenidos(contenidos, i, cant);
        aux = contenidos[menor];
        contenidos[menor] = contenidos[i];
        contenidos[i] = aux;
        i++;
    }
}

/**
 * \brief   BUSCA LA POSICION DEL MENOR (CANTIDAD DE LIKES)
 * \param   ARREGLO DE CONTENIDOS
 * \param   POSICION
 * \param   CANTIDAD
 * \return  POSICION DEL MENOR
 */

int posMayorLikesContenidos(stContenido contenidos[], int pos, int cant) {
    int i = pos+1;
    int posMayor = pos;
	int mayor = contenidos[pos].likes;

    while(i < cant) {
        if(mayor < contenidos[i].likes) {
            mayor = contenidos[i].likes;
            posMayor = i;
        }
        i++;
    }
    return posMayor;
}

/**
 * \brief   ORDENA POR SELECCION EL ARREGLO DE CONTENIDOS POR CANTIDAD DE LIKES. SE USA LA FUNCION ANTERIOR
 * \param   ARREGLO DE CONTENIDOS
 * \param   CANTIDAD
 * \return  VOID
 */

void ordenaArregloContenidosSeleccionLikes(stContenido contenidos[], int cant) {
    int i = 0;
    int mayor;
    stContenido aux;

    while(i < cant) {
        mayor = posMayorLikesContenidos(contenidos, i, cant);
        aux = contenidos[mayor];
        contenidos[mayor] = contenidos[i];
        contenidos[i] = aux;
        i++;
    }
}

/**
 * \brief   BUSCA LA POSICION DEL MENOR (PUNTOS POR COMPARTIR)
 * \param   ARREGLO DE CONTENIDOS
 * \param   POSICION
 * \param   CANTIDAD
 * \return  POSICION DEL MENOR
 */

int posMenorPuntosCompartirContenidos(stContenido contenidos[], int pos, int cant) {
    int i = pos+1;
    int posMenor = pos;
	int menor = contenidos[pos].puntosPorCompartir;

    while(i < cant) {
        if(menor > contenidos[i].puntosPorCompartir) {
            menor = contenidos[i].puntosPorCompartir;
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief   ORDENA POR SELECCION EL ARREGLO DE CONTENIDOS POR PUNTOS POR COMPARTIR. SE USA LA FUNCION ANTERIOR
 * \param   ARREGLO DE CONTENIDOS
 * \param   CANTIDAD
 * \return  VOID
 */

void ordenaArregloContenidosSeleccionPuntosCompartir(stContenido contenidos[], int cant) {
    int i = 0;
    int menor;
    stContenido aux;

    while(i < cant) {
        menor = posMenorPuntosCompartirContenidos(contenidos, i, cant);
        aux = contenidos[menor];
        contenidos[menor] = contenidos[i];
        contenidos[i] = aux;
        i++;
    }
}
