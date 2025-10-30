#include <stdio.h>
#include <stdlib.h>
#include "colaEst.h"
#include "piladin.h"
typedef struct nodo
{
    TCola CL;
    struct nodo *sig;

} nodo;
typedef nodo *TLista;
void cargalista(TLista *L);
void cargaPila(TPila *P, TLista L);
void muestraPila(TPila *P);

void main(int argc, char const *argv[])
{
    TLista L;
    TPila P;
    cargalista(&L);
    cargaPila(&P, L);
    muestraPila(&P);
}
void cargalista(TLista *L)
{
    TLista aux, ultimo;
    FILE *archt;
    TElementoC valor;
    *L = NULL;
    archt = fopen("numeroscolaLista.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(archt, " %d", &valor);
        while (!feof(archt))
        {
            aux = (TLista)malloc(sizeof(nodo));
            IniciaC(&aux->CL);
            if (*L == NULL)
            {
                aux->sig = *L;
                *L = aux;
                ultimo = aux;
            }
            else
            {
                ultimo->sig = aux;
                aux->sig = NULL;
                ultimo = aux;
            }
            while (valor != 0)
            {
                poneC(&aux->CL, valor);

                fscanf(archt, " %d", &valor);
            }
            fscanf(archt, " %d", &valor);
        }
        fclose(archt);
    }
}
void cargaPila(TPila *P, TLista L)
{
    TLista Laux;
    TElementoC valor;
    TElementoC max;
    Laux = L;
    IniciaP(P);
    while (Laux != NULL)
    {
        if (!VaciaC(Laux->CL))
            sacaC(&Laux->CL, &max);
        while (!VaciaC(Laux->CL))
        {
            sacaC(&Laux->CL, &valor);
            if (valor > max)
                max = valor;
        }
        poneP(P, max);
        Laux = Laux->sig;
    }
}
void muestraPila(TPila *P)
{
    TPila Paux;
    TElementoP valor;
    IniciaP(&Paux);
    printf("los valores maximos son : \n");
    while (!VaciaP(*P))
    {
        sacaP(P, &valor);
        poneP(&Paux, valor);
    }
    while (!VaciaP(Paux))
    {
        sacaP(&Paux, &valor);
        printf(" %d \n", valor);
        poneP(P, valor);
    }
}
