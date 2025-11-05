#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
#include "colaEst.h"
#define MAX 50

void RecorridoProfundidad(int mat[][MAX], int vv[], int N);
void RecorridoAmplitud(int mat[][MAX], int vv[], int N);
void main()
{
}
int Todosvisit(int vec[], int N)
{
    int i = 0;
    while (i < N && vec[i] == 1)
        i++;
    if (i < N)
        return 0;
    else
        return 1;
}
void RecorridoProfundidad(int mat[][MAX], int vv[], int N)
{
    TPila P;
    TElementoP V;
    int cont = 0;
    IniciaP(&P);
    int j, vertAct, i, flag;
    for (i = 0; i < N; i++)
    {
        if (vv[i] == 0)
        {

            vertAct = i;
            printf(" %d", vertAct);
            vv[vertAct] = 1;
            poneP(&P, vertAct);
            while (!VaciaP(P))
            {
                vertAct = consultaP(P);
                j = 0;
                flag = 0;
                while (j < N && (mat[vertAct][j] == 0 || vv[j] == 1))
                {
                    j++;
                    if (mat[vertAct][j] == 1)
                        flag = 1;
                }
                if (flag)
                    cont++;
                if (j < N)
                {
                    if (vv[j] == 0)
                    {
                        poneP(&P, j);
                        printf(" %d", j);
                        vv[j] = 1;
                    }
                }
                else
                    sacaP(&P, &V);
            }
        } // preguntar por la condicion de conexa
    }
    printf("la cantidad de componentes conexas es : %d", cont);
}
void RecorridoAmplitud(int mat[][MAX], int vv[], int N)
{
    TElementoC V;
    TCola C;
    int vertAct, j;
    IniciaC(&C);
    vertAct = 0;
    printf(" %d", vertAct);
    vv[vertAct] = 1;
    poneC(&C, vertAct);
    while (!Todosvisit(vv, N) && !VaciaC(C))
    {
        sacaC(&C, &vertAct);

        j = 0;
        while (j < N)
        {
            if (mat[vertAct][j] == 1 && vv[j] == 0)
            {
                printf("%d", j);
                poneC(&C, j);
                vv[j] = 1;
            }
            j++;
        }
    }
}
