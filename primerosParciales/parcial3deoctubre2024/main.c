#include <stdio.h>
#include <stdlib.h>
#include "colaDin.h"
#include "string.h"
#define EN_RANGO(a, b, x) ((x) >= (a) && (x) <= (b))
typedef struct nodito
{
    char pat[7];
    int fechaj;
    char hora[5];
    int tah, tam;
    int trh, trm;
    struct nodito *sig;
} nodito;
typedef nodito *Sublista;
typedef struct nodoD
{
    char cod[5];
    char nombre[30];
    char Est;
    Sublista multa;
    struct nodoD *ant, *sig;

} nodoD;
typedef nodoD *PnodoD;
typedef struct
{
    char pat[7];
    int fechaj;
    char hora[5];
    int tah, tam;
    int trh, trm;
} Tregm;
typedef struct
{
    PnodoD pri, ult;

} TlistaD;
int mesJuliano(int dia)
{
    int diasMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int mes = 1;
    int acumulado = 0;

    while (dia > acumulado + diasMes[mes - 1])
    {
        acumulado += diasMes[mes - 1];
        mes++;
    }

    return mes;
}
void cargaLista(TlistaD *LD);
void cargaCola(TCola *C);
void cargaSeptiembre(TlistaD *LD, TCola *C);
void agenteAG(TlistaD LD, char AG[5], int K);
void eliminaAGX(TlistaD *LD, char X[5]);
void main()
{
    TlistaD LD;
    TCola C;
    char AG[5], X[5];
    int k;
    LD.pri = NULL;
    LD.ult = NULL;
    IniciaC(&C);
    cargaCola(&C);
    cargaLista(&LD);
    cargaSeptiembre(&LD, &C);
    printf("ingrese el agente AG y el numero k");
    scanf(" %s %d", AG, &k);
    agenteAG(LD, AG, k);
    printf("ingrese el agente X");
    scanf(" %s", X);
    eliminaAGX(&LD, X);
}
void cargaSeptiembre(TlistaD *LD, TCola *C)
{
    PnodoD aux;
    Sublista actS, antS, nuevoS;
    TCola Caux;
    TElementoC regC;
    IniciaC(&Caux);
    while (!VaciaC(*C))
    {
        sacaC(C, &regC);
        if ((regC.fechamulta >= 240 && regC.fechamulta <= 270) && regC.TP < regC.TR)
        {

            aux = (*LD).pri;
            while (aux != NULL && strcmp(regC.codAg, aux->cod) != 0)
            {
                aux = aux->sig;
            }
            nuevoS = (Sublista)malloc(sizeof(nodito));
            strcpy(nuevoS->pat, regC.pat);
            strcpy(nuevoS->hora, regC.horamulta);
            nuevoS->fechaj = regC.fechamulta;
            nuevoS->tah = regC.TP / 60;
            nuevoS->tam = regC.TP % 60;
            nuevoS->trh = regC.TR / 60;
            nuevoS->trm = regC.TR % 60;
            nuevoS->sig = NULL;

            if (aux->multa == NULL || strcmp(nuevoS->pat, aux->multa->pat) < 0)
            {
                nuevoS->sig = aux->multa;
                aux->multa = nuevoS;
            }
            else
            {
                actS = aux->multa->sig;
                antS = aux->multa;
                while (actS != NULL && strcmp(nuevoS->pat, actS->pat) > 0)
                {
                    antS = actS;
                    actS = actS->sig;
                }
                antS->sig = nuevoS;
                nuevoS->sig = actS;
            }
        }
        else
            poneC(&Caux, regC);
    }
    while (!VaciaC(Caux))
    {
        sacaC(&Caux, &regC);
        poneC(C, regC);
    }
}
void agenteAG(TlistaD LD, char AG[5], int K)
{
    PnodoD aux;
    int cont = 0;
    Sublista actS;
    Tregm regm;
    FILE *archb;
    archb = fopen("MULTAS.DAT", "wb");
    if (archb != NULL)
    {
        aux = LD.pri;
        while (aux != NULL && strcmp(AG, aux->cod) != 0)
        {
            aux = aux->sig;
        }
        if (aux->multa != NULL)
        {
            actS = aux->multa;
            while (actS != NULL)
            {
                if (mesJuliano(actS->fechaj) % 2 == 0 && (strcmp(actS->hora, "12:00") < 0 || strcmp(actS->hora, "18:00") > 0))
                {
                    cont++;
                    strcpy(regm.pat, actS->pat);
                    strcpy(regm.hora, actS->hora);
                    regm.fechaj = actS->fechaj;
                    regm.tah = actS->tah;
                    regm.tam = actS->tam;
                    regm.trh = actS->trh;
                    regm.trm = actS->trm;
                    fwrite(&regm, sizeof(regm), 1, archb);
                }
                actS = actS->sig;
            }
            if (aux->Est == 'S' && cont >= K)
                printf("el agente %s esta en condiciones de recibir la bonificacion del 15\%", AG);
        }
        fclose(archb);
    }
}
void eliminaAGX(TlistaD *LD, char X[5])
{
    PnodoD act;
    Sublista actS, antS, elim;
    if ((*LD).pri != NULL)
    {
        act = (*LD).pri;
        while (act != NULL && strcmp(X, act->cod) != 0)
            act = act->sig;

        if (act == NULL)
            printf("no se encontro el agente X \n");
        else
        {
            actS = act->multa;
            antS = NULL;
            while (actS != NULL)
            {
                if (strncmp(actS->pat, "AF", 2) == 0)
                {
                    if (actS == act->multa)
                        act->multa = actS->sig;
                    else
                        antS->sig = actS->sig;
                    elim = actS;
                    actS = actS->sig;

                    free(elim);
                }
                else
                {
                    antS = actS;
                    actS = actS->sig;
                }
            }
        }
        if (act->multa == NULL)
        {
            if ((*LD).pri == (*LD).ult)
            {
                (*LD).pri = (*LD).ult = NULL;
            }
            if (act == (*LD).pri)
            {
                (*LD).pri = act->sig;
                act->sig->ant = NULL;
            }
            else if (act == (*LD).ult)
            {
                (*LD).ult = act->ant;
                act->ant->sig = NULL;
            }
            else
            {
                act->ant->sig = act->sig;
                act->sig->ant = act->ant;
            }
            free(act);
        }
    }
}
// en el main cont=0;
