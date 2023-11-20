#include "estadisticas.h"

stEstadisticas cargarStats(stEstadisticas a)
{
    printf("\nVITALIDAD: ");
    scanf("%i", &a.vitalidad);
    printf("\nATAQUE: ");
    scanf("%i", &a.ataque);
    printf("\nDEFENSA: ");
    scanf("%f", &a.defensa);
    printf("\nAGILIDAD: ");
    scanf("%i", &a.agilidad);
    printf("\nMANA: ");
    scanf("%i", &a.mana);
    printf("\nCRITICO: ");
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
