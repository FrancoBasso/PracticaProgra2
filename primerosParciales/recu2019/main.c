#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colaDin.h"
#define ANU30 30
#define ANU7 7
typedef struct nodito
{
    char codP[ANU7];
    int dest;
    int cantPS, cantPE;
    struct nodito *sig;
} nodito;
typedef nodito *Sublista;
typedef struct nodoC
{
    int id;
    char nom[ANU30];
    int cantTPS;
    struct nodoC *sig;
    Sublista prod;
} nodoC;
typedef nodoC *TlistaC;
typedef struct nodoR
{
    int idR, idP;
    TCola CP;
    struct nodoR *sig;
} nodoR;
typedef nodoR *TListaR;
void cargaLista(TlistaC *LC);
void cargaRobots(TListaR *LR);
void LeePedidos(TlistaC *LR);
void main()
{
    TlistaC LC;
    TListaR LR;
}
void LeePedidos(TlistaC *LC)
{
    TlistaC act, ant, nuevo;
    Sublista ultS, nuevoS;
    FILE *archt;
    int i, idp, dest, cantP, contP;
    char nomP[ANU30], codP[ANU7];

    archt = fopen("PEDIDOS.TXT", "rt");
    if (archt != NULL)
    {
        fscanf(archt, " %d %s %d", &idp, nomP, &cantP);
        while (!feof(archt))
        {
            nuevo = (TlistaC)malloc(sizeof(nodoC));
            nuevo->id = idp;
            strcpy(nuevo->nom, nomP);
            if (nuevo->id > (*LC)->id)
            {
                nuevo->sig = (*LC)->sig;
                (*LC)->sig = nuevo;
                *LC = nuevo;
            }
            else
            {
                act = (*LC)->sig;
                ant = (*LC);
                while (nuevo->id > act->id)
                {
                    ant = act;
                    act = act->sig;
                }
                if (nuevo->id == act->id)
                {
                    free(nuevo);
                }
                else
                {
                    nuevo->prod = NULL;
                    act = nuevo;
                }
            }
            for (i = 1; i <= cantP; i++)
            {
                fscanf(" %d %s %d ", &dest, codP, &contP);
                nuevoS = (Sublista)malloc(sizeof(nodito));
                nuevoS->dest = dest;
                strcpy(nuevoS->codP, codP);
                nuevoS->cantPS = contP;
                nuevoS->cantPE = 0;
                nuevoS->sig = NULL;
                if (act->prod == NULL)
                {
                    act->prod = nuevo;
                    ultS = nuevoS;
                }
                else
                {
                    ultS->sig = nuevoS;
                    ultS = nuevo;
                }
            }
            fscanf(archt, " %d %s %d", &idp, nomP, &cantP);
        }
        fclose(archt);
    }
}
