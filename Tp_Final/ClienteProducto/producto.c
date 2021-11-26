#include "producto.h"

stProducto cargaUnProducto(int id){
    stProducto p;

    p.idCliente = id;

    do {
        printf("\n\t A%co: ", 164);
        scanf("%d", &p.fecha.year);

        printf("\n\t Mes: ");
        scanf("%d", &p.fecha.month);

        printf("\n\t D%ca: ", 161);
        scanf("%d", &p.fecha.day);
    } while (!validaFecha(p.fecha.year, p.fecha.month, p.fecha.day));

    printf("\n\t Producto: ");
    fflush(stdin);
    gets(p.producto);

    printf("\n\t Precio: ");
    fflush(stdin);
    scanf("%f", &p.precio);

    printf("\n\t Stock: ");
    scanf("%d", &p.stock);

    return p;
}

void cabeceraProducto() {
    gotoxy(35, 1);
    printf("P R O D U C T O S");
    gotoxy(5, 4);
    printf("ID Cliente");
    gotoxy(18, 4);
    printf("ID Producto");
    gotoxy(35, 4);
    printf("Fecha");
    gotoxy(48, 4);
    printf("Producto");
    gotoxy(62, 4);
    printf("Precio");
    gotoxy(72, 4);
    printf("Stock");
    gotoxy(80, 4);
    printf("Sub-Total");

    gotoxy(33, 2);
    for(int i = 0; i < 21; i++) {
        printf("%c", 196);
    }

    gotoxy(0, 5);
    for(int i = 0; i < 94; i++) {
        printf("%c", 205);
    }
}

void muestraUnProducto(stProducto p, int * coordy, int * incy) {
    gotoxy(9, *coordy);
    printf("%d", p.idCliente);
    gotoxy(23, *coordy);
    printf("%d", p.idProducto);
    gotoxy(32, *coordy);
    printf("%4d/%2d/%2d", p.fecha.year, p.fecha.month, p.fecha.day);
    gotoxy(48, *coordy);
    printf("%s", p.producto);
    gotoxy(62, *coordy);
    printf("$%.2f", p.precio);
    gotoxy(73, *coordy);
    printf("%d u", p.stock);
    gotoxy(81, *coordy);
    printf("$%4.2f", (p.precio*p.stock));
    (*coordy) = (*coordy) + (*incy);
}




