#include "adl.h"

int buscaPosMateria(stCelda adl[], stMateria materia, int v) {
    int rta = -1;
    int i = 0;
    while(i < v && rta == -1) {
        if(strcmp(adl[i].dato.materia, materia.materia) == 0) {
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregar(stCelda adl[], stMateria materia, int v) {
    adl[v].dato = materia;
    adl[v].listaNotas = initLista();
    v++;
    return v;
}

int alta (stCelda adl[], stMateria materia, stNotaAlumnos nota, int v) {
    stNodo * aux = crearNodo(nota);
    int pos = buscaPosMateria(adl, materia, v);
    if(pos == -1) {
        v = agregar(adl, materia, v);
        pos = v - 1;
    }
    adl[pos].listaNotas = agregarFinal(adl[pos].listaNotas, aux);
    return v;
}

int archToAdl(stCelda adl[], int v, int dim) {
    FILE * pArch = fopen(arRegistro, "rb");
    if(pArch) {
        stRegistroArchivo rg;
        stMateria m;
        stNotaAlumnos n;
        while(fread(&rg, sizeof(stRegistroArchivo), 1, pArch) > 0 && (v<dim)) {
            m.idMateria = rg.idMateria;
            strcpy(m.materia, rg.materia);
            n.legajo = rg.legajo;
            strcpy(n.apeNom, rg.apeNom);
            n.nota = rg.nota;

            v = alta(adl, m, n, v);
        }
        fclose(pArch);
    }
    return v;
}

void muestraAdl(stCelda adl[], int v) {
    printf("\n\t Muestra Adl\n");
    int i = 0;
    while(i < v) {
        printf("\n\t Materia %d: %s", adl[i].dato.idMateria, adl[i].dato.materia);
        printf("\n\t Lista de Alumnos: %d\n", cuentaListaRegistros(adl[i].listaNotas));
        replicante('-', 50);
        muestraLista(adl[i].listaNotas);
        i++;
    }
}

void guardarAprobadosDesaprobados(stCelda adl[], int v) {
    stRegistroArchivo rg;
    for(int i = 0; i < v; i++) {
        rg.idMateria = adl[i].dato.idMateria;
        strcpy(rg.materia, adl[i].dato.materia);

        stNodo * seg = adl[i].listaNotas;
        while(seg) {
            rg.legajo = seg->dato.legajo;
            rg.nota = seg->dato.nota;
            strcpy(rg.apeNom, seg->dato.apeNom);

            (seg->dato.nota>=6) ? guardaRegistroArchivo(arRegAprob, rg) : guardaRegistroArchivo(arRegDesaprob, rg);
            seg = seg->siguiente;
        }
    }
}
