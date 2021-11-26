#include "adlUsuario.h"

int buscaPosUsuario(stCelda usuarios[], stUsuario user, int v) {
    int rta = -1;
    int i = 0;
    while(i < v && rta == -1) {
        if(strcmp(usuarios[i].usr.username, user.username) == 0) {
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregar(stCelda usuarios[], stUsuario user, int v) {
    usuarios[v].usr = user;
    usuarios[v].listaContenido = inicLista();
    v++;
    return v;
}

int alta (stCelda usuarios[], stUsuario user, stContenido contenido, int v) {
    nodoListaContenido * aux = crearNodoListaContenido(contenido);
    user = cargaUsuario();
    int pos = buscaPosUsuario(usuarios, user, v);
    if(pos == -1) {
        v = agregar(usuarios, user, v);
        pos = v - 1;
    }
    usuarios[pos].listaContenido = insertarContenidoFinal(usuarios[pos].listaContenido, aux);
    ADLToArchivoUsuarios(usuarios, v, ARCHIVO_USUARIO);
    encabezado("REGISTRO EXITOSO", 0);
    gotoxy(2, 7);
    printf("Tu cuenta ha sido registrada exitosamente. Por favor, inicia sesion...");
    system("pause");
    return v;
}


/**
 * \brief   SE BUSCA EL USUARIO POR ID
 * \param   ARREGLO USUARIO
 * \param   VALIDOS
 * \param   ID USUARIO
 * \return  ( 1 | 0 )
 */

int buscarUsuario(stCelda usuarios[], int val, int idUsuario) {
    return (idUsuario <= val);
}

/**
 * \brief   RECORRE EL ARCHIVO DE USUARIO Y DETECTA SI EL NOMBRE USADO PARA EL NUEVO USUARIO QUE INTENTAMOS CREAR YA FUE USADO
 * \param   ID USUARIO QUE SE INTENTA COMPROBAR
 * \param   ARREGLO USUARIOS
 * \param   VALIDOS
 * \return  ( 1 | 0 ) ADMIN O NO
 */

int esAdministrador(int idUsuario, stCelda usuarios[], int val) {
    return (usuarios[idUsuario-1].usr.rol);
}

/**
 * \brief   ADL AL ARCHIVO DE USUARIOS
 * \param   ARCHIVO
 * \return  VOID
 */

void ADLToArchivoUsuarios(stCelda usuarios[], int val, char archivo[]) {
    if(val) {
        stUsuario aux;
        FILE * archi = fopen(archivo,"wb");
        if(archi != NULL) {
            for(int i = 0; i < val; i++) {
                aux = usuarios[i].usr;
                fwrite(&aux, sizeof(stUsuario), 1, archi);
            }
            fclose(archi);
        }
    }
}


/**
 * \brief   ARCHIVO DE USUARIOS --> ADL
 * \param   ARCHIVO
 * \return  VOID
 */

int archivoUsuariosToADL(stCelda usuarios[], int val, char archivo[]) {
    val = cantidadUsuarios(archivo);
    if(val > 0) {
//        usuarios = dimensionarUsuarios(usuarios,val);
        stUsuario aux;
        int i = 0;
        FILE *archi;
        archi = fopen(archivo,"rb");
        if(archi != NULL) {
            while(fread(&aux, sizeof(stUsuario), 1, archi) > 0) {
                usuarios[i].usr = aux;
                usuarios[i].listaContenido = inicLista();
                i++;
            }
            fclose(archi);
        }
    }
    return val;
}



/**
 * \brief   VALIDA LA EXISTENCIA DEL USUARIO
 * \param   NOMBRE DEL USUARIO
 * \return  EXISTE ( 1 | 0 )
 */

int validaUsuario(stCelda usuarios[], int val, char nombreUsuario[]) {
    int existe = 0;
    if(val) {
        int i = 0;
        while(i < val && !existe) {
            if(strcmpi(usuarios[i].usr.username,nombreUsuario) == 0 ) existe = usuarios[i].usr.idUsuario;
            i++;
        }
    }
    return existe;
}


/**
 * \brief   PIDE EL ID DEL USUARIO, RECORRE EL ARCHIVO HASTA ENCONTRARLO Y CAMBIA EL VALOR DEL ACTIVO A 1
 * \param   ID USUARIO
 * \param   ADL
 * \param   VALIDOS
 * \return  ( 1 | 0 ) FUE ELIMINADO | O NO
 */

int bajaUsuario(int idUsuario, stCelda usuarios[], int val) {
    usuarios[idUsuario-1].usr.activo = !usuarios[idUsuario-1].usr.activo;
    return usuarios[idUsuario-1].usr.activo;
}


/**
 * \brief   PERMITE AL USUARIO SELECCIONAR EL CAMPO, INGRESAR EL NUEVO DATO Y GUARDARLO
 * \param   ID USUARIO
 * \param   ACCESO - LUGAR DONDE ACCEDE EL USUARIO ( 0: MENU DE USUARIO | 1: MENU DE ADMINISTRACION )
 * \param   ADL
 * \param   VALIDOS
 * \return  1 (GUARDADO)
 */

void modificarUsuario(stFavorito contFav[], int val_cf, int idUsuario, int acceso, stCelda usuarios[], int val, nodoArbolContenido * arbol) {
    if(idUsuario <= val) {
        int opcion = 0;
        stUsuario aux = usuarios[idUsuario-1].usr;
        char pass[10] = {0};

        encabezado("MODIFICAR USUARIO","ADMINISTRADOR");
        gotoxy(2, 8);
        printf("1 - Nombre de usuario..............: [%s]", aux.nombre);
        gotoxy(2, 10);
        printf("2 - Apellido de usuario............: [%s]", aux.apellido);
        gotoxy(2, 12);
        printf("3 - Username.......................: [%s]", aux.username);
        gotoxy(2, 14);
        printf("4 - Password.......................: [%s]", aux.password);
        gotoxy(2, 16);
        printf("5 - Mail...........................: [%s]", aux.mail);
        gotoxy(2, 18);
        printf("6 - Genero (m/f)...................: [%s]", (aux.genero == 'm')?"Masculino":"Femenino");
        gotoxy(2, 20);
        printf("7 - Puntaje........................: [%d]", aux.puntaje);
        gotoxy(2, 22);
        printf("8 - Nivel..........................: [%d]", aux.nivel);
        gotoxy(2, 24);
        printf("9 - Preferencias de Contenidos.....: [%s]", aux.preferenciasDeContenidos);
        gotoxy(2, 26);
        if(acceso) printf("10 - Rol...........................: [%s]", (aux.rol==1)?"Admin":"User");
        gotoxy(2, 28);
        printf("11 - Activo........................: [%s]", (aux.activo)?"SI":"NO");
        gotoxy(2, 30);
        printf("0-Salir");
        printf("\n\nEsperando opcion: ");
        scanf("%d", &opcion);

        if(opcion == 0) {
            switch(acceso) {
            case 0:
                menuPrincipal(contFav, val_cf, usuarios, val, arbol);
                break;
            case 1:
                menuAdministrarUsuarios(contFav, val_cf, usuarios, val, arbol);
                break;
            }
        } else {
            switch(opcion) {
                case 1: {
                        char nombre[15];
                        printf("\nIngrese el nuevo nombre de usuario: ");
                        fflush(stdin);
                        gets(nombre);
                        strcpy(aux.nombre, nombre);
                    } break;
                case 2: {
                        char apellido[15];
                        printf("\nIngrese el nuevo apellido de usuario: ");
                        fflush(stdin);
                        gets(apellido);
                        strcpy(aux.apellido, apellido);
                    } break;
                case 3: {
                        char username[15];
                        printf("\nIngrese el nuevo nombre de usuario: ");
                        fflush(stdin);
                        gets(username);
                        while(existeUsuario(username)) {
                            printf("\nIngrese el nuevo apellido del nuevo usuario (Error: El usuario ya existe): ");
                            fflush(stdin);
                            gets(username);
                        }
                        strcpy(aux.username, username);
                    } break;
                case 4: {
                        char pass[10] = {0};
                        printf("\nIngrese una password: ");
                        fflush(stdin);
                        gets(pass);
                        while(strlen(pass) > 10) {
                            printf("\nIngrese una password (Error: La password puede tener maximo 10 caracteres): ");
                            fflush(stdin);
                            gets(pass);
                        }
                    } break;
                case 5: {
                    char mail[15];
                    printf("\nIngrese el nuevo mail de usuario: ");
                    fflush(stdin);
                    gets(mail);
                    strcpy(aux.mail, mail);
                    } break;
                case 6: {
                    char genero;
                    printf("\nIngrese el nuevo Genero de usuario: ");
                    fflush(stdin);
                    scanf("%c", &genero);
                    while(genero != 'm' && genero != 'f') {
                        printf("\n\t Ingrese [ M | F ]: ");
                        fflush(stdin);
                        scanf("%c", &genero);
                    }
                    aux.genero = genero;
                    } break;
                case 7:
                    printf("\nIngrese nuevo puntaje: ");
                    fflush(stdin);
                    scanf("%d", &aux.puntaje);
                    break;
                case 8:
                    printf("\nIngrese el nuevo nivel: ");
                    fflush(stdin);
                    scanf("%d", &aux.nivel);
                    break;
                case 9: {
                        char op;
                        char preferencias[5][15] = {"Gammin", "Electronica", "Deportes", "Turismo", "Musica"};
                        printf("\nIngrese la nueva preferencia de contenidos: ");
                        printf("\n\t [ 01 ] - Gamming.");
                        printf("\n\t [ 02 ] - Electronica.");
                        printf("\n\t [ 03 ] - Deportes.");
                        printf("\n\t [ 04 ] - Turismo.");
                        printf("\n\t [ 05 ] - Musica.");
                        printf("\n\t Preferencias de contenidos: ");
                        scanf("%s", &op);
                        switch(op) {
                            case '1':
                                strcpy(aux.preferenciasDeContenidos, preferencias[0]);
                                break;
                            case '2':
                                strcpy(aux.preferenciasDeContenidos, preferencias[1]);
                                break;
                            case '3':
                                strcpy(aux.preferenciasDeContenidos, preferencias[2]);
                                break;
                            case '4':
                                strcpy(aux.preferenciasDeContenidos, preferencias[3]);
                                break;
                            case '5':
                                strcpy(aux.preferenciasDeContenidos, preferencias[4]);
                                break;
                            }
                        } break;
                case 10:
                    if(acceso) {
                        aux.rol = !aux.rol;
                        if(aux.rol) printf("\nEl usuario %s ahora es administrador.", aux.username);
                        else printf("\nEl usuario %s ya no es administrador.", aux.username);
                    }
                    break;
                case 11:
                    aux.activo = !aux.activo;
                    if(aux.rol) printf("\nEl usuario %s ahora esta activo.", aux.username);
                    else printf("\nEl usuario %s ya no esta activo.", aux.username);
                    break;
            }

            usuarios[idUsuario-1].usr = aux;
            ADLToArchivoUsuarios(usuarios, val, ARCHIVO_USUARIO);

            printf("\nSe guardo la modificacion realizada.\n\n");
            system("pause");
            modificarUsuario(contFav, val_cf, idUsuario, acceso, usuarios, val, arbol);
        }
    }
}




/**
 * \brief   BUSCA EN EL ARCHIVO LOS USUARIOS QUE COINCIDEN CON LOS PARAMETROS, MODIFICA ARREGLO DE USUARIOS CON LOS USUARIOS ENCONTRADOS.
 * \param   TIPO - TIPO DE BUSQUEDA QUE SE QUIERE REALIZAR
 * \param   FILTRO - BUSQUEDA POR STRING
 * \param   FILTRO2 - BUSQUEDA NUMERICA
 * \param   ARREGLO DE USUARIO DONDE SE GUARDAN LOS ID DE LOS USUARIOS ENCONTRADOS
 * \param   DIM
 * \param   ADL
 * \param   VALIDOS
 * \return  >0 CANTIDAD DE USUARIOS ENCONTRADOS QUE COINCIDEN CON LA BUSQUEDA
 * \return  =0 NO SE ENCUENTRA EL USUARIO
 */

int consultaUsuarios(int tipo, char filtro[], int filtro2, stUsuario muestra[], int dim, stCelda usuarios[], int val) {
    int i = 0, j = 0; // CONTADOR QUE LLENA ARRAY
    if(val) {
        switch(tipo) {
            case 0: {
                while(i < dim && j < val) { // RECORRE EL ARCHIVO DE USUARIOS Y CORTO SI LLEGO AL MAXIMO DE USUARIOS
                    muestra[i] = usuarios[j].usr;
                    i++;
                    j++;
                }
            } break;
            case 1: {
                while(i < dim && j < val) { // RECORRO EL ARCHIVO DE USUARIOS Y CORTO SI LLEGO AL MAXIMO DE USUARIOS
                    if(strstr(usuarios[j].usr.apellido,filtro) != NULL) { // SI ENCUENTRA LA PALABRA INGRESADA EN EL ARCHIVO DEVUELVE UN PUNTERO, SINO UN NULL
                        muestra[i] = usuarios[j].usr;
                        i++;
                    }
                    j++;
                }
            } break;
			case 2: {
                while(i < dim && j < val) { // RECORRO EL ARCHIVO DE USUARIOS Y CORTO CUANDO LLEGO AL MAXIMO DE USUARIOS
                    if(strstr(usuarios[j].usr.username,filtro) != NULL) { // SI ENCUENTRA LA PALABRA INGRESADA EN EL ARCHIVO DEVUELVE UN PUNTERO, SINO UN NULL
                        muestra[i] = usuarios[j].usr;
                        i++;
                    }
                    j++;
                }
            } break;
        }
    }
    return i;
}


/**
 * \brief   SE LISTA LOS USUARIOS
 * \param   TIPO DE LISTA QUE SE QUIERE
 * \param   ARREGLO DE USUARIO DONDE SE CARGAN Y ORDENAN LOS REGISTROS
 * \param   DIM
 * \param   ADL
 * \param   VALIDOS
 * \return  VOID
 */

void listarUsuarios(int tipo, stUsuario muestra[], int dim, stCelda usuarios[], int val) {
    if(val) {
        int i = 0, j = 0;
        while(i < dim && j < val) {
            muestra[i] = usuarios[j].usr;
            i++;
            j++;
        }
        switch(tipo) {
            case 1:
                ordenaArregloUsuariosSeleccionApellido(muestra,dim);    // APELLIDO
                break;
			case 2:
                ordenaArregloUsuariosSeleccionUsername(muestra,dim);    // NOMBRE DE USUARIO
                break;
            case 3:
                ordenaArregloUsuariosSeleccionNivel(muestra,dim);   // NIVEL
                break;
        }
    }
}



/**
 * \brief   LIMPIA EL ARREGLO DE LISTAS
 * \param   SIN PARAMETROS
 * \return  VOID
 */

void limpiarArregloDeListas(stCelda usuarios[], int val) {
    encabezado("LIMPIAR ARREGLO DE LISTAS","ADMINISTRADOR");
    if(val) {
        for(int i = 0; i < val; i++) {
            usuarios[i].listaContenido = borrarListaContenido(usuarios[i].listaContenido);
        }
        free(usuarios);
        usuarios = realloc(usuarios, sizeof(stCelda *));
        val = 0;
        printf("\n\nArreglo de listas limpiado satisfactoriamente.\nPrecaucion al crear o editar usuarios para no sobrescribir el archivo.\n\n");
    } else {
        printf("\n\nTodavia no se han creado usuarios.\n\n");
    }
    system("pause");
}


/**
 * \brief   PIDE LOS DATOS DE USUARIO Y PASSWORD AL USUARIO, VALIDA LOS DATOS
 * \param   ADL
 * \param   VALIDOS
 * \return  RETORNA EL ID DEL USUARIO LOGUEADO, TAMBIEN SE GUARDA EL ACCESO EN LA VARIABLE GLOBAL (SESION)
 */

void loginUsuario(stFavorito contFav[], int val_cf, stCelda usuarios[], stUsuario user, stContenido contenido, int val, nodoArbolContenido * arbol) {
    int idUsuario = 0;
    int sesion;
    val = archivoUsuariosToADL(usuarios, val, ARCHIVO_USUARIO);
    arbol = archivoToArbolContenido(ARCHIVO_CONTENIDO, arbol, 0);
    if(!val) {
        gotoxy(2,7);
        printf("Error: Aun no se han creado usuarios.");
        system("pause");
        system("cls");
        printf("Error: Aun no se han creado usuarios.");
        encabezado("REGISTRO USUARIO","USUARIO");
        val = alta(usuarios, user, contenido, val);
        menuInicio(contFav, val_cf, usuarios, val, arbol);
    } else {
        char nombreUsuario[30];
        gotoxy(2, 7);
        printf("Ingrese el nombre de usuario: ");
        fflush(stdin);
        gets(nombreUsuario);
        idUsuario = validaUsuario(usuarios, val, nombreUsuario);
        while(!idUsuario) {
            gotoxy(2, 7);
            printf("Ingrese el nombre de usuario (Error: El usuario no existe./0 para volver): ");
            fflush(stdin);
            gets(nombreUsuario);
            if(strcmp(nombreUsuario,"0") == 0) menuInicio(contFav, val_cf, usuarios, val, arbol);
            idUsuario = validaUsuario(usuarios, val, nombreUsuario);
        }
        user = usuarios[idUsuario-1].usr;

        char pass[10] = {0};
        gotoxy(2, 9);
        printf("Ingrese password: ");
        fflush(stdin);
        gets(pass);
        int count = 0;
        while(!existePass(pass) && count < 3) {
            gotoxy(2, 9);
            printf("Ingrese password (Error: Password Incorrecto) ");
            fflush(stdin);
            gets(pass);
            count++;
            if(count == 3) {
                printf("\n\t Fallaste las %d veces, vuelve a intentar mas tarde", 2);
                system("pause");
                menuInicio(contFav, val_cf, usuarios, val, arbol);
            }
        }
        if(strcmp(user.username, nombreUsuario) == 0 && strcmp(user.password, pass) == 0) {
            if(esAdministrador(idUsuario, usuarios, val)) {
                menuAdministracion(contFav, val_cf, usuarios, val, arbol);
            } else {
                menuPrincipal(contFav, val_cf, usuarios, val, arbol);
            }
        } else {
            menuInicio(contFav, val_cf, usuarios, val, arbol);
        }
    }
    sesion = idUsuario;
}


/***************************************************** CONTENIDOS FAVORITOS *****************************************************/


/**
 * \brief   SE MUESRA EL CONTENIDO DE LA LISA DE USUARIO Y CONTENIDO
 * \param   ID USUARIO
 * \param   ID CONTENIDO
 * \return  VOID
 */

void verContenido(stFavorito contFav[], int val_cf, stCelda usuarios[], int val, nodoArbolContenido * arbol, int idUsuario, int idContenido) {
    nodoArbolContenido * vista = buscarContenidoId(arbol,idContenido);
    stContenido aux = vista->dato;
    nodoListaContenido * nuevo = crearNodoListaContenido(aux);
    usuarios[idUsuario-1].listaContenido = insertarContenidoFinal(usuarios[idUsuario-1].listaContenido,nuevo);
    contenidoFavoritoToArchivo(contFav, val_cf, usuarios, val, ARCHIVO_CONT_FAVORITO);
}

/**
 * \brief   CONTENIDO FAVORITO AL ARCHIVO
 * \param   ARCHIVO
 * \return  VOID
 */

void contenidoFavoritoToArchivo(stFavorito contFav[], int val_cf, stCelda usuarios[], int val, char archivo[]) {
    contenidoFavoritoTOArreglo(contFav, val_cf, usuarios, val);
    arregloContenidoFavoritoToArchivo(contFav, val_cf, archivo);
    vaciarContenidoFavorito(contFav, val_cf);
}

/**
 * \brief   CONTENIDO FAVORITOS AL ARREGLO, SE USA LA FUNCION DE listaContenidoFavoritosToArreglo
 * \param   SIN PARAMETROS
 * \return  VOID
 */

void contenidoFavoritoTOArreglo(stFavorito contFav[], int val_cf, stCelda usuarios[], int val) {
    int i = 0;
    while(i < val) {
        if(usuarios[i].listaContenido != NULL) {
            listaContenidoFavoritosToArreglo(contFav, val_cf, usuarios[i].listaContenido, usuarios[i].usr.idUsuario);
        }
        i++;
    }
}

/**
 * \brief   DIMENSIONA EL CONTENIDO FAVORITO
 * \param   CONTENIDO FAVORITO
 * \param   CANTIDAD
 * \return  CONTENIDO FAVORITO
 */

stFavorito * dimensionarContenidoFavorito(stFavorito contFav[], int cant) {
    contFav = calloc(cant, sizeof(stFavorito));
    return contFav;
}

/**
 * \brief   SE REDIMENSIONA EL CONTENIDO FAVORITO
 * \param   CONTENIDO FAVORITO
 * \param   CANTIDAD
 * \return  CONTENIDO FAVORITO
 */

stFavorito * redimensionarContenidoFavorito(stFavorito contFav[], int cant) {
    contFav = realloc(contFav, sizeof(stFavorito)*cant);
    return contFav;
}


/**
 * \brief   LISTA DE CONTENIDOS FAVORITOS AL ARREGLO
 * \param   LISTA
 * \param   ID USUARIO
 * \return  VOID
 */

void listaContenidoFavoritosToArreglo(stFavorito contFavoritos[], int val_cf, nodoListaContenido * lista, int idUsuario) {
    if(lista != NULL) {
        agregarContenidoToArreglo(contFavoritos, val_cf, idUsuario, lista->dato.idContenido);
        listaContenidoFavoritosToArreglo(contFavoritos, val_cf, lista->sig, idUsuario);
    }
}


/**
 * \brief
 * \param
 * \param
 * \return
 */

void agregarContenidoToArreglo(stFavorito contFavoritos[], int val_cf, int idUsuario, int idContenido) {
    if(!val_cf) {
        contFavoritos = dimensionarContenidoFavorito(contFavoritos,val_cf+1);
    } else {
        contFavoritos = redimensionarContenidoFavorito(contFavoritos,val_cf+1);
    }
    contFavoritos[val_cf].idFavorito = val_cf+1;
    contFavoritos[val_cf].idUsuario = idUsuario;
    contFavoritos[val_cf].idContenido = idContenido;
    val_cf++;
}

/**
 * \brief   ARREGLO DE CONTENIDO FAVORITO A ARCHIVO
 * \param   ARCHIVO
 * \return  VOID
 */

void arregloContenidoFavoritoToArchivo(stFavorito contFavoritos[], int val_cf, char archivo[]) {
    FILE * archi = fopen(archivo,"wb");
    if(archi != NULL) {
        for(int i = 0; i < val_cf; i++) {
            fwrite(&contFavoritos[i],sizeof(stFavorito),1,archi);
        }
        fclose(archi);
    }
}

/**
 * \brief   SE VACIA EL CONTENIDO FAVORITO
 * \param   SIN PARAMETROS
 * \return  VOID
 */

void vaciarContenidoFavorito(stFavorito contFavoritos[], int val_cf) {
    free(contFavoritos);
    contFavoritos = realloc(contFavoritos, sizeof(stFavorito *));
}
