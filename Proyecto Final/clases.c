#include "clases.h"

void cargarArchivoClases(char archivito[]){
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

void mostrarArchivoClases(char archivito[]){
    FILE * buffer=fopen(archivito, "rb");
    stRegistroClase aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stRegistroClase), 1, buffer)>0)
        {
            if(aux.alta==1){
                mostrarClase(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nERROR AL MOSTRAR EL ARCHIVO DE CLASES!!!!\n");
    }
}

void mostrarClase(stRegistroClase aux)
{
    printf("\n--------------------------------");
    printf("\nCLASE: %s", aux.nombreClase);
    printf("\nID CLASE: %d", aux.idClase);
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
                fseek(buffer,sizeof(stRegistroClase)*(-1), 1);
                aux=modificarClases(aux);
                fwrite(&aux, sizeof(stRegistroClase), 1, buffer);
                flag=1;
            }
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
        scanf("%d", &aux.estadisticas.defensa);
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
        printf ("\n\n\n\t\t\t\t\tMODIFICAR CLASES\n");
        printf ("\n\t\t\t\t\t[ 1 ] - Nombre clase");
        printf ("\n\t\t\t\t\t[ 2 ] - ID clase");
        printf ("\n\t\t\t\t\t[ 3 ] - Vitalidad");
        printf ("\n\t\t\t\t\t[ 4 ] - Defensa");
        printf ("\n\t\t\t\t\t[ 5 ] - Ataque");
        printf ("\n\t\t\t\t\t[ 6 ] - Mana");
        printf ("\n\t\t\t\t\t[ 7 ] - Agilidad");
        printf ("\n\t\t\t\t\t[ 8 ] - Critico");
        printf ("\n\t\t\t\t\t[ 0 ] - Salir\n");
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
        printf ("\n\t\t\t\t\t[ 4 ] - ARQUERO");
        fflush(stdin);
        opcion = getche();
    }
    while(opcion < '1' || opcion > '4');
    return opcion;
}

int pasarArchivoClaseToCelda(char archivito[], stClase celdaClase[], int dimension){
    FILE * buffer = fopen(archivito, "rb");
    int validos=0;
    stRegistroClase aux;
    if(buffer){
        while(fread(&aux, sizeof(stRegistroClase), 1, buffer)>0){
            validos=altaClase(celdaClase, aux, validos);
        }
        fclose(buffer);
    }else{
        printf("\nERROR, AL ABRIR EL ARCHIVO DE CLASES!!!!\n");
    }
    return validos;
}

int altaClase(stClase celdaClase[], stRegistroClase aux, int validos){
    stEstadisticas stats = crearEstructuraEstadisticas(aux.estadisticas);
    int pos=buscarClaseCelda(celdaClase, aux, validos);
    if(pos==-1){
        validos=crearNuevaClase(celdaClase, aux, validos);
        pos=validos-1;
    }
    celdaClase[pos].estadisticas=stats;
    return validos;
}

int buscarClaseCelda(stClase celdaClase[], stRegistroClase clase, int validos){
    int pos=-1, i=0;
    while(i<validos && pos==-1){
        if((strcmpi(clase.nombreClase, celdaClase[i].nombreClase)==0) && (clase.idClase==celdaClase[validos].idClase)){
            pos=i;
        }
        i++;
    }
    return pos;
}

int crearNuevaClase(stClase celdaClase[], stRegistroClase nuevo, int validos){
    celdaClase[validos].alta=nuevo.alta;
    celdaClase[validos].idClase=nuevo.idClase;
    celdaClase[validos].habilidades=inicLista();
    strcpy(celdaClase[validos].nombreClase, nuevo.nombreClase);
    validos++;
    return validos;
}
