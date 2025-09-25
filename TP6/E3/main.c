#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
typedef struct nodo
{
    int contA;
    char cad[20];
    struct nodo *sig;
} nodo;
typedef nodo *TLista;

void creaLista(TLista *L);
void muestra(TLista L);
void main()
{
    TLista L;
    L = NULL;
    creaLista(&L);
    muestra(L);
}
void muestra(TLista L)
{
    TLista nodoaux;
    nodoaux = L;
    while (nodoaux != NULL)
    {
        printf("%s %d \n", nodoaux->cad, nodoaux->contA);
        nodoaux = nodoaux->sig;
    }
}
void creaLista(TLista *L)
{
    TLista aux, ant, act;
    int encontrada;
    char palabra[SIZE];
    FILE *archt;
    archt = fopen("palabras.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {

        fscanf(archt, " %s", palabra);
        while (!feof(archt))
        {
            encontrada = 0;
            act = *L;
            while (act != NULL && encontrada == 0)
            {
                if (strcmp(act->cad, palabra) == 0)
                {
                    act->contA++;
                    encontrada = 1;
                }
                act = act->sig;
            }
            if (encontrada == 0)
            {
                aux = (TLista)malloc(sizeof(nodo));
                strcpy(aux->cad, palabra);
                aux->contA = 1;

                if (*L == NULL || strcmp(aux->cad, (*L)->cad) < 0)
                {
                    aux->sig = *L;
                    *L = aux;
                }

                else
                {
                    ant = NULL;
                    act = *L;
                    while (act != NULL && strcmp(aux->cad, act->cad) > 0)
                    {
                        ant = act;
                        act = act->sig;
                    }
                    aux->sig = act;
                    ant->sig = aux;
                }
            }
            fscanf(archt, " %s", palabra);
        }
        fclose(archt);
    }
}
