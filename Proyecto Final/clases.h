#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "estadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

///ESTRUCTURAS CLASE

typedef struct stClase{
    char nombreClase[30];
    int idClase;
    int alta;
    stEstadisticas estadisticas;
    struct listaHabilidades * habilidades;
}stClase;

typedef struct stRegistroClase{
    char nombreClase[30];
    int idClase;
    int alta;
    stEstadisticas estadisticas;
}stRegistroClase;



///PROTOTIPADO FUNCIONES CLASE
void cargarArchivoClases(char archivito[]);
stRegistroClase cargarClase(stRegistroClase aux);
void mostrarArchivoClases(char archivito[]);
void mostrarClase(stRegistroClase aux);
void modificarArchivoClases(char archivito[], int id);
stRegistroClase modificarClases(stRegistroClase aux);
stRegistroClase modificarCampoClase(stRegistroClase aux, char sw);
char menuModificarClases();
int pasarArchivoClaseToCelda(char archivito[], stClase celdaClase[], int dimension);
int altaClase(stClase celdaClase[], stRegistroClase aux, int validos);
int buscarClaseCelda(stClase celdaClase[], stRegistroClase clase, int validos);
int crearNuevaClase(stClase celdaClase[], stRegistroClase nuevo, int validos);
void darBajaClase(char archivito[], int idClase);
void darAltaClase(char archivito[], int idClase);
char menuClases();
void mostrarClasesBajasArchivo(char archivito[]);
#endif // CLASES_H_INCLUDED
