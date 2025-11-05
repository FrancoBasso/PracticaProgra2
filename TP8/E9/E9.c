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
int verticeMayor(TLA vec[], int N);
void main()
{
}
int verticeMayorEnt(TLA vec[], int N)
{
    int Vmax = -1, gr, grmax = -1, i, j;
    TLista aux;
    for (j = 0; j < N; j++)
    {
        gr = 0;
        for (i = 0; i < N; i++)
        {

            if (vec[i].L != NULL)
            {
                aux = vec[i].L;
                while (aux != NULL)
                {
                    if (vec[j].vertice == aux->dato)
                        gr++;
                    aux = aux->sig;
                }
            }
        }
        if (gr > grmax)
        {
            grmax = gr;
            Vmax = vec[j].vertice;
        }
    }

    return Vmax;
}