#include <stdio.h>
#include <stdlib.h>
typedef struct NodoA
{
    int dato;
    struct nodo *izq, *der;

} NodoA;
typedef NodoA *Tarbol;
int sumaM3(Tarbol A);
int sumaCantH(Tarbol A);
int estaX(Tarbol A, int X);
int main()
{
    Tarbol A;

    return 0;
}
int sumaM3(Tarbol A)
{
    if (A != NULL)
    {
        if (A->dato % 3 == 0)
            return A->dato + sumaM3(A->izq) + sumaM3(A->der);
        else
            return sumaM3(A->izq) + sumaM3(A->der);
    }
    else
        return 0;
}
int sumaCantH(Tarbol A)
{
    if (A != NULL)
    {
        if (A->der == NULL && A->izq == NULL)
            return 1;
        else
            return sumaCantH(A->izq) + sumaCantH(A->der);
    }
    else
        return 0;
}
int estaX(Tarbol A, int X)
{
    if (A != NULL)
    {
        if (X == A->dato)
            return 1;
        else
            return estaX(A->izq, X) || estaX(A->der, X);
    }
    else
        return 0;
}
