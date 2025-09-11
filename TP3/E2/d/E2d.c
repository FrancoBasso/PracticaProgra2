#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void creamatriz(int mat[][SIZE], int n, int m);
void creavector(int mat[][SIZE], int i, int j, int m, int vec[], int max);
void muestraVector(int vec[], int n);
void main()
{
    int n, m;
    int mat[SIZE][SIZE], vec[SIZE];
    printf("ingrese el valor de n y m");
    scanf(" %d %d", &n, &m);
    creamatriz(mat, n, m);
    creavector(mat, n, m, m, vec, 0);
    muestraVector(vec, n);
}
void creamatriz(int mat[][SIZE], int n, int m)
{
    int i, j;
    printf("ingrese los elementos de la matriz cuadrada \n");
    for (i = 0; i < n; i++)
    {
        printf("fila %d \n", i);
        for (size_t j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }
}
void creavector(int mat[][SIZE], int i, int j, int m, int vec[], int max)
{
    if (i != -1)
    {
        if (j < 0)
        {
            vec[i] = max;
            creavector(mat, i - 1, m, m, vec, 0);
        }
        else
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
                creavector(mat, i, j - 1, m, vec, max);
            }
            else
                creavector(mat, i, j - 1, m, vec, max);
        }
    }
}
void muestraVector(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d \t", vec[i]);
    }
}