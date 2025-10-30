#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodoD
{
    char dato;
    struct nodoD *ant, *sig;
} nodoD;
typedef nodoD *PnodoD;
typedef struct
{
    PnodoD pri, ult;
} TlistaD;
void muestra(TlistaD LD);
void armaLista(TlistaD *LD);
int cantVocales(TlistaD LD);
int esVocal(char letra);
int estaOrd(TlistaD LD);
void eliminaPosP(TlistaD *LD, int P);

void main()
{
    TlistaD LD;
    int P;
    LD.pri = NULL;
    LD.ult = NULL;
    armaLista(&LD);
    muestra(LD);
    printf("la cantidad de vocales es : %d \n", cantVocales(LD));
    if (estaOrd(LD))
        printf("la lista esta ordenada \n");
    else
        printf("la lista no esta ordenada \n");
    printf("ingrese una posicion a liberar \n");
    scanf(" %d", &P);
    eliminaPosP(&LD, P);
    muestra(LD);
}
void armaLista(TlistaD *LD)
{
    PnodoD nuevo;

    char c;
    printf("ingrese un caracter : \n");
    scanf(" %c", &c);
    while (c != '0')
    {
        nuevo = (PnodoD)malloc(sizeof(nodoD));
        nuevo->dato = c;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
        if ((*LD).pri == NULL && (*LD).ult == NULL)
        {

            (*LD).pri = nuevo;
            (*LD).ult = nuevo;
        }
        else
        {
            (*LD).ult->sig = nuevo;
            nuevo->ant = (*LD).ult;
            (*LD).ult = nuevo;
        }
        printf("ingrese un caracter  o 0 para fin de datos: \n");
        scanf(" %c", &c);
    }
}
void muestra(TlistaD LD)
{
    while (LD.pri != NULL)
    {
        printf(" %c \t", LD.pri->dato);
        LD.pri = LD.pri->sig;
    }
    printf("\n");
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
int cantVocales(TlistaD LD)
{
    int cont = 0;
    while (LD.pri != NULL)
    {

        if (esVocal(toupper(LD.pri->dato)))
            cont++;
        LD.pri = LD.pri->sig;
    }
    return cont;
}
int estaOrd(TlistaD LD)
{
    while (LD.ult->ant != NULL)
    {
        if (LD.ult->dato < LD.ult->ant->dato)
            return 0;

        LD.ult = LD.ult->ant;
    }
    if (LD.ult == NULL)
        return 1;
}
void eliminaPosP(TlistaD *LD, int P)
{
    int cont = 0;

    PnodoD act;
    act = (*LD).pri;
    if (act != NULL)
    {
        if (P == 0)
        {
            (*LD).pri = act->sig;
            free(act);
        }
        else
        {
            while (act != NULL && cont < P)
            {
                act = act->sig;
                cont++;
            }
            if (act->sig == NULL)
            {
                (*LD).ult = act->ant;
                (*LD).ult->sig = NULL;
            }
            else
            {
                act->sig->ant = act->ant;
                act->ant->sig = act->sig;
            }
            free(act);
        }
    }
}