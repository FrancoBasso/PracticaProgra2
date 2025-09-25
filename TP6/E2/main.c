#include <stdio.h>
#include <stdlib.h>
#define MAXE 50

typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
void creaVector(int vec[], int N);
void insertaOrdDesc(TLista *L, int vec[], int N);
void insertaOrd(TLista *L, int vec[], int N);
void inserta(TLista *L, int vec[], int N);
void muestra(TLista L);

void main(int argc, char const *argv[])
{
    int vec[MAXE];
    int N;
    TLista L;
    printf("ingrese la cantidad de numeros \n");
    scanf("%d", &N);
    creaVector(vec, N);
    printf("orden dado \n");
    inserta(&L, vec, N);
    muestra(L);
    printf("ordenado asc \n");
    insertaOrd(&L, vec, N);
    muestra(L);
    printf("ordenado desc \n");
    insertaOrdDesc(&L, vec, N);
    muestra(L);
}
void insertaOrdDesc(TLista *L, int vec[], int N)
{
    TLista aux, act, ant;
    *L = NULL;

    int i;
    for (i = 0; i < N; i++)
    {
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = vec[i];
        if (*L == NULL || vec[i] > (*L)->dato)
        {
            aux->sig = *L;
            *L = aux;
        }
        else
        {
            ant = NULL;
            act = *L;
            while (act != NULL && vec[i] < act->dato)
            {
                ant = act;
                act = act->sig;
            }
            aux->sig = act;
            ant->sig = aux;
        }
    }
}
void insertaOrd(TLista *L, int vec[], int N)
{
    TLista aux, act, ant;
    *L = NULL;

    int i;
    for (i = 0; i < N; i++)
    {
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = vec[i];
        if (*L == NULL || vec[i] < (*L)->dato)
        {
            aux->sig = *L;
            *L = aux;
        }
        else
        {
            ant = NULL;
            act = *L;
            while (act != NULL && vec[i] > act->dato)
            {
                ant = act;
                act = act->sig;
            }
            aux->sig = act;
            ant->sig = aux;
        }
    }
}
void inserta(TLista *L, int vec[], int N)
{
    TLista aux, ultimo;
    int i;
    *L = NULL;
    for (i = 0; i < N; i++)
    {
        aux = (TLista)malloc(sizeof(nodo));
        aux->dato = vec[i];
        if (*L == NULL)
        {
            aux->sig = *L;
            *L = aux;
            ultimo = aux;
        }
        else
        {
            ultimo->sig = aux;
            ultimo = aux;
        }
    }
}
void creaVector(int vec[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("ingrese el valor  % d del vector \n", i + 1);
        scanf(" %d", &vec[i]);
    }
}
void muestra(TLista L)
{
    TLista nodoaux;
    nodoaux = L;
    while (nodoaux != NULL)
    {
        printf("%d \t", nodoaux->dato);
        nodoaux = nodoaux->sig;
    }
    printf("\n");
}