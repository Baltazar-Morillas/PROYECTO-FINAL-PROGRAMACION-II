#ifndef FUNCIONESPELEAS_H_INCLUDED
#define FUNCIONESPELEAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"
#include "filas.h"

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

int funcionDePelea(stPersonaje player, stEnemigo enemy, int pocionRoja, int pocionAzul);
void cargarMatrizEscena(char matrizEscena[][50], char escena[]);
void mostrarEscena(char escena[][50]);
void barraDeVida(int vidaMaxima, float * vidaActual);
void barraDeMana(int manaMaximo, int * manaActual);
void menuCombate(float * vidaActual, float * vidaEnemigo, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
void cajaDeTexto(Fila * accionesCombate, int turno);
void accionesEnemigo(float * vidaActual, float * vidaEnemigo,stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
stPersonaje cargarPersonaje(stClase celdaClase[], int validos);
stPersonaje cargarClasePersonaje(stClase celdaClase[], int id, stPersonaje personaje, int validos);
void items(float * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo, Fila * accionesCombate);
void dibujarEscena(stPersonaje player, stEnemigo enemy, float * vidaActual, float * vidaActualEnemigo, int * manaActual, Fila * accionesCombate, char matrizEscena[][50], int turno);
listaHabilidades * habilidadElegida(listaHabilidades * lista, int habilidadElegida);

#endif // FUNCIONESPELEAS_H_INCLUDED
