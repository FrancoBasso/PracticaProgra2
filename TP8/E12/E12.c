#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
#include "colaEst.h"
#define MAX 50
typedef struct nodo
{
    int dato;
    struct nodo *sig;
} nodo;
typedef nodo *TLista;
typedef struct
{
    int vertice;
    TLista L;
} TLA;
void RecorridoProfundidad(TLA LA[], int vv[], int N);
void RecorridoAmplitud(TLA LA[], int vv[], int N);

void main()
{
}
void RecorridoProfundidad(TLA LA[], int vv[], int N)
{
    TPila P;
    IniciaP(&P);
    TElementoP X;
    int Vact, i, contVal = 0;
    TLista aux;
    for (i = 0; i < N; i++)
    {
        if (vv[i] == 0)
        {

            Vact = i;
            printf(" %d", Vact);
            poneP(&P, Vact);
            vv[Vact] = 1;

            while (!VaciaP(P))
            {
                Vact = consultaP(P);
                if (LA[Vact].L != NULL)
                {
                    contVal++;
                    aux = LA[Vact].L;
                    while (aux != NULL && vv[aux->dato] == 1)
                        aux = aux->sig;
                    if (aux != NULL)
                    {
                        if (vv[aux->dato] == 0)
                        {
                            printf(" %d", aux->dato);
                            poneP(&P, aux->dato);
                            vv[aux->dato] = 1;
                        }
                    }
                    else
                        sacaP(&P, &X);
                }
            }
        }
    }
    printf("los vertices conexos son un total de : %d", contVal);
}
void RecorridoAmplitud(TLA LA[], int vv[], int N)
{
    TCola C;
    IniciaC(&C);
    TElementoC X;
    int Vact, i, contVal = 0;
    TLista aux;
    for (i = 0; i < N; i++)
    {
        if (vv[i] == 0)
        {
            Vact = i;
            printf(" %d", Vact);
            poneC(&C, Vact);
            vv[Vact] = 1;
            while (!VaciaC(C))
            {
                sacaC(&C, &Vact);
                if (LA[Vact].L != NULL)
                {
                    aux = LA[Vact].L;
                    while (aux != NULL)
                    {
                        if (vv[aux->dato] == 0)
                        {
                            printf(" %d", aux->dato);
                            vv[aux->dato] = 1;
                            poneC(&C, aux->dato);
                        }
                        aux = aux->sig;
                    }
                }
            }
        }
    }
}