#include <stdio.h>
#include <stdlib.h>
#include "pilaEst.h"

void mostrarinverso(TPila *P, int N);
void mostrar(TPila *P, int N);
void main()
{
    int N;
    TPila P;
    int DNI;
    IniciaP(&P);
    printf("ingrese el dni o 0 para fin de datos");
    scanf("%d", &DNI);
    while (DNI != 0)
    {
        poneP(&P, DNI);
        printf("ingrese el dni o 0 para fin de datos");
        scanf("%d", &DNI);
    }
    printf("ingrese el nuemro de DNIs a mostrar");
    scanf("%d", &N);
    mostrarinverso(&P, N);
    mostrar(&P, N);
}
void mostrarinverso(TPila *P, int N)
{
    int aux, i;
    TPila Paux;
    IniciaP(&Paux);
    printf("orden iverso \n");
    for (i = 0; i < N; i++)
    {
        if (!VaciaP(*P))
        {
            sacaP(P, &aux);
            printf("%d \n", aux);
            poneP(&Paux, aux);
        }
    }
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
}
void mostrar(TPila *P, int N)
{
    int aux, i;
    TPila Paux;
    IniciaP(&Paux);
    printf("orden en el que sufragaron \n");
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        poneP(&Paux, aux);
    }
    for (i = 0; i < N; i++)
    {
        if (!VaciaP(Paux))
        {
            sacaP(&Paux, &aux);
            printf("%d \n", aux);
            poneP(P, aux);
        }
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
}
