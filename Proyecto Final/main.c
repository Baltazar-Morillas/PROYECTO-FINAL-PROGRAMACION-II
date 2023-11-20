#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"
#include "FuncionesPeleas.h"

const char archivitoHabilidades[]="archivitoHabilidades.bin";
const char archivitoClases[]="archivitoClases.bin";

int main()
{
    int id=0, validos=0;
    stClase celdaClase[5];
    stPersonaje personaje;
    /*
    system("color 0B");

    int victoria;
    stPersonaje player;
    stEnemigo enemy;

    //player.clase.estadisticas = cargarStats(player.clase.estadisticas);
   //enemy.estadisticasE = cargarStats(enemy.estadisticasE);

    victoria = funcionDePelea(player, enemy);
    */
    //cargarArchivoHabilidades(archivitoHabilidades);
    //mostrarArchivitoHabilidades(archivitoHabilidades);
    /*printf("\nIngrese el id de la habilidad a modificar: ");
    scanf("%d", &id);
    modificarArchivoHabilidades(archivitoHabilidades, id);*/
    /*
    cargarArchivoClases(archivitoClases);
    mostrarArchivoClases(archivitoClases);
    printf("\nIngrese el id de la clase a modificar: ");
    scanf("%d", &id);
    modificarArchivoClases(archivitoClases, id);*/
    validos=pasarArchivoClaseToCelda(archivitoClases, celdaClase, 3);
    pasarArchivoHabilidadesToCLase(celdaClase, archivitoHabilidades, validos);
    personaje=cargarPersonaje(celdaClase, validos);
    system ("cls");
    mostrarPersonaje(personaje);
    return 0;
}
