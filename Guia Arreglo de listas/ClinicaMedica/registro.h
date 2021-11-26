#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    int idRegistro;
    int idPaciente;
    int idEspecialidad;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
}stRegistroMedico;

typedef struct {
    int idRegistro;
    int idPaciente;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char nombreDoctor[30];
}stRegistro;

typedef struct {
    int idEspecialidad;
    char especialidadMedica[30];
}stEspecialidad;

typedef struct _nodoRegistro {
    stRegistro data;
    struct _nodoRegistro * sig;
}nodoRegistro;

typedef struct {
    stEspecialidad dato;
    nodoRegistro * lista;
}celda;

typedef struct _nodoCelda {
    celda data;
    struct _nodoCelda * sig;
}nodoCelda;

//Funciones nodoRegistro
nodoRegistro * inicNodoRegistro();
nodoRegistro * crearNodoRegistro(stRegistro data);
nodoRegistro * agregarPpioNodoRegistro(nodoRegistro * lista, nodoRegistro * nuevo);
//Funciones nodoCelda
nodoCelda * inicNodoCelda();
nodoCelda * crearNodoCelda(celda data);
nodoCelda * agregarPpioNodoCelda(nodoCelda * lista, nodoCelda * nuevo);
//Funciones Lista de Listas
nodoCelda * cargarRegistros(nodoCelda * lista);
nodoCelda * agregarRegistro(nodoCelda * lista, stEspecialidad especialidad, stRegistro data);
nodoCelda * agregarCelda(nodoCelda * lista, stEspecialidad especialidad);
nodoCelda * cargarCeldasDesdeArchivo(nodoCelda * lista, char file[]);
void mostrarRegistro(stRegistro data);
void mostrarEspecialidad(stEspecialidad data);
void mostrarCelda(celda data);
void mostrarCeldas(nodoCelda * lista);
int existeEspecialidad(nodoCelda * lista, char especialidadMedica[30]);
nodoRegistro * buscarPorNombreYApellido(nodoRegistro * lista, char nombre[], char apellido[]);
int seHaAtendido(nodoCelda * lista, char nombre[], char apellido[], char especialidadMedica[]);
void subProgramaEj5(nodoCelda * lista);
int contarAtenciones(nodoRegistro * lista);
nodoCelda * masAtenciones(nodoCelda * lista);
void subProgramaEj6(nodoCelda * lista);
void guardarEspecialidadEnArchivo(char file[], nodoCelda * lista, char especialidadMedica[]);
void subProgramaEj7(nodoCelda * lista);

//Elegi una estructura compuesta de Lista de Listas, ya que se van a poder agregar nuevas especialidades, y no debería haber limite
//de especialidades, si hubiera sido el caso de que hubiera limite podría haber hecho un arreglo de listas

//Intente comentar lo más posible los incisos pero no me quedó más tiempo para comentar y algunas funciones no son propias
//de cada inciso, por lo que se me dificultaba poner los comentarios justos, aun asi esta bastante entendible todo, saludos!



#endif // REGISTRO_H_INCLUDED
