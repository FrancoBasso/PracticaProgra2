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
void iniciaMat(int matmat[][MAX], int N);
void mostrar(int matmat[][MAX], int N);
int gradoEnt(int mat[][MAX], int N, int vert);
int gradoSal(int mat[][MAX], int N, int vert);
void main()
{
    int mat[MAX][MAX];
    TLA vec[MAX];
    int N, vert;
    int grS, grE, vv = 0;
    cargaMatriz(mat, &N);
    mostrar(mat, N);
    printf("ingrese el vertice a evaluar su grado \n");
    scanf(" %d", &vert);
    grE = gradoEnt(mat, N, vert);
    grS = gradoSal(mat, N, vert);
    if (mat[vert - 1][vert - 1] == 1)
        vv = 1;
    printf("el grado de entrada es: %d  \t el grado de salida es: %d \t el grado total es %d \n", grE, grS, grE + grS - vv);
}
void cargaMatriz(int mat[][MAX], int *N)
{
    FILE *archt;
    int i = 0, j;
    archt = fopen("Matriz.txt", "rt");
    if (archt != NULL)
    {
        fscanf(archt, " %d", N);
        while (!feof(archt))
        {
            for (j = 0; j < *N; j++)
            {
                fscanf(archt, " %d", &mat[i][j]);
            }
            i++;
        }
    }
}
void mostrar(int mat[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf(" %d \t", mat[i][j]);
        }
        printf("\n");
    }
}
int gradoEnt(int mat[][MAX], int N, int vert)
{
    int i, pos = vert - 1, cont = 0;

    for (i = 0; i < N; i++)
    {
        cont += mat[i][pos];
    }
    return cont;
}
int gradoSal(int mat[][MAX], int N, int vert)
{
    int i, pos = vert - 1, cont = 0;

    for (i = 0; i < N; i++)
    {
        cont += mat[pos][i];
    }
    return cont;
}
int gradoEntL(TLA vec[], int vert, int N)
{
    int i;
    int cont = 0;
    TLista aux;
    for (i = 0; i < N; i++)
    {
        if (vec[i].L != NULL)
        {
            aux = vec[i].L;
            while (aux != NULL)
            {
                if (aux->dato == vert)
                    cont++;
                aux = aux->sig;
            }
        }
    }
    return cont;
}
int gradoSalL(TLA vec[], int vert, int N)
{
    int i, cont = 0;
    i = 0;
    TLista aux;
    while (vec[i].vertice != vert)
        i++;
    aux = vec[i].L;
    while (aux != NULL)
    {
        if (aux->dato == vert)
        {
            cont--;
        }
        cont++;
        aux = aux->sig;
    }
    return cont;
} // preguntar en la clase