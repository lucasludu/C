#ifndef ADLUSUARIO_H_INCLUDED
#define ADLUSUARIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include "contenido.h"
#include "listaContenido.h"
#include "arbolContenido.h"

#define ARCHIVO_USUARIO "usuarios.dat"
#define ARCHIVO_CONTENIDO "contenidos.dat"
#define ARCHIVO_CONT_FAVORITO "contenidoFavorito.dat"

typedef struct {
    stUsuario usr;
    nodoListaContenido * listaContenido;
} stCelda;

typedef struct {
    int idFavorito;
    int idUsuario;
    int idContenido;
} stFavorito;

int buscaPosUsuario(stCelda usuarios[], stUsuario user, int v);
int agregar(stCelda usuarios[], stUsuario user, int v);
int alta (stCelda usuarios[], stUsuario user, stContenido contenido, int v);
int buscarUsuario(stCelda usuarios[], int val, int idUsuario);
int esAdministrador(int idUsuario, stCelda usuarios[], int val);
void ADLToArchivoUsuarios(stCelda usuarios[], int val, char archivo[]);
int archivoUsuariosToADL(stCelda usuarios[], int val, char archivo[]);
int validaUsuario(stCelda usuarios[], int val, char nombreUsuario[]);
int bajaUsuario(int idUsuario, stCelda usuarios[], int val);
void modificarUsuario(stFavorito contFav[], int val_cf, int idUsuario, int acceso, stCelda usuarios[], int val, nodoArbolContenido * arbol);
int consultaUsuarios(int tipo, char filtro[], int filtro2, stUsuario muestra[], int dim, stCelda usuarios[], int val);
void listarUsuarios(int tipo, stUsuario muestra[], int dim, stCelda usuarios[], int val);
void limpiarArregloDeListas(stCelda usuarios[], int val);
void loginUsuario(stFavorito contFav[], int val_cf, stCelda usuarios[], stUsuario user, stContenido contenido, int val, nodoArbolContenido * arbol);




#endif // ADLUSUARIO_H_INCLUDED
