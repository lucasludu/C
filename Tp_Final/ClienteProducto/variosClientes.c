#include "variosClientes.h"

//****************************************************************************************************** VALIDACIONES.

/**
 * \brief Valida el ultimo ID (Es autoincremental) Para no repetir
 * \param Sin parametro
 * \return Ultimo ID
 */

int buscaUltimoID() {
    stCliente c;
    int ultimoId = 0;
    FILE * pArchCli = fopen(ARCLIENTE,"rb");
    if (pArchCli) {
        fseek(pArchCli, (-1) * sizeof(stCliente), SEEK_END);
        if (fread(&c, sizeof (stCliente),1, pArchCli) > 0) {
            ultimoId = c.id;
        }
    }
    return ultimoId;
}

/**
 * \brief Valida la existencia del dni para que no se repita
 * \param dni []
 * \return flag
 */

int existeDNICliente(char dni[]) {
    stCliente aux;
    int flag = 0;
    FILE * archi = fopen(ARCLIENTE, "rb");
    if(archi) {
        while(flag == 0 && fread(&aux, sizeof(stCliente), 1, archi) >0) {
            if(strcmp(aux.dni, dni) == 0) {
                flag = 1;
            }
        }
        fclose(archi);
    }
    return flag;
}

//****************************************************************************************************** ARREGLO.

/**
 * \brief Muestra los clientes que hay en el arreglo
 * \param Arreglo de cliente
 * \param validos
 * \return void
 */

void muestraArregloClientes (stCliente c[], int v){
    int * coordy = 6;
    int * incy = 2;
    for(int i=0; i<v; i++){
        cabeceraClientes();
        muestraUnCliente(c[i], &coordy, &incy);
    }
}

//****************************************************************************************************** ARCHIVOS.

/**
 * \brief Guardo los clientes cargados en el archivo.
 * \param Cliente
 * \return void
 */

void archivarClientes (stCliente c) {
    FILE * pArch = fopen(ARCLIENTE, "ab");
    if(pArch) {
        fwrite(&c, sizeof(stCliente), 1, pArch);
        fclose(pArch);
    }
}

/**
 * \brief Carga archivo de clientes
 * \param Sin parametro
 * \return void
 */

void cargaArchivoClientes() {
    stCliente c;
    char continuar = 's';
    do {
        system("cls");
        c = cargaUnCliente();
        archivarClientes(c);
        printf("\n\n\t\t\t Desea continuar con la carga de clientes? [ S | N ]");
        continuar = getch();
        system("cls");
    } while(continuar == 's');
}

/**
 * \brief Muestra el archivo de clientes
 * \param Archivo
 * \return void
 */

void muestraArchivoClientes(char archivo[]) {
    stCliente c;
    int *coordy = 3;
    int *indc = 2;
    FILE *pArch = fopen(archivo, "rb");
    if(pArch) {
        cabeceraClientes();
        while(fread(&c, sizeof(stCliente), 1, pArch) > 0) {
            muestraUnCliente(c, &coordy, &indc);
        }
        fclose(pArch);
    }
}

//****************************************************************************************************** ORDENACIONES POR SELECCION.

/**
 * \brief Busca la posicion del menor DNI
 * \param Arreglo Clientes
 * \param Validos
 * \param Pos Inicio
 * \return Pos del menor dni del arreglo
 */

