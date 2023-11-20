#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo * siguiente;
    struct nodo * anterior;
}nodo;

typedef struct Fila{
    struct nodo * inicio;
    struct nodo * fin;
}Fila;


nodo * inicLista();
void inicFila(Fila * fila);
nodo * crearNodo(int num);
nodo * agregarAlFinal(nodo * lista, nodo * nuevo);
void agregar(Fila * fila, int dato);
int verPrimero(nodo * lista);
nodo * borrarPrimero(nodo * lista);
int extraer(Fila * fila);
nodo * buscarUltimo(nodo * lista);
void recorrerYmostrar(nodo * lista);
void mostrarNodo(int dato);
void mostrarFila(Fila * fila);
void leer(Fila * fila);
int primero(Fila * fila);
int filaVacia(Fila * fila);

#endif // FILAS_H_INCLUDED
