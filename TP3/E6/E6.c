#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void creamatriz(int mat[][SIZE], int n, int m);
int verificaSuma(int mat[][SIZE], int i, int j, int m, int sumaact, int sumaant);
void main()
{
    int mat[SIZE][SIZE];
    int n, m;
    int res;

    printf("ingrese el valor de n y m\n");

    scanf(" %d %d", &n, &m);

    creamatriz(mat, n, m);
    res = verificaSuma(mat, n - 1, m - 1, m - 1, 0, 0);
    if (res > 0)
        printf("la matriz verifica ");
    else
        printf("la matriz no verifica");
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
int verificaSuma(int mat[][SIZE], int i, int j, int m, int sumaact, int sumaant)
{
    if (i < 0)
        return 1;
    else if (i == 0)
    {
        if (j == 0)
        {
            if (sumaact % 2 == 0)
                return verificaSuma(mat, i - 1, m, m, 0, sumaact);
            else
                return 0;
        }
        else
            return verificaSuma(mat, i, j - 1, m, (sumaact + mat[i][j]), sumaant);
    }
    else if (j == 0)
    {
        if (sumaact > sumaant)
            return verificaSuma(mat, i - 1, m, m, 0, sumaact);
        else
            return 0;
    }
    else
        return verificaSuma(mat, i, j - 1, m, (sumaact + mat[i][j]), sumaant);
}
