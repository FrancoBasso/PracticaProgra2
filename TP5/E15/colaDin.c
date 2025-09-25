#include "colaDin.h"
#include <stdlib.h>
#include <string.h> // para strcpy

void IniciaC(TCola *C)
{
    C->pri = C->ult = NULL;
}

int VaciaC(TCola C)
{
    return C.pri == NULL;
}

void poneC(TCola *C, TElementoC X)
{
    nodo *aux = (nodo *)malloc(sizeof(nodo));
    if (!aux)
        exit(1);

    strcpy(aux->dato, X); // copiar string
    aux->sig = NULL;

    if (C->pri == NULL)
        C->pri = aux;
    else
        C->ult->sig = aux;

    C->ult = aux;
}

void sacaC(TCola *C, TElementoC X)
{
    nodo *aux;
    if (C->pri != NULL)
    {
        aux = C->pri;
        strcpy(X, aux->dato); // devolver string
        C->pri = C->pri->sig;
        if (C->pri == NULL)
            C->ult = NULL;
        free(aux);
    }
}

void consultaC(TCola C, TElementoC X)
{
    if (C.pri != NULL)
        strcpy(X, C.pri->dato);
}