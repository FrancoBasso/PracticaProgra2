#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
void muestra(TLista L);
void creaLista(TLista *L);
int cuentaVocales(TLista L);
int esVocal(char letra);
int ordenada(TLista L);
void eliminaPosP(TLista *L, int Pos);
void main(int argc, char const *argv[])
{
    TLista L;
    int Pos;
    creaLista(&L);
    muestra(L);
    printf("la cantidad de vocales es %d \n", cuentaVocales(L));
    if (ordenada(L))
        printf("la lista esta ordenada \n");
    else
        printf("la lista no esta ordenada \n");
    printf("ingrese una posicion a elimniar \n");
    scanf(" %d", &Pos);
    eliminaPosP(&L, Pos);
    muestra(L);
}
void creaLista(TLista *L)
{
    char letra;
    TLista nuevo, ultimo;
    *L = NULL;

    printf("ingrese una letra \n");
    scanf(" %c", &letra);
    while (letra != '0')
    {
        nuevo = (TLista)malloc(sizeof(nodo));
        if (nuevo == NULL)
        {
            printf("error al reservar memoria");
            return;
        }
        nuevo->dato = letra;
        nuevo->sig = NULL;
        if (*L == NULL)
        {
            *L = nuevo;
            ultimo = nuevo;
        }
        else
        {
            ultimo->sig = nuevo;
            ultimo = nuevo;
        }
        printf("Ingrese una letra (0 para terminar): \n ");
        scanf(" %c", &letra);
    }
}
void muestra(TLista L)
{
    TLista nodoaux;
    nodoaux = L;
    while (nodoaux != NULL)
    {
        printf("%c \n", nodoaux->dato);
        nodoaux = nodoaux->sig;
    }
}
int esVocal(char letra)
{
    switch (letra)
    {
    case 'E':
    case 'A':
    case 'I':
    case 'O':
    case 'U':
        return 1;

    default:
        return 0;
    }
}
int cuentaVocales(TLista L)
{
    TLista nodoaux;
    int cont = 0;
    nodoaux = L;
    while (nodoaux != NULL)
    {
        if (esVocal(toupper(nodoaux->dato)))
            cont++;
        nodoaux = nodoaux->sig;
    }
    return cont;
}
int ordenada(TLista L)
{
    TLista nodoaux;
    nodoaux = L;
    while (nodoaux != NULL && nodoaux->sig != NULL)
    {
        if (nodoaux->dato > nodoaux->sig->dato)
            return 0;
        else
            nodoaux = nodoaux->sig;
    }
    return 1;
}
void eliminaPosP(TLista *L, int Pos)
{
    int cont = 0;
    TLista ant, act;
    act = *L;
    if (*L != NULL)
    {
        if (Pos == 0)
        {
            *L = act->sig;
            free(act);
        }
        while (act != NULL && cont < Pos)
        {
            ant = act;
            act = act->sig;
            cont++;
        }
        if (act != NULL)
        {
            ant->sig = act->sig;
            free(act);
        }
    }
}
