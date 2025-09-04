#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Crea y llena una matriz N x M con valores aleatorios entre 0 y 99.
   mat será asignado dentro de la función (por eso se pasa int ***mat). */
void crear_matriz_aleatoria(int ***mat, int n, int m)
{
    if (n <= 0 || m <= 0)
    {
        *mat = NULL;
        return;
    }

    *mat = malloc(n * sizeof(int *));
    if (*mat == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++)
    {
        (*mat)[i] = malloc(m * sizeof(int));
        if ((*mat)[i] == NULL)
        {
            perror("malloc");
            // liberar filas ya asignadas antes de salir
            for (int k = 0; k < i; k++)
                free((*mat)[k]);
            free(*mat);
            exit(EXIT_FAILURE);
        }
    }

    /* Llenar con números aleatorios (0..99) */
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            (*mat)[i][j] = rand() % 100;
}

/* Imprime la matriz */
void imprimir_matriz(int **mat, int n, int m)
{
    if (mat == NULL)
        return;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}

/* Libera la memoria de la matriz */
void liberar_matriz(int **mat, int n)
{
    if (mat == NULL)
        return;
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
}
void buscapos(int **mat, int n, int m, int x)
{
    int i = 0, j = 0;
    while (i < n && mat[i][j] != x)
    {
        j = 0;
        while (j < m && mat[i][j] != x)
            j++;

        if (mat[i][j] != x)
        {
            i++;
        }
    }
    if (mat[i][j] == x)
        printf("la pocicion en donde se encuentra el valor %d es la [%d,%d] \n", x, i, j);
    else
        printf("el valor no se encuentra en la matriz \n");
}
void promedioColumna(int **mat, int n, int m)
{
    int i, j;
    float prom;
    for (size_t j = 0; j < m; j++)
    {
        prom = 0;
        for (size_t i = 0; i < n; i++)
        {
            prom = prom + mat[i][j];
        }
        prom = prom / n;
        printf("el promedio para la columna %d es %f \n", j, prom);
    }
}

int main(void)
{
    int n, m, x;
    int **mat = NULL;

    printf("Ingrese N (filas): ");
    if (scanf("%d", &n) != 1)
        return 1;
    printf("Ingrese M (columnas): ");
    if (scanf("%d", &m) != 1)
        return 1;

    /* Semilla para rand */
    srand((unsigned)time(NULL));

    crear_matriz_aleatoria(&mat, n, m);

    printf("\nMatriz %d x %d aleatoria:\n", n, m);
    imprimir_matriz(mat, n, m);

    printf("ingrese el valor a buscar \n");
    scanf("%d", &x);
    buscapos(mat, n, m, x);
    promedioColumna(mat, n, m);
    liberar_matriz(mat, n);
    return 0;
}
