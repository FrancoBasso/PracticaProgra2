#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;
void insertaIterativo(Tarbol *A, int X)
{
    Tarbol nuevo, act, ant;
    nuevo = (Tarbol)malloc(sizeof(nodoA));
    nuevo->dato = X;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    if (*A == NULL)
        *A = nuevo;
    else
    {
        act = *A;
        ant = NULL;
        while (act != NULL)
        {
            if (nuevo->dato < act->dato)
            {
                ant = act;
                act = act->izq;
            }
            else if (nuevo->dato > act->dato)
            {
                ant = act;
                act = act->der;
            }
        }
        if (ant->dato > nuevo->dato)
            ant->izq = nuevo;
        else
            ant->der = nuevo;
    }
}
void liberarArbol(Tarbol A)
{
    if (A != NULL)
    {
        liberarArbol(A->izq);
        liberarArbol(A->der);
        free(A);
    }
}
void mostrarInorden(Tarbol A);
void main()
{
    Tarbol A = NULL;
    int n, i, X;
    printf("ingrese la cantidad de valores a ingresar");
    scanf(" %d", &n);
    for (i = 0; i < n; i++)
    {
        printf("ingrese el valor a insertar");
        scanf(" %d", &X);
        insertaIterativo(&A, X);
    }
    mostrarInorden(A);
    liberarArbol(A);
}
void mostrarInorden(Tarbol A)
{
    if (A != NULL)
    {
        mostrarInorden(A->izq);
        printf(" %d", A->dato);
        mostrarInorden(A->der);
    }
}