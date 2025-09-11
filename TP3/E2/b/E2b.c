#include <stdio.h>
#include <stdlib.h>
int busqueda(float vec[], int n, float x);
int busquedabinaria(float vec[], int fin, int inicio, float x);
void main()
{
    float vec1[] = {1.5, 33.4, 44.3, 76.6, 12.7, 21.8, 13.1};
    float vec2[] = {1.2, 1.4, 1.5, 1.6, 2.7, 3.8};
    int n = 6, m = 5;
    int res1, res2;
    float x;
    printf("ingrese el valor x a buscar para la busqueda lineal \n");
    scanf("%f", &x);
    res1 = busqueda(vec1, n, x);
    if (res1 != -1)
        printf("el elemento se encuentra en la posicion %d \n", res1);
    else
        printf("el elemento no se encuentra en el vector");
    printf("ingrese el valor x a buscar para la busqueda binaria \n");
    scanf("%f", &x);
    res2 = busquedabinaria(vec2, m, 0, x);
    if (res2 != -1)
        printf("el elemento se encuentra en la posicion %d ", res2);
    else
        printf("el elemento no se encuentra en el vector");
}
int busqueda(float vec[], int n, float x)
{
    if (n < 0)
        return -1;
    else
    {
        if (vec[n] == x)
            return n;
        else
            return busqueda(vec, n - 1, x);
    }
}
int busquedabinaria(float vec[], int fin, int inicio, float x)
{
    int medio = (inicio + fin) / 2;
    if (inicio > fin)
        return -1;
    else
    {
        if (vec[medio] == x)
            return medio;
        else if (vec[medio] > x)
            return busquedabinaria(vec, medio - 1, inicio, x);
        else
            return busquedabinaria(vec, fin, medio + 1, x);
    }
}
