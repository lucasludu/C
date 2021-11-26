#include "variosProductos.h"

//******************************************************************************* VALIDACIONES

int validaFecha(int anio, int mes, int dia){
    int flag = 0;
    if (mes >= 1 && mes <= 12){
        switch(mes){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia >= 1 && dia <= 31){
                flag = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia >= 1 && dia <= 30){
                flag = 1;
            }
            break;
        case 2:
            if (anio % 4 == 0 || anio % 100 != 0 || anio % 400 == 0){
                if (dia >= 1 && dia <= 29){
                    flag = 1;
                }
            } else if (dia >= 1 && dia <= 28) {
                flag = 1;
            }
        }
    }
    return flag;
}

int buscaUltimoIDConsumo(){
    stProducto p;
    int id = -1;
    FILE * pArchProducto = fopen(ARPRODUCTO, "rb");
    if (pArchProducto){
        fseek(pArchProducto, sizeof(stProducto)*(-1), SEEK_END);
        if (fread(&p, sizeof(stProducto), 1, pArchProducto) > 0){
            id = p.idProducto;
        }
        fclose(pArchProducto);
    }
    return id;
}

//******************************************************************************* ORDENA

int buscaPosMenorFecha (stProducto p[], int v, int inicio){
    int posMenor = inicio;
    int i = inicio + 1;
    while(i<v) {
        if(p[i].fecha.year < p[posMenor].fecha.year) {
                posMenor = i;
        } else {
            if(p[i].fecha.year == p[posMenor].fecha.year) {
                if(p[i].fecha.month < p[posMenor].fecha.month) {
                    posMenor=i;
                } else {
                    if(p[i].fecha.month == p[posMenor].fecha.month) {
                        if (p[i].fecha.day <= p[posMenor].fecha.day) {
                            posMenor=i;
                        }
                    }
                }
            }
        }
        i++;
    }
    return posMenor;
}

