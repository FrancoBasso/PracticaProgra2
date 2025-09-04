#include <stdio.h>
#include <stdlib.h>
void asiganarYcargarVector(float **vec, int *n);
void ListarPositivos(float *vec, int n);

int main(int argc, char const *argv[])
{
    float *vec;
    int n;
    asiganarYcargarVector(&vec, &n);
    if (vec == NULL)
        printf("error al asignar memoria");
    else
    {
        ListarPositivos(vec, n);
        free(vec);
        vec = NULL;
    }

    return 0;
}
void asiganarYcargarVector(float **vec, int *n)
{
    int i;
    printf("ingrese el tamanio del vector : \n");
    scanf("%d", n);
    *vec = (float *)malloc(*n * sizeof(float));
    if (*vec == NULL)
        printf("error al asignar memoria");
    else
    {
        printf("ingrese los valores");
        for (size_t i = 0; i < *n; i++)
        {
            printf("[%d]", i);
            scanf("%f", (*vec + i));
        }
    }
}
void ListarPositivos(float *vec, int n)
{
    int i;
    for (size_t i = 0; i < n; i++)

    {
        if (*(vec + i) > 0)
            printf("%f \n", *(vec + i));
    }
}