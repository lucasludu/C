#include "registro.h"

/// funcion que asigna en la variable recibida un nombre al azar
int getEspecie(char e[]){
    char especies[][10] = {"Mamifero","Ave","Reptil","Pez"};
    int idEspecie = randomRango(0, sizeof(especies)/(sizeof(char)*10));
    strcpy(e,especies[idEspecie]);
    return idEspecie;
}

/// funcion que asigna en la variable recibida un apellido al azar
void getAnimal(char a[], int idEspecie){
    char mamiferos[][20] = {"Canguro", "Mono", "Antilope", "Vaca", "Caballo", "Cerdo", "Oveja", "Cabra", "Leon", "Jirafa",
                            "Tapir", "Cebra", "Burro", "Gato", "Perro", "Mangosta", "Leopardo", "Guepardo", "Jirafa", "Okapi",
                            "Camello", "Llama", "Pacari", "Hipopotamo", "Elefante", "Zorro", "Panda", "Oso", "Conejo", "Liebre" };
    char aves[][20] = {"Cisne", "Pato", "Suiriri", "Anade", "Gorrion", "Aguila", "Condor", "Paloma", "Gaviota", "Ganzo"};
    char reptiles[][20] = {"Cobra", "Caiman", "Iguana", "Dragon", "Camaleon", "Vibora", "Tortuga", "Cocodrilo", "Gecko", "Culebra"};
    char peces[][20] = {"Tiburon", "Raya", "Arenque", "Carpa", "Anchoa", "Barracuda", "Salmon", "Anguila", "Morena", "Corvina"};

    switch(idEspecie){
        case 0:
            strcpy(a,mamiferos[randomRango(0,sizeof(mamiferos)/(sizeof(char)*20))]);
            break;
        case 1:
            strcpy(a,aves[randomRango(0,sizeof(aves)/(sizeof(char)*20))]);
            break;
        case 2:
            strcpy(a,reptiles[randomRango(0,sizeof(reptiles)/(sizeof(char)*20))]);
            break;
        case 3:
            strcpy(a,peces[randomRango(0,sizeof(peces)/(sizeof(char)*20))]);
            break;
        default:
            strcpy(a,"Error");
    }
}

/// Funcion que retorna un numero de habitat de 0 a 3 al azar
int getHabitat(int idEspecie){
    return ((idEspecie)>=0&&(idEspecie<=2))?randomRango(0,3):3;
}


/// Funcion que retorna cantidad de animales
int getCantidad(){
    return randomRango(0,8000);
}

/// funcion que asigna en la variable recibida el tipo correspondiente de habitat
void getHabitatChar(int n, char h[]){
    switch(n){
        case 0:
            strcpy(h,"Selva");
            break;
        case 1:
            strcpy(h,"Savana");
            break;
        case 2:
            strcpy(h,"Bosque");
            break;
        case 3:
            strcpy(h,"Mar");
            break;
        default:
            strcpy(h,"Error");
    }
}

/************************************************************************************************************************************************************************/
/************************************************************************************************************************************************************************/

stRegistro cargaUnRegistroManual(){
    stRegistro r;

    do{
        printf("\n\tAnimal: ");
        fflush(stdin);
        gets(r.animal);
    } while(strlen(r.animal)==0);

    printf("\n\tCantidad: ");
    scanf("%d", &r.cantidad);

    do{
        printf("\n\tID Especie: ");
        scanf("%d", &r.idEspecie);
    }while(r.idEspecie>0);

    do{
        printf("\n\tEspecie: ");
        fflush(stdin);
        gets(r.especie);
    }while(strlen(r.especie)==0);

    do{
        printf("\n\tHabitat: ");
        scanf("%d", &r.habitat);
    }while(r.habitat>0&&r.habitat<3);

    return r;
}

stRegistro cargaUnRegistroRandom(){
    stRegistro r;
    r.idEspecie = getEspecie(r.especie);
    getAnimal(r.animal, r.idEspecie);
    r.habitat = getHabitat(r.idEspecie);
    r.cantidad = getCantidad();
    return r;
}

void muestraUnRegistro(stRegistro r){
    char habitat[10];
    getHabitatChar(r.habitat, habitat);
    printf("\n\tAnimal..........: %s", r.animal);
    printf("\n\tCantidad........: %d", r.cantidad);
    printf("\n\tID Especie......: %d", r.idEspecie);
    printf("\n\tEspecie.........: %s", r.especie);
    printf("\n\tHabitat.........: %d - %s", r.habitat, habitat);
    replicante(205, 70);
}
