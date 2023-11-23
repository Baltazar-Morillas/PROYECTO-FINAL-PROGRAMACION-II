#ifndef PERSONAJEYENEMIGOS_H_INCLUDED
#define PERSONAJEYENEMIGOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"

///ESTRUCTURAS

typedef struct{
    char nombreE[20];
    int IdEnemigo;
    int alta;
    stEstadisticas estadisticasE;
    char sprite[1000];
}stEnemigo;

///PROTOTIPADO

#endif // PERSONAJEYENEMIGOS_H_INCLUDED
