#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "clases.h"

typedef struct Usuario{
    int IdUsuario;
    char Nombre[20];
    stClase Clase;
    int Lugar;
} Usuario;

typedef struct NodoL{
     Usuario dato;
     struct NodoL * siguiente;
} NodoL;



void InicLista(NodoL** lista);
NodoL* CrearNodo(Usuario dato);
NodoL* BuscarUltimo(NodoL**lista);
void AgregarFinal(NodoL** lista,Usuario Dato);
void MostrarPersonaje(Usuario Personaje);
void MostrarHistorial(char ArchivoP[]);
void BajaPersonaje(char ArchivoP[]);
void MostrarUltimaPartida(char ArchivoP[]);
void UsuarioToarchivo(Usuario personaje,char ArchivoP[]);
void ArchivoToLista(NodoL **Lista);
int VerificarUsuarios(char ArchivoP[]);
int IDUsuario(char ArchivoP[]);

#endif // LISTAS_H_INCLUDED
