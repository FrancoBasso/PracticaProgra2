#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void iniciaParaFloyd(int mat[][MAX], int A[][MAX], int N);
void Floyd(int A[][MAX], int N);
void matrizAlcance(int A[][MAX], int R[][MAX], int N);
void main()
{
    int Mat[MAX][MAX];
    int A[MAX][MAX];
    int N;

    iniciaParaFloyd(Mat, A, N);
    Floyd(A, N);
}
void iniciaParaFloyd(int mat[][MAX], int A[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == j)
                A[i][j] = 0;
            else if (mat[i][j] != 0)
                A[i][j] = mat[i][j];
            else
                A[i][j] = 9999; // representa el infinito
        }
    }
}
void Floyd(int A[][MAX], int N)
{
    int i, j, k;
    for (k = 1; k <= N; k++)
        for (i = 1; i <= N; i++)
            for (j = 1; j <= N; j++)
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
}
void matrizAlcance(int A[][MAX], int R[][MAX], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i = j)
                R[i][j] = 1;
            else if (A[i][j] != 999)
                R[i][j] = 1;
            else
                R[i][j] = 0;
        }
    }
}