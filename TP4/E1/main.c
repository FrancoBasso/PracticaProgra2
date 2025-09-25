#include <stdio.h>
#include <stdlib.h>
#include "fracciones.h"
void main()
{
    Tfracc f1, f2, aux;
    int a, b;
    printf("ingrese los valores de la primera fraccion num/den \n");
    scanf("%d %d", &a, &b);
    f1 = crear(a, b);
    printf("ingrese los valores de la segunda fraccion num/den \n");
    scanf(" %d %d", &a, &b);
    f2 = crear(a, b);
    aux = sumar(f1, f2);
    printf("la suma de las fracciones es %d / %d ", aux.num, aux.den);
}
