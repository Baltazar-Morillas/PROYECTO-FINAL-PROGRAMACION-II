#include "clases.h"

void cargarArchivoClases(char archivito[])
{
    FILE * buffer = fopen(archivito, "ab");
    stRegistroClase aux;
    char control = 's';
    if(buffer)
    {
        while(control=='s')
        {
            aux=cargarClase(aux);
            fwrite(&aux, sizeof(stRegistroClase),1,buffer);
            printf("Ingresa s\n para continuar cargando clases: ");
            fflush(stdin);
            control=getche();
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR NO SE CARGO EL ARCHIVO DE CLASES!!!!\n");
    }
}

stRegistroClase cargarClase(stRegistroClase aux)
{
    printf("\nIngrese el nombre de la clase: ");
    fflush(stdin);
    gets(aux.nombreClase);
    printf("\nIngrese el id de la clase: ");
    scanf("%d", &aux.idClase);
    printf("\nIngrese el alta de la clase: ");
    scanf("%d", &aux.alta);
    aux.estadisticas=cargarStats(aux.estadisticas);
    return aux;
}

nodoClases * inicListaClases()
{
    return NULL;
}

nodoClases * crearNodoListaClase(stRegistroClase dato)
{
    nodoClases * aux = (nodoClases *) malloc(sizeof(nodoClases));
    aux->siguiente=inicListaClases();
    aux->registro=dato;
    return aux;
}

nodoClases * agregarAlPrincipioListaClase(nodoClases * lista, nodoClases * nuevo){
    if(lista==NULL){
        lista=nuevo;
    }else{
        nuevo->siguiente=lista;
        lista=nuevo;
    }
    return lista;
}

nodoClases * agregarNodoOrdenadoClases(nodoClases * lista, nodoClases * nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else if(strcmpi(lista->registro.nombreClase, nuevo->registro.nombreClase)>0)
    {
        lista=agregarAlPrincipioListaClase(lista, nuevo);
    }
    else
    {
        nodoClases * ante=lista;
        nodoClases * seg=lista->siguiente;
        while((seg!=NULL) && (strcmpi(seg->registro.nombreClase, nuevo->registro.nombreClase)<0))
        {
            ante=seg;
            seg=seg->siguiente;
        }
        if(seg!=NULL && (strcmpi(seg->registro.nombreClase, nuevo->registro.nombreClase)>0))
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

int mostrarArchivoAltaClasesOrdenado(char archivito[])
{
    FILE * buffer=fopen(archivito, "rb");
    nodoClases * lista=inicListaClases();
    stRegistroClase aux;
    int res=0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroClase), 1, buffer)>0)
        {
            if(aux.alta==1)
            {
                lista = agregarNodoOrdenadoClases(lista, crearNodoListaClase(aux));
                res=1;
            }
        }
        if(res==0)
        {
            printf("\nNo se encontro ninguna clase dada de alta!!!\n");
            system("pause");
        }else{
            mostrarListaOrdenadaClases(lista);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR AL MOSTRAR EL ARCHIVO DE CLASES!!!!\n");
    }
    return res;
}

void mostrarListaOrdenadaClases(nodoClases * lista)
{
    char sw;
    switch(sw=menuMostrarClaseOrdenada())
    {
    case '1':
        mostrarListaClasesRecursivaAscendente(lista);

        break;
    case '2':
        mostrarListaClasesRecursivaDescendiente(lista);

        break;
    }
}

