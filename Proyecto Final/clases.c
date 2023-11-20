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
