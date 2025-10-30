#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
#define ABC 27
typedef struct nodito
{
    char titulo[MAX];
    char autor[MAX];
    int anio;
    struct nodito *sig;
} nodito;
typedef nodito *Sublista;

typedef struct nodoP
{
    char nomAS[MAX];
    Sublista subL;
    struct nodoP *sig;

} nodoP;
typedef nodoP *TLista;
typedef struct
{
    char letra;
    TLista Lv;
} Tvec;
void cargaVector(Tvec vec[]);
int iniciaVec(Tvec vec[]);
void cargaLista(TLista *L);
void Prestar(TLista *L, Tvec vec[], char nomS[], char autor[], char titulo[]);
void devolver(TLista *L, Tvec vec[], char nomS[], char autor[], char titulo[]);

int buscapos(Tvec vec[], char letra);
void main()
{
    Tvec vec[ABC];
    TLista L;
    char autor[MAX], titulo[MAX], operacion, socio[MAX];
    iniciaVec(vec);
    cargaVector(vec);
    L = NULL;
    cargaLista(&L);
    printf("ingrese el autor ,el titulo , el socio y la operacion que desea realizar P para pedir prestado y D para devolver");
    scanf(" %s %s %s %c", autor, titulo, socio, &operacion);
    operacion = toupper(operacion);
    if (operacion == 'P')
        Prestar(&L, vec, socio, autor, titulo);
    else if (operacion == 'D')
        devolver(&L, vec, socio, autor, titulo);
}
void cargaVector(Tvec vec[])
{
    char autor[MAX], titulo[MAX];
    int pos, anio;
    FILE *archt;
    Sublista auxS, antS, actS;

    TLista aux, ant, act;
    archt = fopen("biblioteca.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe ");
    else
    {
        fscanf(archt, " %s", autor);
        while (!feof(archt))
        {
            pos = buscapos(vec, autor[0]);
            aux = (TLista)malloc(sizeof(nodoP));
            strcpy(aux->nomAS, autor);
            if (vec[pos].Lv == NULL || strcmp(aux->nomAS, vec[pos].Lv->nomAS) < 0)
            {
                aux->sig = vec[pos].Lv;
                vec[pos].Lv = aux;
            }
            else
            {
                ant = vec[pos].Lv;
                act = vec[pos].Lv->sig;
                while (act != NULL && strcmp(aux->nomAS, act->nomAS) > 0)
                {
                    ant = act;
                    act = act->sig;
                }
                aux->sig = act;
                ant->sig = aux;
            }
            fscanf(" %s %s %d", titulo, autor, &anio);
            while (!feof(archt) && strcmp(titulo, "***") != 0)
            {
                auxS = (Sublista)malloc(sizeof(nodito));
                strcpy(auxS->autor, autor);
                strcpy(auxS->titulo, titulo);
                auxS->anio = anio;
                if (vec[pos].Lv->subL == NULL || strcmp(auxS->titulo, vec[pos].Lv->subL) < 0)
                {
                    auxS->sig = vec[pos].Lv->subL;
                    vec[pos].Lv->subL = auxS;
                }
                else
                {
                    antS = vec[pos].Lv->subL;
                    actS = vec[pos].Lv->subL->sig;
                    while (actS != NULL && strcmp(auxS->titulo, actS->titulo) > 0)
                    {
                        antS = actS;
                        actS = actS->sig;
                    }
                    auxS->sig = actS;
                    ant->sig = auxS;
                }
                fscanf(" %s %s %d", titulo, autor, &anio);
            }
            fscanf(archt, " %s", autor);
        }
        fclose(archt);
    }
}
int iniciaVec(Tvec vec[])
{
    int i;
    char Letra = 'A';

    for (size_t i = 0; i < ABC; i++)
    {
        vec[i].letra = Letra + i;
        vec[i].Lv = NULL;
        vec[i].Lv->subL = NULL;
    }
}
int buscapos(Tvec vec[], char letra)
{
    int i;
    i = 0;
    while (i < ABC && vec[i].letra != letra)
        i++;
    if (i < ABC)
        return i;
}
void cargaLista(TLista *L)
{
    char autor[MAX], titulo[MAX];
    int anio;
    FILE *archt;
    Sublista auxS, antS, actS;

    TLista aux, ant, act;
    archt = fopen("clientes.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe ");
    else
    {
        fscanf(archt, " %s", autor);
        while (!feof(archt))
        {

            aux = (TLista)malloc(sizeof(nodoP));
            strcpy(aux->nomAS, autor);
            if (*L == NULL || strcmp(aux->nomAS, (*L)->nomAS) < 0)
            {
                aux->sig = *L;
                *L = aux;
            }
            else
            {
                ant = *L;
                act = (*L)->sig;
                while (act != NULL && strcmp(aux->nomAS, act->nomAS) > 0)
                {
                    ant = act;
                    act = act->sig;
                }
                aux->sig = act;
                ant->sig = aux;
            }
            fscanf(" %s %s %d", titulo, autor, &anio);
            while (!feof(archt) && strcmp(titulo, "***") != 0)
            {
                auxS = (Sublista)malloc(sizeof(nodito));
                strcpy(auxS->autor, autor);
                strcpy(auxS->titulo, titulo);
                auxS->anio = anio;
                if ((*L)->subL == NULL || strcmp(auxS->titulo, (*L)->subL) < 0)
                {
                    auxS->sig = (*L)->subL;
                    (*L)->subL = auxS;
                }
                else
                {
                    antS = (*L)->subL;
                    actS = (*L)->subL->sig;
                    while (actS != NULL && strcmp(auxS->titulo, actS->titulo) > 0)
                    {
                        antS = actS;
                        actS = actS->sig;
                    }
                    auxS->sig = actS;
                    ant->sig = auxS;
                }
                fscanf(" %s %s %d", titulo, autor, &anio);
            }
            fscanf(archt, " %s", autor);
        }
        fclose(archt);
    }
}
void Prestar(TLista *L, Tvec vec[], char nomS[], char autor[], char titulo[])
{
    TLista aux;
    Sublista auxS, antS, actS, elim;
    int pos = buscapos(vec, autor[0]), anio;
    if (vec[pos].Lv != NULL)
    {
        aux = vec[pos].Lv;
        while (aux != NULL && strcmp(aux->nomAS, autor) != 0)
            aux = aux->sig;
        if (aux != NULL)
        {
            if (aux->subL != NULL)
            {
                if (strcmp(aux->subL->titulo, titulo) == 0)
                {
                    elim = aux->subL;
                    aux->subL = aux->subL->sig;
                    free(elim);
                }
                else
                {
                    antS = aux->subL;
                    antS = aux->subL->sig;
                    while (actS != NULL && strcmp(actS->titulo, titulo) != 0)
                    {
                        antS = actS;
                        actS = actS->sig;
                    }

                    anio = actS->anio;
                    antS->sig = actS->sig;
                    free(actS);
                }
            }
            else
                printf("no existe el titulo solicitado");
        }
        else
            printf("el autor no existe o no esta registgrado en la biblioteca");
    }
    if (L != NULL)
    {
        aux = *L;
        while (aux != NULL && strcmp(aux->nomAS, autor) != 0)
            aux = aux->sig;
        if (aux != NULL)
        {
            auxS = (Sublista)malloc(sizeof(nodito));
            strcpy(auxS->titulo, titulo);
            strcpy(auxS->autor, autor);
            auxS->anio = anio;
            if ((*L)->subL == NULL || strcmp(auxS->titulo, (*L)->subL) < 0)
            {
                auxS->sig = (*L)->subL;
                (*L)->subL = auxS;
            }
            else
            {
                antS = (*L)->subL;
                actS = (*L)->subL->sig;
                while (actS != NULL && strcmp(auxS->titulo, actS->titulo) > 0)
                {
                    antS = actS;
                    actS = actS->sig;
                }
                auxS->sig = actS;
                antS->sig = auxS;
            }
        }
        else
            printf("el socio no existe o no esta registgrado en la biblioteca");
    }
}
void devolver(TLista *L, Tvec vec[], char nomS[], char autor[], char titulo[])
{
    TLista aux;
    Sublista auxS, antS, actS, elim;
    int pos = buscapos(vec, autor[0]), anio;
    if (*L != NULL)
    {
        aux = *L;
        while (aux != NULL && strcmp(aux->nomAS, autor) != 0)
            aux = aux->sig;
        if (aux != NULL)
        {
            if (aux->subL != NULL)
            {
                if (strcmp(aux->subL->titulo, titulo) == 0)
                {
                    elim = aux->subL;
                    aux->subL = aux->subL->sig;
                    free(elim);
                }
                else
                {
                    antS = aux->subL;
                    antS = aux->subL->sig;
                    while (actS != NULL && strcmp(actS->titulo, titulo) != 0)
                    {
                        antS = actS;
                        actS = actS->sig;
                    }

                    anio = actS->anio;
                    antS->sig = actS->sig;
                    free(actS);
                }
            }
            else
                printf("no existe el titulo solicitado");
        }
        else
            printf("el autor no existe o no esta registgrado en la biblioteca");
    }
    if (vec[pos].Lv != NULL)
    {
        aux = vec[pos].Lv;
        while (aux != NULL && strcmp(aux->nomAS, autor) != 0)
            aux = aux->sig;
        if (aux != NULL)
        {
            auxS = (Sublista)malloc(sizeof(nodito));
            strcpy(auxS->titulo, titulo);
            strcpy(auxS->autor, autor);
            auxS->anio = anio;
            if ((*L)->subL == NULL || strcmp(auxS->titulo, (*L)->subL) < 0)
            {
                auxS->sig = (*L)->subL;
                (*L)->subL = auxS;
            }
            else
            {
                antS = (*L)->subL;
                actS = (*L)->subL->sig;
                while (actS != NULL && strcmp(auxS->titulo, actS->titulo) > 0)
                {
                    antS = actS;
                    actS = actS->sig;
                }
                auxS->sig = actS;
                antS->sig = auxS;
            }
        }
        else
            printf("el socio no existe o no esta registgrado en la biblioteca");
    }
}
