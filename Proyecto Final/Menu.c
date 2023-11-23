#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Menu.h"
#include "clases.h"
#include "FuncionesHistoria.h"
#include "habilidades.h"
#include "FuncionesPeleas.h"
#include "Usuario.h"
#include"filas.h"

void Menu(char ArchivoP[],char archivitoClases[],char archivitoHabilidades[], char archivoArbol[], char archivoTexto[], char archivoEnemigo[])
{
    stClase celdaClase[10];

    int validos = pasarArchivoClaseToCelda(archivitoClases, celdaClase, 10);
    pasarArchivoHabilidadesToCLase(celdaClase, archivitoHabilidades, validos);
    arbolLugar * arbolHistoria= inicArbol();
    arbolHistoria = archivoToArbolDeListas(archivoArbol,archivoTexto, arbolHistoria);


    stEnemigo enemy;

    int f=0;
    Usuario Personaje;

    if(VerificarUsuarios(ArchivoP)==1)
    {
        do
        {
            InicioConPartidas();
            switch(getche())
            {
            case '1':
                ContinuarPartida(ArchivoP,celdaClase,validos);
                break;
            case '2':
                Historial(ArchivoP);
                break;
            case '3':
                Admin(archivitoClases,archivitoHabilidades,archivoTexto,archivoEnemigo,archivoArbol);
            default:
                f=1;
            }
        }
        while(f==0);
    }
    else
    {
        do
        {
            InicioSinPartidas();
            switch(getche())
            {
            case '1':
                Personaje=NuevaPartida(ArchivoP,celdaClase,validos);
                arbolHistoria = movermeA(arbolHistoria, 0, Personaje, archivoEnemigo);


                break;
            case '2':
                Historial(ArchivoP);
                break;
            case '3':
                Admin(archivitoClases,archivitoHabilidades,archivoTexto,archivoEnemigo,archivoArbol);
                break;
            default:
                f=1;
            }
        }
        while(f==0);
    }
    system("cls");
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |               ||Gracias Por Jugar||              |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");

}

