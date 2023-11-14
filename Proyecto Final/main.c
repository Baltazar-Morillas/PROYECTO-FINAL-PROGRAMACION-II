#include <stdio.h>
#include <stdlib.h>

typedef struct stRegistroClase{
    char nombreClase[30];
    int vitalidad;
    int defensa;
    int ataque;
    int destreza;
    int magia;
    int agilidad;
    int critico;
}stRegistroClase;

typedef struct stEstadisticas{
    int vitalidad;
    int defensa;
    int ataque;
    int destreza;
    int magia;
    int agilidad;
    int critico;
}stEstadistica;

typedef struct stRegistroHabilidades{
    char nombre[30];
    int damage;
    int idHabilidad;
}stRegistroHabilidades;

typedef struct listaHabilidades{
    char nombre[30];
    int damage;
    int idHabilidad;
    struct listaHabilidades * siguiente;
}listaHabilidades;

typedef struct stClase{
    char nombreClase[30];
    int nivel;
}stClase;

typedef struct stPersonaje{
    stEstadisticas estadisticas;
    stClase clase;
    struct listaHabilidades * habilidades;
}stPersonaje;

int main()
{
    return 0;
}
