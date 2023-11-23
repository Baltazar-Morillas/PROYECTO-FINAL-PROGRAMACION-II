#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Usuario.h"
#include "filas.h"

void Menu(char ArchivoP[],char archivitoClases[],char archivitoHabilidades[], char archivoArbol[], char archivoTexto[], char archivoEnemigo[], Fila * accionesCombate);
void InicioConPartidas();
void InicioSinPartidas();
void ContinuarPartida(char ArchivoP[],stClase celdaClase[], int validos);
Usuario NuevaPartida(char ArchivoP[],stClase celdaClase[], int validos);
void Historial(char ArchivoP[]);
void Admin(char archivitoClases[],char archivitoHabilidades[]);


#endif // MENU_H_INCLUDED
