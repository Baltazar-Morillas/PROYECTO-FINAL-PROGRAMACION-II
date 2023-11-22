#include "estadisticas.h"

stEstadisticas cargarStats(stEstadisticas a)
{
    printf("VITALIDAD: ");
    scanf("%i", &a.vitalidad);
    printf("ATAQUE: ");
    scanf("%i", &a.ataque);
    printf("DEFENSA: ");
    scanf("%f", &a.defensa);
    printf("AGILIDAD: ");
    scanf("%i", &a.agilidad);
    printf("MANA: ");
    scanf("%i", &a.mana);
    printf("CRITICO: ");
    scanf("%i", &a.critico);
    return a;
}

void mostrarEstadisticas(stEstadisticas aux){
    printf("\nVITALIDAD: %d", aux.vitalidad);
    printf("\nDEFENSA: %g", aux.defensa);
    printf("\nATAQUE: %d", aux.ataque);
    printf("\nMANA: %d", aux.mana);
    printf("\nAGILIDAD: %d", aux.agilidad);
    printf("\nCRITICO: %d", aux.critico);
}

stEstadisticas crearEstructuraEstadisticas(stEstadisticas dato){
    stEstadisticas aux;
    aux=datosToEstadistica(aux, dato);
    return aux;
}

stEstadisticas datosToEstadistica(stEstadisticas aux, stEstadisticas dato){
    aux.agilidad=dato.agilidad;
    aux.ataque=dato.ataque;
    aux.critico=dato.critico;
    aux.defensa=dato.defensa;
    aux.mana=dato.mana;
    aux.vitalidad=dato.vitalidad;
    return aux;
}
