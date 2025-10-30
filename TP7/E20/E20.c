#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;
int nivelesImpares(Tarbol A, int K);
Tarbol crearNodo(char dato);
Tarbol crearArbolEjemplo();
int alturaOG(Tarbol A);
int gradoOG(Tarbol A);
int gradoK(Tarbol A, int K, int *contnodos);
void main()
{
    int K = 1, contnodo = 0;
    int X = 1;
    Tarbol A = NULL;

    A = crearArbolEjemplo();
    printf("la cantidad de hijos en nivels impares son %d \n", nivelesImpares(A, K));
    printf("el promedio de los grados X es %f \n", gradoK(A, X, &contnodo) / (float)contnodo);
    printf("la altura del arbol original era %d \n", alturaOG(A));
    printf("el grado del arbol es %d", gradoOG(A));
}
int nivelesImpares(Tarbol A, int K)
{
    if (A != NULL)
    {
        if (K % 2 != 0)
            return 1 + nivelesImpares(A->izq, K + 1) + nivelesImpares(A->der, K);
        else
            return nivelesImpares(A->izq, K + 1) + nivelesImpares(A->der, K);
    }
    else
        return 0;
}
Tarbol crearNodo(char dato)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}
Tarbol crearArbolEjemplo()
{
    /*
          A
         /|\
        B C D
          |
          E
    */

    Tarbol A = crearNodo('A');
    Tarbol B = crearNodo('B');
    Tarbol C = crearNodo('C');
    Tarbol D = crearNodo('D');
    Tarbol E = crearNodo('E');

    // Enlace de hijos/hermanos (modelo hijo-izquierdo, hermano-derecho)
    A->izq = B; // A → primer hijo B
    B->der = C; // B → hermano derecho C
    C->der = D; // C → hermano derecho D
    C->izq = E; // C → primer hijo E

    return A;
}
int gradoK(Tarbol A, int K, int *cantnodos)
{
    int gr;
    Tarbol aux;
    if (A != NULL)
    {
        aux = A->izq;
        gr = 0;
        while (aux != NULL)
        {
            gr++;
            aux = aux->der;
        }
        if (gr == K)
        {
            (*cantnodos)++;
            return A->dato + gradoK(A->izq, K, cantnodos) + gradoK(A->der, K, cantnodos);
        }
        else
            return gradoK(A->izq, K, cantnodos) + gradoK(A->der, K, cantnodos);
    }
    else
        return 0;
}
int alturaOG(Tarbol A)
{
    int altizq, altder;
    if (A != NULL)
    {
        altizq = 1 + alturaOG(A->izq);
        altder = alturaOG(A->der);
        if (altizq > altder)
            return altizq;
        else
            return altder;
    }
    else
        return -1;
}
int gradoOG(Tarbol A)
{
    int gr, grizq, grder;
    Tarbol aux;
    if (A != NULL)
    {
        gr = 0;
        aux = A->izq;
        while (aux != NULL)
        {
            gr++;
            aux = aux->der;
        }
        grizq = gradoOG(A->izq);
        grder = gradoOG(A->der);
        if (gr >= grizq && gr >= grder)
            return gr;
        else if (grizq >= grder)
            return grizq;
        else
            return grder;
    }
    else
        return 0;
}
