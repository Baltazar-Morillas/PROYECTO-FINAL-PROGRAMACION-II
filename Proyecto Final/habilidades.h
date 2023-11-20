#ifndef HABILIDADES_H_INCLUDED
#define HABILIDADES_H_INCLUDED

///ESTRUCTURAS
 stRegistroHabilidades{
    char nombreHabilidad[30];
    int damage;
    int idHabilidad;
    int mana;
    int idClase;
}stRegistroHabilidades;

typedef struct listaHabilidades{
    char nombre[30];
    int damage;
    int idHabilidad;
    int mana;
    int idClase;
    struct listaHabilidades * siguiente;
}listaHabilidades;


#endif // HABILIDADES_H_INCLUDED
