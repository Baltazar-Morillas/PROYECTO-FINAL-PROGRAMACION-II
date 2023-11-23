#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "Menu.h"
#include "clases.h"
#include "habilidades.h"
#include "FuncionesPeleas.h"
#include "Usuario.h"

void Menu(char ArchivoP[],char archivitoClases[],char archivitoHabilidades[]){

    int f=0;

    if(VerificarUsuarios(ArchivoP)==1){
        do{
            InicioConPartidas();
            switch(getche()){
            case '1':
                ContinuarPartida(ArchivoP);
                break;
            case '2':
                Historial(ArchivoP);
                break;
            case '3':
                Admin(archivitoClases,archivitoHabilidades);
                default:
                f=1;
            }
        }while(f==0);
    }else{
        do{
            InicioSinPartidas();
            switch(getche()){
            case '1':

                NuevaPartida(ArchivoP);
                break;
            case '2':
                Historial(ArchivoP);
                break;
            case '3':
                Admin(archivitoClases,archivitoHabilidades);
                break;
                default:
                f=1;
            }
        }while(f==0);
    }
    system("cls");
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |               ||Gracias Por Jugar||              |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");

}

void InicioConPartidas(){

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

void InicioSinPartidas(){

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

void ContinuarPartida(char ArchivoP[]){

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

    switch(getche()){
    case '1':

        break;
    case '2':
        BajaPersonaje(ArchivoP);
        NuevaPartida(ArchivoP);
        break;
    }
}

void NuevaPartida(char ArchivoP[]){

    char escena[1000] ="1100000000000000000000001000000000000111110000001110000000100000000000000010000000100010000010001001011100001111111111111000100000010101000111000101000101111110000000000001001000100010010001000000100001011001111111111111111010010100001000001000010000010111111000000000000100100010000110000011001010000111000011111111111110001000000010000000001001000000000000100000000000000010000000111111111110000000000000000000000000000000100000000000000000000000001111111111111111111111111111111111111111111111111100000000000000000000000010000000000010000000000000000000111111111111000000100000011111111111000000000000010000000000001000001000001001001001001000000000000101001111001010000010000100111111111001000000000001000100001000100000100010010000100001001000000000001001000010010000001000101000001000001010000000000010001111000100000010010010000010000010010000000000010000000010000000100101111111111111110100001000000011111111000000001001110000001000000111000111000000000000000000000010000000000111000000000011";
    char matrizEscena[20][50];

    srand(time(NULL));
    Usuario Personaje;

    int f=0;

    system("cls");
    Personaje.IdUsuario=IDUsuario(ArchivoP);
    Personaje.Clase.alta=0;
    Personaje.Lugar = rand() % 7 + 1;
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |      ||------Como quieres llamarte?-----||       |\n");
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");
    printf("||-->>");
    fflush(stdin);
    gets(Personaje.Nombre);

    do{

        system("cls");
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
        switch(getche()){
        case '1':
            Personaje.Clase.idClase=1;
            strcpy(Personaje.Clase.nombreClase,"Guerrero");
            break;
        case '2':
            Personaje.Clase.idClase=2;
            strcpy(Personaje.Clase.nombreClase,"Mago");
            break;
        case '3':
            Personaje.Clase.idClase=3;
            strcpy(Personaje.Clase.nombreClase,"Tanque");
            break;
        case '4':
            Personaje.Clase.idClase=4;
            strcpy(Personaje.Clase.nombreClase,"Arquero");
            break;
        default:
            f=1;
        }
    }while(f==0);

    UsuarioToarchivo(Personaje,ArchivoP);

}

void Historial(char ArchivoP[]){

    system("cls");

    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               |              ||----Historial-----||              |\n");
    MostrarHistorial(ArchivoP);
    printf("                               |                                                  |\n");
    printf("                               \\--------------------------------------------------/\n");

    system("pause");
}

void Admin(char archivitoClases[],char archivitoHabilidades[]){

    int id=0,F1=0;

    do{
        int F2=0;
        system("cls");

        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |              | |-----Admin-----| |               |\n");
        printf("                               |                                                  |\n");
        printf("                               |              [1]----Clases-----[1]               |\n");
        printf("                               |              [2]--Habilidades--[2]               |\n");
        printf("                               |              [3]---Enemigos----[3]               |\n");
        printf("                               |              [4]---Historia----[4]               |\n");
        printf("                               |              [0]----Salir------[0]               |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");

        switch(getche())
        {
        case '1':

            do{

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

                switch(getche()){
                case '1':
                    system("cls");

                    cargarArchivoClases(archivitoClases);
                    break;
                case '2':
                    system("cls");
                    res=mostrarArchivoAltaClasesOrdenado(archivitoClases);

                    if(res==1){

                    printf("\nIngrese ID de la clase que quiera dar de ALTA\n");
                    printf("||-->>");
                    scanf("%i",&id);

                    darBajaClase(archivitoClases,id);
                    }
                    break;
                case '3':
                    system("cls");
                    res=mostrarClasesBajasArchivoOrdenado(archivitoClases);


                    if(res==1){

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

            }while(F2==0);

            break;

        case '2':

            do{
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
                    if(res==1){

                    printf("\nIngrese ID de la clase que quiera dar de ALTA\n");
                    printf("||-->>");
                    scanf("%i",&id);
                    darBajaHabilidad(archivitoHabilidades,id);
                    }

                    break;
                case '3':
                    system("cls");
                    res=mostrarArchivoHabilidadesBajaOrdenado(archivitoHabilidades);
                    if(res==1){

                    printf("\nIngrese ID de la clase que quiera dar de BAJA\n");
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

                    printf("\nIngrese ID de la clase que quiera MODIFICAR\n");
                    printf("||-->>");
                    scanf("%i",&id);

                    modificarArchivoHabilidades(archivitoHabilidades,id);
                    break;
                    default:
                    F2=1;
                }

            }while(F2==0);

            break;
        case '3':

            do{

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

                    break;
                case '2':
                    system("cls");

                    break;
                case '3':
                    system("cls");

                    break;
                case '4':
                    system("cls");

                    break;
                    default:
                    F2=1;
                }
            }while(F2==0);

            break;
        case '4':

            do{

                system("cls");

                printf("                               /--------------------------------------------------\\\n");
                printf("                               |                                                  |\n");
                printf("                               |              | |---Historia----| |               |\n");
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

                    break;
                case '2':
                    system("cls");

                    break;
                case '3':
                    system("cls");

                    break;
                case '4':
                    system("cls");

                    break;
                    default:
                    F2=1;
                    }
            }while(F2==0);

            break;
            default:
            F1=1;
        }
    }while(F1==0);
}









