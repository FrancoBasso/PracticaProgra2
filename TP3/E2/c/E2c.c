#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void creamatriz(int mat[][SIZE], int n);
int Minimo(int mat[][SIZE], int i, int j, int n);
void main()
{
    int mat[SIZE][SIZE], n;
    printf("ingrese el tamanio de la matriz");
    scanf("%d", &n);
    creamatriz(mat, n);
    printf("el minimo de la matriz es %d", Minimo(mat, n - 1, n - 1, n - 1));
}
void creamatriz(int mat[][SIZE], int n)
{
    int i, j;
    printf("ingrese los elementos de la matriz cuadrada \n");
    for (i = 0; i < n; i++)
    {
        printf("fila %d \n", i);
        for (size_t j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}
int Minimo(int mat[][SIZE], int i, int j, int n)
{
    int min;
    if (i == 0 && j == 0)
        return mat[i][j];
    else
    {
        if (j == 0)
            min = Minimo(mat, i - 1, n - 1, n);
        else
            min = Minimo(mat, i, j - 1, n);
    }
    if (mat[i][j] < min)
        return mat[i][j];
    else
        return min;
}
