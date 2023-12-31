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

    printf("                               ||Vitalidad: %d||\n",aux.vitalidad);
    printf("                               ||Defensa: %g||\n",aux.defensa);
    printf("                               ||Ataque: %d||\n",aux.ataque);
    printf("                               ||Mana: %d||\n",aux.mana);
    printf("                               ||Agilidad: %d||\n",aux.agilidad);
    printf("                               ||Critico: %d||\n",aux.critico);
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");
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
