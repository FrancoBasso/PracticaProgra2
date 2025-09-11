#include <stdio.h>
#include <stdlib.h>
int suma(int vec[], int n);
void muestra(int vec[], int n);
void muestrainversa(int vec[], int n);
void main()
{
    int vec[] = {1, 33, 44, 76, 12, 21, 13};
    int n = 6;
    printf("la suma de sus elementos es: %d \n", suma(vec, n));

    muestra(vec, n);
    printf("\n");
    muestrainversa(vec, n);
}
int suma(int vec[], int n)
{
    if (n < 0)
        return 0;
    else
        return vec[n] + suma(vec, n - 1);
}
void muestrainversa(int vec[], int n)
{
    if (n >= 0)
    {
        printf("%d \t", vec[n]);
        muestrainversa(vec, n - 1);
    }
}
void muestra(int vec[], int n)
{
    if (n >= 0)
    {
        muestra(vec, n - 1);
        printf("%d \t", vec[n]);
    }
}
