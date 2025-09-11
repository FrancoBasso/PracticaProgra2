#include <stdio.h>
#include <stdlib.h>
float suma(int vec[], int n);
void main()
{
    int vec[] = {1, 33, 44, 76, 12, 21, 13};
    int n = 6;
    printf("el promedio de sus elementos %f \n", suma(vec, n) / (n + 1));
}
float suma(int vec[], int n)
{
    if (n < 0)
        return 0;
    else
        return vec[n] + suma(vec, n - 1);
}