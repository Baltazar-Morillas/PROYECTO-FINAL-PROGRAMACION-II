#ifndef LIBRERIAPRINCIPAL_H_INCLUDED
#define LIBRERIAPRINCIPAL_H_INCLUDED
#include "estadisticas.h"
#include "clases.h"
#include "habilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

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

#endif // LIBRERIAPRINCIPAL_H_INCLUDED
