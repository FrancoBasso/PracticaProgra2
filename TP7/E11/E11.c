#include <stdio.h>
#include <stdlib.h>

typedef struct NodoA
{
    int dato;
    struct NodoA *izq, *der;
} NodoA;

typedef NodoA *Tarbol;

// --- Prototipos ---
Tarbol crearNodo(int valor);
Tarbol insertarABB(Tarbol A, int valor);
Tarbol cargarABB();
void mostrarInOrden(Tarbol A);
int minimoABB(Tarbol A);

// --- Programa principal ---
void main()
{
    Tarbol A = cargarABB();

    printf("Recorrido InOrden del ABB:\n");
    mostrarInOrden(A);

    printf("\n\nValor mínimo del ABB: %d\n", minimoABB(A));
}

// --- Crear nodo nuevo ---
Tarbol crearNodo(int valor)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(NodoA));
    nuevo->dato = valor;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

// --- Insertar en ABB ---
Tarbol insertarABB(Tarbol A, int valor)
{
    if (A == NULL)
        return crearNodo(valor);

    if (valor < A->dato)
        A->izq = insertarABB(A->izq, valor);
    else if (valor > A->dato)
        A->der = insertarABB(A->der, valor);

    return A;
}

// --- Cargar árbol ABB automáticamente ---
Tarbol cargarABB()
{
    Tarbol A = NULL;
    int valores[] = {15, 10, 20, 8, 12, 25, 5};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        A = insertarABB(A, valores[i]);

    return A;
}

// --- Mostrar recorrido InOrden (ascendente) ---
void mostrarInOrden(Tarbol A)
{
    if (A != NULL)
    {
        mostrarInOrden(A->izq);
        printf("%d ", A->dato);
        mostrarInOrden(A->der);
    }
}

// --- Función para encontrar el mínimo en ABB ---
int minimoABB(Tarbol A)
{
    if (A != NULL)
    {
        if (A->izq == NULL)
            return A->dato;
        else
            return minimoABB(A->izq);
    }
    else
        return 0; // árbol vacío
}