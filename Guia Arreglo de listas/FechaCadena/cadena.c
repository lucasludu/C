#include "cadena.h"

/*******************************************
 *  C[i] = L   U   C   A   S
 *  i      0   1   2   3   4
 *  C[i = 0] L --> Se elimina.
 *  C[i+1 = 1] U --> Pasa a estar en C[0].
 *******************************************/

 // EJERCICIO 1

/**************************************************************
 * \brief   Elimina el carácter ubicado en la posicion dada.
 * \param   Char c[].
 * \param   int Posicion.
 * \return  void
 **************************************************************/

void fStrDelPosChar(char c[], int pos){
    int v = strlen(c) - 1;
    int i;
    for(i = pos; i < v; i++){
        c[i] = c[i+1];
    }
    c[i] = '\0';
}

 // EJERCICIO 2

/*******************************************************************
 * \brief   Elimina espacios en blanco a la izquiera de la cadena.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrLTrim(char c[]){
    int flag = 0;
    int i = 0;
    int v = strlen(c);
    while(i<v && flag==0){
        if(isblank(c[i])){
            fStrDelPosChar(c, i);
            v--;
        } else {
            flag = 1;
        }
    }
}

 // EJERCICIO 3

/*******************************************************************
 * \brief   Elimina espacios en blanco a la derecha de la cadena.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrRTrim(char c[]){
    int flag = 0;
    int v = strlen(c);
    int i = v - 1;
    while(i>=0 && flag == 0){
        if(isblank(c[i])){
            c[i] = '\0';
        } else {
            flag = 1;
        }
        i--;
    }
}

 // EJERCICIO 4

/*******************************************************************
 * \brief   Elimina todos los espacios en blanco de la cadena.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrAllTrim(char c[]){
    int v = strlen(c);
    int i = v - 1;
    while(i >= 0){
        if(isblank(c[i])){
            fStrDelPosChar(c, i);
        }
        i--;
    }
}

 // EJERCICIO 5

/*******************************************************************
 * \brief   Elimina el contenido de la cadena.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrDelete(char c[]){
    c[0] = '\0';
}

 // EJERCICIO 6

/*******************************************************************
 * \brief   Convierte la cadena en mayuscula.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrToUpper(char c[]){
    int v = strlen(c);
    for(int i = 0; i < v; i++){
        c[i] = toupper(c[i]);
    }
}

 // EJERCICIO 7

/*******************************************************************
 * \brief   Convierte la cadena en minuscula.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrToLower(char c[]){
    int v = strlen(c);
    for(int i = 0; i < v; i++){
        c[i] = tolower(c[i]);
    }
}

 // EJERCICIO 8

/*******************************************************************
 * \brief   Convierte la la primera letra de la cadena en mayuscula.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

 /********************************************************
  * ISALPHA COMPRUEBA SI LA PRIMERA LETRA DE LA CADENA
  * ES DE CARACTER ALFAVETICA.
  ********************************************************/

void fStrToUpperFirst(char c[]){
    int v = strlen(c);
    if(v>0){
        c[0] = (isalpha(c[0]))?toupper(c[0]):c[0];
    }
}

 // EJERCICIO 9

/*******************************************************************
 * \brief   Convierte la primera letra de cada palabra en mayuscula.
 * \param   Char c[].
 * \return  void
 *******************************************************************/

void fStrToUpperAllFirstLetters(char c[]){
    fStrToUpperFirst(c);
    int v = strlen(c) - 1;
    for(int i = 0; i < v; i++){
        if(isblank(c[i])){
            c[i+1] = (isalpha(c[i+1]))?toupper(c[i+1]):c[i+1];
        }
    }
}

 // EJERCICIO 10

/*******************************************************************
 * \brief   Reemplaza la primer ocurrencia de un caracter dado por otro.
 * \param   Char c[].
 * \param   Char o.
 * \param   Char r.
 * \return  void
 *******************************************************************/

void fStrFirstCharReplace(char c[], char o, char r){
    int i = 0;
    int v = strlen(c);
    int flag = 0;
    while(i < v && flag == 0){
        if(c[i] == o){
            c[i] = r;
            flag = 1;
        }
        i++;
    }
}

 // EJERCICIO 11

/*******************************************************************
 * \brief   Reemplaza todas las ocurrencias de un caracter dado por otro.
 * \param   Char c[].
 * \param   Char o.
 * \param   Char r.
 * \return  void
 *******************************************************************/

void fStrAllCharReplace(char c[], char o, char r){
    int v = strlen(c);
    for(int i = 0; i < v; i++){
        c[i] = (c[i] == o)?r:c[i];
    }
}

 // EJERCICIO 12

/*******************************************************************
 * \brief   Busca un caracter en la cadena, retorna la posicion.
 * \param   Char c[].
 * \param   Char f.
 * \return  void
 *******************************************************************/

int fStrFindChar(char c[], char f){
    int i = 0;
    int v = strlen(c);
    int flag = -1;
    while(i<v && flag ==-1){
        if(c[i] == f){
            flag = i;
        }
        i++;
    }
    return flag;
}

 // EJERCICIO 13

/*******************************************************************
 * \brief   Elimina la primer ocurrencia de un char.
 * \param   Char c[].
 * \param   Char e.
 * \return  void
 *******************************************************************/

void fStrDelFirstChar(char c[], char e){
    int flag = 0;
    int i = 0;
    int v = strlen(c);
    while(i<v && flag == 0){
        if(c[i] == e){
            fStrDelPosChar(c, i);
            flag = 1;
        }
        i++;
    }
}

 // EJERCICIO 14

/*******************************************************************
 * \brief   Elimina todas las ocurrencias de un char.
 * \param   Char c[].
 * \param   Char e.
 * \return  void
 *******************************************************************/

void fStrDelAllChar(char c[], char e){
    int v = strlen(c);
    int i = 0;
    while(i < v){
        if(c[i] == e){
            fStrDelPosChar(c, i);
            v--;
        }
        i++;
    }
}

 // EJERCICIO 15

/*******************************************************************
 * \brief   Reemplaza un caracter en una posicion dada por otro.
 * \param   Char c[].
 * \param   Char r.
 * \param   Int pos.
 * \return  void
 *******************************************************************/

void fStrReplace(char c[], char r, int pos){
    c[pos] = r;
}

void fStrStr(char c[], char d[], int desde, int cant){
    int i;
    if(strlen(c)>=(desde+cant)){
        for(i = desde; i <(desde+cant)-1; i++){
            d[i-desde] = c[i];
        }
        d[i-desde+1] = '\0';
    }
}
