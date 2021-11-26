#include "variosRegistros.h"

/*********************************************************//**
* \brief Carga un arreglo de clientes con intervencion del usuario
* \param stRegistro c[] - el arreglo de clientes
* \param int v - sus validos
* \param int dim - su dimension
* \return int v - sus validos
***********************************************************/

int cargaArregloManual(stRegistro c[], int v, int dim){
    char opcion = 0;
    while(v<dim && opcion!=27){
        system("cls");
        c[v] = cargaUnRegistroManual();
        v++;
        printf("\n\n\t\t\tESC para salir.....");
        opcion = getch();
        system("cls");
    }
    return v;
}

int cargaArregloRandom(stRegistro c[], int v, int dim){
    char continuar = 's';
    while(v<dim && continuar == 's'){
        system("cls");
        c[v] = cargaUnRegistroRandom();
        v++;
        printf("\n\tDesea continuar? [SI - NO]");
        continuar = getch();
        system("cls");
    }
    return v;
}

/*********************************************************//**
* \brief Muestra un arreglo de clientes
* \param stRegistro c[] - el arreglo de clientes
* \param int v - sus validos
* \return void
***********************************************************/

void muestraArreglo(stRegistro c[], int v){
    for(int i = 0; i < v; i++){
        muestraUnRegistro(c[i]);
    }
}

/*********************************************************//**
* \brief Guarda un cliente en el archivo
* \param stRegistro cliente - un cliente
* \return void
***********************************************************/

void guardaArchivo(stRegistro c){
    FILE *pArch = fopen(AR_ANIMALES, "ab");
    if(pArch){
        fwrite(&c, sizeof(stRegistro), 1, pArch);
        fclose(pArch);
    }
}

/*********************************************************//**
* \brief Carga un archivo de clientes con intervencion del usuario
* \param ninguno
* \return void
***********************************************************/

void cargaArchivoManual(){
    stRegistro c;
    char opcion;
    do{
        system("cls");
        c = cargaUnRegistroManual();
        guardaArchivo(c);
        printf("\n\n\t\t\tESC para salir.....");
        opcion = getch();
        system("cls");
    } while(opcion!=27);
}

void cargaArchivoRandom(int cant){
    stRegistro c;
    for(int i = 0; i < cant; i++){
        system("cls");
        c = cargaUnRegistroRandom();
        guardaArchivo(c);
        system("cls");
    }
}

/*********************************************************//**
* \brief Muestra un archivo de clientes
* \param char archCli[] - el nombre del archivo
* \return void
***********************************************************/

void muestraArchivo(char archivo[]){
    stRegistro c;
    FILE *pArch = fopen(archivo, "rb");
    if(pArch){
        while(fread(&c, sizeof(stRegistro), 1, pArch)>0){
            muestraUnRegistro(c);
        }
        fclose(pArch);
        printf("\n");
    }
}

/*********************************************************//**
* \brief Cuenta la cantidad de registra de un archivo
* \param char archivo[] - el nombre del archivo
* \param int dataSize - el sizeof del tipo de dato del archivo
* \return int v - la cantidad de registros - 0 si está vacío
***********************************************************/

int cuentaCantidadRegistros(char archivo[], int bytes){
    FILE *pArch = fopen(archivo, "rb");
    int cantidadReg = 0;
    if(pArch){
        fseek(pArch, 0, SEEK_END);
        cantidadReg = ftell(pArch)/bytes;
        fclose(pArch);
    }
    return cantidadReg;
}

/*********************************************************//**
* \brief Copia los clientes de una archivo a un arreglo de clientes
* \param char archivo[] - el nombre del archivo
* \param stRegistro c[] - el arreglo de clientes
* \param int v - sus validos
* \param int dim - su dimension
* \return int v - sus validos
***********************************************************/

int archivoTOarreglo(char archivo[], stRegistro c[], int v, int dim){
    FILE *pArch = fopen(archivo, "rb");
    if(pArch){
        while(v<dim && fread(&c[v], sizeof(stRegistro), 1, pArch)>0){
            v++;
        }
        fclose(pArch);
    }
    return v;
}

