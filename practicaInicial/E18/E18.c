#include <stdio.h>
#include <stdlib.h>
void duplicadofor(int vec[], int n);
void duplicadowhile(int vec[], int n);
void duplicadodowhile(int vec[], int n);
void muestra(int vec[], int n);
void main()
{
    int vec[] = {1, 3, 5, 4, 7}, n = 5;

    duplicadofor(vec, n);
    printf("duplicado por for \n");
    muestra(vec, n);
    printf("duplicado por dowhile \n");

    duplicadodowhile(vec, n);
    muestra(vec, n);
    printf("duplicado por while \n");

    duplicadowhile(vec, n);
    muestra(vec, n);
}
void duplicadofor(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            vec[i] = vec[i] * 2;
        }
    }
}
void duplicadowhile(int vec[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (i % 2 == 0)
        {
            vec[i] = vec[i] * 2;
        }
        i++;
    }
}
void duplicadodowhile(int vec[], int n)
{
    int i = 0;
    do
    {
        if (i % 2 == 0)
        {
            vec[i] = vec[i] * 2;
        }
        i++;
    } while (i < n);
}
void muestra(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d \t", vec[i]);
    }
    printf("\n");
}
// preguntar si esta bien