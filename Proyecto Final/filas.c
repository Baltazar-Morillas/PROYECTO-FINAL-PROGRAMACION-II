#include "filas.h"

nodo * inicLista(){
    return NULL;
}

void inicFila(Fila * fila){
    fila->inicio=inicLista();
    fila->fin=inicLista();
}

nodo * crearNodo(int num){
    nodo * aux = (nodo *) malloc(sizeof(nodo));
    aux->dato=num;
    aux->siguiente=NULL;
    aux->anterior=NULL;
    return aux;
}

nodo * buscarUltimo(nodo * lista)
{
    while(lista->siguiente !=NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nodo * ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevo;
        nuevo->anterior=ultimo;
    }
    return lista;
}

void agregar(Fila * fila, int dato){
    nodo * nuevo = crearNodo(dato);
    if(fila->inicio==NULL){
        fila->inicio=nuevo;
        fila->fin=nuevo;
    }else{
        fila->inicio = agregarAlFinal(fila->inicio, nuevo);
        fila->fin=nuevo;
    }
}

int verPrimero(nodo * lista){
    int res=0;
    if(lista!=NULL){
        res=lista->dato;
    }
    return res;
}

nodo * borrarPrimero(nodo * lista){
    nodo * aux=lista;
    if(lista!=NULL){
        lista=lista->siguiente;
        if(lista!=NULL){
            lista->anterior=NULL;
        }
        free(aux);
    }
    return lista;
}

int extraer(Fila * fila){
    int res;
    if(fila->inicio!=NULL){
        res=verPrimero(fila->inicio);
        fila->inicio=borrarPrimero(fila->inicio);
        if(fila->inicio==NULL){
            fila->fin=inicLista();
        }
    }
    return res;
}

void recorrerYmostrar(nodo * lista){
    nodo * seg=lista;
    while(seg!=NULL){
        mostrarNodo(seg->dato);
        seg=seg->siguiente;
    }
}

void mostrarNodo(int dato){
    printf("|%d| ", dato);
}

void mostrarFila(Fila * fila){
    printf("\nINCIO");
    recorrerYmostrar(fila->inicio);
    printf("\nFIN");
}

void leer(Fila * fila){
    int dato=0;
    printf("\nIngrese un dato a la fila: ");
    scanf("%d", &dato);
    agregar(fila, dato);
}

int primero(Fila * fila){
    int res;
    if(fila->inicio!=NULL){
        res=verPrimero(fila->inicio);
    }
    return res;
}

int filaVacia(Fila * fila){
    int res=0;
    if(fila->inicio==NULL){
        res=1;
    }
    return res;
}
