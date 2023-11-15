#include <stdio.h>
#include <stdlib.h>
#include "LibreriaPrincipal.h"
#include "FuncionesPeleas.h"


int main()
{
    system("color 0B");

    int victoria;
    stPersonaje player;
    stEnemigo enemy;

    player.estadisticas = cargarStats(player.estadisticas);
    enemy.estadisticasE = cargarStats(enemy.estadisticasE);

    victoria = funcionDePelea(player, enemy);




    return 0;
}
