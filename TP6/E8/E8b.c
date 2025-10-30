#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
void armaLista(TLista *L);
void muestra(TLista L);
int cuentaVoc(TLista L);
int esVocal(char letra);
int estaOrd(TLista L);
void eliminaPosP(TLista *L, int P);

void main()
{
    TLista L;
    int P;
    L = NULL;
    armaLista(&L);
    muestra(L);
    printf("la cantidad de vocales es : %d \n", cuentaVoc(L));
    if (estaOrd(L))
        printf("esta ordenada \n");
    else
        printf("no esta ordenada \n");
    printf("ingrese una posicion para eliminar \n");
    scanf(" %d", &P);
    eliminaPosP(&L, P);
    muestra(L);
}
void armaLista(TLista *L)
{
    TLista nuevo;
    char car;
    printf("ingrese una por una las letras de la lista 0 para fin de datos");
    scanf(" %c", &car);
    while (car != '0')
    {
        nuevo = (TLista)malloc(sizeof(nodo));
        nuevo->dato = car;
        if (*L == NULL)
        {
            nuevo->sig = nuevo;
            *L = nuevo;
        }
        else
        {
            nuevo->sig = (*L)->sig;
            (*L)->sig = nuevo;
            (*L) = nuevo;
        }
        scanf(" %c", &car);
    }
}
void muestra(TLista L)
{
    TLista aux;
    aux = L->sig;
    if (L != NULL)
    {
        do
        {
            printf(" %c", aux->dato);
            aux = aux->sig;
        } while (aux != L->sig);
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
int cuentaVoc(TLista L)
{
    TLista aux;
    int cont = 0;
    if (L != NULL)
    {
        aux = L->sig;
        do
        {

            if (esVocal(toupper(aux->dato)))
                cont++;
            aux = aux->sig;
        } while (aux != L->sig);
    }
    return cont;
}
int estaOrd(TLista L)
{
    TLista aux;
    if (L != NULL)
    {
        aux = L->sig;
        do
        {
            if (aux->dato > aux->sig->dato)
                return 0;
        } while (aux != L->sig);
    }
    return 1;
}
void eliminaPosP(TLista *L, int P)
{
    TLista aux, ant;
    int i;
    if (*L != NULL)
    {
        ant = *L;
        aux = (*L)->sig;
        for (i = 0; i < P; i++)
        {
            ant = aux;
            aux = aux->sig;
        }
        if (aux == *L)
            *L = ant;

        ant->sig = aux->sig;
        free(aux);
    }
}
