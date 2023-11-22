#include "habilidades.h"

void cargarArchivoHabilidades(char archivito[])
{
    FILE * buffer=fopen(archivito, "ab");
    stRegistroHabilidades aux;
    char control = 's';
    if(buffer)
    {
        while(control=='s')
        {
            aux=cargarHabilidad(aux);
            fwrite(&aux, sizeof(stRegistroHabilidades),1,buffer);
            printf("Ingresa s\n para continuar cargando habilidades: ");
            fflush(stdin);
            control=getche();
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR NO SE CARGO EL ARCHIVO DE HABILIDADES!!!!\n");
    }
}

stRegistroHabilidades cargarHabilidad(stRegistroHabilidades aux)
{
    printf("\nIngrese el nombre de la habilidad: ");
    fflush(stdin);
    gets(aux.nombreHabilidad);
    printf("\nIngrese el damage de la habilidad: ");
    scanf("%d", &aux.damage);
    printf("\nIngrese el id de la habilidad: ");
    scanf("%d", &aux.idHabilidad);
    printf("\nIngrese el mana de la habilidad: ");
    scanf("%d", &aux.mana);
    printf("\nIngrese el efecto de la habilidad: ");
    scanf("%d", &aux.efecto);
    printf("\nIngrese los usos de la habilidad: ");
    scanf("%d", &aux.usos);
    printf("\nIngrese el id de la clase de la habilidad: ");
    scanf("%d", &aux.idClase);
    printf("\nIngrese el alta de la clase de la habilidad: ");
    scanf("%d", &aux.alta);
    printf("\nIngrese el sprite de la habilidad: ");
    fflush(stdin);
    gets(aux.sprite);
    return aux;
}

void mostrarArchivitoHabilidades(char archivito[])
{
    FILE * buffer=fopen(archivito, "rb");
    stRegistroHabilidades aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.alta==1){
                mostrarHabilidad(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR NO SE CARGO EL ARCHIVO DE HABILIDADES!!!!\n");
    }
}

void mostrarHabilidad(stRegistroHabilidades aux)
{
    printf("\n--------------------------------");
    printf("\nHABILIDAD: %s", aux.nombreHabilidad);
    printf("\nDAMAGE: %d", aux.damage);
    printf("\nID HABILIDAD: %d", aux.idHabilidad);
    printf("\nMANA: %d", aux.mana);
    printf("\nUSOS: %d", aux.usos);
    printf("\nEFECTO: %d", aux.efecto);
    printf("\nCLASE: %d", aux.idClase);
    printf("\nALTA: %d", aux.alta);
    printf("\nSPRITE: %s", aux.sprite);
}

void modificarArchivoHabilidades(char archivito[], int id)
{
    FILE * buffer=fopen(archivito, "r+b");
    stRegistroHabilidades aux;
    int flag=0;
    if(buffer)
    {
        while(flag==0 && fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.idHabilidad==id)
            {
                fseek(buffer,sizeof(stRegistroHabilidades)*(-1), 1);
                aux=modificarHabilidades(aux);
                fwrite(&aux, sizeof(stRegistroHabilidades), 1, buffer);
                flag=1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR, NO SE MODIFICO EL ARCHIVO DE HABILIDADES!!!!\n");
    }
}

stRegistroHabilidades modificarHabilidades(stRegistroHabilidades aux)
{
    char sw, flag=0;
    do
    {
        sw=menuModificarHabilidades();
        if(sw=='0')
        {
            flag=1;
        }
        else
        {
            aux=modificarCampoHabilidad(aux, sw);
        }
    }
    while(flag==0);
    return aux;
}

stRegistroHabilidades modificarCampoHabilidad(stRegistroHabilidades aux, char sw)
{
    switch(sw)
    {
    case '1':
        printf("\nIngrese el nuevo nombre de la habilidad: ");
        fflush(stdin);
        gets(aux.nombreHabilidad);
        break;
    case '2':
        printf("\nIngrese el damage de la habilidad: ");
        scanf("%d", &aux.damage);
        break;
    case '3':
        printf("\nIngrese el id de la habilidad: ");
        scanf("%d", &aux.idHabilidad);
        break;
    case '4':
        printf("\nIngrese el mana de la habilidad: ");
        scanf("%d", &aux.mana);
        break;
    case '5':
        printf("\nIngrese el efecto de la habilidad: ");
        scanf("%d", &aux.efecto);
        break;
    case '6':
        printf("\nIngrese los usos de la habilidad: ");
        scanf("%d", &aux.usos);
        break;
    case '7':
        printf("\nIngrese el id de la clase: ");
        scanf("%d", &aux.idClase);
        break;
    case '8':
        printf("\nIngrese el nuevo sprite de la habilidad: ");
        fflush(stdin);
        gets(aux.sprite);
        break;
    }
    return aux;
}

char menuModificarHabilidades()
{
    char opcion;
    do
    {
        system ("cls");
        printf ("\n\n\n\t\tMODIFICAR HABILIDADES\n");
        printf ("\n\t\t\t\t\t[ 1 ] - Nombre estructura");
        printf ("\n\t\t\t\t\t[ 2 ] - Damage");
        printf ("\n\t\t\t\t\t[ 3 ] - ID habilidad");
        printf ("\n\t\t\t\t\t[ 4 ] - Mana");
        printf ("\n\t\t\t\t\t[ 5 ] - Usos");
        printf ("\n\t\t\t\t\t[ 6 ] - Efectos");
        printf ("\n\t\t\t\t\t[ 7 ] - Clase");
        printf ("\n\t\t\t\t\t[ 8 ] - Sprite");
        printf ("\n\t\t\t\t\t\[ 0 ] - Salir\n");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '0' || opcion > '9');
    return opcion;
}

void pasarArchivoHabilidadesToCLase(stClase celdaClase[], char archivito[], int validos){
    FILE * buffer=fopen(archivito, "rb");
    stRegistroHabilidades aux;
    if(buffer){
        while(fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0){
            altaHabilidad(celdaClase, aux, validos);

        }
        fclose(buffer);
    }else{
        printf("\nERROR, NO SE PUDO ABRIR EL ARCHIVO!!!!\n");
    }
}

void altaHabilidad(stClase celdaClase[], stRegistroHabilidades habilidad, int validos){
    listaHabilidades * lista=crearNodoLista(habilidad);
    int pos=buscarHabilidadClase(celdaClase, habilidad.idClase, validos);
    printf("%i", pos);
    celdaClase[pos].habilidades=agregarAlFinalHabilidad(celdaClase[pos].habilidades, lista);

}

listaHabilidades * agregarAlFinalHabilidad(listaHabilidades * lista, listaHabilidades * nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        listaHabilidades * ultimo=buscarUltimoHabilidad(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}

listaHabilidades * buscarUltimoHabilidad(listaHabilidades * lista){
    listaHabilidades * seg=lista;
    if(seg!=NULL){
        while(seg->siguiente!=NULL){
            seg=seg->siguiente;
        }
    }
    return seg;
}

int buscarHabilidadClase(stClase celdaClase[], int id, int validos){
    int pos=-1, i=0;
    while(i<validos && pos==-1){
        if(id==celdaClase[i].idClase){
            pos=i;
        }
        i++;
    }
    return pos;
}

listaHabilidades * crearNodoLista(stRegistroHabilidades dato){
    listaHabilidades * aux = (listaHabilidades*) malloc(sizeof(listaHabilidades));
    aux->siguiente=NULL;
    aux=registroToLista(aux, dato);
    return aux;
}

listaHabilidades * registroToLista(listaHabilidades * nodo, stRegistroHabilidades dato){
    nodo->alta=dato.alta;
    nodo->damage=dato.damage;
    nodo->efecto=dato.efecto;
    nodo->idClase=dato.idClase;
    nodo->idHabilidad=dato.idHabilidad;
    nodo->mana=dato.mana;
    strcpy(nodo->nombreHabilidad, dato.nombreHabilidad);
    strcpy(nodo->sprite, dato.sprite);
    nodo->usos=dato.usos;
    return nodo;
}

listaHabilidades * inicListaHabilidad(){
    return NULL;
}
