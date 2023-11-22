#include "personajeYenemigos.h"

stPersonaje cargarPersonaje(stClase celdaClase[], int validos){
    stPersonaje personaje;
    char opcion;
    printf("Ingrese el nombre de su personaje: ");
    fflush(stdin);
    gets(personaje.nombre);
    personaje.alta=1;
    switch(opcion=menuClases()){
    case '1':
        personaje=cargarClasePersonaje(celdaClase, 1, personaje, validos);
        break;
    case '2':
        personaje=cargarClasePersonaje(celdaClase, 2, personaje, validos);
        break;
    case '3':
        personaje=cargarClasePersonaje(celdaClase, 3, personaje, validos);
        break;
    case '4':
        personaje=cargarClasePersonaje(celdaClase, 4, personaje, validos);
        break;
    }
    return personaje;
}

stPersonaje cargarClasePersonaje(stClase celdaClase[], int id, stPersonaje personaje, int validos){
    int flag=0, i=0;
    while(i<validos && flag==0){
        if(id==celdaClase[i].idClase){
            personaje.clase=celdaClase[i];
            flag=1;
        }
        i++;
    }
    return personaje;
}

void mostrarPersonaje(stPersonaje personaje){
    char res;
    printf("\nNOMBRE: %s", personaje.nombre);
    printf("\nCLASE: %s", personaje.clase.nombreClase);
    printf("\nID CLASE: %d", personaje.clase.idClase);///No se si esto es necesario
    printf("\n------------------------------");
    printf("\nESTADISTICAS");
    printf("\n------------------------------");
    ///Capaz quieran agregar aca el nodo en el que se encuentra.
    mostrarEstadisticas(personaje.clase.estadisticas);
}

stPersonaje darBajaPersonaje(stPersonaje personaje){
    personaje.alta=0;
    system("cls");
    printf("El personaje se ha dado de baja!!\n");
    system("pause");
    return personaje;
}
