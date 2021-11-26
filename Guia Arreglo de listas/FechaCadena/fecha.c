#include "fecha.h"

const char * monthsLarge[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
const char * dayLarge[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

void fGetNow(char date[]){
    time_t tiempo = time(0);
    struct tm * tLocal = localtime(&tiempo);
    strftime(date, 128, "%Y - %m - %d - %w %H:%M:%S", tLocal);
}

int fGetAnioLarge(char date[]){
    char anio[5];
    int anioNumber = 0;
    int i;
    if(strlen(date)>0){
        for(i = 0; i < 5; i++){
            anio[i] = date[i];
        }
        anio[i+1] = '\0';
        anioNumber = atoi(anio);
    }
    return anioNumber;
}

int fGetAnioShort(char date[]){

}

int fGetMonthNumber(char date[]){

}

void fGetMonthLarge(char date[],char month[]){

}

void fGetMonthShort(char date[],char month[]){

}

int fGetDayNumber(char date[]){

}

int fGetDayOfWeek(char date[]){

}

void fGetDayLarge(char date[],char day[]){

}

void fGetDayShort(char date[],char day[]){

}

int fGetHour(char date[]){

}

int fGetMinute(char date[]){

}
