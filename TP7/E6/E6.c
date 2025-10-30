#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef struct NodoA
{
    char dato[MAX];
    struct nodo *izq, *der;

} NodoA;
typedef NodoA *Tarbol;
Tarbol crearNodo(char *valor)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(NodoA));
    if (!nuevo)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    strcpy(nuevo->dato, valor);
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Función para insertar un nodo en el árbol de forma simple (no ordenada)
void insertar(Tarbol *raiz, char *valor)
{
    if (*raiz == NULL)
    {
        *raiz = crearNodo(valor);
    }
    else
    {
        if (strlen(valor) <= strlen((*raiz)->dato))
        {
            insertar(&((*raiz)->izq), valor);
        }
        else
        {
            insertar(&((*raiz)->der), valor);
        }
    }
}
void nivmasLargo(Tarbol A, int nivAct, int *nivmax, int *longmax);

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void main()
{
    Tarbol arbol = NULL;
    int nivMax = 0;
    int longmax = 0;
    insertar(&arbol, "Armeria");
    insertar(&arbol, "Almacen");
    insertar(&arbol, "Árbol");
    insertar(&arbol, "Binario");
    insertar(&arbol, "C");
    nivmasLargo(arbol, 0, &nivMax, &longmax);
    printf("el nivel donde se encuentra la palabra mas larga que empieza con A es :%d", nivMax);
}
void nivmasLargo(Tarbol A, int nivAct, int *nivmax, int *longmax)
{

    if (A != NULL)
    {
        if (A->dato[0] == 'A')
        {
            if (strlen(A->dato) > *longmax)
            {
                *longmax = strlen(A->dato);
                *nivmax = nivAct;
            }
        }
        nivmasLargo(A->der, nivAct + 1, nivmax, longmax);
        nivmasLargo(A->izq, nivAct + 1, nivmax, longmax);
    }
}