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
#include "personajeYenemigos.h"

int funcionDePelea(stPersonaje player, stEnemigo enemy, int pocionRoja, int pocionAzul);
void cargarMatrizEscena(char matrizEscena[][50], char escena[]);
void mostrarEscena(char escena[][50]);
void barraDeVida(int vidaMaxima, int vidaActual);
void barraDeMana(int manaMaximo, int manaActual);
void menuCombate(int * vidaActual, int * vidaEnemigo, int * pocionRoja, int * pocionAzul, int * bombaHumo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
void cajaDeTexto(Fila * accionesCombate, int turno);
int accionesEnemigo(int * vidaActual, int * vidaEnemigo,stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
void items(int * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo);
void dibujarEscena(stPersonaje player, stEnemigo enemy, int vidaActual, int vidaActualEnemigo, int manaActual, Fila * accionesCombate, char matrizEscena[][50], int turno);


#endif // FUNCIONESPELEAS_H_INCLUDED
