#ifndef FUNCIONESPELEAS_H_INCLUDED
#define FUNCIONESPELEAS_H_INCLUDED


#include "LibreriaPrincipal.h"


int funcionDePelea(stPersonaje player, stEnemigo enemy);
void cargarMatrizEscena(char matrizEscena[][50], char escena[]);
void mostrarEscena(char escena[][50]);
int barraDeVida(int vidaMaxima, int vidaActual);
int menuCombate(int * vidaActual, int * vidaEnemigo, stPersonaje player, stEnemigo enemy);
void cajaDeTexto(int eleccion, int danioRecibidoP, int danioRecibidoE, int turno);
int accionesEnemigo(int * vidaActual, int * vidaEnemigo,stPersonaje player, stEnemigo enemy);


///Funciones estadisticas (temporal)

stEstadisticas cargarStats(stEstadisticas a);


#endif // FUNCIONESPELEAS_H_INCLUDED
