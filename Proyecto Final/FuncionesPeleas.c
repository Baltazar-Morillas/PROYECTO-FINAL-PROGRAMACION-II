#include "FuncionesPeleas.h"




int funcionDePelea(stPersonaje player, stEnemigo enemy, int pocionRoja, int pocionAzul)
{

    Fila * accionesCombate;
    inicFila(accionesCombate);

    int victoria, bombaHumo = 0, vidaActual = player.clase.estadisticas.vitalidad, vidaActualEnemigo = enemy.estadisticasE.vitalidad, manaActual = player.clase.estadisticas.mana, turno = 1;

    char matrizEscena[20][50];
    char escena[1000] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char escena2[600] = "001000100011100010010010000010010010010000010100010001001001001001001001001101000000100001000100100100100100100100101100000010000100010010010001010100010010010000001000001110000110000010100001001001000000000000000000000000000000000000000000000000000000000111001000100000000000000000000000000000100010010100000000000000000000000000000001110001110000000000000000000000000000000111000010000000000000000000000000000000101011110000000000000000000000000000000001100000000000000000000000000000000000000010000000000000000000000000000000000000010100000000000000000000000000000000000011011000000000000000000000";
    char escena3[600] = "010100110010010010000110001100111100000001010100101001001000100101000010000000000010010010100100100010010011001111000000001001001010010010001001000010100000000000100011000110001110011000110011110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111110000000000000000000000000000000100000000100000000000000000000000000000010011111010000010000000000000000000000001000000001000011100000000000000000000000100000000100010100000000000000000000000010000000010001000000000000000000000011111111111111111111100000000000000000010000000000000000000001110000000000000";

    while(bombaHumo == 0 && vidaActual > 0 && vidaActualEnemigo > 0)
    {
        cargarMatrizEscena(matrizEscena, escena);
        dibujarEscena(player, enemy, vidaActual, vidaActualEnemigo, manaActual, accionesCombate, matrizEscena, turno);
        menuCombate(&vidaActual,&vidaActualEnemigo, &pocionRoja, &pocionAzul, &bombaHumo, player, enemy, accionesCombate);
        accionesEnemigo(&vidaActual, &vidaActualEnemigo, player, enemy, accionesCombate);
        system("cls");
        if(bombaHumo == 0)
        {
            dibujarEscena(player, enemy, vidaActual, vidaActualEnemigo, manaActual, accionesCombate, matrizEscena, turno);
            turno++;
            system("pause");
            system("cls");
        }


    }



    if(bombaHumo == 1)
    {
        printf("Te escapaste anashe\n");
        victoria = 1;
    }
    else if(vidaActual <= 0)
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

void dibujarEscena(stPersonaje player, stEnemigo enemy, int vidaActual, int vidaActualEnemigo, int manaActual, Fila * accionesCombate, char matrizEscena[][50], int turno)
{
    cajaDeTexto(accionesCombate, turno);
    mostrarEscena(matrizEscena);
    printf("\t\t\tPlayer \t\t\t\t\t\t\t Enemy\n");
    printf(" Vida:");
    barraDeVida(player.clase.estadisticas.vitalidad, vidaActual);
    printf("    Vida:");
    barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo);
    printf("\n");
    printf(" Mana:");
    barraDeMana(player.clase.estadisticas.mana, manaActual);
    printf("\n");
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

void barraDeVida(int vidaMaxima, int vidaActual)
{

    HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(Con, &consoleInfo);
    WORD defautAtt = consoleInfo.wAttributes;

    SetConsoleTextAttribute(Con, FOREGROUND_RED | FOREGROUND_INTENSITY);

    int i = 0, vidaMostrarMaxima = 20;
    float vidaMostrar;

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
    printf("%i/%i", vidaActual, vidaMaxima);

}


void barraDeMana(int manaMaximo, int manaActual)
{

    HANDLE Con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(Con, &consoleInfo);
    WORD defautAtt = consoleInfo.wAttributes;

    SetConsoleTextAttribute(Con, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

    int i = 0, manaMostrarMaximo = 20;
    float manaMostrar;

    if(manaActual < 0)
    {
        manaActual=0;
    }
    if(manaActual>manaMaximo)
    {
        manaActual = manaMaximo;
    }
    manaMostrar= ceil(((float)manaActual/manaMaximo) * manaMostrarMaximo);

    printf("{");
    while(i < manaMostrar)
    {
        printf("|o");
        i++;
    }
    while(i >= manaMostrar && i < manaMostrarMaximo)
    {
        printf("| ");
        i++;
    }
    printf("}");
    SetConsoleTextAttribute(Con, defautAtt);
    printf("%i/%i", manaActual, manaMaximo);

}

void menuCombate(int * vidaActual, int * vidaEnemigo, int * pocionRoja, int * pocionAzul, int * bombaHumo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate)
{
    int eleccion, flag = 0, criticHit, critic = 21-player.clase.estadisticas.critico,succesfulDodge, dodge = 21 - enemy.estadisticasE.agilidad;
    srand(time(NULL));
    if(*vidaActual > 0)
    {
        printf("\n\n\t\t\t\t1.Pelear   -    2.Habilidades    -     3.items\n");

        while(flag == 0)
        {
            do
            {
                scanf("%i", &eleccion);
            }
            while(eleccion>3 || eleccion < 1);


            switch(eleccion)
            {
            case 1:
                succesfulDodge = rand() % dodge;

                if(succesfulDodge != 0)
                {

                    criticHit = rand() % critic;
                    if(criticHit == 0)
                    {
                        *vidaEnemigo = *vidaEnemigo - ((player.clase.estadisticas.ataque * enemy.estadisticasE.defensa)*2);
                    }
                    else
                    {
                        *vidaEnemigo = *vidaEnemigo - (player.clase.estadisticas.ataque * enemy.estadisticasE.defensa);
                    }
                    agregar(accionesCombate, 0);
                    if(criticHit == 0)
                    {
                        agregar(accionesCombate, 5);
                    }
                }
                else
                {
                    agregar(accionesCombate, 6);
                }
                flag = 1;
                break;
            case 2:
                printf("Menu de habilidades anashe\n");
                flag = 1;
                agregar(accionesCombate, 1);
                break;
            case 3:
                items(vidaActual, vidaEnemigo, pocionRoja, pocionAzul, bombaHumo);
                agregar(accionesCombate, 2);
                if(*bombaHumo == 1)
                {
                    flag = 1;
                }
                break;
            }

        }
    }
    else
    {
        printf("\nEl enemigo te ha derrotado\n");
    }


}

void cajaDeTexto(Fila * accionesCombate, int turno)
{
    printf("\t\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
    printf("\t\t\t\t\tEstas en el turno %i\n\n", turno);
    if(turno == 1)
    {
        printf("\n");
        printf("\t\t\t\t\tUn monstruo te ataca\n");
    }


    while(!filaVacia(accionesCombate))
    {
        switch(extraer(accionesCombate))
        {
        case 0:
            printf("\t\t\t\t\tRealizaste un ataque!\n");
            break;
        case 1:
            printf("\t\t\t\t\tUtilizaste una habilidad!\n");
            break;
        case 2:
            printf("\t\t\t\t\tUsaste un item!\n");
            break;
        case 3:
            printf("\t\t\t\t\tEl enemigo te ataco!\n");
            break;
        case 4:
            printf("\t\t\t\t\tEl enemigo uso una habilidad!\n");
            break;
        case 5:
            printf("\t\t\t\t\tFue un ataque critico!\n");
            break;
        case 6:
            printf("\t\t\t\t\tEl enemigo esquivo tu ataque!\n");
            break;
        case 7:
            printf("\t\t\t\t\tEsquivaste el ataque!\n");
            break;
        case 8:
            printf("\t\t\t\t\tRealizaste un ataque\n");
            break;
        }
    }



    printf("\n\t\t\t\t++++++++++++++++++++++++++++++++++++++++\n");
}

int accionesEnemigo(int * vidaActual, int * vidaEnemigo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate)
{
    int accion, criticHit, critic = 19 - enemy.estadisticasE.critico, succesfulDodge, dodge = 21 - player.clase.estadisticas.agilidad;
    srand(time(NULL));
    accion = rand() % 2;
    switch(accion)
    {
    case 0:
        succesfulDodge = rand() % dodge;

        if(succesfulDodge != 0)
        {
            criticHit = rand() % critic;
            if(criticHit == 0)
            {
                *vidaActual = *vidaActual - ((enemy.estadisticasE.ataque * player.clase.estadisticas.defensa)*2);
            }
            else
            {
                *vidaActual = *vidaActual - (enemy.estadisticasE.ataque * player.clase.estadisticas.defensa);
            }
            agregar(accionesCombate, 3);
        }
        else
        {
            agregar(accionesCombate, 7);
        }
        break;
    case 1:
        printf("El monstruo realizo una habilidad habilidad\n");
        agregar(accionesCombate, 4);
        break;
    }
    return accion;

}


void items(int * vidaActual, int * manaActual, int * pocionRoja, int * pocionAzul, int * bombaHumo)
{
    char eleccion, confirmar;
    int flag = 0;
    printf("\t\t\t1.Pocion roja x %i 2.Pocion azul x %i 3.Bomba de humo 0.salir\n", *pocionRoja, *pocionAzul);


    do
    {


        do
        {
            fflush(stdin);
            scanf("%c", &eleccion);
        }
        while(eleccion < 0 && eleccion > 3);

        switch(eleccion)
        {
        case '0':
            flag == 1;
            break;
        case '1':
            if(*pocionRoja > 0)
            {
                (*vidaActual) = (*vidaActual) + 50;
                (*pocionRoja) = * pocionRoja - 1;
                flag = 1;
            }
            else
            {
                printf("No te quedan pociones rojas\n");
            }
            break;
        case '2':
            if(*pocionAzul > 0)
            {
                (*manaActual) = (*manaActual) + 50;
                (*pocionAzul) = *pocionAzul - 1;
                flag = 1;
            }
            else
            {
                printf("No te quedan pociones azules\n");
            }
            break;
        case '3':

            printf("Seguro que quiere escapar del combate? s/n :");
            do
            {
                fflush(stdin);
                scanf("%c", &confirmar);
            }
            while(confirmar != 's' && confirmar != 'n');
            if(confirmar == 's')
            {
                *bombaHumo = 1;
                flag = 1;
            }

            break;
        }
    }
    while(flag == 0);


    if(*bombaHumo == 0)
    {
        printf("\nQue accion desea realizar ahora? :");
    }
}


