#include "FuncionesPeleas.h"

stPersonaje cargarPersonaje(stClase celdaClase[], int validos){
    stPersonaje personaje;
    char opcion;
    printf("\nIngrese el nombre de su personaje: ");
    fflush(stdin);
    gets(personaje.nombre);
    switch(opcion=menuClases()){
    case '1':
        personaje=cargarClasePersonaje(celdaClase, 1, personaje, validos);
        break;
    case '2':
        personaje=cargarClasePersonaje(celdaClase, 2, personaje, validos);
        break;
    case '3':
        personaje=cargarClasePersonaje(celdaClase, 3, personaje, validos);
        break;
    case '4':
        personaje=cargarClasePersonaje(celdaClase, 4, personaje, validos);
        break;
    }
    return personaje;
}

stPersonaje cargarClasePersonaje(stClase celdaClase[], int id, stPersonaje personaje, int validos){
    int flag=0, i=0;
    while(i<validos && flag==0){
        if(id==celdaClase[i].idClase){
            personaje.clase=celdaClase[i];
            flag=1;
        }
        i++;
    }
    return personaje;
}

void mostrarPersonaje(stPersonaje personaje){
    char res;
    printf("\nNOMBRE: %s", personaje.nombre);
    printf("\nCLASE: %s", personaje.clase.nombreClase);
    printf("\nID CLASE: %d", personaje.clase.idClase);
    printf("\nIngrese s/n para ver las estadisticas del personaje: ");
    fflush(stdin);
    res=getche();
    if(res=='s'){
        system("cls");
        printf("ESTADISTICAS");
        mostrarEstadisticas(personaje.clase.estadisticas);
    }
}
/*
int funcionDePelea(stPersonaje player, stEnemigo enemy)
{
    Fila * accionesCombate;
    inicFila(accionesCombate);
    int victoria, vidaActual = player.clase.estadisticas.vitalidad, vidaActualEnemigo = enemy.estadisticasE.vitalidad,danioRecibidoP, danioRecibidoE, turno = 1, accionRealizadaJ, accionRealizadaE;
    char matrizEscena[20][50];
    char escena[1000] = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    char escena2[600] = "001000100011100010010010000010010010010000010100010001001001001001001001001101000000100001000100100100100100100100101100000010000100010010010001010100010010010000001000001110000110000010100001001001000000000000000000000000000000000000000000000000000000000111001000100000000000000000000000000000100010010100000000000000000000000000000001110001110000000000000000000000000000000111000010000000000000000000000000000000101011110000000000000000000000000000000001100000000000000000000000000000000000000010000000000000000000000000000000000000010100000000000000000000000000000000000011011000000000000000000000";
    char escena3[600] = "010100110010010010000110001100111100000001010100101001001000100101000010000000000010010010100100100010010011001111000000001001001010010010001001000010100000000000100011000110001110011000110011110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111111110000000000000000000000000000000100000000100000000000000000000000000000010011111010000010000000000000000000000001000000001000011100000000000000000000000100000000100010100000000000000000000000010000000010001000000000000000000000011111111111111111111100000000000000000010000000000000000000001110000000000000";
    do
    {
        cargarMatrizEscena(matrizEscena, escena);
        cajaDeTexto(accionesCombate, turno);
        mostrarEscena(matrizEscena);
        printf("Player ");
        vidaActual = barraDeVida(player.clase.estadisticas.vitalidad, vidaActual);
        printf("    ");
        printf("Enemy");
        vidaActualEnemigo = barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo);
        accionRealizadaJ = menuCombate(&vidaActual,&vidaActualEnemigo, player, enemy, accionesCombate);
        accionRealizadaE = accionesEnemigo(&vidaActual, &vidaActualEnemigo, player, enemy, accionesCombate);
        system("cls");
        cajaDeTexto(accionesCombate, turno);
        mostrarEscena(matrizEscena);
        printf("Player ");
        vidaActual = barraDeVida(player.clase.estadisticas.vitalidad, vidaActual);
        printf("    ");
        printf("Enemy");
        vidaActualEnemigo = barraDeVida(enemy.estadisticasE.vitalidad, vidaActualEnemigo);

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

int barraDeVida(int vidaMaxima, int vidaActual)
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





    return vidaActual;

}

int menuCombate(int * vidaActual, int * vidaEnemigo, stPersonaje player, stEnemigo enemy, Fila * accionesCombate)
{
    int eleccion, criticHit, critic = 21-player.clase.estadisticas.critico,succesfulDodge, dodge = 21 - enemy.estadisticasE.agilidad;
    srand(time(NULL));
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
            break;
        case 2:
            printf("Menu de habilidades anashe\n");
            agregar(accionesCombate, 1);
            break;
        case 3:
            printf("Menu de items anashe\n");
            agregar(accionesCombate, 3);
            break;
        }


    }
    else
    {
        printf("\nEl enemigo te ha derrotado\n");
    }
    return eleccion;
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
            printf("\t\t\t\t\tRealizaste un ataque\n");
            break;
        case 1:
            printf("\t\t\t\t\tUtilizaste una habilidad\n");
            break;
        case 2:
            printf("\t\t\t\t\tUsaste un item\n");
            break;
        case 3:
            printf("\t\t\t\t\tEl enemigo te ataco\n");
            break;
        case 4:
            printf("\t\t\t\t\tEl enemigo uso una habilidad\n");
            break;
        case 5:
            printf("\t\t\t\t\tFue un ataque critico!\n");
            break;
        case 6:
            printf("\t\t\t\t\tEl enemigo esquivo tu ataque!\n");
            break;
        case 7:
            printf("\t\t\t\t\tRealizaste un ataque\n");
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
            agregar(accionesCombate, 6);
        }
        break;
    case 1:
        printf("El monstruo realizo una habilidad habilidad\n");
        agregar(accionesCombate, 4);
        break;
    }
    return accion;

}
*/
