#include "personajeYenemigos.h"

int mostrarArchivoEnemigoAlta(char archivoLugar[])
{
    FILE * buffer = fopen(archivoLugar, "rb"); ///devuelve 1 si tiene elementos dados de alta, 0 si no
    int flag = 0;
    stEnemigo aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stEnemigo), 1, buffer) > 0)
        {
            if(aux.alta == 1)
            {
                mostrarEnemigo(aux);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo no se pudo abrir\n");
    }
     return flag;

}

int mostrarArchivoEnemigoBaja(char archivoLugar[])
{
    FILE * buffer = fopen(archivoLugar, "rb"); ///devuelve 1 si tiene elementos dados de alta, 0 si no
    int flag = 0;
    stEnemigo aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stEnemigo), 1, buffer) > 0)
        {
            if(aux.alta == 0)
            {
                mostrarEnemigo(aux);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo no se pudo abrir\n");
    }
     return flag;

}

void mostrarEnemigo(stEnemigo a)
{
    printf("ID: %d \n", a.IdEnemigo);
    printf("Nombre: %s \n", a.nombreE);
    mostrarEstadisticas(a.estadisticasE);
    mostrarSprite(a.sprite);
}

stEstadisticas modificarStatsEnemigos(stEstadisticas a)
{
    int f = 0, nuevaAgilidad=0, nuevoAtaque=0, nuevoCritico=0, nuevoMana=0;
    float nuevaDefensa=0, nuevaVitalidad=0;
    char sw;

    printf("Que quiere modificar? 1: agilidad / 2: ataque / 3: critico / 4: defensa / 5: mana / 6: vitalidad / Cualquier otro caracter para dejar de cargar \n");
    sw = getche();

    do
    {
        switch(sw)
        {
        case '1':
            printf("Ingrese nueva Agilidad: \n");
            scanf("%d", &nuevaAgilidad);
            a.agilidad = nuevaAgilidad;
            break;
        case '2':
            printf("Ingrese nuevo Ataque: \n");
            scanf("%d", &nuevoAtaque);
            a.ataque = nuevoAtaque;
            break;
        case '3':
            printf("Ingrese nuevo Critico: \n");
            scanf("%d", &nuevoCritico);
            a.critico = nuevoCritico;
            break;
        case '4':
            printf("Ingrese nueva Defensa: \n");
            scanf("%f", &nuevaDefensa);
            a.defensa = nuevaDefensa;
            break;
        case '5':
            printf("Ingrese nuevo Mana: \n");
            scanf("%d", &nuevoMana);
            a.mana = nuevoMana;
            break;
        case '6':
            printf("Ingrese nueva Vitalidad: \n");
            scanf("%f", &nuevaVitalidad);
            a.vitalidad = nuevaVitalidad;
            break;
        default:
            f = 1;
        }
    }while(f == 0);

    return a;
}

stEnemigo modificarEnemigo(stEnemigo a)
{
    int nuevoID=0;
    char sw, nuevoSprite[1000], nuevoNombre[50];
    printf("Que quiere modificar? 1: Estadisticas / 2: ID / 3: Nombre / 4: Sprite \n");
    sw = getche();

    switch(sw)
    {
    case '1':
        a.estadisticasE=modificarStatsEnemigos(a.estadisticasE);
        break;
    case '2':
        printf("Ingrese el nuevo ID: \n");
        scanf("%d", &nuevoID);
        break;
    case '3':
        printf("Ingrese el nuevo nombre: \n");
        fflush(stdin);
        gets(nuevoNombre);
        break;
    case '4':
        printf("Ingrese el nuevo sprite: \n");
        fflush(stdin);
        gets(nuevoSprite);
        break;
    default:
        printf("Opcion incorrecta \n");
    }
    return a;
}

