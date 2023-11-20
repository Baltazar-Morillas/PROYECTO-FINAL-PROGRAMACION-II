#ifndef FUNCIONESHISTORIA_H_INCLUDED
#define FUNCIONESHISTORIA_H_INCLUDED

const char archivoLugar[]="archivoLugar.bin";
const char archivoRelato[]="archivoRelato.bin";

///Estructuras -----------------------------------------------------------------

typedef struct stTexto
{
    char texto[1000];
    int id;

}stTexto;

typedef struct stLugar
{
    char lugar[1000];
    int id;

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
nodoTexto * inicLista();
nodoTexto * crearNodoLista(stTexto a);
arbolLugar * crearArbol(stLugar a);
stLugar copiarLugar(char lugar[], int id);
stTexto copiarTexto(char texto[], int id);
arbolLugar * buscarArbolID(arbolLugar * arbol, int id); //Busca un nodo del arbol por id
arbolLugar * alta(arbolLugar * arbol, stLugar nuevoLugar); //Da de alta un nuevo elemento en el arbol de listas
nodoTexto * buscarUltimoNodoLista(nodoTexto * lista);
arbolLugar * insertarNodoArbol(arbolLugar * arbol, stLugar dato);
nodoTexto * agregarFinalLista(nodoTexto * lista, nodoTexto * nuevoNodo);
void cargarArchivoLugar(stLugar a);
void cargarArchivoTexto(stTexto a);
stLugar cargarRegistro(); //Funcion auxiliar de cargarArchivoLugar
arbolLugar * archivoToArbolDeListas(arbolLugar * arbol);
nodoTexto * archivoToLista(const char archivoRelato[], nodoTexto * lista, int id);
arbolLugar * movermeA(arbolLugar * arbol);


///Funciones mostrado -----------------------------------

void mostrarTexto(stTexto a);
void mostrarLista(nodoTexto * lista);
void mostrarLugar(stLugar a);
void mostrarArbolInOrder(arbolLugar * arbol);
void mostrarListaConPausa(nodoTexto * lista);


#endif // FUNCIONESHISTORIA_H_INCLUDED


