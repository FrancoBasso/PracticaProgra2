#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

// -----------------------------
// Definición de estructuras
// -----------------------------
typedef struct NodoA
{
    int dato;
    struct NodoA *izq, *der;
} NodoA;

typedef NodoA *Tarbol;

// -----------------------------
// Prototipos
// -----------------------------
Tarbol crearNodo(int valor);
Tarbol cargarArbol(); // función automática de carga
void mostrarInOrden(Tarbol A);
void grado1(Tarbol A, int nivAct, int nivX, int *suma);
int grado1f(Tarbol A, int nivAct, int nivX);

// -----------------------------
// Programa principal
// -----------------------------
int main()
{
    Tarbol arbol = cargarArbol();

    printf("Recorrido InOrden del árbol:\n");
    mostrarInOrden(arbol);
    printf("\n");

    int nivel = 2;
    int suma = 0;

    // Versión con puntero
    grado1(arbol, 0, nivel, &suma);
    printf("Suma (con puntero) de nodos de grado 1 en nivel %d: %d\n", nivel, suma);

    // Versión con retorno
    int suma2 = grado1f(arbol, 0, nivel);
    printf("Suma (con retorno) de nodos de grado 1 en nivel %d: %d\n", nivel, suma2);

    return 0;
}

// -----------------------------
// Funciones auxiliares
// -----------------------------
Tarbol crearNodo(int valor)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(NodoA));
    nuevo->dato = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Carga automática del árbol
Tarbol cargarArbol()
{
    /* Árbol generado:
               10
              /  \
             5    15
            / \     \
           3   7     20
              /
             6
    */

    Tarbol raiz = crearNodo(10);
    raiz->izq = crearNodo(5);
    raiz->der = crearNodo(15);
    raiz->izq->izq = crearNodo(3);
    raiz->izq->der = crearNodo(7);
    raiz->izq->der->izq = crearNodo(6);
    raiz->der->der = crearNodo(20);

    return raiz;
}

void mostrarInOrden(Tarbol A)
{
    if (A != NULL)
    {
        mostrarInOrden(A->izq);
        printf("%d ", A->dato);
        mostrarInOrden(A->der);
    }
}

// -----------------------------
// Función con puntero
// -----------------------------
void grado1(Tarbol A, int nivAct, int nivX, int *suma)
{
    if (A != NULL)
    {
        if (nivAct == nivX && ((A->izq == NULL && A->der != NULL) || (A->izq != NULL && A->der == NULL)))
        {
            *suma = *suma + A->dato;
        }

        if (nivAct < nivX)
        {
            grado1(A->izq, nivAct + 1, nivX, suma);
            grado1(A->der, nivAct + 1, nivX, suma);
        }
    }
}

// -----------------------------
// Función con retorno directo
// -----------------------------
int grado1f(Tarbol A, int nivAct, int nivX)
{
    if (A != NULL)
    {
        if (nivAct == nivX && ((A->izq == NULL && A->der != NULL) || (A->izq != NULL && A->der == NULL)))
        {
            return A->dato;
        }
        else if (nivAct < nivX)
            return grado1f(A->izq, nivAct + 1, nivX) + grado1f(A->der, nivAct + 1, nivX);
    }
    return 0;
}