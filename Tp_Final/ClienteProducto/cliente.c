#include "cliente.h"

/**
 * \brief Carga un cliente
 * \param Sin parametro
 * \return Un cliente
 */


stCliente cargaUnCliente() {
    stCliente c;
    int existe = 0;

    c.id = buscaUltimoID() + 1;
    printf("\n\t ID N%c: %d", 167, c.id);

    do {
        printf("\n\t DNI:\t");
        fflush(stdin);
        gets(c.dni);
        while(strlen(c.dni) != 8 || strlen(c.dni) > 9) {
            system("cls");
            printf("\n\t Ingresar DNI entre 8 y 9 caracteres, intente de nuevo: ");
            fflush(stdin);
            gets(c.dni);
            system("cls");
        }
        existe = existeDNICliente(c.dni);
    } while(existe);

    do {
        printf("\n\t Nombre:\t");
        fflush(stdin);
        gets(c.nombre);
    } while(strlen(c.nombre) == 0);

    do {
        printf("\n\t Apellido:\t");
        fflush(stdin);
        gets(c.apellido);
    } while(strlen(c.apellido) == 0);

    printf("\n\t Telefono:\t");
    fflush(stdin);
    gets(c.telefono);

    printf("\n\t Domicilio:\t");
    fflush(stdin);
    gets(c.domicilio);

    c.baja = 0;

    return c;
}

/**< Cabecera del menu mostrar */

void cabeceraClientes() {
    gotoxy(42, 1);
    printf("C L I E N T E S");
    gotoxy(4, 4);
    printf("ID");
    gotoxy(12, 4);
    printf("DNI");
    gotoxy(25, 4);
    printf("Nombre");
    gotoxy(40, 4);
    printf("Apellido");
    gotoxy(55, 4);
    printf("Telefono");
    gotoxy(72, 4);
    printf("Domicilio");
    gotoxy(91, 4);
    printf("Baja");

    gotoxy(40, 2);
    for(int i = 0; i < 19; i++) {
        printf("%c", 196);
    }

    gotoxy(0, 5);
    for(int i = 0; i < 100; i++) {
        printf("%c", 205);
    }
}

/**
 * \brief Muestra un cliente
 * \param Cliente
 * \param Puntero int(coord Y)
 * \param Puntero int(inc Y)
 * \return Un cliente
 */

void muestraUnCliente(stCliente c, int *coordY, int *incY) {
    gotoxy(4,*coordY);
    printf("%2d", c.id);
    gotoxy(10,*coordY);
    printf("%s", c.dni);
    gotoxy(24,*coordY);
    printf("%s", c.nombre);
    gotoxy(40,*coordY);
    printf("%s", c.apellido);
    gotoxy(55,*coordY);
    printf("%s", c.telefono);
    gotoxy(70,*coordY);
    printf("%s", c.domicilio);
    gotoxy(92,*coordY);
    printf("%s", (c.baja)?"SI":"NO");
    (*coordY) = (*coordY) + (*incY);
}