void intercambiaProductos(stProducto *a, stProducto *b){
    stProducto aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ordenaSeleccionFecha (stProducto p[], int v){
    int posMenor = 0;
    int i = 0;
    while (i < v-1){
        posMenor = buscaPosMenorFecha(p, v, i);
        intercambiaProductos(&p[i], &p[posMenor]);
        i++;
    }
}

//******************************************************************************* ARREGLO

void muestraArregloProducto (stProducto p[], int v){
    int * coordy = 6;
    int * incy = 2;
    for (int i = 0; i < v; i++){
        muestraUnProducto(p[i], &coordy, &incy);
    }
}

//******************************************************************************* ARCHIVO

void archivarConsumo (stProducto p){
    FILE * pArchProducto = fopen(ARPRODUCTO, "ab");
    if (pArchProducto){
        fwrite(&p, sizeof(stProducto), 1, pArchProducto);
        fclose(pArchProducto);
    }
}

void cargaArchivoProducto(stCliente c){
    char continuar = 's';
    stProducto p;
    while (continuar == 's'){
        system("cls");
        p = cargaUnProducto(c.id);
        p.idProducto = buscaUltimoIDConsumo() + 1;
        archivarConsumo(p);
        printf("\n\n\t\t\t\tDesea continuar con la carga de consumo? [ S | N ]");
        continuar = getch();
        system("cls");
    }
}

void cargaProdcuto_SegunCliente(){
    stCliente aux;
    char apellido[20];
    do{
        printf("\n\tApellido del cliente: ");
        fflush(stdin);
        gets(apellido);

        aux = buscaClienteApellido(apellido);

        if (aux.id != -1){
            cargaArchivoProducto(aux);
        } else {
            printf("\n\tEl cliente no se encuentra en el archivo.");
        }
    } while(aux.id == -1);
}

void muestraArchivoProducto(char archivo[]){
    int * coordy = 6;
    int * incy = 2;
    stProducto p;
    FILE * pArchProducto = fopen(archivo, "rb");
    if (pArchProducto){
        while (fread(&p, sizeof(stProducto), 1, pArchProducto) > 0){
            cabeceraProducto();
            muestraUnProducto(p, &coordy, &incy);
        }
        fclose(pArchProducto);
    }
}

int contarCantidadProductos(char archivo[]) {
    FILE * pArchProducto = fopen(archivo, "rb");
    stProducto p;
    int i = 1;
    if(pArchProducto) {
        while(fread(&p,sizeof(stProducto),1,pArchProducto) > 0) {
            i++;
        }
        fclose(pArchProducto);
    }
    return i;
}

stProducto buscaProductoFecha (int a, int m, int d){
    stProducto p;
    int flag = 0;
    FILE * pArchProducto = fopen(ARPRODUCTO, "rb");
    if(pArchProducto){
        while (flag == 0 && fread(&p, sizeof(stProducto), 1, pArchProducto) > 0){
            if (p.fecha.year == a && p.fecha.month == m && p.fecha.day == d){
                flag = 1;
            }
        }
        fclose(pArchProducto);
    }
    if (flag == 0){
        p.idProducto = -1;
    }
    return p;
}

stProducto buscaProductoPorID(int idProd) {
    stProducto p;
    int flag = 0;
    FILE * pArchProducto = fopen(ARPRODUCTO,"rb");
    if(pArchProducto){
        while(flag == 0 && fread(&p, sizeof(stProducto), 1, pArchProducto) > 0){
            if(p.idProducto == idProd){
                flag = 1;
            }
        }
        fclose(pArchProducto);
    }
    if(flag == 0){
        p.idProducto = -1;
    }
    return p;
}

int buscaPosProducto (int id){
    int pos = -1;
    stProducto p;
    FILE * pArchProducto = fopen(ARPRODUCTO, "rb");
    if(pArchProducto){
        while(pos == -1 && fread(&p, sizeof(stProducto), 1, pArchProducto) > 0){
            if(p.idProducto == id){
                pos = ftell(pArchProducto)/sizeof(stProducto)-1;
            }
        }
        fclose(pArchProducto);
    }

    return pos;
}

//******************************************************************************* PASAJES

int archToArrayProducto(char archivo[], stProducto p[], int dim){
    stProducto producto;
    int i = 0;
    FILE * pArchProducto = fopen(archivo, "rb");
    if (pArchProducto){
        while (i<dim && fread(&producto, sizeof(stProducto), 1, pArchProducto) > 0){
            p[i] = producto;
            i++;
        }
        fclose(pArchProducto);
    }
    return i;
}

int archToArrayProductoId(stProducto p[], int dim, int nro){
    stProducto producto;
    int i = 0;
    FILE * pArchProducto = fopen(ARPRODUCTO, "rb");
    if (pArchProducto){
        while (fread(&producto, sizeof(stProducto), 1, pArchProducto) > 0){
            if (producto.idCliente == nro){
                p[i] = producto;
                i++;
            }
        }
        fclose(pArchProducto);
    }
    return i;
}

//******************************************************************************* MODIFICAR PRODUCTO

void modificaRegistroProducto(stProducto p){
    int pos = 0;
    pos = buscaPosProducto(p.idProducto);
    FILE * pArchProducto = fopen(ARPRODUCTO, "r+b");
    if(pArchProducto){
        fseek(pArchProducto, sizeof(stProducto) * pos, SEEK_SET);
        fwrite(&p, sizeof(stProducto), 1, pArchProducto);
        fclose(pArchProducto);
    }
}

stProducto modificaProducto(stProducto p){
    char op;
    stProducto producto;
    do {
        system("cls");
        gotoxy(15, 10);
        printf("\n\tSeleccione el campo que desea modificar: ");
        gotoxy(15, 13);
        printf("[ 01 ] - Fecha");
        gotoxy(15, 15);
        printf("[ 02 ] - Precio");
        gotoxy(15, 17);
        printf("[ 03 ] - Stock");
        gotoxy(25, 20);
        printf("Presione < ESC > para salir");
        op = getch();
        system("cls");
        switch (op) {
        case '1':
            do {
                gotoxy(10, 8);
                printf("A%co: ", 164);
                scanf("%d", &producto.fecha.year);

                gotoxy(10, 10);
                printf("Mes: ");
                scanf("%d", &producto.fecha.month);

                gotoxy(10, 12);
                printf("D%ca: ", 161);
                scanf("%d", &producto.fecha.day);
            } while (!validaFecha(producto.fecha.year, producto.fecha.month, producto.fecha.day));
            p.fecha = producto.fecha;
            break;
        case '2':
            gotoxy(10, 8);
            printf("Ingrese el Precio del Producto a modificar: ");
            scanf("%f", &producto.precio);
            p.precio = producto.precio;
            break;
        case '3':
            gotoxy(10, 8);
            printf("Ingrese el Stock del Producto a modificar: ");
            scanf("%d", &producto.stock);
            p.stock = producto.stock;
            break;
        }
        getch();
    } while (op != 27);
    return p;
}

void funcionModificarProducto(){
    int a, m, d;
    int * coordy = 6;
    int * incy = 2;
    stProducto aux, modif;

    gotoxy(10, 7);
    printf("Ingrese Fecha del Producto: ");
    do{
        gotoxy(10, 10);
        printf("A%co: ", 164);
        scanf("%d", &a);

        gotoxy(10, 12);
        printf("Mes: ");
        scanf("%d", &m);

        gotoxy(10, 14);
        printf("D%ca: ", 161);
        scanf("%d", &d);
    } while (!validaFecha(a, m, d));

    aux = buscaProductoFecha(a, m, d);

    system("cls");
    cabeceraProducto();
    muestraUnProducto(aux, &coordy, &incy);
    getch();
    system("cls");

    if (aux.idProducto >= 0){
        modif = modificaProducto(aux);
        modificaRegistroProducto(modif);
        gotoxy(10, 20);
        printf("Registro modificado");
    } else {
        gotoxy(10, 20);
        printf("La fecha es incorrecta. Ingrese nuevamente");
    }
}

float sumaTotalCompra_segunMes(stProducto p[], int v, int month) {
    int suma = 0;
    for(int i = 0; i < v; i++) {
        if(month == p[i].fecha.month) {
            suma += p[i].precio * p[i].stock;
        }
    }
    return suma;
}

float sumaTotalCompra_segunAnio(stProducto p[], int v, int year) {
    int suma = 0;
    for(int i = 0; i < v; i++) {
        if(year == p[i].fecha.year) {
            suma += p[i].precio * p[i].stock;
        }
    }
    return suma;
}

stProducto buscarMayorCompra (stProducto p[], int v) {
    int i = 0;
    stProducto mayor = p[i];
    while (i < v) {
        if((mayor.precio * mayor.stock) < (p[i].precio * p[i].stock)) {
            mayor = p[i];
        }
        i++;
    }
    return mayor;
}

stProducto buscarMenorCompra (stProducto p[], int v) {
    int i = 0;
    stProducto menor = p[i];
    while (i < v) {
        if((menor.precio * menor.stock) > (p[i].precio * p[i].stock)) {
            menor = p[i];
        }
        i++;
    }
    return menor;
}

void menuCompras(stProducto p[], int v, int dim) {
    char op;
    stProducto menor, mayor;
    int * coordy = 6;
    int * incy = 2;
    v = archToArrayProducto(ARPRODUCTO, p, dim);
    do {
        system("cls");
        contornoMenu();
        gotoxy(15, 7);
        printf("MENU DE COMPRAS");
        gotoxy(15, 10);
        printf("[ 01 ] - Mostrar Mayor Compra del A%co.", 164);
        gotoxy(15, 12);
        printf("[ 02 ] - Mostrar Menor Compra del A%co.", 164);
        gotoxy(15, 15);
        printf("Presione < ESC > para volver al menu principal de productos.");
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            mayor = buscarMayorCompra(p, v);
            cabeceraProducto();
            muestraUnProducto(mayor, &coordy, &incy);
            break;
        case '2':
            menor = buscarMenorCompra(p, v);
            cabeceraProducto();
            muestraUnProducto(menor, &coordy, &incy);
            break;
        }
        getch();
    } while(op != 27);
}


