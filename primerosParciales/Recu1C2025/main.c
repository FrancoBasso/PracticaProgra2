#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piladin.h"
#define ANU40 40
#define ANU30 30
#define ANU10 10
#define ANU13 13
typedef struct nodoC
{
    char RS[ANU40];
    char prov[ANU30];
    float cpv;
    struct nodoC *sig;
} nodoC;
typedef nodoC *TListaC;
typedef struct
{
    char RS[ANU40];
    float recB, recN;
} TregB;
typedef struct
{
    char RS[ANU40];
    char prov[ANU30];
    char codMP[ANU10];
    char fecha[10];
    char hora[9];
    char cuit[ANU13];
    float imp;

} Tregt;
void cargalista(TListaC *L);
void cargaPila(TPila *P);
void eliminaProv(TListaC *L, char prov[ANU30]);
void comisionPila(TPila *P, char codMP[ANU10], float *comP);
int buscaLista(TListaC L, char RS[ANU40]);
void generarbinario(TListaC *L, TPila *P);
int esMayo2025(char fechaHora[10])
{
    int dia, mes, anio;
    sscanf(fechaHora, "%d/%d/%d", &dia, &mes, &anio);
    return (mes == 5 && anio == 2025);
}
void main()
{
    TListaC L;
    TPila P;
    cargalista(&L);
    IniciaP(&P);
    cargaPila(&P);
    generarbinario(&L, &P);
}
void generarbinario(TListaC *L, TPila *P)
{
    FILE *archt;
    FILE *archb;
    char auxrs[3], RSact[ANU40];
    TListaC nuevo;
    Tregt regt;
    TregB regb;
    float impB, impN, comP;

    archt = fopen("VENTAS.TXT", "rt");
    if (archt == NULL)
        printf("el archivo de texto no existe");
    else
    {
        archb = fopen("COMXCC202505.DAT", "ab");
        if (archb == NULL)
            printf("no se pudo abrir el archivo binario");
        else
        {
            fscanf(archt, " %s %s %s %s %s %f", regt.RS, regt.prov, regt.codMP, regt.fecha, regt.cuit, &regt.imp);

            while (!feof(archt))
            {
                strcpy(auxrs, regt.RS + strlen(regt.RS) - 2);
                while (strcmp(auxrs, "AR") != 0 || esMayo2025(regt.fecha) == 0)
                {
                    fscanf(archt, " %s %s %s %s %s %s %f", regt.RS, regt.prov, regt.codMP, regt.fecha, regt.hora, regt.cuit, &regt.imp);
                    strcpy(auxrs, regt.RS + strlen(regt.RS) - 2);
                }

                if (buscaLista(L, regt.RS) == 1)
                {
                    nuevo = (TListaC)malloc(sizeof(nodoC));
                    strcpy(nuevo->RS, regt.RS);
                    strcpy(nuevo->prov, regt.prov);
                    nuevo->cpv = 0.045;
                    if (*L == NULL)
                    {
                        nuevo->sig = nuevo;
                        (*L) = nuevo;
                    }
                    else
                    {
                        nuevo->sig = (*L)->sig;
                        (*L)->sig = nuevo;
                        (*L) = nuevo;
                    }
                }

                strcpy(RSact, regt.RS);
                impB = 0;
                impN = 0;

                while (!feof(archt) && strcmp(RSact, regt.RS) == 0 && esMayo2025(regt.fecha) == 1)
                {
                    impB = impB + regt.imp;
                    comP = 0.045;
                    comisionPila(P, regt.codMP, &comP);
                    impN = impN - (regt.imp - regt.imp * comP);
                    fscanf(archt, " %s %s %s %s %s %s %f", regt.RS, regt.prov, regt.codMP, regt.fecha, regt.hora, regt.cuit, &regt.imp);
                }
                strcpy(regb.RS, RSact);
                regb.recB = impB;
                regb.recN = impN;
                fwrite(&regb, sizeof(TregB), 1, archb);
            }
            fclose(archt);
            fclose(archb);
        }
    }
}
int buscaLista(TListaC L, char RS[ANU40])
{
    TListaC aux;
    if (L != NULL)
    {
        aux = L->sig;
        do
        {
            aux = aux->sig;
        } while (aux != L->sig && strcmp(aux->RS, RS) != 0);
        if (aux == L->sig && strcmp(aux->RS, RS) != 0)
            return 1;
        else
            return 0;
    }
    else
        return 1;
}
void comisionPila(TPila *P, char codMP[ANU10], float *comP)
{
    TElementoP elem;

    if (!VaciaP(*P))
    {
        sacaP(P, &elem);
        comisionPila(P, codMP, comP);
        if (strcmp(elem.codMP, codMP) == 0)
            *comP = elem.comision;
        poneP(P, elem);
    }
}
void eliminaProv(TListaC *L, char prov[ANU30])
{
    TListaC act, ant, elim;
    if (*L != NULL)
    {
        act = (*L)->sig;
        ant = (*L);
        if ((*L)->sig == *L && strcmp((*L)->prov, prov) == 0)
        {
            free(*L);
            *L = NULL;
        }
        else
        {
            do
            {
                if (strcmp(act->prov, prov) == 0)
                {
                    if (act == *L)
                        (*L) = ant;
                    ant->sig = act->sig;
                    elim = act;
                    act = act->sig;

                    free(elim);
                }
                else
                {
                    ant = act;
                    act = act->sig;
                }

            } while (act != (*L)->sig);
        }
    }
}