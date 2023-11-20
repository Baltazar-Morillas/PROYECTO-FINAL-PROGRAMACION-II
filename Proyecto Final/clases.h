#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "estadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

///ESTRUCTURAS

typedef struct stClase{
    char nombreClase[30];
    int idClase;
    int alta;
    stEstadisticas estadisticas;
    struct listaHabilidades * habilidades;
}stClase;

typedef struct{
    char nombre[20];
    stClase clase;
}stPersonaje;

typedef struct{
    char nombreE[20];
    int IdEnemigo;
    stEstadisticas estadisticasE;
    char sprite[1000];
}stEnemigo;

typedef struct stRegistroClase{
    char nombreClase[30];
    int idClase;
    int alta;
    stEstadisticas estadisticas;
}stRegistroClase;

void cargarArchivoClases(char archivito[]);
stRegistroClase cargarClase(stRegistroClase aux);
void mostrarArchivoClases(char archivito[]);
void mostrarClase(stRegistroClase aux);
void modificarArchivoClases(char archivito[], int id);
stRegistroClase modificarClases(stRegistroClase aux);
stRegistroClase modificarCampoClase(stRegistroClase aux, char sw);
char menuModificarClases();
#endif // CLASES_H_INCLUDED
