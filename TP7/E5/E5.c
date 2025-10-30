#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NodoA
{
    int dato;
    struct nodo *izq, *der;

} NodoA;
typedef NodoA *Tarbol;
int calcularProf(Tarbol A);
int max(int a, int b);
int longitudCad(Tarbol A);
int cantDer(Tarbol A);
void main()
{
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int calcularProf(Tarbol A)
{
    if (A != NULL)
    {
        if (A->izq == NULL && A->der == NULL)
            return 1;
        else
            return 1 + max(calcularProf(A->izq), calcularProf(A->der));
    }
    else
        return 0;
}
int longitudCad(Tarbol A)
{
    int auxizq, auxder;
    if (A != NULL)
    {

        auxizq = longitudCad(A->izq);
        auxder = longitudCad(A->der);
        return max(strlen(A->dato), max(auxizq, auxder));
    }
    else
        return 0;
}
int cantDer(Tarbol A)
{
    if (A != NULL)
    {
        if (A->der != NULL)
            return 1 + cantDer(A->izq) + cantDer(A->der);
        else
            return cantDer(A->izq) + cantDer(A->der);
    }
    else
        return 0;
}
