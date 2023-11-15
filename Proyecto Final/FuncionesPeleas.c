#include "FuncionesPeleas.h"



int funcionDePelea(stPersonaje player, stEnemigo enemy)
{
    int victoria, vidaActual = player, vidaActualEnemigo = enemy.estadisticasE.vitalidad, danioRecibidoP = 0, danioRecibidoE = 0, turno = 1, accionRealizadaJ, accionRealizadaE;
    char matrizEscena[20][50];
    char escena[1000] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char escena2[600] = "001000100011100010010010000010010010010000010100010001001001001001001001001101000000100001000100100100100100100100101100000010000100010010010001010100010010010000001000001110000110000010100001001001000000000000000000000000000000000000000000000000000000000111001000100000000000000000000000000000100010010100000000000000000000000000000001110001110000000000000000000000000000000111000010000000000000000000000000000000101011110000000000000000000000000000000001100000000000000000000000000000000000000010000000000000000000000000000000000000010100000000000000000000000000000000000011011000000000000000000000";
    char escena3[600] = "010100110010010010000110001100111100000001010100101001001000100101000010000000000010010010100100100010010011001111000000001001001010010010001001000010100000000000100011000110001110011000110011110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111110000000000000000000000000000000100000000100000000000000000000000000000010011111010000010000000000000000000000001000000001000011100000000000000000000000100000000100010100000000000000000000000010000000010001000000000000000000000011111111111111111111100000000000000000010000000000000000000001110000000000000";
    do
    {
        cargarMatrizEscena(matrizEscena, escena);
        cajaDeTexto(accionRealizadaJ, danioRecibidoP, danioRecibidoE, turno);
        mostrarEscena(matrizEscena);
        printf("Player ");
        vidaActual = barraDeVida(player.estadisticas.vitalidad, vidaActual,danioRecibidoP);
        printf("    ");
        printf("Enemy");
        vidaActualEnemigo = barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo, danioRecibidoE);
        danioRecibidoP = 0;
        danioRecibidoE = 0;
        if(player.estadisticas.agilidad > enemy.estadisticasE.agilidad)
        {
            accionRealizadaJ = menuCombate(&vidaActual,&vidaActualEnemigo,&danioRecibidoP, &danioRecibidoE, player.estadisticas.ataque);
            accionRealizadaE = accionesEnemigo(&vidaActual, &vidaActualEnemigo, &danioRecibidoP, &danioRecibidoE, enemy.estadisticasE.ataque);
            system("cls");
            cajaDeTexto(accionRealizadaJ, danioRecibidoP, danioRecibidoE, turno);
            mostrarEscena(matrizEscena);
            printf("Player ");
            vidaActual = barraDeVida(player.estadisticas.vitalidad, vidaActual,danioRecibidoP);
            printf("    ");
            printf("Enemy");
            vidaActualEnemigo = barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo, danioRecibidoE);
        }
        else
        {

            accionRealizadaE = accionesEnemigo(&vidaActual, &vidaActualEnemigo, &danioRecibidoP, &danioRecibidoE, enemy.estadisticasE.ataque);
            accionRealizadaJ = menuCombate(&vidaActual,&vidaActualEnemigo,&danioRecibidoP, &danioRecibidoE, player.estadisticas.ataque);
            system("cls");
            cajaDeTexto(accionRealizadaJ, danioRecibidoP, danioRecibidoE, turno);
            mostrarEscena(matrizEscena);
            printf("Player ");
            vidaActual = barraDeVida(player.estadisticas.vitalidad, vidaActual,danioRecibidoP);
            printf("    ");
            printf("Enemy");
            vidaActualEnemigo = barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo, danioRecibidoE);
        }
        turno++;
        system("pause");
        system("cls");

    }
    while(vidaActual > 0 && vidaActualEnemigo > 0);

    if(vidaActual <= 0)
    {
        victoria = 0;
        cargarMatrizEscena(matrizEscena, escena3);
        mostrarEscena(matrizEscena);
    }
    else
    {
        victoria = 1;
        cargarMatrizEscena(matrizEscena, escena2);
        mostrarEscena(matrizEscena);
    }

    return victoria;
}


void cargarMatrizEscena(char matrizEscena[][50], char escena[])
{
    int i, j, t=0;
    for(i=0; i<15; i++)
    {
        for(j=0; j<50; j++)
        {

            if(escena[t] == '1')
            {
                matrizEscena[i][j] = '0';
            }
            else
            {
                matrizEscena[i][j] = '-';
            }
            t++;
        }
    }
}

