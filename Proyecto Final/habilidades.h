#ifndef HABILIDADES_H_INCLUDED
#define HABILIDADES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
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

#endif // HABILIDADES_H_INCLUDED
