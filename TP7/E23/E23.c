#include <stdio.h>
#include <stdlib.h>
#include "TDAN-Ario.h"
int cantNodos(TarbolN A, pos P);
void contarPares(TArbolN A, pos P, int *pares, int *total);
int gradoArbol(Tarbol A, pos P);
void contImpares(Tarbol A, pos P, int impares, int niveles);
float porcentaje(TArbolN A, pos P);
void verhijos(Tarbol A, pos P, int verifica);
int verhijosint(Tarbol A, pos P);
void PromedioK(Tarbol A, pos P, int niveles, float *prom);
void main()
{
}
int cantNodos(TarbolN A, pos P)
{
    pos C;
    int cont = 0;
    if (!nulo(P))
    {
        cont = 1;
        C = hijomasizq(P, A);
        while (!nulo(C))
        {
            cont += cantNodos(A, C);
            C = hijoder(C, A);
        }
    }
    return cont;
}
void contarPares(TArbolN A, pos P, int *pares, int *total)
{
    pos C;

    if (!nulo(P))
    {
        (*total)++;
        if (info(P, A) % 2 == 0) // accede al dato según tu TDA
            (*pares)++;

        C = hijomasizq(P, A);
        while (!nulo(C))
        {
            contarPares(A, C, pares, total);
            C = hijoder(C, A);
        }
    }
}

float porcentaje(TArbolN A, pos P)
{
    int pares = 0, total = 0;
    float porc = 0;

    contarPares(A, P, &pares, &total);

    if (total > 0)
        porc = (float)pares * 100 / total;

    return porc;
}
int gradoArbol(Tarbol A, pos P)
{
    pos C;
    int gr = 0;
    int max = 0, submax;
    if (!nulo(P))
    {
        C = hijomasizq(P, A);
        while (!nulo(C))
        {
            gr++;
            submax = gradoArbol(A, C);
            if (submax > max)
                max = submax;
            C = hijoder(C, A);
        }
        if (gr > max)
            max = gr;
        return max;
    }
}
void contImpares(Tarbol A, pos P, int *impares, int niveles)
{
    pos C;
    int gr = 0;
    if (!nulo(P))
    {
        C = hijomasizq(P, A);
        while (!nulo(C))
        {
            gr++;
            contImpares(A, C, impares, niveles + 1);
            C = hijoder(C, A);
        }

        if (niveles % 2 != 0)
            if (gr % 2 != 0)
                (*impares)++;
    }
}
void verhijos(Tarbol A, pos P, int *verifica)
{
    pos C;
    int gr = 0;
    if (!nulo(P) && *verifica == 1)
    {
        C = hijomasizq(P, A);
        while (!nulo(C))
        {
            gr++;
            verhijos(A, C, verifica);
            C = hijoder(C, A);
        }
        if (gr > 0)
            if (gr != info(P, A))
                *verifica = 0;
    }
}
int verhijosint(Tarbol A, pos P)
{
    // version int
    pos C;
    int verifica = 1, gr = 0;
    if (!nulo(P))
    {
        C = hijomasizq(P, A);
        while (!nulo(C) && verifica == 1)
        {
            gr++;
            verifica = verhijosint(A, C);
            C = hijoder(C, A);
        }
        if (gr > 0)
        {
            if (gr != info(P, A))
                verifica = 0;
        }
        return verifica;
    }
    else
        return 1;
}
void PromedioK(Tarbol A, pos P, int nivel, float *prom, int K, int *suma, int *cont)
{
    pos C;

    if (!nulo(P))
    {
        if (nivel == K)
        {
            (*cont)++;
            *suma += info(P, A);
        }

        C = hijomasizq(P, A);
        while (!nulo(C))
        {

            PromedioK(A, C, nivel + 1, prom, K, suma, cont);
            C = hijoder(C, A);
        }
        if (*cont != 0 && nivel == 0)
            *prom = (float)*suma / *cont;
    }
}
