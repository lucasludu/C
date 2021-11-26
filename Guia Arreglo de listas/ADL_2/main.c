#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "persona.h"
#include "listaCliente.h"
#include "nodoCaja.h"

#define ESC 27
#define DIM 50

stNodoCaja * ingresarListasCajas(stNodoCaja * lista);

int main() {

    stNodoCaja * listaCajaCliente = inicListaCaja();
    listaCajaCliente = ingresarListasCajas(listaCajaCliente);
    muestraListaCajaClientes(listaCajaCliente);

    return 0;
}

stNodoCaja * ingresarListasCajas(stNodoCaja * lista) {
    char continuar = 's';
    stPersona p;
    int nroCaja;

    do {
        system("cls");
        p = cargaUnaPersona();

        printf("\n\t ¿A que numero de caja desea ingresar el cliente?");
        fflush(stdin);
        scanf("%d", &nroCaja);

        stNodo * cliente = crearNodoCliente(p);
        lista = alta(lista, cliente, nroCaja);

        printf("\n\n\t\t\t Desea continuar? [ S | N ]");
        continuar = getch();
        system("cls");
    } while(continuar == 's');
    return lista;
}
