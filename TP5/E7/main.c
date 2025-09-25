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
    printf("\n");
    mostrar(&P, N);
}
void mostrarinverso(TPila *P, int N)
{
    if (N > 0 && !VaciaP(*P))
    {
        TElementoP x;
        sacaP(P, &x);
        printf("%d \n", x);
        mostrarinverso(P, N - 1);

        poneP(P, x);
    }
}
void mostrar(TPila *P, int N)
{
    if (N > 0 && !VaciaP(*P))
    {
        TElementoP x;
        sacaP(P, &x);
        mostrar(P, N - 1);
        printf("%d \n", x);
        poneP(P, x);
    }
}