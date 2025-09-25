#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piladin.h"
#include "colaDin.h"
#include <ctype.h>
#define SIZE 50
typedef struct
{
    char letra;
    TPila P;
} pilas;
void armaPilas(TCola *C, pilas vec[], int *N);
int buscapos(pilas vec[], char letra, int N);
void muestraPilaPedida(pilas vec[], int pos);

void main()
{
    pilas vec[SIZE];
    TCola C;
    char aux[20];
    char letra;
    int N, pos;
    IniciaC(&C);
    printf("ingrese el apellido y nombre del competidor");
    scanf("%s", aux);
    while (strcmp(aux, "***") != 0)
    {
        poneC(&C, aux);
        printf("ingrese el apellido y nombre del competidor o *** para el fin de los datos \n");
        scanf("%s", aux);
    }
    armaPilas(&C, vec, &N);
    printf("ingrese una inicial para mostrar todos los participantes \n");
    scanf(" %c", &letra);
    pos = buscapos(vec, letra, N);
    if (pos != -1)
        muestraPilaPedida(vec, pos);
    else
        printf("no hay apellidos con esa inicial\n");
}
int buscapos(pilas vec[], char letra, int N)
{
    int i = 0;

    while (i < N && vec[i].letra != letra)
        i++;
    if (i < N)
        return i;
    else
        return -1;
}
void armaPilas(TCola *C, pilas vec[], int *N)
{
    char aux[20];
    int pos;
    *N = 0;
    while (!VaciaC(*C))
    {
        sacaC(C, aux);
        pos = buscapos(vec, toupper(aux[0]), *N);
        if (pos == -1)
        {
            (*N)++;
            pos = *N;

            vec[pos].letra = toupper(aux[0]);
            IniciaP(&vec[pos].P);
        }
        poneP(vec[pos].P, aux);
    }
}
void muestraPilaPedida(pilas vec[], int pos)
{
    char aux[20];
    TPila Paux;
    IniciaP(&Paux);
    while (!VaciaP(vec[pos].P))
    {
        sacaP(&vec[pos].P, &aux);
        printf("%s \n", aux);
        poneP(&Paux, aux);
    }
    while (!VaciaP(Paux))
    {
        sacaP(Paux, &aux);
        poneP(&vec[pos].P, aux);
    }
}
