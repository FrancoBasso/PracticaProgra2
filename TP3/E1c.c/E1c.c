#include <stdio.h>
#include <stdlib.h>
int maximo(int vec[], int n);
void Max(int vec[], int n, int *maxium);
void main()
{
    int vec[] = {1, 33, 44, 76, 12, 21, 13};

    int n = 6, maxium = 0;
    printf("maximo con funcion : %d \n", maximo(vec, n));

    Max(vec, n, &maxium);
}
int maximo(int vec[], int n)
{
    int max;
    if (n == 0)
        return vec[n];
    else
    {
        max = maximo(vec, n - 1);
        if (vec[n] > max)
            return vec[n];
        else
            return max;
    }
}
void Max(int vec[], int n, int *maxium)
{

    if (n == 0)
        printf(" el maximo es %d", *maxium);
    else
    {

        if (vec[n] > *maxium)
        {
            *maxium = vec[n];
            Max(vec, n - 1, maxium);
        }

        else
            Max(vec, n - 1, maxium);
    }
}
