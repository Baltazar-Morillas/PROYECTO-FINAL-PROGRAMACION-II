#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "Menu.h"
#include "FuncionesHistoria.h"
#include "habilidades.h"
#include "estadisticas.h"
#include "clases.h"
#include "filas.h"
#include "FuncionesPeleas.h"
#include "personajeYenemigos.h"


const char ArchivoP[]="ArchivoPersonajes.bin";
const char archivitoClases[]="archivitoClases.bin";
const char archivitoHabilidades[]="archivitoHabilidades.bin";
const char archivoArbol[] = "archivoLugar.bin";
const char archivoTexto[] = "archivoRelato.bin";
const char archivoEnemigo[]= "ArchivoEnemigos.bin";

int main()
{
    ///admin=admin contrasenia=123

    Menu(ArchivoP,archivitoClases,archivitoHabilidades, archivoArbol, archivoTexto, archivoEnemigo);


    return 0;
}


