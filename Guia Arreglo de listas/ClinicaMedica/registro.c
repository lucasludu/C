#include "registro.h"
//Ejercicio 1

                /**< FUNCIONES NODO REGISTRO */

nodoRegistro * inicNodoRegistro() {
    return NULL;
}

nodoRegistro * crearNodoRegistro(stRegistro data) {
    nodoRegistro * nuevo = (nodoRegistro*) malloc(sizeof(nodoRegistro));
    nuevo->data = data;
    nuevo->sig = NULL;
    return nuevo;
}

nodoRegistro * agregarPpioNodoRegistro(nodoRegistro * lista, nodoRegistro * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

                /**< FUNCIONES NODO CELDA */

nodoCelda * inicNodoCelda() {
    return NULL;
}

nodoCelda * crearNodoCelda(celda data) {
    nodoCelda * nuevo = (nodoCelda*) malloc(sizeof(nodoCelda));
    nuevo->data = data;
    nuevo->sig = NULL;
    return nuevo;
}

nodoCelda * agregarPpioNodoCelda(nodoCelda * lista, nodoCelda * nuevo) {
    if(!lista) {
        lista = nuevo;
    } else {
        nuevo->sig = lista;
        lista = nuevo;
    }
    return lista;
}

nodoCelda * buscarNodoCelda(nodoCelda * lista, char especialidadMedica[30]) {
    nodoCelda * aux = lista;
    if(aux) {
        while(aux && strcmpi(aux->data.dato.especialidadMedica, especialidadMedica) != 0) {
            aux = aux->sig;
        }
    }
    return aux;
}

//Funciones Lista de Listas

nodoCelda * agregarCelda(nodoCelda * lista, stEspecialidad especialidad) {
    celda data;
    data.dato = especialidad;
    data.lista = NULL;
    nodoCelda * aux = crearNodoCelda(data);
    lista = agregarPpioNodoCelda(lista, aux);
    return lista;
}


nodoCelda * agregarRegistro(nodoCelda * lista, stEspecialidad especialidad, stRegistro data) {
    nodoRegistro * aux = crearNodoRegistro(data);
    nodoCelda * pos = buscarNodoCelda(lista, especialidad.especialidadMedica);
    if(!pos) {
        lista = agregarCelda(lista, especialidad);
        pos = lista;
    }
    pos->data.lista = agregarPpioNodoRegistro(pos->data.lista, aux);
    return lista;
}

nodoCelda * cargarCeldasDesdeArchivo(nodoCelda * lista, char file[]) {
    FILE * archi = NULL;
    archi = fopen(file, "rb");
    if(archi != NULL) {
        stRegistroMedico aux;
        while(fread(&aux, sizeof(stRegistroMedico), 1, archi) > 0) {
            stRegistro data;
            stEspecialidad esp;
            strcpy(data.nombrePaciente, aux.nombrePaciente);
            strcpy(data.apellidoPaciente, aux.apellidoPaciente);
            strcpy(data.nombreDoctor, aux.nombreDoctor);
            strcpy(data.diagnostico, aux.diagnostico);
            strcpy(data.fechaAtencion, aux.fechaAtencion);
            data.idPaciente = aux.idPaciente;
            data.idRegistro = aux.idRegistro;
            esp.idEspecialidad = aux.idEspecialidad;
            strcpy(esp.especialidadMedica, aux.especialidadMedica);
            lista = agregarRegistro(lista, esp, data);
        }
    }
    fclose(archi);
    return lista;
}

//Ejercicio 3

void mostrarRegistro(stRegistro data) {
    printf("\nID Registro: %i\n", data.idRegistro);
    printf("ID Paciente: %i\n", data.idPaciente);
    printf("Nombre Paciente: %s\n", data.nombrePaciente);
    printf("Apellido Paciente: %s\n", data.apellidoPaciente);
    printf("Diagnostico: %s\n", data.diagnostico);
    printf("Fecha de Atencion: %s\n", data.fechaAtencion);
    printf("Nombre Doctor: %s\n", data.nombreDoctor);
}

void mostrarEspecialidad(stEspecialidad data) {
    printf("\n\t ID Especialidad Medica....: %d", data.idEspecialidad);
    printf("\n\t Especialidad Medica.......: %s\n", data.especialidadMedica);
}

void mostrarCelda(celda data) {
    mostrarEspecialidad(data.dato);
    nodoRegistro * aux = data.lista;
    while(aux) {
        mostrarRegistro(aux->data);
        aux = aux->sig;
    }
}

void mostrarCeldas(nodoCelda * lista) {
    nodoCelda * aux = lista;
    while(aux) {
        mostrarCelda(aux->data);
        aux = aux->sig;
    }
}

int existeEspecialidad(nodoCelda * lista, char especialidadMedica[30]) {
    int rta = 0;
    nodoCelda * aux = buscarNodoCelda(lista, especialidadMedica);
    if(aux) {
        rta = 1;
    }
    return rta;
}

//Ejercicio 4

nodoCelda * cargarRegistros(nodoCelda * lista) {
    char control;
    stEspecialidad especialidad;
    int idEspecialidad;
    char especialidadMedica[30];
    stRegistro data;

    do {
        printf("Ingrese el nombre de la especialidad: ");
        fflush(stdin);
        gets(especialidadMedica);

        if(!existeEspecialidad(lista, especialidadMedica)) {
            printf("Ingrese el ID de la especialidad: ");
            scanf("%d", &idEspecialidad);
        } else {
            idEspecialidad = -1;
        }
        especialidad.idEspecialidad = idEspecialidad;
        strcpy(especialidad.especialidadMedica, especialidadMedica);

        printf("Ingrese el ID del registro: ");
        scanf("%i", &data.idRegistro);
        printf("Ingrese el ID del paciente: ");
        scanf("%i", &data.idPaciente);
        printf("Ingrese el nombre del paciente: ");
        fflush(stdin);
        gets(data.nombrePaciente);
        printf("Ingrese el apellido del paciente: ");
        fflush(stdin);
        gets(data.apellidoPaciente);
        printf("Ingrese el diagnostico del paciente: ");
        fflush(stdin);
        gets(data.diagnostico);
        printf("Ingrese la fecha de atencion (AAAA-MM-DD): ");
        fflush(stdin);
        gets(data.fechaAtencion);
        printf("Ingrese el nombre del doctor: ");
        fflush(stdin);
        gets(data.nombreDoctor);

        lista = agregarRegistro(lista, especialidad, data);

        printf("Quiere ingresar otro registro? s/n\n");
        do {
            control = getch();
        } while(control != 's' && control != 'n');

    } while(control == 's');
    return lista;
}


//Ejercicio 5

nodoRegistro * buscarPorNombreYApellido(nodoRegistro * lista, char nombre[], char apellido[]) {
    nodoRegistro * aux = lista;
    if(aux) {
        while(aux && (strcmpi(aux->data.apellidoPaciente, apellido) != 0 && strcmpi(aux->data.nombrePaciente, nombre) != 0)) {
            aux = aux->sig;
        }
    }
    return aux;

}

int seHaAtendido(nodoCelda * lista, char nombre[], char apellido[], char especialidadMedica[]) {
    int rta = 0;
    nodoCelda * pos = buscarNodoCelda(lista, especialidadMedica);
    if(pos) {
        nodoRegistro * buscado = buscarPorNombreYApellido(pos->data.lista, nombre, apellido);
        if(buscado) {
            rta = 1;
        }
    }
    return rta;
}

void subProgramaEj5(nodoCelda * lista) {
    char especialidadMedica[30];
    char nombre[20];
    char apellido[20];
    printf("Ingrese el nombre de la especialidad\n");
    fflush(stdin);
    gets(especialidadMedica);
    printf("Ingrese el nombre del paciente\n");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese el apellido del paciente\n");
    fflush(stdin);
    gets(apellido);

    if(seHaAtendido(lista, nombre, apellido, especialidadMedica)) {
        printf("Si, %s %s se ha atendido en %s\n", nombre, apellido, especialidadMedica);
    } else {
        printf("No, %s %s no se ha atendido en %s\n", nombre, apellido, especialidadMedica);
    }
}

//Ejercicio 6

int contarAtenciones(nodoRegistro * lista) {
    int rta = 0;
    nodoRegistro * aux = lista;

    if(aux) {
        while(aux) {
            rta += 1;
            aux = aux->sig;
        }
    }
    return rta;
}

nodoCelda * masAtenciones(nodoCelda * lista) {
    nodoCelda * aux = lista;
    nodoCelda * mayor = aux;
    int cant = contarAtenciones(aux->data.lista);
    aux = aux->sig;
    while(aux) {
        int atenciones = contarAtenciones(aux->data.lista);
        if(atenciones > cant) {
            cant = atenciones;
            mayor = aux;
        }
        aux = aux->sig;
    }
    return mayor;
}

void subProgramaEj6(nodoCelda * lista) {
    nodoCelda * aux = masAtenciones(lista);

    printf("La especialidad con mas atenciones es: %s\n", aux->data.dato.especialidadMedica);
    printf("Tiene una cantidad de %i atenciones\n", contarAtenciones(aux->data.lista));
}

//Ejercicio 7

void guardarEspecialidadEnArchivo(char file[], nodoCelda * lista, char especialidadMedica[]) {
        stRegistroMedico aGuardar;
        nodoCelda * aux = buscarNodoCelda(lista, especialidadMedica);
        aGuardar.idEspecialidad = aux->data.dato.idEspecialidad;
        strcpy(aGuardar.especialidadMedica, aux->data.dato.especialidadMedica);

        nodoRegistro * registros = aux->data.lista;

        FILE * archi = NULL;
        archi = fopen(file, "ab");

        if(archi != NULL) {
            while(registros) {
                aGuardar.idRegistro = registros->data.idRegistro;
                aGuardar.idPaciente = registros->data.idPaciente;
                strcpy(aGuardar.nombrePaciente, registros->data.nombrePaciente);
                strcpy(aGuardar.apellidoPaciente, registros->data.apellidoPaciente);
                strcpy(aGuardar.diagnostico, registros->data.diagnostico);
                strcpy(aGuardar.fechaAtencion, registros->data.fechaAtencion);
                strcpy(aGuardar.nombreDoctor, registros->data.nombreDoctor);

                fwrite(&aGuardar, sizeof(stRegistroMedico), 1, archi);
                registros = registros->sig;
            }
        }
        fclose(archi);
}

void subProgramaEj7(nodoCelda * lista) {
    char especialidadMedica[30];
    printf("Ingrese el nombre de la especialidad medica a guardar\n");
    fflush(stdin);
    gets(especialidadMedica);
    if(existeEspecialidad(lista, especialidadMedica)) {
        char nombreArchi[30];
        strcpy(nombreArchi, especialidadMedica);
        strcat(nombreArchi, ".dat");
        guardarEspecialidadEnArchivo(nombreArchi, lista, especialidadMedica);
    } else {
        printf("No existe esa especialidad\n");
    }
}

