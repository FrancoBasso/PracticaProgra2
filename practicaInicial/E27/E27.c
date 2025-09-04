#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50
typedef struct
{
    int fila, columna, valor;
} Treg;
void LeeMatriz(int mat[][SIZE], int *, int *);
void armaVector(Treg vec[], int mat[][SIZE], int n, int m, int *);
void muestra(Treg vec[], int);
void main()
{
    int n, m, l;
    int mat[SIZE][SIZE];
    Treg vec[SIZE];
    LeeMatriz(mat, &n, &m);
    armaVector(vec, mat, n, m, &l);
    muestra(vec, l);
}
void LeeMatriz(int mat[][SIZE], int *n, int *m)
{
    int i, j;
    printf("\nn: ");
    scanf(" %d", n);
    printf("\nm: ");
    scanf(" %d", m);
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *m; j++)
        {
            scanf(" %d", &mat[i][j]);
        }
        printf("\n");
    }
}
void armaVector(Treg vec[], int mat[][SIZE], int n, int m, int *l)
{
    int i, j;
    *l = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (mat[i][j] % (n + m) == 0)
            {
                vec[*l].fila = i;
                vec[*l].columna = j;
                vec[*l].valor = mat[i][j];
                (*l)++;
            }
        }
    }
}
void muestra(Treg vec[], int l)
{
    int i;
    printf("los valores que son divisibles por n+m son \n");
    for (size_t i = 0; i < l; i++)
    {
        printf("[%d,%d]=%d \n", vec[i].fila, vec[i].columna, vec[i].valor);
    }
}
