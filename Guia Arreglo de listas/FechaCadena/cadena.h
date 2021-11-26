#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void fStrDelPosChar(char c[], int pos);
void fStrLTrim(char c[]);
void fStrRTrim(char c[]);
void fStrAllTrim(char c[]);
void fStrDelete(char c[]);
void fStrToUpper(char c[]);
void fStrToLower(char c[]);
void fStrToUpperFirst(char c[]);
void fStrToUpperAllFirstLetters(char c[]);
void fStrFirstCharReplace(char c[], char o, char r);
void fStrAllCharReplace(char c[], char o, char r);
int fStrFindChar(char c[], char f);
void fStrDelFirstChar(char c[], char e);
void fStrDelAllChar(char c[], char e);
void fStrReplace(char c[], char r, int pos);


#endif // CADENA_H_INCLUDED
