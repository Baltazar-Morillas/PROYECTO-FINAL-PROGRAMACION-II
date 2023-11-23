#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "clases.h"

typedef struct Usuario{
    int IdUsuario;
    char Nombre[20];
    stClase Clase;
    int Lugar;
} Usuario;

void MostrarPersonaje(Usuario Personaje);
Usuario cargarClasePersonaje(stClase celdaClase[], int id, Usuario personaje, int validos);
void MostrarHistorial(char ArchivoP[]);
void BajaPersonaje(char ArchivoP[]);
void MostrarUltimaPartida(char ArchivoP[]);
void UsuarioToarchivo(Usuario personaje,char ArchivoP[]);
int VerificarUsuarios(char ArchivoP[]);
int IDUsuario(char ArchivoP[]);

#endif // LISTAS_H_INCLUDED
