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

void mostrarArchivoHabilidadesAltaOrdenado(char archivito[])
{
    FILE * buffer=fopen(archivito, "rb");
    nodoHabilidades * lista=inicListaHabilidadesRegistro();
    stRegistroHabilidades aux;
    int res=0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.alta==1){
                lista=agregarNodoOrdenadoHabilidades(lista, crearNodoListaHabilidades(aux));
                res=1;
            }
        }
        if(res==0){
            printf("\nNo se encontro ninguna habilidad dada de alta!!!!");
        }else{
            mostrarListaOrdenadaHabilidades(lista);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR NO SE PUDO MOSTRAR EL ARCHIVO DE HABILIDADES!!!!\n");
    }
}

void mostrarListaOrdenadaHabilidades(nodoHabilidades * lista){
    char sw;
    switch(sw=menuMostrarHabilidadOrdenada())
    {
    case '1':
        mostrarListaHabilidadesRecursivaAscendente(lista);
        system("pause");
        break;
    case '2':
        mostrarListaHabilidadesRecursivaDescendente(lista);
        system("pause");
        break;
    }
}

char menuMostrarHabilidadOrdenada()
{
    char opcion;
    do
    {
        system ("cls");
        printf ("\n\n\n\t\t\t\t\tMOSTRAR HABILIDADES\n");
        printf ("\n\t\t\t\t\t[ 1 ] - Mostrar habilidades de forma ascendente");
        printf ("\n\t\t\t\t\t[ 2 ] - Mostrar habilidades de forma descendente");
        printf ("\n\t\t\t\t\t[ 0 ] - Salir\n");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '0' || opcion > '2');
    return opcion;
}

nodoHabilidades * inicListaHabilidadesRegistro()
{
    return NULL;
}

nodoHabilidades * crearNodoListaHabilidades(stRegistroHabilidades dato)
{
    nodoHabilidades * aux = (nodoHabilidades *) malloc(sizeof(nodoHabilidades));
    aux->siguiente=inicListaHabilidadesRegistro();
    aux->registro=dato;
    return aux;
}

nodoHabilidades * agregarNodoOrdenadoHabilidades(nodoHabilidades * lista, nodoHabilidades * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else if(strcmpi(lista->registro.nombreHabilidad, nuevo->registro.nombreHabilidad)>0)
    {
        lista=agregarAlPrincipioListaHabilidades(lista, nuevo);
    }
    else
    {
        nodoHabilidades * ante=lista;
        nodoHabilidades* seg=lista->siguiente;
        while((seg!=NULL) && (strcmpi(seg->registro.nombreHabilidad, nuevo->registro.nombreHabilidad)<0))
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg!=NULL && (strcmpi(seg->registro.nombreHabilidad, nuevo->registro.nombreHabilidad)>0))
        {
            ante->siguiente=nuevo;
            nuevo->siguiente=seg;
        }
        else
        {
            ante->siguiente=nuevo;
        }
    }
    return lista;
}

nodoHabilidades * agregarAlPrincipioListaHabilidades(nodoHabilidades * lista, nodoHabilidades * nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

void mostrarListaHabilidadesRecursivaAscendente(nodoHabilidades * lista)
{
    if(lista!=NULL)
    {
        mostrarHabilidad(lista->registro);
        mostrarListaHabilidadesRecursivaAscendente(lista->siguiente);
    }
}

void mostrarListaHabilidadesRecursivaDescendente(nodoHabilidades * lista)
{
    if(lista!=NULL)
    {
        mostrarListaHabilidadesRecursivaDescendente(lista->siguiente);
        mostrarHabilidad(lista->registro);
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
    printf("\nSPRITE: \n");
    mostrarSprite(aux.sprite);
}

void mostrarSprite(char sprite[]){
    char matrizEscena[20][50];
    cargarMatrizEscena(matrizEscena, sprite);
    mostrarEscena(matrizEscena);
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
                flag=1;
            }
        }
        if(flag==1){
            aux=modificarHabilidades(aux);
            fseek(buffer,sizeof(stRegistroHabilidades)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroHabilidades), 1, buffer);
        }else{
            printf("\nNo se encontro la habilidad que desea modificar!!!");
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
        printf ("\n\t\t\t\t\t[ 1 ] - Nombre habilidad");
        printf ("\n\t\t\t\t\t[ 2 ] - Damage");
        printf ("\n\t\t\t\t\t[ 3 ] - ID habilidad");
        printf ("\n\t\t\t\t\t[ 4 ] - Mana");
        printf ("\n\t\t\t\t\t[ 5 ] - Usos");
        printf ("\n\t\t\t\t\t[ 6 ] - Efectos");
        printf ("\n\t\t\t\t\t[ 7 ] - Clase");
        printf ("\n\t\t\t\t\t[ 8 ] - Sprite");
        printf ("\n\t\t\t\t\t[ 0 ] - Salir\n");
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
    celdaClase[pos].habilidades=agregarAlPrincipioHabilidad(celdaClase[pos].habilidades, lista);
}

listaHabilidades * agregarAlPrincipioHabilidad(listaHabilidades * lista, listaHabilidades * nuevo){
    if(lista==NULL){
        lista=nuevo;
        lista->siguiente = NULL;
    }else{
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
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
    aux->siguiente = NULL;
    aux = registroToLista(aux, dato);
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

void darBajaHabilidad(char archivito[], int idHabilidad){
    FILE * buffer = fopen(archivito, "r+b");
    stRegistroHabilidades aux;
    int flag=0;
    if(buffer){
        while(flag==0 && fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.idHabilidad==idHabilidad)
            {
                flag=1;
            }
        }
        if(flag==1){
            aux.alta=0;
            fseek(buffer,sizeof(stRegistroHabilidades)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroHabilidades), 1, buffer);
        }else{
            printf("\nNo se encontro la habilidad que desea dar de baja!!!!");
        }
        fclose(buffer);
    }else{
        printf("\nERROR, NO SE PUDO DAR DE BAJA LA HABILIDAD PORQUE NO SE ABRIO EL ARCHIVO!!!!\n");
    }
}

void darAltaHabilidad(char archivito[], int idHabilidad){
    FILE * buffer = fopen(archivito, "r+b");
    stRegistroHabilidades aux;
    int flag=0;
    if(buffer){
        while(flag==0 && fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.idHabilidad==idHabilidad)
            {
                flag=1;
            }
        }
        if(flag==1){
            aux.alta=1;
            fseek(buffer,sizeof(stRegistroHabilidades)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroHabilidades), 1, buffer);
        }else{
            printf("\nNo se encontro la habilidad que quiere dar de alta!!!!");
        }
        fclose(buffer);
    }else{
        printf("\nERROR, NO SE PUDO DAR DE BAJA LA HABILIDAD PORQUE NO SE ABRIO EL ARCHIVO!!!!\n");
    }
}

void mostrarArchivoHabilidadesBajaOrdenado(char archivito[])
{
    FILE * buffer=fopen(archivito, "rb");
    nodoHabilidades * lista=inicListaHabilidadesRegistro();
    stRegistroHabilidades aux;
    int res=0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroHabilidades), 1, buffer)>0)
        {
            if(aux.alta==0){
                lista=agregarNodoOrdenadoHabilidades(lista, crearNodoListaHabilidades(aux));
                res=1;
            }
        }
        if(res==0){
            printf("\nNo se encontro ninguna habilidad dada de alta!!!!");
        }else{
            mostrarListaOrdenadaHabilidades(lista);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR NO SE PUDO MOSTRAR EL ARCHIVO DE HABILIDADES!!!!\n");
    }
}
