#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void cargaMatriz(int matmat[][MAX], int N);
void iniciaMat(int matmat[][MAX], int N);
void mostrar(int matmat[][MAX], int N);
void MatrizSubyacente(int matmat[][MAX], int N);
void main()
{
    int mat[MAX][MAX];
    int N = 4;
    iniciaMat(mat, N);
    cargaMatriz(mat, N);
    mostrar(mat, N);
    MatrizSubyacente(mat, N);
    mostrar(mat, N);
}
void cargaMatriz(int mat[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("ingrese el valor de la fila %d y de la columna %d \n", i, j);
            scanf(" %d", &mat[i][j]);
        }
    }
}
void MatrizSubyacente(int mat[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (mat[i][j] == 1)
                mat[j][i] = 1;
        }
    }
}
void iniciaMat(int mat[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            mat[i][j] = 0;
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