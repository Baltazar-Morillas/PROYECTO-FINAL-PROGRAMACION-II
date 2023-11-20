#ifndef HABILIDADES_H_INCLUDED
#define HABILIDADES_H_INCLUDED
#include "clases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

///ESTRUCTURAS
typedef struct stRegistroHabilidades{
    char nombreHabilidad[30];
    int damage;
    int idHabilidad;
    int mana;
    int efecto;
    int usos;
    int idClase;
    int alta;
    char sprite[1000];
}stRegistroHabilidades;

typedef struct listaHabilidades{
    char nombreHabilidad[30];
    int damage;
    int idHabilidad;
    int mana;
    int usos;
    int efecto;
    int idClase;
    int alta;
    char sprite[1000];
    struct listaHabilidades * siguiente;
}listaHabilidades;

void cargarArchivoHabilidades(char archivito[]);
stRegistroHabilidades cargarHabilidad(stRegistroHabilidades habilidad);
void mostrarArchivitoHabilidades(char archivito[]);
void mostrarHabilidad(stRegistroHabilidades aux);
void modificarArchivoHabilidades(char archivito[], int id);
stRegistroHabilidades modificarHabilidades(stRegistroHabilidades aux);
stRegistroHabilidades modificarCampoHabilidad(stRegistroHabilidades aux, char sw);
char menuModificarHabilidades();
void pasarArchivoHabilidadesToCLase(stClase celdaClase[], char archivito[], int validos);
void altaHabilidad(stClase celdaClase[], stRegistroHabilidades habilidad, int validos);
listaHabilidades * agregarAlFinal(listaHabilidades * lista, listaHabilidades * nuevo);
listaHabilidades * buscarUltimo(listaHabilidades * lista);
int buscarHabilidadClase(stClase celdaClase[], int id, int validos);
listaHabilidades * crearNodoLista(stRegistroHabilidades dato);
listaHabilidades * registroToLista(listaHabilidades * nodo, stRegistroHabilidades dato);
listaHabilidades * inicLista();
#endif // HABILIDADES_H_INCLUDED
