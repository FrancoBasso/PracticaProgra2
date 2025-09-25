#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
void cuenta0(TPila *P);
void promedio(TPila *P);
void maxYmin(TPila *P);
void quitaUltimos(TPila *P);
void Muestra(TPila *P);
void main()
{
    TPila P;
    int N, i, aux;
    IniciaP(&P);
    printf("ingrese la cantidad de numeros a ingresar \n");
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        printf("ingrese el numero %d \n", i);
        scanf("%d", &aux);
        poneP(&P, aux);
    }
    cuenta0(&P);
    promedio(&P);
    maxYmin(&P);
    quitaUltimos(&P);
    Muestra(&P);
}
void cuenta0(TPila *P)
{
    int cont = 0;
    TPila Paux;
    int aux;
    IniciaP(&Paux);
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        if (aux == 0)
            cont++;
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
    printf("la cantidad de 0s es de : %d \n", cont);
}
void promedio(TPila *P)
{
    int cont = 0;
    float prom = 0;
    TPila Paux;
    int aux;
    IniciaP(&Paux);
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        cont++;
        prom = aux + prom;
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
    prom = prom / cont;
    printf("el promedio de sus elementos es : %f \n", prom);
}
void maxYmin(TPila *P)
{
    int max, min;
    TPila Paux;
    int aux;
    IniciaP(&Paux);
    sacaP(P, &min);
    max = min;

    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        if (aux > max)
            max = aux;
        if (aux < min)
            min = aux;
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
    printf("el mayor elementos es : %d \n", max);
    printf("el menor elementos es : %d \n", min);
}
void quitaUltimos(TPila *P)
{
    int ultimo;
    TPila Paux;
    int aux;
    IniciaP(&Paux);
    sacaP(P, &ultimo);
    poneP(&Paux, ultimo);
    while (!VaciaP(*P))
    {
        sacaP(P, &aux);
        if (aux <= ultimo)
            poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &aux);
        poneP(P, aux);
    }
}
void Muestra(TPila *P)
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
