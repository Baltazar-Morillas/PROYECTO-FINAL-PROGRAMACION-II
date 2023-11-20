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
void barraDeVida(int vidaMaxima, int vidaActual);
void barraDeMana(int manaMaximo, int manaActual);
void menuCombate(int * vidaActual, int * vidaEnemigo, int * pocionRoja, int * pocionAzul, int * bombaHumo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
void cajaDeTexto(Fila * accionesCombate, int turno);
int accionesEnemigo(int * vidaActual, int * vidaEnemigo,stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
stPersonaje cargarPersonaje(stClase celdaClase[], int validos);
stPersonaje cargarClasePersonaje(stClase celdaClase[], int id, stPersonaje personaje, int validos);
void items(int * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo);
void dibujarEscena(stPersonaje player, stEnemigo enemy, int vidaActual, int vidaActualEnemigo, int manaActual, Fila * accionesCombate, char matrizEscena[][50], int turno);


#endif // FUNCIONESPELEAS_H_INCLUDED
