#include <stdio.h>
#include <stdlib.h>
#define MAX 50
typedef struct nodo
{
    char dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
typedef struct
{
    int vertice;
    TLista L;
} TLA;
void cargaMatriz(int matmat[][MAX], int *N);
int grVerticeL(TLA vecL[], int N, int vert);
void main()
{
}
int grVerticeL(TLA vecL[], int N, int vert)
{
    int i = 0;
    int cont = 0;
    TLista aux;
    while (i < N && vecL[i].vertice != vert)
        i++;
    if (vecL[i].L != NULL)
    {
        aux = vecL[i].L;
        while (aux != NULL)
        {
            cont++;
            aux = aux->sig;
        }
    }
    return cont;
}
