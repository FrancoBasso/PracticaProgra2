#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct nodoA
{
    int dato;
    struct nodoA *izq, *der;
} nodoA;

typedef nodoA *Tarbol;
int alturaArbol(Tarbol A);
int cantArbolesK(Tarbol A, int X);
int claveMayor(Tarbol A);
Tarbol crearNodo(int dato);
Tarbol crearBosqueEjemplo();
void generarVect(Tarbol A, int vec[], int *n);
int verificaGK(Tarbol A, int K);
int verifica(Tarbol A, int K);
void mostrarVect(int vec[], int n);

void main()
{
    Tarbol A = crearBosqueEjemplo();
    int X = 1, K = 0;
    int vec[MAX];
    int n = 0;
    printf("la cantidad de arboles con altura %d del bosque es %d \n ", X, cantArbolesK(A, X));
    generarVect(A, vec, &n);
    mostrarVect(vec, n);
    if (verifica(A, K))
        printf(" verifica \n");
    else
        printf("no verifica");
}
int cantArbolesK(Tarbol A, int K)
{
    int cont = 0;
    while (A != NULL)
    {
        if (A->izq == NULL)
        {
            if (K == 0)
                cont++;
        }
        else if (alturaArbol(A->izq) + 1 >= K)
            cont++;
        A = A->der;
    }
    return cont;
}
int alturaArbol(Tarbol A)
{
    int altizq, altder;
    if (A != NULL)
    {

        altizq = 1 + alturaArbol(A->izq);
        altder = alturaArbol(A->der);
        return (altizq > altder) ? altizq : altder;
    }
    else
        return -1;
}
void generarVect(Tarbol A, int vec[], int *n)
{
    int max;
    while (A != NULL)
    {
        max = claveMayor(A->izq);
        if (A->dato > max)
            vec[*n] = A->dato;
        else
            vec[*n] = max;

        (*n)++;
        A = A->der;
    }
}
int claveMayor(Tarbol A)
{
    int claizq, clader, mayor;
    if (A != NULL)
    {
        claizq = claveMayor(A->izq);
        clader = claveMayor(A->der);
        mayor = A->dato;

        if (mayor < claizq)
            mayor = claizq;
        if (mayor < clader)
            mayor = clader;
        return mayor;
    }
    else
        return 0;
}
int verifica(Tarbol A, int K)
{
    int ver = 1;
    while (A != NULL && ver)
    {
        ver = verificaGK(A, K);

        A = A->der;
    }
    return ver;
}
int verificaGK(Tarbol A, int K)
{
    int gr;
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
        if (gr == K)
            return 1;
        else
            return verificaGK(A->izq, K) || verificaGK(A->der, K);
    }
    else
        return 0;
}
// Crear nodo
Tarbol crearNodo(int dato)
{
    Tarbol nuevo = (Tarbol)malloc(sizeof(nodoA));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

// Crear bosque ejemplo
Tarbol crearBosqueEjemplo()
{
    // Árbol 1
    Tarbol A1 = crearNodo(10);
    Tarbol N5 = crearNodo(5);
    Tarbol N8 = crearNodo(8);
    A1->izq = N5;
    N5->der = N8;

    // Árbol 2
    Tarbol A2 = crearNodo(7);
    A1->der = A2;

    // Árbol 3
    Tarbol A3 = crearNodo(15);
    A2->der = A3;
    Tarbol N12 = crearNodo(12);
    Tarbol N20 = crearNodo(20);
    A3->izq = N12;
    N12->der = N20;

    return A1; // raíz del primer árbol
}
void mostrarVect(int vec[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" %d \t", vec[i]);
    }
    printf("\n");
}
