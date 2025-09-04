#include <stdio.h>
void binario(int vec[], int n, int *l);
void muestra(int vec[], int);
void main()
{
    int n, l;
    int *vec;
    printf("ingrese un numero \n");
    scanf("%d", &n);
    binario(vec, n, &l);
    muestra(vec, l);
}
void muestra(int vec[], int l)
{
    int i;
    for (i = l - 1; i >= 0; i--)
    {
        printf("%d", vec[i]);
    }
}
void binario(int vec[], int n, int *l)
{
    int i = 0, aux;

    do
    {
        vec[i] = n % 2;
        n = n / 2;
        i++;
    } while (n > 0);
    *l = i;
}