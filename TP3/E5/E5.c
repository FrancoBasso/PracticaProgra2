#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void creamatriz(int mat[][SIZE], int n, int m);
int esdiagonal(int mat[][SIZE], int i, int j, int m);
void main()
{
    int mat[SIZE][SIZE];
    int n, m;
    int res;

    printf("ingrese el valor de n y m\n");

    scanf(" %d %d", &n, &m);

    creamatriz(mat, n, m);
    res = esdiagonal(mat, n - 1, m - 1, m - 1);
    if (res > 0)
        printf("la matriz es simetrica");
    else
        printf("la matriz no es simatrica");
}
void creamatriz(int mat[][SIZE], int n, int m)
{
    int i, j;
    printf("ingrese los elementos de la matriz  \n");
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
int esdiagonal(int mat[][SIZE], int i, int j, int m)
{
    if (i < 0)
        return 1;
    else if (j == i)
        return esdiagonal(mat, i - 1, m, m);
    else if (mat[i][j] == mat[j][i])
        return esdiagonal(mat, i, j - 1, m);
    else
        return 0;
}
