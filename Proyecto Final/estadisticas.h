#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>
#include <windows.h>

///ESTRUCTURAS
typedef struct{
    int vitalidad;
    float defensa;
    int ataque;
    int mana;
    int agilidad;
    int critico;
}stEstadisticas;

stEstadisticas cargarStats(stEstadisticas a);
void mostrarEstadisticas(stEstadisticas aux);
stEstadisticas crearEstructuraEstadisticas(stEstadisticas dato);
stEstadisticas datosToEstadistica(stEstadisticas aux, stEstadisticas dato);
#endif // ESTADISTICAS_H_INCLUDED
