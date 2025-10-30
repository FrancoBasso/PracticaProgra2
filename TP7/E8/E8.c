#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct NodoA
{
    char dato[MAX];
    struct NodoA *izq, *der;
} NodoA;

typedef NodoA *Tarbol;
Tarbol crearNodo(char *nombre)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(NodoA));
    strcpy(nuevo->dato, nombre);
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}
Tarbol crearArbolEjemplo()
{
    Tarbol A = crearNodo("Nadal");        // ganador
    A->izq = crearNodo("Alcaraz");        // finalista 1
    A->der = crearNodo("Djokovic");       // finalista 2
    A->izq->izq = crearNodo("Sinner");    // semifinalista 1
    A->izq->der = crearNodo("Zverev");    // semifinalista 2
    A->der->izq = crearNodo("Rune");      // semifinalista 3
    A->der->der = crearNodo("Tsitsipas"); // semifinalista 4
    return A;
}
void mostrarGanador(Tarbol A);
void mostrarFinalistas(Tarbol A);
void mostrarSemifinalistas(Tarbol A);
void mostrarTodos(Tarbol A, int *cont);
void main()
{
    Tarbol torneo = crearArbolEjemplo();
    int cont = 0;
    mostrarGanador(torneo);
    mostrarFinalistas(torneo);
    mostrarSemifinalistas(torneo);

    printf("\n\nTodos los competidores:\n");
    mostrarTodos(torneo, &cont);
    printf("la cantidad de competidores es : %d \n", cont);
}
void mostrarGanador(Tarbol A)
{
    if (A != NULL)
    {
        printf(" ganador : %s \n", A->dato);
    }
}
void mostrarFinalistas(Tarbol A)
{
    if (A != NULL)
    {
        printf("finalistas : %s \t %s \n", A->izq->dato, A->der->dato);
    }
}
void mostrarSemifinalistas(Tarbol A)
{
    if (A != NULL)
    {
        printf(" semifinalistas :%s \t %s \t %s \t %s ", A->izq->izq->dato, A->izq->der->dato, A->der->izq->dato, A->der->der->dato);
    }
}
void mostrarTodos(Tarbol A, int *cont)
{
    if (A != NULL)
    {
        printf(" %s \n", A->dato);
        (*cont)++;
        mostrarTodos(A->izq, cont);
        mostrarTodos(A->der, cont);
    }
}
