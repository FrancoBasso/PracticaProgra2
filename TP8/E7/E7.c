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
int grVerticeM(int mat[][MAX], int N, int vert);
void main()
{
}
int grVerticeM(int mat[][MAX], int N, int vert)
{
    int j, i;
}