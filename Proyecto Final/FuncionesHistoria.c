#include "FuncionesHistoria.h"


void darDeAltaLugarArchivo(char archivo[])
{
    FILE * buffer = fopen(archivo, "r+b");
    int id=0, i=0 , posAlta = -1, posBaja = -1;
    stLugar aux, alta, baja;

    printf("Ingrese ID del lugar a a dar de alta: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(fread(&aux, sizeof(stLugar), 1, buffer)>0)
        {
            if(aux.baja == 0 && aux.id == id)
            {
                baja=aux;
                posBaja = i;
            }

            if(aux.baja == 1 && aux.id == id)
            {
                alta=aux;
                posAlta == i;
            }
            i++;

        }

        if(posBaja == -1)
        {
            printf("No se encontro un lugar dado de baja con esa id\n");
        }
        else if( (posBaja =! -1) && (posAlta != -1))
        {
            printf("Se encontro un lugar con la misma id que la que esta dada de baja.\nDaremos la daremos de baja para evitar conflictos\n");
            fseek(buffer, sizeof(stLugar)*posAlta, 0);
            alta.baja = 0;
            fwrite(&alta, sizeof(stLugar), 1, buffer);
            fseek(buffer, sizeof(stLugar)*posBaja, 0);
            baja.baja = 1;
            fwrite(&baja, sizeof(stLugar), 1, buffer);
        }
        else
        {
            fseek(buffer, sizeof(stLugar)*posBaja, 0);
            baja.baja = 1;
            fwrite(&baja, sizeof(stLugar), 1, buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }

}

stTexto modificarTexto(stTexto a)
{
    int nuevoID=0, nuevoCombateMoment=-1;
    char sw, nuevoTexto[1000];
    printf("Que quiere modificar? 1: ID / 2: Lugar / 3: CombateMoment \n");
    sw = getche();

    switch(sw)
    {
    case '1':
        printf("Ingrese el nuevo ID: \n");
        scanf("%d", &nuevoID);
        break;
    case '2':
        printf("Ingrese el nuevo texto: \n");
        fflush(stdin);
        gets(nuevoTexto);
        break;
    case '3':
        do
        {
            printf("Ingrese el nuevo CombateMoment: \n");
            scanf("%d", &nuevoCombateMoment);
        }
        while(nuevoCombateMoment > 2 || nuevoCombateMoment < 0);
        break;
    default:
        printf("Opcion incorrecta \n");
    }

    return a;
}

void modificarTextoArchivo(char archivo[])
{
    FILE * buffer = fopen(archivo, "r+b");
    int pos=0, i=0;
    stTexto aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer)>0)
        {
            mostrarTexto(aux);
            printf("POSICION: %d \n", i);
        }
        printf("Ingrese POSICION del texto a modificar: \n");
        scanf("%d", &pos);

        fseek(buffer, sizeof(stTexto)*pos, 0);
        aux = modificarTexto(aux);
        fwrite(&aux, sizeof(stTexto), 1, buffer);

        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

void mostrarTextoConIDyCombateMoment(stTexto a)
{
    printf("/////////////////////////////////////////////////////// \n");
    printf("%s \n", a.texto);
    printf("ID: %d \n", a.id);
    printf("CombateMoment: %d \n", a.momento);
}

void darDeBajaTextoArchivo(char archivo[])
{
    FILE * buffer = fopen(archivo, "r+b");
    int pos=0, i=0;
    stTexto aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer)>0)
        {
            mostrarTexto(aux);
            printf("POSICION: %d \n", i);
        }
        printf("Ingrese POSICION del texto a borrar: \n");
        scanf("%d", &pos);

        fseek(buffer, sizeof(stTexto)*pos, 0);
        aux.baja = 0;
        fwrite(&aux, sizeof(stTexto), 1, buffer);

        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