void InicioConPartidas()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD defaultAttributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Obtener información de la consola
    defaultAttributes = consoleInfo.wAttributes;

    system("cls");
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("(^\\()_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      Escoge tu aventura      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("_()/^)");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("    |\n");
    printf("                               |     ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf(">/(_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("                                ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("_)\\<");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("     |\n");
    printf("                               |    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("(/\\\\");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("                                   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\\\\)_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("   |\n");
    printf("                               |      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("/|");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      [1]-Continuar Partida-[1]     ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\\  `");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("  |\n");
    printf("                               |      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("``");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      [2]-----Historial-----[2]      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("`");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("    |\n");
    printf("                               |              [3]-------Admin-------[3]           |\n");
    printf("                               |                                                  |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");
    SetConsoleTextAttribute(hConsole, defaultAttributes);

}

void InicioSinPartidas()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Obtener el identificador de la consola

    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD defaultAttributes;

    GetConsoleScreenBufferInfo(hConsole, &consoleInfo); // Obtener información de la consola
    defaultAttributes = consoleInfo.wAttributes;

    system("cls");
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("(^\\()_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      Escoge tu aventura      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("_()/^)");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("    |\n");
    printf("                               |     ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf(">/(_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("                                ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("_)\\<");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("     |\n");
    printf("                               |    ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("(/\\\\");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("                                   ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\\\\)_");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("   |\n");
    printf("                               |      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("/|");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      [1]-Nueva Partida-[1]         ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("\\  `");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("  |\n");
    printf("                               |      ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("``");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("      [2]---Historial---[2]          ");
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("`");
    SetConsoleTextAttribute(hConsole, defaultAttributes);
    printf("    |\n");
    printf("                               |              [3]-----Admin-----[3]               |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");
    SetConsoleTextAttribute(hConsole, defaultAttributes);


}

void ContinuarPartida(char ArchivoP[],stClase celdaClase[], int validos)
{

    system("cls");

    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |              ||-Desea Continuar?-||              |\n");
    MostrarUltimaPartida(ArchivoP);
    printf("                               |                                                  |\n");
    printf("                               |              [1]------SI-------[1]               |\n");
    printf("                               |              [2]------NO-------[2]               |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");

    switch(getche())
    {
    case '1':

        break;
    case '2':
        BajaPersonaje(ArchivoP);
        NuevaPartida(ArchivoP,celdaClase,validos);

        break;
    }
}

Usuario NuevaPartida(char ArchivoP[],stClase celdaClase[], int validos)
{

    char escena[1000] ="1100000000000000000000001000000000000111110000001110000000100000000000000010000000100010000010001001011100001111111111111000100000010101000111000101000101111110000000000001001000100010010001000000100001011001111111111111111010010100001000001000010000010111111000000000000100100010000110000011001010000111000011111111111110001000000010000000001001000000000000100000000000000010000000111111111110000000000000000000000000000000100000000000000000000000001111111111111111111111111111111111111111111111111100000000000000000000000010000000000010000000000000000000111111111111000000100000011111111111000000000000010000000000001000001000001001001001001000000000000101001111001010000010000100111111111001000000000001000100001000100000100010010000100001001000000000001001000010010000001000101000001000001010000000000010001111000100000010010010000010000010010000000000010000000010000000100101111111111111110100001000000011111111000000001001110000001000000111000111000000000000000000000010000000000111000000000011";
    char matrizEscena[20][50];

    srand(time(NULL));
    Usuario Personaje;

    int f=0;

    system("cls");
    Personaje.IdUsuario=IDUsuario(ArchivoP);
    Personaje.Clase.alta=0;
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |      ||------Como quieres llamarte?-----||       |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");
    printf("||-->>");
    fflush(stdin);
    gets(Personaje.Nombre);

    system("cls");
    do
    {

        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |           | |--Escoge una clase--| |             |\n");
        printf("                               |                                                  |\n");
        printf("                               |           [1]------Guerrero------[1]             |\n");
        printf("                               |           [2]--------Mago--------[2]             |\n");
        printf("                               |           [3]-------Tanque-------[3]             |\n");
        printf("                               |           [4]------Arquero-------[4]             |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n\n");
        cargarMatrizEscena(matrizEscena,escena);
        mostrarEscena(matrizEscena);
        printf("||-->>");
        switch(getche())
        {
        case '1':
            Personaje=cargarClasePersonaje(celdaClase, 1, Personaje, validos);
            f=1;
            break;
        case '2':
            Personaje=cargarClasePersonaje(celdaClase, 2, Personaje, validos);
            f=1;
            break;
        case '3':
            Personaje=cargarClasePersonaje(celdaClase, 3, Personaje, validos);
            f=1;
            break;
        case '4':
            Personaje=cargarClasePersonaje(celdaClase, 4, Personaje, validos);
            f=1;
            break;
        default:
            system("cls");
            printf("                               /--------------------------------------------------\\\n");
            printf("                               |     | |Clase Inexsistente Intente de nuevo| |     |\n");
            printf("                               \\--------------------------------------------------/\n\n");
        }
    }
    while(f==0);
    system("cls");

    UsuarioToarchivo(Personaje,ArchivoP);
    return Personaje;

}

void Historial(char ArchivoP[])
{

    system("cls");

    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |              ||----Historial-----||              |\n");
    MostrarHistorial(ArchivoP);
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");

    system("pause");
}

void Admin(char archivitoClases[],char archivitoHabilidades[],char archivoTexto[],char archivoEnemigo[],char archivoArbol[])
{

    int id=0,F1=0,Contrasenia=0;
    char admin[50];
    system("cls");
    do
    {
        if(strcmpi(admin,"admin")!=0 && Contrasenia!=123){
        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |              | |Ingrese Usuario| |               |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");
        printf("||-->>");
        fflush(stdin);
        scanf("%s",&admin);
        system("cls");


        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |            | |Ingrese Contrasenia| |             |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");
        printf("||-->>");
        scanf("%i",&Contrasenia);
        }

        if(strcmpi(admin,"admin")==0 && Contrasenia==123){
        int F2=0;
        system("cls");

        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |              | |-----Admin-----| |               |\n");
        printf("                               |                                                  |\n");
        printf("                               |              [1]----Clases-----[1]               |\n");
        printf("                               |              [2]--Habilidades--[2]               |\n");
        printf("                               |              [3]---Enemigos----[3]               |\n");
        printf("                               |              [4]----Lugares----[4]               |\n");
        printf("                               |              [5]-----Texto-----[5]               |\n");
        printf("                               |              [0]-----Salir-----[0]               |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");

        switch(getche())
        {
        case '1':

            do
            {

                int res=0;
                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |----Clases-----| |               |\n");
                printf("                               |                                                  |\n");
                printf("                               |              [1]-----Crear-----[1]               |\n");
                printf("                               |              [2]--Dar de baja--[2]               |\n");
                printf("                               |              [3]--Dar de alta--[3]               |\n");
                printf("                               |              [4]---Modificar---[4]               |\n");
                printf("                               |              [0]----Salir------[0]               |\n");
                printf("                               |                                                  |\n");
                printf("                               \\--------------------------------------------------/\n");

                switch(getche())
                {
                case '1':
                    system("cls");

                    cargarArchivoClases(archivitoClases);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoAltaClasesOrdenado(archivitoClases);

                    if(res==1)
                    {

                        printf("\nIngrese ID de la clase que quiera dar de ALTA\n");
                        printf("||-->>");
                        scanf("%i",&id);

                        darBajaClase(archivitoClases,id);
                    }
                    break;
                case '3':
                    system("cls");
                    res=mostrarClasesBajasArchivoOrdenado(archivitoClases);


                    if(res==1)
                    {

                        printf("\nIngrese ID de la clase que quiera dar de BAJA\n");
                        printf("||-->>");
                        scanf("%i",&id);

                        darAltaClase(archivitoClases,id);
                    }
                    break;
                case '4':
                    system("cls");
                    printf("                                              | |----Baja-----| |                \n");
                    mostrarClasesBajasArchivoOrdenado(archivitoClases);
                    printf("                                              | |----Alta-----| |                \n");
                    mostrarArchivoAltaClasesOrdenado(archivitoClases);

                    printf("\nIngrese ID de la clase que quiera MODIFICAR\n");
                    printf("||-->>");
                    scanf("%i",&id);

                    modificarArchivoClases(archivitoClases,id);
                    break;
                default:
                    F2=1;
                }

            }
            while(F2==0);

            break;

        case '2':

            do
            {
                int res=0;
                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |--Habilidades--| |               |\n");
                printf("                               |                                                  |\n");
                printf("                               |              [1]-----Crear-----[1]               |\n");
                printf("                               |              [2]--Dar de baja--[2]               |\n");
                printf("                               |              [3]--Dar de alta--[3]               |\n");
                printf("                               |              [4]---Modificar---[4]               |\n");
                printf("                               |              [0]----Salir------[0]               |\n");
                printf("                               |                                                  |\n");
                printf("                               \\--------------------------------------------------/\n");

                switch(getche())
                {
                case '1':
                    system("cls");

                    cargarArchivoHabilidades(archivitoHabilidades);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);
                    if(res==1)
                    {

                        printf("\nIngrese ID de la Habilidad que quiera dar de ALTA\n");
                        printf("||-->>");
                        scanf("%i",&id);
                        darBajaHabilidad(archivitoHabilidades,id);
                    }

                    break;
                case '3':
                    system("cls");
                    res=mostrarArchivoHabilidadesBajaOrdenado(archivitoHabilidades);
                    if(res==1)
                    {

                        printf("\nIngrese ID de la Habilidad que quiera dar de BAJA\n");
                        printf("||-->>");
                        scanf("%i",&id);
                        darAltaHabilidad(archivitoHabilidades,id);
                    }
                    break;
                case '4':
                    system("cls");
                    printf("                                              | |----Baja-----| |                \n");
                    mostrarArchivoHabilidadesBajaOrdenado(archivitoHabilidades);
                    printf("                                              | |----Alta-----| |                \n");
                    mostrarArchivoHabilidadesAltaOrdenado(archivitoHabilidades);

                    printf("\nIngrese ID de la Habilidad que quiera MODIFICAR\n");
                    printf("||-->>");
                    scanf("%i",&id);

                    modificarArchivoHabilidades(archivitoHabilidades,id);
                    break;
                default:
                    F2=1;
                }

            }
            while(F2==0);

            break;
        case '3':

            do
            {
                int res=0;
                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |---Enemigos----| |               |\n");
                printf("                               |                                                  |\n");
                printf("                               |              [1]-----Crear-----[1]               |\n");
                printf("                               |              [2]--Dar de baja--[2]               |\n");
                printf("                               |              [3]--Dar de alta--[3]               |\n");
                printf("                               |              [4]---Modificar---[4]               |\n");
                printf("                               |              [0]----Salir------[0]               |\n");
                printf("                               |                                                  |\n");
                printf("                               \\--------------------------------------------------/\n");

                switch(getche())
                {
                case '1':
                    system("cls");
                    cargarEnemigoArchivo(archivoEnemigo);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoEnemigoBaja(archivoEnemigo);

                    if(res==1)
                    {
                        darAltaEnemigo(archivoEnemigo);
                    }
                    break;
                case '3':
                    system("cls");
                    res=mostrarArchivoEnemigoAlta(archivoEnemigo);

                    if(res==1)
                    {

                        darBajaEnemigo(archivoEnemigo);
                    }
                    break;
                case '4':
                    system("cls");
                    printf("                                              | |----Baja-----| |                \n");
                    mostrarArchivoEnemigoBaja(archivoEnemigo);
                    printf("                                              | |----Alta-----| |                \n");
                    mostrarArchivoEnemigoAlta(archivoEnemigo);

                    modificarEnemigoArchivo(archivitoHabilidades);
                    break;
                default:
                    F2=1;
                }
            }
            while(F2==0);

            break;
        case '4':
            do
            {
                int res=0;
                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |-----Lugar-----| |               |\n");
                printf("                               |                                                  |\n");
                printf("                               |              [1]-----Crear-----[1]               |\n");
                printf("                               |              [2]--Dar de baja--[2]               |\n");
                printf("                               |              [3]--Dar de alta--[3]               |\n");
                printf("                               |              [4]---Modificar---[4]               |\n");
                printf("                               |              [0]----Salir------[0]               |\n");
                printf("                               |                                                  |\n");
                printf("                               \\--------------------------------------------------/\n");

                switch(getche())
                {
                case '1':
                    system("cls");
                    cargarArchivoLugar(archivoArbol);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoLugarBaja(archivoArbol);

                    if(res==1)
                    {

                        printf("\nIngrese ID del Lugar que quiera dar de BAJA\n");
                        printf("||-->>");
                        scanf("%i",&id);
                        darDeBajaLugarArchivo(archivoArbol,id);
                    }
                    break;
                case '3':
                    system("cls");
                    res=mostrarArchivoLugarAlta(archivoArbol);

                    if(res==1)
                    {
                        printf("\nIngrese ID del lugar que quiera dar de ALTA\n");
                        printf("||-->>");
                        scanf("%i",&id);

                        darDeAltaLugarArchivo(archivoArbol);
                    }
                    break;
                case '4':
                    system("cls");
                    printf("                                              | |----Baja-----| |                \n");
                    mostrarArchivoLugarBaja(archivoArbol);
                    printf("                                              | |----Alta-----| |                \n");
                    mostrarArchivoLugarAlta(archivoArbol);



                    modificarLugarArchivo(archivoArbol);
                    break;
                default:
                    F2=1;
                }
            }
            while(F2==0);
            break;

        case '5':

            do{
            int res=0;


                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |-----Texto-----| |               |\n");
                printf("                               |                                                  |\n");
                printf("                               |              [1]-----Crear-----[1]               |\n");
                printf("                               |              [2]--Dar de baja--[2]               |\n");
                printf("                               |              [3]---Modificar---[3]               |\n");
                printf("                               |              [0]----Salir------[0]               |\n");
                printf("                               |                                                  |\n");
                printf("                               \\--------------------------------------------------/\n");

                switch(getche())
                {
                case '1':
                    system("cls");
                    cargarArchivoTexto(archivoTexto);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoTextoAlta(archivoTexto);
                    if(res==1)
                    {

                        printf("\nIngrese ID del texto que quiera dar de BAJA\n");
                        printf("||-->>");
                        scanf("%i",&id);
                        darDeBajaTextoArchivo(archivoTexto);
                    }
                    break;
                case '3':
                    system("cls");
                    mostrarArchivoTextoBaja(archivoTexto);
                    mostrarArchivoTextoAlta(archivoTexto);

                    printf("\nIngrese ID del texto que quiera MODIFICAR\n");
                    printf("||-->>");
                    scanf("%i",&id);
                    modificarTextoArchivo(archivitoHabilidades,id);

                    break;
                default:
                    F2=1;
                }
            }
            while(F2==0);
            break;
        default:
            F1=1;
        }
        }else{
            system("cls");
            printf("                               /--------------------------------------------------\\\n");
            printf("                               |   ||EL usuario o la contrasenia Son incorrectos|| |\n");
            printf("                               |             ||Intente de nuevamente||             |\n");
            printf("                               \\--------------------------------------------------/\n\n");
    }
    }while(F1==0);

}









