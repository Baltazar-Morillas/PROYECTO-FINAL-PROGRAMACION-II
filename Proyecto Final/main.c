#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "Menu.h"
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"
#include "FuncionesPeleas.h"
#include "personajeYenemigos.h"


const char ArchivoP[]="ArchivoPersonajes.bin";
const char archivitoClases[]="archivitoClases.bin";
const char archivitoHabilidades[]="archivitoHabilidades.bin";

int main()
{
    ///Cosas de Tata

    //Menu(ArchivoP,archivitoClases,archivitoHabilidades);


    ///Cosas de chuli
    system("color 0A");
    int id=0, victoria, pocionRoja = 3, pocionAzul = 3, validos;
    stClase celdaClases[10];
    stPersonaje player;
    stEnemigo enemy;

    validos = pasarArchivoClaseToCelda(archivitoClases, celdaClases, 10);
    pasarArchivoHabilidadesToCLase(celdaClases, archivitoHabilidades, validos);

    player = cargarPersonaje(celdaClases, validos);
    enemy.estadisticasE = cargarStats (enemy.estadisticasE);

    victoria = funcionDePelea(player, enemy, pocionRoja, pocionAzul);



    ///Cosas de balta

    int id=0, validos=0;
    char res;
    stClase celdaClase[5];
    stPersonaje personaje;

    darBajaClase(archivitoClases, 2);
    darBajaClase(archivitoClases, 3);
    mostrarClasesBajasArchivo(archivitoClases);
    system("pause");
    mostrarArchivoClases(archivitoClases);
    darAltaClase(archivitoClases, 2);
    darAltaClase(archivitoClases, 3);
    system("pause");
    mostrarArchivoClases(archivitoClases);
    system("pause");
    */
    //mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);

    //mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);
    /*modificarArchivoHabilidades(archivitoHabilidades, 5);
    mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);*/
    //mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);

    return 0;
}


