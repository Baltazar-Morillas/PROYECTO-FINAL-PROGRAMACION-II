#ifndef HABILIDADES_H_INCLUDED
#define HABILIDADES_H_INCLUDED

///ESTRUCTURAS
typedef struct stRegistroHabilidades{
    char nombreHabilidad[30];
    int damage;
    int idHabilidad;
}stRegistroHabilidades;

typedef struct listaHabilidades{
    char nombre[30];
    int damage;
    int idHabilidad;
    struct listaHabilidades * siguiente;
}listaHabilidades;


#endif // HABILIDADES_H_INCLUDED
