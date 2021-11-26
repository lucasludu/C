#include "persona.h"

stPersona cargaUnaPersona() {
    stPersona p;

    do {
        printf("\n\t Nro de Cliente: ");
        scanf("%d", &p.nroCliente);
    } while(p.nroCliente <= 0);

    do {
        printf("\n\t Nombre: ");
        fflush(stdin);
        gets(p.nombre);
    } while(strlen(p.nombre) == 0);

    do {
        printf("\n\t Cantidad de Prodcutos: ");
        scanf("%d", &p.cantProductos);
    } while(p.cantProductos <= 0);

    return p;
}

void muestraPersona(stPersona p) {
    printf("\n\t Nro de Cliente.............: %d", p.nroCliente);
    printf("\n\t Nombre.....................: %s", p.nombre);
    printf("\n\t Cantidad de Productos......: %d", p.cantProductos);
    printf("\n------------------------------------------------\n");
}
