#include <stdio.h>
#include <stdlib.h>

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;

Tarbol insertar(Tarbol A, int valor);
int cuantos(Tarbol Ar, int A, int B);

int main()
{
    Tarbol Ar = NULL;
    int A, B, n, valor;

    // Pedimos los límites
    printf("Ingrese los valores de A y B respectivamente: ");
    scanf("%d %d", &A, &B);

    // Pedimos la cantidad de nodos y sus valores
    printf("Ingrese la cantidad de nodos a insertar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el valor del nodo %d: ", i + 1);
        scanf("%d", &valor);
        Ar = insertar(Ar, valor);
    }

    printf("La cantidad de valores entre %d y %d es: %d\n", A, B, cuantos(Ar, A, B));

    return 0;
}

// Inserta un valor en el ABB
Tarbol insertar(Tarbol A, int valor)
{
    if (A == NULL)
    {
        Tarbol nuevo = (Tarbol)malloc(sizeof(nodoA));
        nuevo->dato = valor;
        nuevo->izq = nuevo->der = NULL;
        return nuevo;
    }
    if (valor < A->dato)
        A->izq = insertar(A->izq, valor);
    else if (valor > A->dato)
        A->der = insertar(A->der, valor);
    return A;
}
int cuantos(Tarbol Ar, int A, int B)
{
    if (Ar != NULL)
    {
        if (Ar->dato >= A && Ar->dato <= B)
            return 1 + cuantos(Ar->izq, A, B) + cuantos(Ar->der, A, B);
        else if (Ar->dato < A)
            return cuantos(Ar->der, A, B);
        else if (Ar->dato > B)
            return cuantos(Ar->izq, A, B);
    }
    else
        return 0;
}