#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
int cuentaX(int mat[][SIZE], int i, int j, int m, int X);
void creamatriz(int mat[][SIZE], int n, int m);
void cuentaequis(int mat[][SIZE], int i, int j, int m, int X, int cont);
void main()
{
    int mat[SIZE][SIZE];
    int n, m;
    int X;
    printf("ingrese el valor de n y m\n");

    scanf(" %d %d", &n, &m);

    creamatriz(mat, n, m);
    printf("ingrese el valor a buscar \n");
    scanf(" %d", &X);
    printf("cuenata x con funcion int : %d \n", cuentaX(mat, n - 1, m - 1, m - 1, X));
    cuentaequis(mat, n - 1, m - 1, m - 1, X, 0);
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
int cuentaX(int mat[][SIZE], int i, int j, int m, int X)
{
    if (i < 0)
        return 0;
    else if (j < 0)
        return cuentaX(mat, i - 1, m, m, X);
    else
    {
        if (mat[i][j] == X)
            return 1 + cuentaX(mat, i, j - 1, m, X);
        else
            return cuentaX(mat, i, j - 1, m, X);
    }
}
void cuentaequis(int mat[][SIZE], int i, int j, int m, int X, int cont)
{
    if (i < 0)
        printf("el nmumero de apraiciones de %d es de %d", X, cont);
    else if (j < 0)
        cuentaequis(mat, i - 1, m, m, X, cont);
    else if (mat[i][j] == X)
    {

        cuentaequis(mat, i, j - 1, m, X, cont + 1);
    }
    else
        cuentaequis(mat, i, j - 1, m, X, cont);
}
