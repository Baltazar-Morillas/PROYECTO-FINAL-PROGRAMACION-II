#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "habilidades.h"
#include "estadisticas.h"

///ESTRUCTURAS

typedef struct stClase{
    char nombreClase[30];
    int idClase;
    stEstadisticas estadisticas;
    listaHabilidades * habilidades;
}stClase;

typedef struct stRegistroClase{
    char nombreClase[30];
    int idClase;
    stEstadisticas estadisticas;
}stRegistroClase;



#endif // CLASES_H_INCLUDED