char menuMostrarClaseOrdenada()
{
    char opcion;
    do
    {

        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |     | |----------Mostrar Clases----------| |     |\n");
        printf("                               |                                                  |\n");
        printf("                               |     [1]Mostrar clase de forma ascendente-[1]     |\n");
        printf("                               |     [2]Mostrar clase de forma descendente[2]     |\n");
        printf("                               |     [0]---------------Salir--------------[0]     |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '0' || opcion > '2');
    return opcion;
}

void mostrarListaClasesRecursivaAscendente(nodoClases * lista)
{
    if(lista!=NULL)
    {
        mostrarClase(lista->registro);
        mostrarListaClasesRecursivaAscendente(lista->siguiente);
    }
}

void mostrarListaClasesRecursivaDescendiente(nodoClases * lista)
{
    if(lista!=NULL)
    {
        mostrarListaClasesRecursivaAscendente(lista->siguiente);
        mostrarClase(lista->registro);
    }
}

void mostrarClase(stRegistroClase aux)
{
    printf("                               /--------------------------------------------------\\\n");
    printf("                               |                                                  |\n");
    printf("                               ||Clase: %s||\n",aux.nombreClase);
    printf("                               ||IDClase: %d||\n",aux.idClase);
    printf("                               ||Alta: %d||\n",aux.alta);
    mostrarEstadisticas(aux.estadisticas);
}

void modificarArchivoClases(char archivito[], int id)
{
    FILE * buffer=fopen(archivito, "r+b");
    stRegistroClase aux;
    int flag=0;
    if(buffer)
    {
        while(flag==0 && fread(&aux, sizeof(stRegistroClase), 1, buffer)>0)
        {
            if(aux.idClase==id)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            aux=modificarClases(aux);
            fseek(buffer,sizeof(stRegistroClase)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroClase), 1, buffer);
        }
        else
        {
            printf("\nNo se encontro la habilidad que se desea modificar!!!");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR AL MODIFICAR EL ARCHIVO DE CLASES!!!!\n");
    }
}

stRegistroClase modificarClases(stRegistroClase aux)
{
    char sw, flag=0;
    do
    {
        sw=menuModificarClases(sw);
        if(sw=='0')
        {
            flag=1;
        }
        else
        {
            aux=modificarCampoClase(aux, sw);
        }
    }
    while(flag==0);
    return aux;
}

stRegistroClase modificarCampoClase(stRegistroClase aux, char sw)
{
    switch(sw)
    {
    case '1':
        printf("\nIngrese el nuevo nombre de la clase: ");
        fflush(stdin);
        gets(aux.nombreClase);
        break;
    case '2':
        printf("\nIngrese el id de la clase: ");
        scanf("%d", &aux.idClase);
        break;
    case '3':
        printf("\nIngrese la vitalidad de la clase: ");
        scanf("%d", &aux.estadisticas.vitalidad);
        break;
    case '4':
        printf("\nIngrese la defensa de la habilidad: ");
        scanf("%f", &aux.estadisticas.defensa);
        break;
    case '5':
        printf("\nIngrese el ataque de la clase: ");
        scanf("%d", &aux.estadisticas.ataque);
        break;
    case '6':
        printf("\nIngrese el mana de la clase: ");
        scanf("%d", &aux.estadisticas.mana);
        break;
    case '7':
        printf("\nIngrese la agilidad de la clase: ");
        scanf("%d", &aux.estadisticas.agilidad);
        break;
    case '8':
        printf("\nIngrese el critico de la clase: ");
        scanf("%d", &aux.estadisticas.critico);
        break;
    }
    return aux;
}

char menuModificarClases()
{
    char opcion;
    do
    {
        system ("cls");
        printf("                               /--------------------------------------------------\\\n");
        printf("                               |                                                  |\n");
        printf("                               |             | |Modificar Clases| |               |\n");
        printf("                               |                                                  |\n");
        printf("                               |             [1]-----Nombre-----[1]               |\n");
        printf("                               |             [2]-------ID-------[2]               |\n");
        printf("                               |             [3]----Vitalidad---[3]               |\n");
        printf("                               |             [4]-----Defensa----[4]               |\n");
        printf("                               |             [5]-----Ataque-----[5]               |\n");
        printf("                               |             [6]------Mana------[6]               |\n");
        printf("                               |             [7]----Agilidad----[7]               |\n");
        printf("                               |             [8]----Critico-----[8]               |\n");
        printf("                               |             [0]------Salir-----[0]               |\n");
        printf("                               |                                                  |\n");
        printf("                               \\--------------------------------------------------/\n");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '0' || opcion > '9');
    return opcion;
}

char menuClases()
{
    char opcion;
    do
    {
        system ("cls");
        printf ("\n\n\n\t\t\t\t\t CLASES\n");
        printf ("\n\t\t\t\t\t[ 1 ] - GUERRERO");
        printf ("\n\t\t\t\t\t[ 2 ] - MAGO");
        printf ("\n\t\t\t\t\t[ 3 ] - TANQUE");
        printf ("\n\t\t\t\t\t[ 4 ] - ARQUERO\n");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '1' || opcion > '4');
    return opcion;
}

int pasarArchivoClaseToCelda(char archivito[], stClase celdaClase[], int dimension)
{
    FILE * buffer = fopen(archivito, "rb");
    int validos=0;
    stRegistroClase aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroClase), 1, buffer)>0)
        {
            validos=altaClase(celdaClase, aux, validos);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR, AL ABRIR EL ARCHIVO DE CLASES!!!!\n");
    }
    return validos;
}

