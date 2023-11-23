#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "estadisticas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
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

typedef struct nodoClases{
    stRegistroClase registro;
    struct nodoClases * siguiente;
}nodoClases;


///PROTOTIPADO FUNCIONES CLASE
void cargarArchivoClases(char archivito[]);
stRegistroClase cargarClase(stRegistroClase aux);
int mostrarArchivoAltaClasesOrdenado(char archivito[]);
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
int mostrarClasesBajasArchivoOrdenado(char archivito[]);
void mostrarListaClasesRecursivaDescendiente(nodoClases * lista);
void mostrarListaClasesRecursivaAscendente(nodoClases * lista);
nodoClases * agregarNodoOrdenadoClases(nodoClases * lista, nodoClases * nuevo);
nodoClases * inicListaClases();
nodoClases * crearNodoListaClase(stRegistroClase dato);
char menuMostrarClaseOrdenada();
void mostrarListaOrdenadaClases(nodoClases * lista);
nodoClases * agregarAlPrincipioListaClase(nodoClases * lista, nodoClases * nuevo);

#endif // CLASES_H_INCLUDED
