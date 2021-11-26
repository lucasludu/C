#include "utilidades.h"
#include "time.h"
#include "windows.h"

int randomRango(int a, int b){
    return rand() % (b-a+1)+a;
}

void replicante(char c, int n){
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%c",c);
    }
    printf("\n");
}

void cargando(){
    printf("\nCargando: ");
    for(int i = 0; i < 10; i++){
        Sleep(500);
        printf("%c", 219);
    }
    printf("\n");
}

void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
         wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
         SetConsoleTextAttribute(hStdOut, wColor);
    }
}


void SetColorAndBackground(int ForgC, int BackC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
