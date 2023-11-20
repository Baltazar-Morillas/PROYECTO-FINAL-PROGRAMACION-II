#include <stdio.h>
#include <stdlib.h>
#include "LibreriaPrincipal.h"



int main()
{
    system("color 0B");

    int victoria;
    stPersonaje player;
    stEnemigo enemy;

    player.clase.estadisticas = cargarStats(player.clase.estadisticas);
    enemy.estadisticasE = cargarStats(enemy.estadisticasE);

    victoria = funcionDePelea(player, enemy);




    return 0;
}
