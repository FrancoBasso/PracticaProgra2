#include <stdio.h>
#include <stdlib.h>
#include "colaEst.h"
void formato(int N)
{
    int h, m, s;
    h = N / 3600;
    N = N % 3600;
    m = N / 60;
    s = N % 60;
    printf("%d:%d:%d\t", h, m, s);
}
void mostrar(TCola *C);
void promedio(TCola *C);
void mayorEspera(TCola *C);
void main(int argc, char const *argv[])
{
    TCola C;
    TElementoC aux;
    FILE *archt;
    archt = fopen("microondas.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(archt, "%d %d %d", &aux.Nlegajo, &aux.horaArribo, &aux.Uso);

        while (!feof(archt))
        {
            poneC(&C, aux);
            fscanf(archt, "%d %d %d", &aux.Nlegajo, &aux.horaArribo, &aux.Uso);
        }
        fclose(archt);
        mostrar(&C);
        promedio(&C);
        maximo(&C);
    }
}

void mostrar(TCola *C)
{
    TCola Caux;
    TElementoC aux;

    while (!VaciaC(*C))
    {
        sacaC(C, &aux);
        printf("%d \t", aux.Nlegajo);
        formato(aux.horaArribo);
        formato(aux.horaArribo + aux.Uso);
        poneC(&Caux, aux);
    }
    while (!VaciaC(Caux))
    {
        sacaC(&Caux, &aux);

        poneC(C, aux);
    }
}
void promedio(TCola *C)
{
    TCola Caux;
    int cont = 0;
    float prom = 0;
    TElementoC aux;

    while (!VaciaC(*C))
    {
        sacaC(C, &aux);
        prom = prom + (aux.Uso);
        cont++;
        poneC(&Caux, aux);
    }
    while (!VaciaC(Caux))
    {
        sacaC(&Caux, &aux);

        poneC(C, aux);
    }
    printf("el promedio es %f", prom / cont);
}
void mayorEspera(TCola *C)
{
    TCola Caux;
    TElementoC aux;
    int legmax = 0, maximo = 0;
    while (!VaciaC(*C))
    {
        sacaC(C, &aux);
        if (maximo < aux.Uso)
        {
            maximo = aux.Uso;
            legmax = aux.Nlegajo;
        }
        poneC(&Caux, aux);
    }
    while (!VaciaC(Caux))
    {
        sacaC(&Caux, &aux);

        poneC(C, aux);
    }
    printf("el legajo con mayor tiempo de espera fue %d", legmax);
}
