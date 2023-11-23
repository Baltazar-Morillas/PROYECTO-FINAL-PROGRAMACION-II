#ifndef PERSONAJEYENEMIGOS_H_INCLUDED
#define PERSONAJEYENEMIGOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"

///ESTRUCTURAS
typedef struct{
    char nombre[20];
    int alta;
    stClase clase;
}stPersonaje;

typedef struct{
    char nombreE[20];
    int IdEnemigo;
    stEstadisticas estadisticasE;
    char sprite[1000];
}stEnemigo;

///PROTOTIPADO
stPersonaje cargarPersonaje(stClase celdaClase[], int validos);
stPersonaje cargarClasePersonaje(stClase celdaClase[], int id, stPersonaje personaje, int validos);
void mostrarPersonaje(stPersonaje personaje);
stPersonaje darBajaPersonaje(stPersonaje personaje);
#endif // PERSONAJEYENEMIGOS_H_INCLUDED
