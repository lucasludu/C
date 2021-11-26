#include "adl.h"

    /******************************************************
     * \brief   BUSCA LA POSICION DE LA ESPECIE.
     * \param   CELDA ADA[].
     * \param   ESTRUCTURA DE ESPECIE E.
     * \param   INT VALIDOS.
     * \return  INT VALIDOS.
     ******************************************************/

int buscaPosEspecie(stCelda ada[], stEspecie e, int v){
    int rta = -1;
    int i = 0;
    while(i<v && rta==-1){
        if(strcmp(ada[i].dato.especie, e.especie)==0){
            rta = i;
        }
        i++;
    }
    return rta;
}

    /******************************************************
     * \brief   AGREGA ARREGLOS DE LISTAS.
     * \param   CELDA ADA[].
     * \param   ESTRUCTURA DE ESPECIE E.
     * \param   INT VALIDOS.
     * \return  INT VALIDOS.
     ******************************************************/

int agregar(stCelda ada[], stEspecie e, int v){
    ada[v].dato = e;
    ada[v].arbolAnimales = inicTree();
    v++;
    return v;
}

    /******************************************************
     * \brief   DA DE ALTA EL ARREGLO DE LISTAS.
     * \param   CELDA ADA[].
     * \param   ESTRUCTURA DE ESPECIE E.
     * \param   ESTRUCTURA DE ANIMAL A.
     * \param   INT VALIDOS.
     * \return  INT VALIDOS.
     ******************************************************/

int alta(stCelda ada[], stEspecie e, stAnimal a, int v){
    stNodoArbol * aux = crearNodoTree(a);
    int pos = buscaPosEspecie(ada, e, v);
    if(pos==-1){
        v = agregar(ada, e, v);
        pos = v - 1;
    }
    ada[pos].arbolAnimales = insertarArbol(ada[pos].arbolAnimales, aux);
    return v;
}

    /******************************************************
     * \brief   PASA EL ARCHIVO AL ARREGLO DE LISTAS.
     * \param   CELDA ADA[].
     * \param   INT VALIDOS.
     * \param   INT DIM.
     * \return  INT VALIDOS.
     ******************************************************/

int archToAda(stCelda ada[], int v, int dim){
    FILE * pArch = fopen(AR_ANIMALES, "rb");
    if(pArch){
        stRegistro r;
        stEspecie e;
        stAnimal a;
        while(fread(&r, sizeof(stRegistro), 1, pArch)>0 && (v<dim)){
            e.idEspecie = r.idEspecie;
            strcpy(e.especie, r.especie);
            a.cantidad = r.cantidad;
            strcpy(a.animal, r.animal);
            a.habitat = r.habitat;
            v = alta(ada, e, a, v);
        }
        fclose(pArch);
    }
    return v;
}

    /******************************************************
     * \brief   MUESTRA ARREGLO DE LISTAS.
     * \param   CELDA ADA[].
     * \param   INT DIM.
     * \return  VOID.
     ******************************************************/

void mostrarADA(stCelda ada[], int v){
    printf("\n\tMostando arreglo de especies.\n\n");
    int i = 0;
    while(i<v){
        printf("\n\tEspecie %2d: %s", ada[i].dato.idEspecie, ada[i].dato.especie);
        printf("\n\tArbol de animales: %6d", cuentaCantidadNodosArbol(ada[i].arbol));
        printf("\n\tCantidad total de animales: %6d", cuentaCantidadAnimalesArbol(ada[i].arbol));
        replicante(205, 50);
        inOrder(ada[i].arbol);
        i++;
    }
}

    /******************************************************
     * \brief   GUARDA LA LISTA DE ESPECIE EN EL ARCHIVO.
     * \param   CELDA ADA[].
     * \param   INT VALIDOS.
     * \return  VOID.
     ******************************************************/

void guardarEspecies(stCelda ada[],int v){
    char arEspecie[20];
    for(int i = 0; i < v; i++){
        arEspecie[0]='\0';                      /// Genero el nombre del archivo con el nombre de la especie
        strcat(arEspecie,ada[i].e.especie);
        strcat(arEspecie,".dat");

        FILE* pArch = fopen(arEspecie,"wb");

        if(pArch){
            guardarArbol(pArch,ada[i].arbol);
            fclose(pArch);
        }
    }
}

    /******************************************************
     * \brief   GUARDA EL ARBOL EN EL ARCHIVO.
     * \param   FILE *PF.
     * \param   NODO ARBOL - ARBOL.
     * \return  VOID.
     ******************************************************/

void guardarArbol(FILE* pf, stNodoArbol* arbol){
    if(arbol){
        guardarArbol(pf,arbol->izq);
        fwrite(&arbol->dato,sizeof(stAnimal),1,pf);
        guardarArbol(pf,arbol->der);
    }
}

    /******************************************************
     * \brief   MUESTRA LOS ANIMALES EN EL ARCHIVO.
     * \param   CHAR ARHIVO[].
     * \return  VOID.
     ******************************************************/

void mostrarAnimales(char archivo[]){
    stAnimal a;
    FILE * pArch = fopen(archivo,"rb");
    if(pArch){
        while(fread(&a,sizeof(stAnimal),1,pArch)>0){
            mostrarUnAnimal(a);
        }
    }
}