int altaClase(stClase celdaClase[], stRegistroClase aux, int validos)
{
    stEstadisticas stats = crearEstructuraEstadisticas(aux.estadisticas);
    int pos=buscarClaseCelda(celdaClase, aux, validos);
    if(pos==-1)
    {
        validos=crearNuevaClase(celdaClase, aux, validos);
        pos=validos-1;
    }
    celdaClase[pos].estadisticas=stats;
    return validos;
}

int buscarClaseCelda(stClase celdaClase[], stRegistroClase clase, int validos)
{
    int pos=-1, i=0;
    while(i<validos && pos==-1)
    {
        if((strcmpi(clase.nombreClase, celdaClase[i].nombreClase)==0) && (clase.idClase==celdaClase[validos].idClase))
        {
            pos=i;
        }
        i++;
    }
    return pos;
}

int crearNuevaClase(stClase celdaClase[], stRegistroClase nuevo, int validos)
{
    celdaClase[validos].alta=nuevo.alta;
    celdaClase[validos].idClase=nuevo.idClase;
    celdaClase[validos].habilidades = inicListaHabilidad();
    strcpy(celdaClase[validos].nombreClase, nuevo.nombreClase);
    validos++;
    return validos;
}

void darBajaClase(char archivito[], int idClase)
{
    FILE * buffer = fopen(archivito, "r+b");
    stRegistroClase aux;
    int flag=0;
    if(buffer)
    {
        while((flag==0) && (fread(&aux, sizeof(stRegistroClase), 1, buffer)>0))
        {
            if(aux.idClase==idClase)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            aux.alta=0;
            fseek(buffer,sizeof(stRegistroClase)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroClase), 1, buffer);
        }
        else
        {
            printf("\nNo se encontro la clase que quiere dar de baja!!!!");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR, NO SE PUDO DAR DE BAJA LA CLASE PORQUE NO SE ABRIO EL ARCHIVO!!!!\n");
    }
}

void darAltaClase(char archivito[], int idClase)
{
    FILE * buffer = fopen(archivito, "r+b");
    stRegistroClase aux;
    int flag=0;
    if(buffer)
    {
        while((flag==0) && (fread(&aux, sizeof(stRegistroClase), 1, buffer)>0))
        {
            if(aux.idClase==idClase)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            aux.alta=1;
            fseek(buffer,sizeof(stRegistroClase)*(-1), 1);
            fwrite(&aux, sizeof(stRegistroClase), 1, buffer);
        }
        else
        {
            printf("\nNo se encontro la clase que quiere dar de alta!!");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR, NO SE PUDO DAR DE BAJA LA CLASE PORQUE NO SE ABRIO EL ARCHIVO!!!!\n");
    }
}

int mostrarClasesBajasArchivoOrdenado(char archivito[])
{
    FILE * buffer=fopen(archivito, "rb");
    nodoClases * lista=inicListaClases();
    stRegistroClase aux;
    int res=0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroClase), 1, buffer)>0)
        {
            if(aux.alta==0)
            {
                lista = agregarNodoOrdenadoClases(lista, crearNodoListaClase(aux));
                res=1;
            }
        }
        if(res==0)
        {
            printf("\nNo se encontro ninguna clase dada de Baja!!!\n");
            system("pause");
        }else{
            mostrarListaOrdenadaClases(lista);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR AL MOSTRAR EL ARCHIVO DE CLASES!!!!\n");
    }
    return res;
}
