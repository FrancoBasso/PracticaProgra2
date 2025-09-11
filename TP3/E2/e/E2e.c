#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void mezcla(int A[], int B[], int C[], int i, int j, int n, int m, int *l);
void muestra(int C[], int l);
void main()
{
    int A[] = {1, 3, 5, 7, 14, 55};
    int B[] = {2, 4, 44, 90, 120};
    int C[SIZE];
    int n = 6, m = 5, l;
    mezcla(A, B, C, 0, 0, n, m, &l);
    muestra(C, l + 1);
}
void mezcla(int A[], int B[], int C[], int i, int j, int n, int m, int *l)
{
    if (i == 0 && j == 0)
        *l = -1;
    if (i < n || j < m)
    {
        if (i < n && (j >= m || A[i] < B[j]))
        {
            (*l)++;
            C[*l] = A[i];
            mezcla(A, B, C, i + 1, j, n, m, l);
        }
        else if (j < m && (i >= n || A[i] > B[j]))
        {
            (*l)++;
            C[*l] = B[j];
            mezcla(A, B, C, i, j + 1, n, m, l);
        }
        else if ((i < n && j < m) && A[i] == B[j])
        {
            (*l)++;
            C[*l] = A[i];
            mezcla(A, B, C, i + 1, j + 1, n, m, l);
        }
    }
}
void muestra(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d \n", vec[i]);
    }
}
