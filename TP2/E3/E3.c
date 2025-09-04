#include <stdio.h>
#include <stdlib.h>
int *asignarPunteros();
void Lectura(int *p);
int suma(int p, int p2, int p3);
int producto(int p, int p2, int p3);
void liberar(int *p, int *p2, int *p3);

void main(int argc, char const *argv[])
{
    int *pint1, *pint2, *pint3;
    pint1 = asignarPunteros();
    pint2 = asignarPunteros();
    pint3 = asignarPunteros();
    if (pint1 != NULL || pint2 != NULL || pint3 != NULL)
    {
        Lectura(pint1);
        Lectura(pint2);
        Lectura(pint3);
        printf("Suma = %d", suma(*pint1, *pint2, *pint3));
        printf("producto = %d", producto(*pint1, *pint2, *pint3));
        liberar(pint1, pint2, pint3);
    }
    else
        printf("error de en asigancion de memoria \n");
}
int *asignarPunteros()
{
    int *p;
    p = (int *)malloc(sizeof(int));

    if (p == NULL)
        return NULL;
    return p;
}
void Lectura(int *p)
{
    if (p == NULL)
    {
        printf("error al leer la memoria");
    }
    else
    {
        printf("ingrese el valor de el espacio de memoria \n");
        scanf("%d", p);
    }
}
int suma(int p, int p2, int p3)
{
    return p + p2 + p3;
}
int producto(int p, int p2, int p3)
{
    return p * p2 * p3;
}
void liberar(int *p, int *p2, int *p3)
{
    free(p);
    p = NULL;
    free(p2);
    p2 = NULL;
    free(p3);
    p3 = NULL;
}