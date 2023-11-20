#ifndef FUNCIONESPELEAS_H_INCLUDED
#define FUNCIONESPELEAS_H_INCLUDED
#include "LibreriaPrincipal.h"

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


int funcionDePelea(stPersonaje player, stEnemigo enemy);
void cargarMatrizEscena(char matrizEscena[][50], char escena[]);
void mostrarEscena(char escena[][50]);
int barraDeVida(int vidaMaxima, int vidaActual);
int menuCombate(int * vidaActual, int * vidaEnemigo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate);
void cajaDeTexto(Fila * accionesCombate, int turno);
int accionesEnemigo(int * vidaActual, int * vidaEnemigo,stPersonaje player, stEnemigo enemy, Fila * accionesCombate);


///Funciones estadisticas (temporal)

stEstadisticas cargarStats(stEstadisticas a);


#endif // FUNCIONESPELEAS_H_INCLUDED