stLugar modificarLugar(stLugar a)
{
    int nuevoID=0;
    char sw, nuevoLugar[1000];
    printf("Que quiere modificar? 1: ID / 2: Lugar  \n");
    sw = getche();

    switch(sw)
    {
    case '1':
        printf("Ingrese el nuevo ID: \n");
        scanf("%d", &nuevoID);
        break;
    case '2':
        printf("Ingrese el lugar: \n");
        fflush(stdin);
        gets(nuevoLugar);
        break;
    default:
        printf("Opcion incorrecta \n");
    }

    return a;
}

void modificarLugarArchivo(char archivo[])
{
    FILE * buffer = fopen(archivo, "r+b");
    int id=0, flag = 0;
    stLugar aux;

    printf("Ingrese ID del lugar a modificar: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stLugar), 1, buffer)>0)
        {
            if(aux.id == id)
            {
                aux=modificarLugar(aux);
                fseek(buffer, (long)sizeof(stLugar)* -1, 1);
                fwrite(&aux, sizeof(stLugar), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }

}

void darDeBajaLugarArchivo(char archivo[])
{
    FILE * buffer = fopen(archivo, "r+b");
    int id=0, flag = 0;
    stLugar aux;

    printf("Ingrese ID del lugar a borrar: \n");
    scanf("%d", &id);

    if(buffer)
    {
        while(flag == 0 && fread(&aux, sizeof(stLugar), 1, buffer)>0)
        {
            if(aux.id == id)
            {
                aux.baja = 0;
                fseek(buffer, (long)sizeof(stLugar)* -1, 1);
                fwrite(&aux, sizeof(stLugar), 1, buffer);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

void mostrarArchivoLugar(char archivoLugar[])
{
    FILE * buffer = fopen(archivoLugar, "rb");
    stLugar aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stLugar), 1, buffer) > 0)
        {
            mostrarLugar(aux);
        }
        fclose(buffer);
    }
    else
    {
        printf("El archivo no se pudo abrir\n");
    }

}
int mostrarArchivoLugarAlta(char archivoLugar[])
{
    FILE * buffer = fopen(archivoLugar, "rb"); ///devuelve 1 si tiene elementos dados de alta, 0 si no
    int flag = 0;
    stLugar aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stLugar), 1, buffer) > 0)
        {
            if(aux.baja == 1)
            {
                mostrarLugar(aux);
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
int mostrarArchivoLugarBaja(char archivoLugar[])
{
    FILE * buffer = fopen(archivoLugar, "rb");///devuelve 1 si tiene elementos dados de baja, 0 si no
    stLugar aux;
    int flag = 0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stLugar), 1, buffer) > 0)
        {
            if(aux.baja == 0)
            {
                mostrarLugar(aux);
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

void mostrarArchivoTexto(char archivoRelato[])
{
    FILE * buffer = fopen(archivoRelato, "rb");
    stTexto aux;
    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer) > 0)
        {
            mostrarTexto(aux);
        }
        fclose(buffer);

    }
    else
    {
        printf("El archivo no se pudo abrir\n");
    }
}
int mostrarArchivoTextoAlta(char archivoRelato[])
{
    FILE * buffer = fopen(archivoRelato, "rb");///devuelve 1 si tiene elementos dados de alta, 0 si no
    stTexto aux;
    int flag;
    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer) > 0)
        {
            if(aux.baja == 1)
            {
            mostrarTexto(aux);
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
int mostrarArchivoTextoBaja(char archivoRelato[])
{
    FILE * buffer = fopen(archivoRelato, "rb");///devuelve 1 si tiene elementos dados de baja, 0 si no
    stTexto aux;
    int flag = 0;
    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer) > 0)
        {
            if(aux.baja == 0)
            {
            mostrarTexto(aux);
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
void mostrarListaConPausa(nodoTexto * lista, int combateMoment, int id)
{
    /// combateMoment = 0: antes del combate ||| combateMoment = 1: combate ganado ||| combateMoment = 2: combate perdido
    nodoTexto * seg = lista;
    if(seg == NULL)
    {
        printf("Lista Vacia \n");
    }
    else
    {
        while(seg != NULL)
        {
            if(seg->dato.momento == combateMoment && seg->dato.id == id)
            {
                mostrarTexto(seg->dato);
                system("pause");
            }
            seg = seg->siguiente;
        }
    }
}

arbolLugar * movermeA(arbolLugar * arbol, int combateMoment, Usuario player, char archivoEnemigo[])
{
    /// combateMoment = 0: antes del combate ||| combateMoment = 1: combate ganado ||| combateMoment = 2: combate perdido
    int lado=0, victoria, pocionRoja = 3, pocionAzul = 3;
    stEnemigo enemy;
    enemy.estadisticasE = cargarStats(enemy.estadisticasE);
    if(arbol)
    {
        if(arbol->izq != NULL && arbol->der != NULL)
        {
            printf("Lugar Actual: \n");
            mostrarLugar(arbol->dato);
            mostrarListaConPausa(arbol->lista, combateMoment,arbol->dato.id);
            printf("COMBATE======================================\n");
            combateMoment = funcionDePelea(player, enemy, pocionRoja, pocionAzul);
            if(combateMoment == 1)
            {
                mostrarListaConPausa(arbol->lista, combateMoment,arbol->dato.id);
                printf("Opcion 1: \n");
                mostrarLugar(arbol->izq->dato);
                printf("Opcion 2: \n");
                mostrarLugar(arbol->der->dato);
                do
                {
                    printf("Ingrese 1 para la primer opcion, 2 para la segunda \n");
                    scanf("%d", &lado);
                    if(lado != 1 && lado != 2)
                    {
                        printf("Opcion invalida, por favor seleccione 1 o 2 \n");
                    }
                }
                while(lado > 2 || lado < 1);

                if(lado == 1)
                {
                    arbol = movermeA(arbol->izq, combateMoment, player, archivoEnemigo);
                }
                else if(lado == 2)
                {
                    arbol = movermeA(arbol->der, combateMoment, player, archivoEnemigo);
                }
            }
            else if(combateMoment == 2)
            {
                mostrarListaConPausa(arbol->lista, combateMoment,arbol->dato.id);
            }
        }
    }
    return arbol;
}

void mostrarArbolInOrder(arbolLugar * arbol, int combateMoment)
{
    if(arbol)
    {
        mostrarArbolInOrder(arbol->izq, combateMoment);
        mostrarLugar(arbol->dato);
        mostrarLista(arbol->lista, combateMoment);
        mostrarArbolInOrder(arbol->der, combateMoment);
    }
}

void mostrarLugar(stLugar a)
{
    printf("************************************************ \n");
    printf("%s \n", a.lugar);
    printf("ID: %d \n", a.id);
    printf("************************************************ \n");
}

void mostrarLista(nodoTexto * lista, int combateMoment)
{
    nodoTexto * seg = lista;
    if(seg == NULL)
    {
        printf("Lista Vacia \n");
    }
    else
    {
        while(seg != NULL)
        {
            if(seg->dato.momento == combateMoment)
            {
                mostrarTexto(seg->dato);
            }
            seg = seg->siguiente;
        }
    }
}

void mostrarTexto(stTexto a)
{
    printf("/////////////////////////////////////////////////////// \n");
    printf("%s \n", a.texto);
}

nodoTexto * archivoToLista(const char archivoRelato[], nodoTexto * lista, int id)
{
    FILE * buffer = fopen(archivoRelato, "rb");

    stTexto aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(stTexto), 1, buffer)>0)
        {
            if(aux.id == id && aux.baja == 1)
            {

                nodoTexto * nuevoNodoTexto = crearNodoListaTexto(aux);

                lista = agregarFinalLista(lista, nuevoNodoTexto);
            }
        }
        fclose(buffer);
    }
    if(lista == NULL)
    {
        printf("No habia elementos bajo ese ID, no se cargo nada en la lista \n");
    }

    return lista;
}