//******************************************************************************* MENU DE PRODUCTOS

void menuMostrarProducto(stProducto p[], int v, int dim) {
    char op;
    v = archToArrayProducto(ARPRODUCTO, p, dim);
    do {
        system("cls");
        contornoMenu();
        gotoxy(25, 7);
        printf("MENU DE MOSTRAR");
        gotoxy(15, 10);
        printf("[ 01 ] - Mostrar Productos");
        gotoxy(15, 12);
        printf("[ 02 ] - Mostrar Productos Ordenados por fecha");
        gotoxy(15, 15);
        printf("Presione < ESC > para salir.");
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            cabeceraProducto();
            muestraArregloProducto(p, v);
            break;
        case '2':
            ordenaSeleccionFecha(p, v);
            cabeceraProducto();
            muestraArregloProducto(p, v);
            break;
        }
        getch();
    } while(op != 27);
}

void menuPpalProductos(stProducto p[], int v, int dim) {
    char op;
    stProducto mayor;
    int * coordy = 6;
    int * incy = 2;
    do {
        system("cls");
        contornoMenu();
        gotoxy(25, 7);
        printf("MENU PRINCIPAL < PRODUCTOS >");
        gotoxy(15, 10);
        printf("[ 01 ] - Carga Productos seg%cn Cliente.", 163);
        gotoxy(15, 12);
        printf("[ 02 ] - Muestra Productos.");
        gotoxy(15, 14);
        printf("[ 03 ] - Modificar Productos.");
        gotoxy(15, 16);
        printf("[ 04 ] - Compras.");
        gotoxy(15, 19);
        printf("Presione < ESC > para salir.");
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            cargaProdcuto_SegunCliente();
            break;
        case '2':
            menuMostrarProducto(p, v, dim);
            break;
        case '3':
            funcionModificarProducto();
            break;
        case '4':
            menuCompras(p, v, dim);
            break;
        }
        getch();
    } while(op != 27);
}
