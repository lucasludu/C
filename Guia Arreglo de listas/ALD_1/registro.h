#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define arRegistro "registroArchivo.dat"

typedef struct {
   int nota;
   int legajo;
   char apeNom[40];
   char materia[40];
   int idMateria;
} stRegistroArchivo;

stRegistroArchivo ingresarUnRegistro();
void agregarRegistro(stRegistroArchivo r);
void ingresarRegistros();

void mostrarUnRegistro(stRegistroArchivo r);
void mostrarRegistros(char archivo[]);

void getNombre(char n[]);
void getApellido(char a[]);
void getApellidoYNombre(char an[]);
int getMateria(char m[]);
int getLegajo();
int getNota();
stRegistroArchivo cargoRegistroArchivoRandom();
void guardaRegistroArchivo(char archivo[], stRegistroArchivo r);
void generaArchivoRandom(int cantidad);
int cuentaRegistros(char nombreArchivo[], int tamStruct);


#endif // REGISTRO_H_INCLUDED