arbolLugar * archivoToArbolDeListas(char archivo[],char archivo2[], arbolLugar * arbol)
{
    FILE * buffer = fopen(archivo, "rb");

    stLugar aux;

    if(buffer)
    {
        while(fread(&aux, sizeof(stLugar), 1, buffer)>0)
        {
            if(aux.baja == 1)
            {
                arbol = alta(archivo2, arbol, aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
    return arbol;
}

stTexto cargarTexto()
{
    stTexto a;

    printf("Ingrese texto: \n");
    fflush(stdin);
    gets(a.texto);

    printf("Ingrese ID del texto: \n");
    scanf("%i", &a.id);

    do
    {
        printf("Ingrese momento donde va texto: 0 si es antes del combate/1 si gana el combate/2 si pierde el combate\n");
        scanf("%i", &a.momento);
    }
    while(a.momento > 2 || a.momento < 0);

    a.baja = 1;

    return a;
}

stLugar cargarLugar()
{
    stLugar a;

    printf("Ingrese lugar: \n");
    fflush(stdin);
    gets(a.lugar);

    printf("Ingrese ID del lugar: \n");
    scanf("%i", &a.id);

    a.baja = 1;

    return a;
}

void cargarArchivoTexto(char archivo[], stTexto a)
{
    FILE * buffer = fopen(archivo, "a+b");

    if(buffer)
    {
        char opc='s';

        while(opc == 's')
        {
            a=cargarTexto();
            fwrite(&a, sizeof(stTexto),1,buffer);

            printf("Desea seguir cargando textos? s/n \n");
            opc=getche();
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

void cargarArchivoLugar(char archivo[], stLugar a)
{
    FILE * buffer = fopen(archivo, "ab");

    if(buffer)
    {
        char opc='s';

        while(opc == 's')
        {
            a=cargarLugar();
            fwrite(&a, sizeof(stLugar),1,buffer);

            printf("Desea seguir cargando lugares? s/n \n");
            opc=getche();
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }
}

arbolLugar * insertarNodoArbol(arbolLugar * arbol, stLugar dato)
{
    if(arbol == NULL)
    {
        arbol = crearArbol(dato);
    }
    else
    {
        if(dato.id > arbol->dato.id)
        {
            arbol->der = insertarNodoArbol(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertarNodoArbol(arbol->izq, dato);
        }
    }
    return arbol;
}

nodoTexto * buscarUltimoNodoLista(nodoTexto * lista)
{
    nodoTexto * seg = lista;

    if(seg != NULL)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodoTexto * agregarFinalLista(nodoTexto * lista, nodoTexto * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoTexto * ultimo = buscarUltimoNodoLista(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

arbolLugar * alta(char archivo[], arbolLugar * arbol, stLugar nuevoLugar)
{
    arbolLugar * pos = buscarArbolID(arbol, nuevoLugar.id);

    if(pos == NULL)
    {
        arbol = insertarNodoArbol(arbol, nuevoLugar);
        pos = buscarArbolID(arbol, nuevoLugar.id);
    }

    nodoTexto * aux = inicListaTexto();

    aux = archivoToLista(archivo, aux, pos->dato.id);

    pos->lista = aux;

    return arbol;
}

arbolLugar * buscarArbolID(arbolLugar * arbol, int id)
{
    arbolLugar * rta = NULL;
    if(arbol != NULL)
    {
        if(arbol->dato.id == id)
        {
            rta = arbol;
        }
        else
        {
            if(arbol->dato.id < id)
            {
                rta = buscarArbolID(arbol->der, id);
            }
            else
            {
                rta = buscarArbolID(arbol->izq, id);
            }
        }
    }

    return rta;
}

arbolLugar * crearArbol(stLugar a)
{
    arbolLugar * nuevoArbol = (arbolLugar*)malloc(sizeof(arbolLugar));
    nuevoArbol->dato = a;
    nuevoArbol->izq = NULL;
    nuevoArbol->der = NULL;

    nuevoArbol->lista = inicListaTexto();

    return nuevoArbol;
}

nodoTexto * crearNodoListaTexto(stTexto a)
{
    nodoTexto * nuevoNodo = (nodoTexto*)malloc(sizeof(nodoTexto));
    nuevoNodo->dato = a;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

nodoTexto * inicListaTexto()
{
    return NULL;
}

arbolLugar * inicArbol()
{
    return NULL;
}
