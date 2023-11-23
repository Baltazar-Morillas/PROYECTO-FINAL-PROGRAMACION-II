#ifndef FUNCIONESPELEAS_H_INCLUDED
#define FUNCIONESPELEAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "Usuario.h"
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"
#include "filas.h"
#include "personajeYenemigos.h"

int funcionDePelea(Usuario player, stEnemigo enemy, int pocionRoja, int pocionAzul);
void cargarMatrizEscena(char matrizEscena[][50], char escena[]);
void mostrarEscena(char escena[][50]);
void barraDeVida(int vidaMaxima, float * vidaActual);
void barraDeMana(int manaMaximo, int * manaActual);
void menuCombate(float * vidaActual, float * vidaEnemigo, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo, Usuario * player, stEnemigo * enemy);
//void menuCombate(float * vidaActual, float * vidaEnemigo, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo, Usuario * player, stEnemigo * enemy, Fila * accionesCombate);
//void cajaDeTexto(Fila * accionesCombate, int turno);
void accionesEnemigo(float * vidaActual, float * vidaEnemigo,Usuario player, stEnemigo enemy);
//void accionesEnemigo(float * vidaActual, float * vidaEnemigo,Usuario player, stEnemigo enemy, Fila * accionesCombate);
void items(float * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo);
//void items(float * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo, Fila * accionesCombate);

void dibujarEscena(Usuario player, stEnemigo enemy, float * vidaActual, float * vidaActualEnemigo, int * manaActual, char matrizEscena[][50], int turno);
//void dibujarEscena(Usuario player, stEnemigo enemy, float * vidaActual, float * vidaActualEnemigo, int * manaActual, Fila * accionesCombate, char matrizEscena[][50], int turno);

listaHabilidades * habilidadElegida(listaHabilidades * lista, int habilidadElegida);
//int menuHabilidades(float * vidaActual, float * vidaActualEnemigo, int * manaActual, Usuario * player, stEnemigo * enemy, Fila * accionesCombate);
int menuHabilidades(float * vidaActual, float * vidaActualEnemigo, int * manaActual, Usuario * player, stEnemigo * enemy);

void mostrarHabilidadesJugador(listaHabilidades * lista);
int efectoHabilidad(float * vidaActual, float * vidaActualEnemigo, int * manaActual, Usuario * player, stEnemigo * enemy, listaHabilidades * habilidadElegida);

///int efectoHabilidad(float * vidaActual, float * vidaActualEnemigo, int * manaActual, Usuario * player, stEnemigo * enemy, listaHabilidades * habilidadElegida, Fila * accionesCombate);

#endif // FUNCIONESPELEAS_H_INCLUDED
