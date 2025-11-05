#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void kruskal(int matD[][MAX], int matK[][MAX], int N, int CC[]);
void prim(int matD[][MAX], int matK[][MAX], int N, int CC[]);
void main()
{
}
void kruskal(int matD[][MAX], int matK[][MAX], int N, int CC[])
{
    int i, j;
    int min, mini, minj;
    iniciaK(matK, N);
    while (!terminaK(CC, N))
    {
        min = 999;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (matD[i][j] != 0 && matD[i][j] < min && matK[i][j] == 0 && CC[i] != CC[j])
                {
                    min = matD[i][j];
                    mini = i;
                    minj = j;
                }
            }
        }
        matK[mini][minj] = min;
        matK[minj][mini] = min;

        for (i = 0; i < N; i++)
        {
            if (CC[i] == CC[minj])
                CC[i] = CC[mini];
        }
    }
}
int estaenU(int U[], int L, int j)
{
    int i = 0;
    while (i < L && U[i] != j)
        i++;
    if (i < L)
        return 1;
    else
        return 0;
}
void insrtaOrd(int U[], int *L, int eleg)
{
    int j = *L;
    while (j > -1 && U[j] > eleg)
    {
        U[j + 1] = U[j];
        j--;
    }
    U[j + 1] = eleg;
    (*L)++;
}

void prim(int matD[][MAX], int matK[][MAX], int N, int V[])
{
    int U[MAX];
    int L = 0;
    int i, j, eleg, elegi;
    int min;
    U[L] = V[0];
    while (L < N)
    {
        min = 9999;
        for (i = 0; i < L; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (matD[U[i]][j] != 0 && matD[U[i]][j] < min && !estaenU(U, L, j))
                {
                    min = matD[U[i]][j];
                    eleg = j;
                    elegi = U[i];
                }
            }
        }
        matK[elegi][eleg] = min;
        matK[eleg][elegi] = min;
        inseratOrd(U, &L, eleg);
    }
}