int buscaPosMenorDNI (stCliente c[], int v, int inicio) {
    int posMenor = inicio;
    int i = inicio + 1;
    while (i < v) {
        if (atoi(c[i].dni) > atoi(c[posMenor].dni)) {
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief Busca la Pos del Cliente menor letra del apellido
 * \param Arreglo clientes
 * \param validos
 * \param pos de inicio
 * \return pos de inicio
 */

int buscaPosMenorApellido(stCliente c[], int v, int inicio) {
    int posMenor = inicio;
    int i = inicio + 1;
    while (i < v) {
        if (strcmp(c[i].apellido, c[posMenor].apellido) < 0) {
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

/**
 * \brief Intercambia dos variables tipo cliente (compara)
 * \param Puntero cliente A
 * \param Puntero cliente B
 * \return void
 */

void intercambioClientes (stCliente *a, stCliente *b) {
    stCliente aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

/**
 * \brief Ordena por seleccion los DNI
 * \param Arreglo Cliente
 * \param validos
 * \return void
 */

void ordenaSeleccionDNI (stCliente c[], int v) {
    int posMenor = 0;
    int i = 0;
    while (i < v-1) {
        posMenor = buscaPosMenorDNI(c, v, i);
        intercambioClientes(&c[i], &c[posMenor]);
        i++;
    }
}

/**
 * \brief Ordena por seleccion los Apellidos
 * \param Arreglo Cliente
 * \param validos
 * \return void
 */

void ordenaSeleccionApellido (stCliente c[], int v) {
    int posMenor = 0;
    int i = 0;
    while(i < v-1) {
        posMenor = buscaPosMenorApellido(c, v, i);
        intercambioClientes(&c[i], &c[posMenor]);
        i++;
    }
}

//****************************************************************************************************** BUSQUEDA

/**
 * \brief Busca la posicion del cliente por ID
 * \param ID
 * \return pos del cliente
 */

int buscaPosId (int id) {
    int pos = -1;
    stCliente c;
    FILE * pArchCliente = fopen(ARCLIENTE, "rb");
    if(pArchCliente) {
        while (pos == -1 && fread(&c, sizeof(stCliente), 1, pArchCliente) > 0) {
            if(c.id == id) {
                pos = ftell(pArchCliente) / sizeof(stCliente) - 1;
            }
        }
        fclose(pArchCliente);
    } else {
        printf("\n\t No existe el archivo de clientes\n");
    }
    return pos;
}


/**
 * \brief Busca al cliente por apellido
 * \param Apellido
 * \return Cliente
 */

stCliente buscaClienteApellido (char apellido[]) {
    stCliente c;
    int flag = 0;
    FILE * pArchCLiente = fopen(ARCLIENTE, "rb");
    if (pArchCLiente) {
        while (flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCLiente) > 0) {
            if (strcmp(c.apellido, apellido) == 0) {
                flag = 1;
            }
        }
        fclose(pArchCLiente);
    }
    if (flag == 0) {
        c.id = -1;
    }
    return c;
}


/**
 * \brief Busca al cliente por dni
 * \param dni
 * \return Cliente
 */

stCliente buscaClienteDni (char dni[]) {
    stCliente c;
    int flag = 0;
    FILE * pArchCLiente = fopen(ARCLIENTE, "rb");
    if (pArchCLiente) {
        while (flag == 0 && fread(&c, sizeof(stCliente), 1, pArchCLiente) > 0) {
            if (strcmp(c.dni, dni) == 0) {
                flag = 1;
            }
        }
        fclose(pArchCLiente);
    }
    if (flag == 0) {
        c.id = -1;
    }
    return c;
}

//****************************************************************************************************** MODIFICAR CLIENTE


/**
 * \brief Modifica el registro
 * \param Cliente a buscar
 * \return void
 */

void modificaRegistro (stCliente c){
    int pos = 0;
    pos = buscaPosId(c.id);
    FILE * pArchCliente = fopen(ARCLIENTE, "r + b");
    if (pArchCliente){
        fseek(pArchCliente, sizeof(stCliente) * pos, SEEK_SET);
        fwrite(&c, sizeof(stCliente), 1, pArchCliente);
        fclose(pArchCliente);
    }
}

stCliente modificaCliente(stCliente c){
    int op, existe;
    stCliente cliente;
    do{
        system("cls");
        gotoxy(15, 7);
        printf("Seleccione el campo que desea Modificar: ");
        gotoxy(15, 10);
        printf("[ 1 ] - Nombre");
        gotoxy(15, 12);
        printf("[ 2 ] - Apellido");
        gotoxy(15, 14);
        printf("[ 3 ] - DNI");
        gotoxy(15, 16);
        printf("[ 4 ] - Telefono");
        gotoxy(15, 18);
        printf("[ 5 ] - Domicilio");
        gotoxy(25, 21);
        printf("Presione < ESC > para salir.");
        op = getch();
        system("cls");
        switch (op){
        case '1':
            printf("\n\tIngrese nuevo nombre del cliente: ");
            fflush(stdin);
            gets(cliente.nombre);
            strcpy(c.nombre, cliente.nombre);
            break;
        case '2':
            printf("\n\tIngrese nuevo apellido del cliente: ");
            fflush(stdin);
            gets(cliente.apellido);
            strcpy(c.apellido, cliente.apellido);
            break;
        case '3':
            do {
                printf("\n\t Ingrese nuevo DNI de cliente\t");
                fflush(stdin);
                gets(cliente.dni);
                strcpy(c.dni, cliente.dni);
                while(strlen(cliente.dni) != 8 || strlen(cliente.dni) > 9) {
                    system("cls");
                    printf("\n\t Ingresar DNI entre 8 y 9 caracteres, intente de nuevo: ");
                    fflush(stdin);
                    gets(cliente.dni);
                    strcpy(c.dni, cliente.dni);
                    system("cls");
                }
                existe = existeDNICliente(cliente.dni);
            } while(existe);
            break;
        case '4':
            printf("\n\tIngrese el nuevo movil del cliente: ");
            fflush(stdin);
            gets(cliente.telefono);
            strcpy(c.telefono, cliente.telefono);
            break;
        case '5':
            printf("\n\tIngrese el nuevo domicilio del cliente: ");
            fflush(stdin);
            gets(cliente.domicilio);
            strcpy(c.domicilio, cliente.domicilio);
            break;
        }
        system("pause");
    }
    while (op != 27);
    return c;
}

void funcionModificar(){
    int continuar;
    char apellido[20];
    stCliente aux, modif;
    int * coordy = 6;
    int * incy = 2;
    do{
        system("cls");
        printf("\n\tIngrese apellido a buscar: ");
        fflush(stdin);
        gets(apellido);

        aux = buscaClienteApellido(apellido);

        if (aux.id != -1){
            printf("\n\tEl cliente se encuentra en el archivo\n\n");
            system("pause");
            system("cls");
            cabeceraClientes();
            muestraUnCliente(aux, &coordy, &incy);
            printf("\n\n\tDesea modificar al cliente? [SI - NO]");
            continuar = getch();
        } else {
            printf("\n\tEl Cliente no se encuentra en el archivo.");
        }

        if (continuar == 's'){
            modif = modificaCliente(aux);
            modificaRegistro(modif);
        } else {
            printf("\n\n\tNo se modifica NADA\n\n");
        }

        system("pause");
        printf("\n\n\tDesea continuar con la modificacion de clientes? [SI - NO]");
        continuar = getch();
    } while(continuar == 's');
}

//****************************************************************************************************** BAJA AL CLIENTE

void bajaClientes(){
    stCliente aux;
    char apellido[20];
    char continuar;
    int * coordy = 6;
    int * incy = 2;

    printf("\n\tApellido del cliente: ");
    fflush(stdin);
    gets(apellido);

    aux = buscaClienteApellido(apellido);

    if (aux.id != -1){
        printf("\n\tEl cliente se encuentra en el archivo");
        system("pause");
        system("cls");
        cabeceraClientes();
        muestraUnCliente(aux, &coordy, &incy);
        printf("\n\n\t\tDesea dar de baja al cliente? [SI - NO]");
        continuar = getch();
        system("cls");
    } else {
        printf("\n\tEl cliente no se encuentra en el archivo");
    }
    if (continuar == 's'){
        aux.baja = 1;
        cabeceraClientes();
        muestraUnCliente(aux, &coordy, &incy);
        modificaRegistro(aux);
    }
}

//****************************************************************************************************** PASAR ARCHIVO AL ARREGLO

int archiToarregloClientes (stCliente c[], int dim){
    stCliente cliente;
    int i = 0;
    FILE * pArchCLiente = fopen(ARCLIENTE, "rb");
    if (pArchCLiente){
        while (fread(&cliente, sizeof(stCliente), 1, pArchCLiente) > 0){
            c[i] = cliente;
            i++;
        }
        fclose(pArchCLiente);
    }
    return i;
}


int archiActivoToarreglo (stCliente c[], int dim){
    stCliente cliente;
    int i=0;
    FILE *pArchCliente = fopen(ARCLIENTE, "rb");
    if(pArchCliente){
        while(fread(&cliente, sizeof(stCliente), 1, pArchCliente) > 0){
            if(cliente.baja == 0){
                c[i] = cliente;
                i++;
            }
        }
        fclose(pArchCliente);
    }
    return i;
}

int archiInactivoToarreglo (stCliente c[], int dim){
    stCliente cliente;
    int i=0;
    FILE *pArchCliente = fopen(ARCLIENTE, "rb");
    if(pArchCliente){
        while(fread(&cliente, sizeof(stCliente), 1, pArchCliente) > 0){
            if(cliente.baja == 1){
                c[i] = cliente;
                i++;
            }
        }
        fclose(pArchCliente);
    }
    return i;
}

//****************************************************************************************************** MENU DE CLIENTES

void menuListarClientes(stCliente c[], int v, int dim) {
    char op;
    v = archiToarregloClientes(c, dim);
    do {
        system("cls");
        contornoMenu();
        gotoxy(25, 7);
        printf("MENU DE MOSTRAR");
        gotoxy(15, 10);
        printf("[ 01 ] - Mostrar Ordenados por ID.");
        gotoxy(15, 12);
        printf("[ 02 ] - Mostrar Ordenados por Apellido.");
        gotoxy(15, 14);
        printf("[ 03 ] - Mostrar Ordenados por Dni.");
        gotoxy(25, 17);
        printf("[ ESC ] - SALIR.");
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            muestraArregloClientes(c, v);
            break;
        case '2':
            ordenaSeleccionApellido(c, v);
            muestraArregloClientes(c, v);
            break;
        case '3':
            ordenaSeleccionDNI(c, v);
            muestraArregloClientes(c, v);
            break;
        }
        getch();
    } while(op != 27);
}

void menuBajaClientes(stCliente c[], int v, int dim) {
    char op;
    do {
        system("cls");
        contornoMenu();
        gotoxy(25, 7);
        printf("BAJA/ALTA DE CLIENTES.");
        gotoxy(15, 10);
        printf("[ 01 ] - Dar de Alta o Baja de Cliente.");
        gotoxy(15, 12);
        printf("[ 02 ] - Mostrar Clientes Activos.");
        gotoxy(15, 14);
        printf("[ 03 ] - Mostrar Clientes Inactivos.");
        gotoxy(25, 17);
        printf("[ ESC ] - Volver al men%c Principal de Clientes.", 163);
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            bajaClientes();
            break;
        case '2':
            v = archiActivoToarreglo(c, dim);
            muestraArregloClientes(c, v);
            break;
        case '3':
            v = archiInactivoToarreglo(c, dim);
            muestraArregloClientes(c, v);
            break;
        }
        getch();
    } while(op != 27);
}

void menuPpalClientes(stCliente c[], int v, int dim) {
    char op;
    do {
        system("cls");
        contornoMenu();
        gotoxy(25, 7);
        printf("MENU PRINCIPAL < CLIENTES >");
        gotoxy(15, 10);
        printf("[ 01 ] - Carga Clientes.");
        gotoxy(15, 12);
        printf("[ 02 ] - Muestra Clientes.");
        gotoxy(15, 14);
        printf("[ 03 ] - Modifica Clientes.");
        gotoxy(15, 16);
        printf("[ 04 ] - Alta/Baja de Clientes.");
        gotoxy(25, 19);
        printf("[ ESC ] - Volver al Men%c Principal.", 163);
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            cargaArchivoClientes();
            break;
        case '2':
            menuListarClientes(c, v, dim);
            break;
        case '3':
            funcionModificar();
            break;
        case '4':
            menuBajaClientes(c, v, dim);
            break;
        }
    } while(op != 27);
}
