#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;
void insertaArbol(Tarbol *A, int X);
void CrearArbol(Tarbol *A);
int esABB(Tarbol A);
void mostarArbolinOr(Tarbol A);
void main()
{
    Tarbol A = NULL;

    CrearArbol(&A);
    if (esABB(A))
        printf("es un ABB \n");
    else
        printf("no es un ABB \n");
    mostarArbolinOr(A);
}
void mostarArbolinOr(Tarbol A)
{
    if (A != NULL)
    {
        mostarArbolinOr(A->izq);
        printf(" %d \t", A->dato);
        mostarArbolinOr(A->der);
    }
}
void insertaArbol(Tarbol *A, int X)
{
    if (*A == NULL)
    {
        *A = (Tarbol)malloc(sizeof(nodoA));
        (*A)->dato = X;
        (*A)->izq = NULL;
        (*A)->der = NULL;
    }
    else

        if (X > (*A)->dato)
        insertaArbol(&((*A)->izq), X);
    else
        insertaArbol(&((*A)->der), X);
}
void CrearArbol(Tarbol *A)
{
    int X, i, n;
    printf("ingrese al cantidad de nodos del ABB \n");
    scanf(" %d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("ingrese el nodo %d ", i);
        scanf(" %d", &X);
        insertaArbol(A, X);
    }
}
int esABB(Tarbol A)
{
    if (A == NULL)
        return 1;
    else
    {
        if (A->izq != NULL && A->dato < A->izq->dato)
            return 0;
        if (A->der != NULL && A->dato > A->der->dato)
            return 0;

        return esABB(A->izq) && esABB(A->der);
    }
}
