#include "registro.h"

void getNombre(char n[]) {
    char nombres[][20] = {"Amalia","Juan","Carolina","Antonio","Claribel","Fernando","Fernanda","Anibal","Fernando","Roberto",
                          "Camila","Anastasio","Artura","Arturo","Maria","Daiana","Tamara","Adolfo","Adolfa","Pedro","Alfredo",
                          "Alfreda","Mauro","Carlitos","Benicio","Benicia","Ildefonso","Ornechu","Cuchuflito","Genga",
                          "Remilgo"
                         };

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*30))]);
}

void getApellido(char a[]) {
    char apellidos[][30] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "Vaccari", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "Zunino", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "Ortega", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"
                           };

    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*30))]);
}

void getDNI(char dni[]) {
    itoa((randomRango(10000000,50000000)),dni,10);
}

int randomRango(int min, int max) {
    return rand() %( max - min) + min;
}


/*********************************************************************************************************************************************/

/**
 * \brief CARGA UN REGISTRO EN FORMA MANUAL
 * \param SIN PARAMETRO
 * \return REGISTRO
 */


stRegistro cargaUnRegistroManual() {
    stRegistro r;

    do {
        printf("\n\t Nombre: ");
        fflush(stdin);
        gets(r.nombre);
    } while(strlen(r.nombre) == 0);

    do {
        printf("\n\t Apellido: ");
        fflush(stdin);
        gets(r.apellido);
    } while(strlen(r.apellido) == 0);

    printf("\n\t DNI: ");
    fflush(stdin);
    gets(r.dni);

    do {
        printf("\n\t Edad: ");
        gets(r.edad);
    } while(r.edad < 0 && r.edad > 99);

    return r;
}

/**
 * \brief CARGA UN REGISTRO EN FORMA RANDOM
 * \param SIN PARAMETRO
 * \return REGISTRO
 */

stRegistro cargaUnRegistroRandom() {
    stRegistro r;

    getNombre(r.nombre);
    getApellido(r.apellido);
    getDNI(r.dni);
    r.edad = randomRango(0, 99);

    return r;
}

/**
 * \brief MUESTRA UN REGISTRO
 * \param REGISTRO
 * \return VOID
 */

void muestraUnRegistro(stRegistro r) {
    printf("\n\t Nombre......: %s", r.nombre);
    printf("\n\t Apellido....: %s", r.apellido);
    printf("\n\t Dni.........: %s", r.dni);
    printf("\n\t Edad........: %d", r.edad);
    printf("\n-----------------------------------------------------\n");
}













