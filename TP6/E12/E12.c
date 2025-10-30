#include <stdio.h>
#include <stdlib.h>
typedef struct nodito
{
    int dato;
    struct nodito *sig;
} nodito;
typedef nodito *Sublista;
typedef struct nodoD
{
    int ra, rb;
    Sublista sub;
    struct nodoD *ant, *sig;
} nodoD;
typedef nodoD *PnodoD;
typedef struct
{

    PnodoD pri, ult;
} TListaD;
typedef struct nodo
{
    float dato;
    int contOOR;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
void armaLista(TListaD *L);
void armalistaSimple(TListaD LD, TLista *L);
void muestra(TLista L);
void main()
{
    TListaD LD;
    TLista L;
    LD.pri = NULL;
    LD.ult = NULL;
    L = NULL;
    armaLista(&LD);
    armalistaSimple(LD, &L);
    muestra(L);
}
void armaLista(TListaD *L)
{
    PnodoD nuevo;
    int ra, rb, dato;
    Sublista ultimo, nuevoS;
    printf("ingrese el un rango de numeros  >0 ej primero uno despuies el otro ra < rb");
    scanf(" %d %d", &ra, &rb);
    while (ra != -1)
    {
        nuevo = (PnodoD)malloc(sizeof(nodoD));
        nuevo->ra = ra;
        nuevo->rb = rb;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
        nuevo->sub = NULL;
        if ((*L).pri == NULL)
        {
            (*L).pri = nuevo;
            (*L).ult = nuevo;
        }
        else
        {
            (*L).ult->sig = nuevo;
            nuevo->ant = (*L).ult;
            (*L).ult = nuevo;
        }

        printf("ingrese numero por numero los elementos de la sublista ,9999 para el fin de los datos ");
        scanf(" %d", &dato);
        while (dato != 9999)
        {
            nuevoS = (Sublista)malloc(sizeof(nodito));
            nuevoS->dato = dato;
            if (nuevo->sub == NULL)
            {
                nuevoS->sig = nuevo->sub;
                nuevo->sub = nuevoS;
                ultimo = nuevoS;
            }
            else
            {
                ultimo->sig = nuevoS;
                ultimo = nuevoS;
                nuevoS->sig = NULL;
            }
            scanf(" %d", &dato);
        }
        printf("ingrese el un rango de numeros  >0 ej primero uno despuies el otro ra < rb o -1 para el fin de los datos");
        scanf(" %d %d", &ra, &rb);
    }
}
void armalistaSimple(TListaD LD, TLista *L)
{
    TLista nuevo, ult;
    Sublista actS;
    int sum, contR, contG;
    while (LD.pri != NULL)
    {
        actS = LD.pri->sub;
        sum = 0;
        contR = 0;
        contG = 0;
        while (actS != NULL)
        {
            if (actS->dato < LD.pri->ra || actS->dato > LD.pri->rb)
                contR++;
            contG++;
            sum = sum + actS->dato;
            actS = actS->sig;
        }
        nuevo = (TLista)malloc(sizeof(nodo));
        if (contG != 0)
            nuevo->dato = (float)sum / contG;
        nuevo->contOOR = contR;
        nuevo->sig = NULL;
        if (*L == NULL)
        {

            *L = nuevo;
            ult = nuevo;
        }
        else
        {
            ult->sig = nuevo;
            ult = nuevo;
        }
        LD.pri = LD.pri->sig;
    }
}
void muestra(TLista L)
{
    while (L != NULL)
    {
        printf(" promedio : %f cantidad OOR : %d \n", L->dato, L->contOOR);
        L = L->sig;
    }
}