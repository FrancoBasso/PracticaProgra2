#include <stdlib.h>
#include <string.h> // para strcpy
#include "piladin.h"

void poneP(TPila *P, TElementoP x)
{
    TPila N = (TPila)malloc(sizeof(nodop));
    if (!N)
        exit(1);

    strcpy(N->dato, x); // copiar string
    N->sig = *P;
    *P = N;
}

void sacaP(TPila *P, TElementoP x)
{
    TPila N;
    if (*P)
    {
        N = *P;
        strcpy(x, N->dato); // devolver string
        *P = N->sig;
        free(N);
    }
}

void consultaP(TPila P, TElementoP x)
{
    if (P)
        strcpy(x, P->dato); // copiar string en buffer
}

int VaciaP(TPila P)
{
    return P == NULL;
}

void IniciaP(TPila *P)
{
    *P = NULL;
}