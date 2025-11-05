#include <stdio.h>
#include <stdalign.h>
#define MAX 50
void cargaMatriz(int mat[][MAX], int *N);
void cargaVector(int mat[][MAX], int vec[], int i, int j, int N);
void main()
{
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
void cargaVector(int mat[][MAX], int vec[], int i, int j, int N)
{
    int gr = 0;
    if (i < N)
    {
        if (j < N)
        {
            cargaVector(mat, vec, i, j + 1, N);
            vec[i] += mat[i][j];
        }
        else
        {
            vec[i] = 0;
            cargaVector(mat, vec, i + 1, 0, N);
        }
    }
}
void mayorGradoEnt(int mat[][MAX], int i, int j, int N, int *suma)
{
    int max = -1;
    int vertmax = -1;
    if (j < N)
    {
        if (i < N)
        {
            *suma += mat[i][j];
            mayorGradoEnt(mat, i + 1, j, N, suma);
        }
        else
        {
            if (*suma > max)
            {
                max = *suma;
                vertmax = j;
            }
            *suma = 0;
            mayorGradoEnt(mat, i + 1, j, N, suma);
        }
    }
}