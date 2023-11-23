#ifndef FUNCIONESHISTORIA_H_INCLUDED
#define FUNCIONESHISTORIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "conio.h"
#include "Usuario.h"
#include "FuncionesPeleas.h"
#include "personajeYenemigos.h"
#include "estadisticas.h"


///Estructuras -----------------------------------------------------------------

typedef struct stTexto
{
    char texto[1000];
    int id;
    int momento;
    int baja; ///Cuando se inicializa baja esta en 1(significa que esta activo el nodo), cuando se da de baja se lo coloca en 0

}stTexto;

typedef struct stLugar
{
    char lugar[1000];
    int id;
    int baja;///Cuando se inicializa baja esta en 1(significa que esta activo el nodo), cuando se da de baja se lo coloca en 0

} stLugar;

typedef struct arbolLugar
{
    stLugar dato;
    struct nodoTexto * lista;
    struct arbolLugar * izq;
    struct arbolLugar * der;

} arbolLugar;

typedef struct nodoTexto
{
    stTexto dato;
    struct nodoTexto * siguiente;

} nodoTexto;

///Prototipados--------------------------------------------------------

arbolLugar * inicArbol();
nodoTexto * inicListaTexto();
nodoTexto * crearNodoListaTexto(stTexto a);
arbolLugar * crearArbol(stLugar a);
stLugar copiarLugar(char lugar[], int id);
stTexto copiarTexto(char texto[], int id);
arbolLugar * buscarArbolID(arbolLugar * arbol, int id); //Busca un nodo del arbol por id
arbolLugar * alta(char archivo[], arbolLugar * arbol, stLugar nuevoLugar); //Da de alta un nuevo elemento en el arbol de listas
nodoTexto * buscarUltimoNodoLista(nodoTexto * lista);
arbolLugar * insertarNodoArbol(arbolLugar * arbol, stLugar dato);
nodoTexto * agregarFinalLista(nodoTexto * lista, nodoTexto * nuevoNodo);
void cargarArchivoLugar(char archivo[], stLugar a);
void cargarArchivoTexto(char archivo[], stTexto a);
stLugar cargarRegistro(); //Funcion auxiliar de cargarArchivoLugar
arbolLugar * archivoToArbolDeListas(char archivo[], arbolLugar * arbol);
nodoTexto * archivoToLista(const char archivoRelato[], nodoTexto * lista, int id);
arbolLugar * movermeA(arbolLugar * arbol, int combateMoment, Usuario player, char archivoEnemigo[]);

///Funciones Alta, Baja y Modificado ------------------------------------
//Funcs. Lugar
void darDeBajaLugarArchivo(); //Da de baja un lugar en el archivo
void modificarLugarArchivo(); //Modifica un lugar en el archivo
stLugar modificarLugar(stLugar a); //Func. Aux de modificarLugarArchivo
//Funcs. Texto
void mostrarTextoConIDyCombateMoment(stTexto a);
void darDeBajaTextoArchivo(); //Da de baja un texto en el archivo
void modificarTextoArchivo(); //Modifica un texto en el archivo
stTexto modificarTexto(stTexto a); //Func. Aux de modificarTextoArchivo
void darDeAltaLugarArchivo();

///Funciones mostrado ---------------------------------------------------

void mostrarTexto(stTexto a);
void mostrarLista(nodoTexto * lista, int combateMoment);
void mostrarLugar(stLugar a);
void mostrarArbolInOrder(arbolLugar * arbol, int combateMoment);
void mostrarListaConPausa(nodoTexto * lista, int combateMoment, int id);
void mostrarArchivoLugar(char archivoLugar[]);
int mostrarArchivoLugarAlta(char archivoLugar[]);
int mostrarArchivoLugarBaja(char archivoLugar[]);
void mostrarArchivoTexto(char archivoRelato[]);
int mostrarArchivoTextoAlta(char archivoRelato[]);
int mostrarArchivoTextoBaja(char archivoRelato[]);




#endif // FUNCIONESHISTORIA_H_INCLUDED


