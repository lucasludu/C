#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <malloc.h>

#include "utilidades.h"
#include "cliente.h"
#include "variosClientes.h"
#include "producto.h"
#include "variosProductos.h"

#define ARCLIENTE "clientes.dat"
#define ARPRODUCTO "productos.dat"

#define ESC 27
#define DIM_CLI 50
#define DIM_PROD 50

int main() {
    char op;
    stCliente clientes[DIM_CLI];
    int vCliente = 0;
    stProducto productos[DIM_PROD];
    int vProd = 0;
    SetColorAndBackground(30, 1);
    do {
        system("cls");
        menuPrincipal();
        op = getch();
        system("cls");
        switch(op) {
        case '1':
            menuPpalClientes(clientes, vCliente, DIM_CLI);
            break;
        case '2':
            menuPpalProductos(productos, vProd, DIM_PROD);
            break;
        }
        getch();
    } while(op != 27);
    return 0;
}

void menuPrincipal() {
    contornoMenu();
    gotoxy(25, 7);
    printf("MENU PRINCIPAL");
    gotoxy(15, 10);
    printf("[ 01 ] - Men%c de Clientes.", 163);
    gotoxy(15, 12);    printf("[ 02 ] - Men%c de productos.", 163);
    gotoxy(25, 15);
    printf("[ ESC ] - SALIR DEL PROGRAMA.");
}
