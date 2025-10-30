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

Tarbol crearNodo(char *nombre);
Tarbol crearArbolInvertido();
void mostrarArbolInvertido(Tarbol A, int nivel);
void mostrarGanadorinv(Tarbol A);
void mostrarFinalistasinv(Tarbol A);

void main()
{
    Tarbol torneoInvertido = crearArbolInvertido();

    printf("\n--- Árbol Binario Invertido (Draw del torneo) ---\n");
    mostrarArbolInvertido(torneoInvertido, 0);
}

// Crea un nuevo nodo
Tarbol crearNodo(char *nombre)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(NodoA));
    strcpy(nuevo->dato, nombre);
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

// Crea el árbol binario invertido del torneo
Tarbol crearArbolInvertido()
{
    // Jugadores iniciales (hojas)
    Tarbol sinner = crearNodo("Sinner");
    Tarbol zverev = crearNodo("Zverev");
    Tarbol rune = crearNodo("Rune");
    Tarbol tsitsipas = crearNodo("Tsitsipas");

    // Ganadores semifinales
    Tarbol alcaraz = crearNodo("Alcaraz");
    Tarbol djokovic = crearNodo("Djokovic");

    // En árbol invertido, los jugadores apuntan hacia abajo al ganador del partido
    sinner->der = alcaraz;
    zverev->izq = alcaraz;
    rune->der = djokovic;
    tsitsipas->izq = djokovic;

    // Ganador final
    Tarbol nadal = crearNodo("Nadal");
    alcaraz->der = nadal;
    djokovic->izq = nadal;

    return sinner; // Devuelve el nodo superior (una hoja inicial)
}

// Muestra el árbol invertido (visual)
void mostrarArbolInvertido(Tarbol A, int nivel)
{
    if (A != NULL)
    {
        for (int i = 0; i < nivel; i++)
            printf("   ");
        printf("-> %s\n", A->dato);
        mostrarArbolInvertido(A->izq, nivel + 1);
        mostrarArbolInvertido(A->der, nivel + 1);
    }
}
void mostrarGanadorinv(Tarbol A)
{
    if (A != NULL)
    {
        if (A->der == NULL && A->izq == NULL)
            printf("ganador %s \n", A->dato);
    }
}