void mostrarEscena(char escena[][50])
{
    int i, j;


    for(i=0; i<15; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<50; j++)
        {
            printf("%c", escena[i][j]);

        }
        printf("\n");
    }
}

int barraDeVida(int vidaMaxima, int vidaActual, int danioRecibido)
{

    HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(Con, &consoleInfo);
    WORD defautAtt = consoleInfo.wAttributes;

    SetConsoleTextAttribute(Con, FOREGROUND_RED | FOREGROUND_INTENSITY);

    int i = 0, vidaMostrarMaxima = 20;
    float vidaMostrar;

    vidaActual = vidaActual - danioRecibido;
    if(vidaActual < 0)
    {
        vidaActual=0;
    }
    if(vidaActual>vidaMaxima)
    {
        vidaActual = vidaMaxima;
    }
    vidaMostrar= ceil(((float)vidaActual/vidaMaxima) * vidaMostrarMaxima);

    printf("{");
    while(i < vidaMostrar)
    {
        printf("|o");
        i++;
    }
    while(i >= vidaMostrar && i < vidaMostrarMaxima)
    {
        printf("| ");
        i++;
    }
    printf("}");
    SetConsoleTextAttribute(Con, defautAtt);
    printf("%g%%", (vidaMostrar/vidaMostrarMaxima) * 100);





    return vidaActual;

}

int menuCombate(int * vidaActual, int * vidaEnemigo, int * danioRecibidoP, int *danioRecibidoE, int armaJugador)
{
    int eleccion;
    if(*vidaActual > 0)
    {
        printf("\n\n\t\t\t\t1.Pelear   -    2.Habilidades    -     3.items\n");
        do
        {
            scanf("%i", &eleccion);
        }
        while(eleccion>3 || eleccion < 1);

        switch(eleccion)
        {
        case 1:
            *danioRecibidoE = armaJugador;
            break;
        case 2:
            printf("Menu de habilidades anashe\n");
            *danioRecibidoP = -30;
            break;
        case 3:
            printf("Menu de items anashe\n");
            break;
        }
    }
    else
    {
        printf("\nEl enemigo te ha derrotado\n");
    }
    return eleccion;
}

void cajaDeTexto(int eleccion, int danioRecibidoP, int danioRecibidoE, int turno)
{
    printf("\t\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t\tEstas en el turno %i\n", turno);
    if(turno == 1)
    {
        printf("\n");
        printf("\t\t\t\t\tUn monstruo te ataca\n");
        printf("\n");
    }
    else
    {
        switch(eleccion)
        {
        case 1:
            printf("\t\t\t\tRealizaste un ataque\n");
            break;
        case 2:
            printf("\t\t\t\tRealizaste una habilidad\n");
            break;
        case 3:
            printf("\t\t\t\tutilizaste un item\n");
            break;
        }

        if(danioRecibidoP >= 0)
        {
            printf("\t\t\t\tRecibiste %i puntos de daño\n", danioRecibidoP);
        }
        else
        {
            printf("\t\t\t\tTe curaste %i puntos de vida\n", danioRecibidoP);
        }

        if(danioRecibidoE >= 0)
        {
            printf("\t\t\t\tEl enemigo recibio %i puntos de daño\n", danioRecibidoE);
        }
        else
        {
            printf("\t\t\t\tEl enemigo se curo %i puntos de vida\n", danioRecibidoE);
        }
    }

    printf("\t\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
}

int accionesEnemigo(int * vidaActual, int * vidaEnemigo, int * danioRecibidoP, int *danioRecibidoE, int danioE)
{
    int accion;
    srand(time(NULL));
    accion = rand() % 2;

    switch(accion)
    {
    case 0:
        *danioRecibidoP = danioE;
        break;
    case 1:
        printf("El monstruo realizo una habilidad habilidad\n");
        break;
    }
    return accion;

}



///funciones estadisticas temporal



stEstadisticas cargarStats(stEstadisticas a)
{
    printf("vitalidad: ");
    scanf("%i", &a.vitalidad);
    printf("ataque: ");
    scanf("%i", &a.ataque);
    printf("defensa: ");
    scanf("%i", &a.defensa);
    printf("agilidad: ");
    scanf("%i", &a.agilidad);

    return a;
}
