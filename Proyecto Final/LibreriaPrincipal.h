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
    stEstadisticas estadisticas;
    stClase clase;
    struct listaHabilidades * habilidades;
}stPersonaje;

typedef struct{
    stEstadisticas estadisticasE;
    struct listaHabilidades * habilidadesE;

}stEnemigo;

#endif // LIBRERIAPRINCIPAL_H_INCLUDED
