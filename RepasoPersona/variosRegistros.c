#include "variosRegistros.h"
#include "registro.h"

/**
 * \brief CARGA ARREGLO DE REGISTROS MANUAL
 * \param REGISTRO
 * \param VALIDOS
 * \param DIMENCION
 * \return VALIDOS
 */

int cargaArregloManual(stRegistro r[], int v, int dim) {
    char continuar = 's';
    while(v < dim && continuar == 's') {
        system("cls");
        r[v] = cargaUnRegistroManual();
        v++;
        printf("\n\tDesea continuar? [SI - NO]");
        continuar = getch();
        system("cls");
    }
    return v;
}

/**
 * \brief CARGA ARREGLO DE REGISTROS RANDOM
 * \param REGISTRO
 * \param VALIDOS
 * \param DIMENCION
 * \return VALIDOS
 */

int cargaArregloRandom(stRegistro r[], int v, int dim) {
    char continuar = 's';
    while(v < dim && continuar == 's') {
        system("cls");
        r[v] = cargaUnRegistroRandom();
        v++;
        printf("\n\tDesea continuar? [SI - NO]");
        continuar = getch();
        system("cls");
    }
    return v;
}

/**
 * \brief MUESTRA ARREGLO DE REGISTROS
 * \param REGISTRO
 * \param VALIDOS
 * \return VOID
 */

void muestraArreglo(stRegistro r[], int v) {
    for(int i = 0; i < v; i++) {
        muestraUnRegistro(r[i]);
    }
}

/**
 * \brief GUARDA EL REGISTRO EN EL ARCHIVO
 * \param REGISTRO
 * \return VOID
 */

void guardarArchivo(stRegistro r) {
    FILE * pArch = fopen(arRegistro, "ab");
    if(pArch) {
        fwrite(&r, sizeof(stRegistro), 1, pArch);
        fclose(pArch);
    }
}

/**
 * \brief CARGA ARCHIVO DE REGISTRO EN FORMA MANUAL
 * \param SIN PARAMETROS
 * \return VOID
 */

void cargaArchivoManual() {
    stRegistro r;
    char continuar = 's';
    do {
        system("cls");
        r = cargaUnRegistroManual();
        guardarArchivo(r);
        printf("\n\t\t Desea continuar? [SI - NO]");
        continuar = getch();
        system("cls");
    } while(continuar == 's');
}

/**
 * \brief CARGA ARCHIVO DE REGISTRO EN FORMA RANDOM
 * \param CANTIDAD DE REGISTROS A CARGAR
 * \return VOID
 */

void cargaArchivoRandom(int cantidad) {
    stRegistro r;
    for(int i = 0; i < cantidad; i++) {
        system("cls");
        r = cargaUnRegistroRandom();
        guardarArchivo(r);
        system("cls");
    }
}

/**
 * \brief MUESTRA EL ARCHIVO DE REGISTROS
 * \param ARCHIVO
 * \return VOID
 */

void muestraArchivo(char archivo[]) {
    stRegistro r;
    FILE * pArch = fopen(archivo, "rb");
    if(pArch) {
        while(fread(&r, sizeof(stRegistro), 1, pArch) > 0) {
            muestraUnRegistro(r);
        }
        fclose(pArch);
        printf("\n");
    }
}

/**
 * \brief CUENTA LA CANTIDAD DE REGISTROS QUE HAY EN EL ARCHIVO
 * \param ARCHIVO
 * \param BYTES
 * \return CANTIDAD DE REGISTROS
 */

int cuentaCantidadRegistros(char archivo[], int bytes) {
    FILE * pArch = fopen(archivo, "rb");
    int cantReg = 0;
    if(pArch) {
        fseek(pArch, 0, SEEK_END);
        cantReg = ftell(pArch) / bytes;
        fclose(pArch);
    }
    return cantReg;
}
