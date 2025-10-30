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
void generarArreglo(Tarbol A, int vec[], int *N);
void mostarArreglo(int vec[], int N);
void mostarArbolinOr(Tarbol A);
void main()
{
    Tarbol A = NULL;
    int vec[50], N = -1;
    CrearArbol(&A);
    mostarArbolinOr(A);
    printf("\n");
    generarArreglo(A, vec, &N);
    mostarArreglo(vec, N);
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
        insertaArbol(&((*A)->der), X);
    else
        insertaArbol(&((*A)->izq), X);
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
void generarArreglo(Tarbol A, int vec[], int *N)
{
    if (A != NULL)
    {
        generarArreglo(A->der, vec, N);
        vec[++(*N)] = A->dato;
        generarArreglo(A->izq, vec, N);
    }
}
void mostarArreglo(int vec[], int N)
{
    int i;
    for (i = 0; i <= N; i++)
    {
        printf(" %d \t", vec[i]);
    }
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
