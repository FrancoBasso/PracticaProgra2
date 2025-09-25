#include <stdio.h>
#include <stdlib.h>
#include "colaEst.h"

void mostrar(TCola *C);
void main()
{
    FILE *archt;
    TCola C;
    int aux;
    IniciaC(&C);
    archt = fopen("numerosE4.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(archt, "%d", &aux);
        while (!feof(archt))
        {
            poneC(&C, aux);
            fscanf(archt, "%d", &aux);
        }
        fclose(archt);
        mostrar(&C);
    }
}
void mostrar(TCola *C)
{
    TCola Caux;
    int aux;
    IniciaC(&Caux);
    while (!VaciaC(*C))
    {
        sacaC(C, &aux);
        printf("%d \t ", aux);
        poneC(&Caux, aux);
    }
    printf("\n");
    while (!VaciaC(Caux))
    {
        sacaC(&Caux, &aux);
        poneC(C, aux);
    }
}
