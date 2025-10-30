#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;
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
int esAVL(Tarbol A, int *altura);
void main()
{
}
int esAVL(Tarbol A, int *altura)
{
    int izq, der, altizq, altder;
    if (A != NULL)
    {
        izq = esAVL(A->izq, &altizq);
        der = esAVL(A->der, &altder);
        *altura = 1 + max(altizq, altder);

        if (abs(altizq - altder) <= 1 && (izq && der))
            return 1;
        else
            return 0;
    }
    else
    {
        *altura = 0;
        return 1;
    }
}