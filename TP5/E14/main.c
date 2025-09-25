#include <stdio.h>
#include <stdlib.h>
#include "pilaEst.h"
#include "colaEst.h"
void main()
{
    TCola C;
    TPila P;
    int i, N;
    char aux1, aux2;
    int espalindromo = 1;
    printf("ingrese el largo de la palabra \n");
    scanf("%d", &N);
    printf("ingrese la palabra letra por letra \n");
    IniciaC(&C);
    IniciaP(&P);
    for (size_t i = 0; i < N; i++)
    {
        scanf(" %c", &aux1);
        poneC(&C, aux1);
        poneP(&P, aux1);
    }
    sacaC(&C, &aux1);
    sacaP(&P, &aux2);
    while (!VaciaC(C) && espalindromo)
    {

        if (aux1 != aux2)
            espalindromo = 0;
        sacaC(&C, &aux1);
        sacaP(&P, &aux2);
    }
    if (espalindromo)
        printf("la palabra es palindroma");
    else
        printf("no es palindroma");
}
