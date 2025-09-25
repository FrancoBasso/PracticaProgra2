#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
void negativo(TPila *P);
void mostrar(TPila *P);
void main()
{
    TPila P;
    int N, i, aux;
    printf("ingrese la cantidad de numeros a ingresar \n");
    scanf("%d", &N);
    IniciaP(&P);
    for (i = 0; i < N; i++)
    {
        printf("ingrese el dato %d", i);
        scanf("%d", &aux);
        poneP(&P, aux);
    }
    negativo(&P);
    mostrar(&P);
}
void negativo(TPila *P)
{
    TElementoP x;
    if (!VaciaP(*P))
    {
        sacaP(P, &x);
        negativo(P);
        poneP(P, -x);
    }
}
void mostrar(TPila *P)
{

    TPila Paux;
    int aux;
    IniciaP(&Paux);
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        printf("%d \n", aux);
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
}