void modificarEnemigoArchivo(char archivoEnemigos[])
{
    FILE * buffer = fopen(archivoEnemigos, "r+b");
    int id=0, flag = 0;
    stEnemigo aux;

    printf("Ingrese ID del enemigo a modificar: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stEnemigo), 1, buffer)>0)
        {
            if(aux.IdEnemigo == id)
            {

                flag = 1;
            }
        }
        if(flag == 1)
        {
            aux=modificarEnemigo(aux);
                fseek(buffer, (long)sizeof(stEnemigo)* -1, 1);
                fwrite(&aux, sizeof(stEnemigo), 1, buffer);
        }
        else
        {
            printf("no se encontro");
        }

        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

void darAltaEnemigo(char archivoEnemigos[])
{
    FILE * buffer = fopen(archivoEnemigos, "r+b");
    int id=0, i=0, posAlta = -1, posBaja = -1;
    stEnemigo aux, alta, baja;

    printf("Ingrese ID del enemigo a dar de alta: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(fread(&aux, sizeof(stEnemigo), 1, buffer)>0)
        {
            if(aux.alta == 0 && aux.IdEnemigo == id)
            {
                baja=aux;
                posBaja = i;
            }

            if(aux.alta == 1 && aux.IdEnemigo == id)
            {
                alta=aux;
                posAlta == i;
            }
            i++;

        }

        if(posBaja == -1)
        {
            printf("No se encontro un enemigo dado de baja con esa id\n");
        }
        else if( (posBaja =! -1) && (posAlta != -1))
        {
            printf("Se encontro un enemigo con la misma id que el que esta dado de baja.\nDaremos la daremos de baja para evitar conflictos\n");
            fseek(buffer, sizeof(stEnemigo)*posAlta, 0);
            alta.alta = 0;
            fwrite(&alta, sizeof(stEnemigo), 1, buffer);
            fseek(buffer, sizeof(stEnemigo)*posBaja, 0);
            baja.alta = 1;
            fwrite(&baja, sizeof(stEnemigo), 1, buffer);
        }
        else
        {
            fseek(buffer, sizeof(stEnemigo)*posBaja, 0);
            baja.alta = 1;
            fwrite(&baja, sizeof(stEnemigo), 1, buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }

}

void darBajaEnemigo(char archivoEnemigos[])
{
    FILE * buffer = fopen(archivoEnemigos, "r+b");
    stEnemigo aux;
    int id=0, flag=0;

    printf("Ingrese ID del enemigo a dar de baja: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stEnemigo), 1, buffer)>0)
        {
            if(aux.IdEnemigo == id)
            {
                aux.alta = 0;
                fseek(buffer, (long)sizeof(stEnemigo)* -1, 1);
                fwrite(&aux, sizeof(stEnemigo), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo de enemigos \n");
    }
}

stEnemigo archivoToEnemigo(char archivoEnemigos[], int id)
{
    FILE * buffer = fopen(archivoEnemigos, "r+b");
    stEnemigo aux;
    int flag=0;

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stEnemigo), 1, buffer)>0)
        {
            if(aux.IdEnemigo == id)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo de enemigos \n");
    }
    return aux;
}

void cargarEnemigoArchivo(char archivoEnemigos[])
{
    FILE * buffer = fopen(archivoEnemigos, "ab");
    stEnemigo aux;
    char opc='s';
    if(buffer)
    {
        do
        {
            aux = CrearEnemigo();
            fwrite(&aux, sizeof(stEnemigo), 1, buffer);
            printf("Desea cargar otro enemigo? s/n \n");
            opc = getche();
        }
        while(opc == 's');
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo de enemigos \n");
    }
}

stEnemigo CrearEnemigo()
{
    stEnemigo aux;
    aux.alta=1;

    printf("ID enemigo: \n");
    scanf("%d", &aux.IdEnemigo);

    printf("Nombre Enemigo: ");
    fflush(stdin);
    gets(aux.nombreE);

    aux.estadisticasE = cargarStats(aux.estadisticasE);

    printf("Sprite enemigo: ");
    fflush(stdin);
    gets(aux.sprite);

    return aux;
}
