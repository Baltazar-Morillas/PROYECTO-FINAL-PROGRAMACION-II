#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Usuario.h"

void MostrarPersonaje(Usuario Personaje){

        printf("                               |                                                  |\n");
        printf("                               ||Nombre: %s||\n",Personaje.Nombre);
        printf("                               ||Clase: %s||\n",Personaje.Clase.nombreClase);
        switch(Personaje.Lugar){
        case 1:
            printf("                               ||Lugar: Montanias de Rivia ||\n");
            break;
        case 2:
            printf("                               ||Lugar: Castillo Kaer Morhen ||\n");
            break;
        case 3:
            printf("                               ||Lugar: Cuevas de Aedirn ||\n");
            break;
        case 4:
            printf("                               ||Lugar: Bosque de Sodden ||\n");
            break;
        case 5:
            printf("                               ||Lugar: Profundidades de la Fosa del Diablo ||\n");
            break;
        case 6:
            printf("                               ||Lugar: Fosa del Diablo ||\n");
            break;
        case 7:
            printf("                               ||Lugar: Torre en ruinas del noble ||\n");
            break;
        }
        printf("                               |                                                  |\n");
}

void MostrarHistorial(char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"r+b");
    Usuario aux;

    if(Buffer){
        while(fread(&aux,sizeof(Usuario),1,Buffer)>0){
            if(aux.Clase.alta==0){
            MostrarPersonaje(aux);
            }
        }
        fclose(Buffer);
    }else{
        printf("                               |                                                  |\n");
        printf("                               |    ||----No tiene personajes guardados-----||    |\n");
        printf("                               |                                                  |\n");
    }
}

void BajaPersonaje(char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"r+b");
    Usuario aux;

    if(Buffer){

        fseek(Buffer,sizeof(Usuario)*-1,2);
        fread(&aux,sizeof(Usuario),1,Buffer);

        aux.Clase.alta=0;

        fseek(Buffer,sizeof(Usuario)*-1,2);
        fwrite(&aux,sizeof(Usuario),1,Buffer);

        fclose(Buffer);
    }else{
        printf("ERROR - el archivo no se a abierto correctamente");
    }
}

void MostrarUltimaPartida(char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"r+b");
    Usuario aux;

    if(Buffer){

        fseek(Buffer,sizeof(Usuario)*-1,2);
        fread(&aux,sizeof(Usuario),1,Buffer);

        MostrarPersonaje(aux);

        fclose(Buffer);
    }else{
        printf("ERROR - el archivo no se a abierto correctamente");
    }
}

void UsuarioToarchivo(Usuario personaje,char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"ab");

    if(Buffer){
        fwrite(&personaje,sizeof(Usuario),1,Buffer);
        fclose(Buffer);
    }else{
        printf("ERROR - el archivo no se a abierto correctamente");
    }
}

int VerificarUsuarios(char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"rb");
    Usuario aux;
    int Res=0;

    if(Buffer){
        while(fread(&aux,sizeof(Usuario),1,Buffer)>0 && Res==0){
            if(aux.Clase.alta==1){
                Res=1;
            }
        }
        fclose(Buffer);
    }else{
        printf("ERROR - el archivo no se a abierto correctamente");
    }
    return Res;
}

int IDUsuario(char ArchivoP[]){
    FILE *Buffer = fopen(ArchivoP,"r+b");
    Usuario aux;
    int ID=0;

    if(Buffer){

        fseek(Buffer,sizeof(Usuario)*-1,2);
        fread(&aux,sizeof(Usuario),1,Buffer);

        ID=aux.IdUsuario;

        fclose(Buffer);
    }else{
     //   printf("ERROR - el archivo no se a abierto correctamente");
    }
    return ID;
}
