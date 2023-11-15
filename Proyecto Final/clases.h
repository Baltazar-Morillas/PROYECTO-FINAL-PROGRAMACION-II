#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "habilidades.h"
#include "estadisticas.h"

///ESTRUCTURAS

typedef struct stClase{
    char nombreClase[30];
    int idClase;
    int nivel;
}stClase;

typedef struct stRegistroClase{
    stClase clase;
    stEstadisticas estadisticas;
    stRegistroHabilidades habilidad;
}stRegistroClase;

typedef struct celdaClases{
    stClase clase;
    stEstadisticas estadisticasClase;
    struct listaHabilidades * habilidadesClase;
}celdaClases;



#endif // CLASES_H_INCLUDED
