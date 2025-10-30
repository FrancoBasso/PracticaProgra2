#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct nodito
{
    char nomJ[MAX];
    int edad;
    char estado;
    struct nodito *sig;
} nodito;
typedef nodito *Sublista;
typedef struct nodo
{
    char nomE[MAX];
    int puntaje;
    struct nodo *sig;
    Sublista sub;
} nodo;
typedef nodo *TLista;
void cargaLista(TLista *L);
void ListaJug(TLista L, char K);
void ListardatosX(TLista L, int X);
int verifica(TLista L, char nomE[MAX], int punt);
void eliminarInactivos(TLista *L);

void main(int argc, char const *argv[])
{
    TLista L;
    char K;
    int X;
    char nomE[MAX];
    cargaLista(&L);
    printf("ingrese una letra \n");
    scanf(" %c", &K);
    printf("ingrese un puntaje");
    scanf(" %d", &X);
    ListardatosX(L, X);
    printf(" ingrese un equipo y un puntaje \n");
    scanf(" %s %d", nomE, &X);
    switch (verifica(L, nomE, X))
    {
    case 1:
        printf("el equipo verifica \n");
        break;
    case 0:
        printf("el equipo no verifica \n");
        break;
    case -1:
        printf(" el equipo no se encuentra \n");
    }
    eliminarInactivos(&L);
}
void cargaLista(TLista *L)
{
    TLista aux, act, ant;
    char nom[MAX];
    int edad;
    Sublista nuevo, ult;
    char activo;
    int punt;
    *L = NULL;

    FILE *archt;
    archt = fopen("clubes.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(archt, " %s %d", nom, &punt);
        while (!feof(archt))
        {
            aux = (TLista)malloc(sizeof(nodo));
            aux->puntaje = punt;
            strcpy(aux->nomE, nom);
            aux->sub = NULL;

            if (*L == NULL || (*L)->puntaje < aux->puntaje || ((*L)->puntaje == aux->puntaje && strcmp(aux->nomE, (*L)->nomE) < 0))
            {
                aux->sig = *L;
                *L = aux;
            }
            else
            {

                ant = *L;
                act = (*L)->sig;
                while ((act != NULL && act->puntaje > aux->puntaje) || (act->puntaje == aux->puntaje && strcmp(act->nomE, aux->nomE) < 0))
                {
                    ant = act;
                    act = act->sig;
                }

                aux->sig = act;
                ant->sig = aux;
                fscanf(archt, " %s %d %c", nom, &edad, &activo);
                while (!feof(archt) && strcmp(nom, "***") != 0)
                {
                    nuevo = (Sublista)malloc(sizeof(nodito));

                    strcpy(nuevo->nomJ, nom);
                    nuevo->edad = edad;
                    nuevo->estado = activo;
                    nuevo->sig = NULL;
                    if (aux->sub == NULL)
                    {

                        aux->sub = nuevo;
                        ult = nuevo;
                    }
                    else
                    {

                        ult->sig = nuevo;
                        ult = nuevo;
                    }
                    fscanf(archt, " %s %d %c", nom, &edad, &activo);
                }
                fscanf(archt, " %s %d", nom, &punt);
            }
        }
        fclose(archt);
    }
}

void ListaJug(TLista L, char K)
{
    TLista aux;
    Sublista act;
    int contTot = 0, contC, max = 0;
    char nom[MAX], nommax[MAX];
    aux = L;
    while (aux != NULL)
    {
        contC = 0;
        act = aux->sub;
        while (act != NULL)
        {
            if (act->nomJ[0] == K)
            {
                printf(" %s \n", act->nomJ);
                contC++;
            }
            act = act->sig;
        }
        contTot = contTot + contC;
        if (contC > max)
        {
            max = contC;
            strcpy(nommax, aux->nomE);
        }
        aux = aux->sig;
    }
    printf("la cantidad de jugadores con la letra %c es : %d \n", K, contTot);
    printf("el club con mas jugadores con la letra %c es %s \n", K, nommax);
}
void ListardatosX(TLista L, int X)
{
    TLista aux;
    Sublista auxS;
    float edadP;
    int cont;
    aux = L;
    while (aux != NULL)
    {
        if (aux->puntaje >= X)
        {
            cont = 0;
            edadP = 0;
            printf(" %s : \n", aux->nomE);
            auxS = aux->sub;
            while (auxS != NULL)
            {
                cont++;
                edadP = edadP + auxS->edad;
                printf(" %s", auxS->nomJ);
                auxS = auxS->sig;
            }
            printf(" la edad primedio de los jeugadores es : %f", edadP / cont);
        }
        aux = aux->sig;
    }
}
int verifica(TLista L, char nomE[MAX], int punt)
{
    TLista aux;
    aux = L;
    while (aux != NULL && strcmp(aux->nomE, nomE) != 0)
    {
        aux = aux->sig;
    }
    if (aux != NULL)
        if (aux->puntaje == punt)
            return 1;
        else
            return 0;
    else
        return -1;
}
void eliminarInactivos(TLista *L)
{
    TLista aux;
    Sublista ant, act, elim;
    aux = *L;
    while (aux != NULL)
    {
        if (aux->sub != NULL)
        {
            act = aux->sub;
            while (act != NULL)
            {
                if (act == aux->sub && act->estado == 'S')
                {
                    elim = act;
                    aux->sub = act->sig;
                    act = act->sig;
                    free(elim);
                }
                else
                {
                    if (act->estado != 'S')
                    {
                        ant = act;
                        act = act->sig;
                    }
                    else
                    {
                        elim = act;
                        ant->sig = act->sig;
                        act = act->sig;
                        free(elim);
                    }
                }
            }
        }
        aux = aux->sig;
    }
}
