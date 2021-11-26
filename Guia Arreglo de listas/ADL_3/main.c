#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define ESC 27
#define DIM 50

#define AR_ANIMALES "animales.dat"
#include "Estructuras.h"
#include "registro.h"
#include "variosRegistros.h"
#include "arbol.h"
#include "adl.h"

int main() {
//    cargaArchivoRandom(20);
    muestraArchivo(AR_ANIMALES);
    return 0;
}
