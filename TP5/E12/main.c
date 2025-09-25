#include <stdio.h>
#include <stdlib.h>
#include "pilaEst.h"
int aplicarOperacion(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("Error: división por cero\n");
            exit(1);
        }
        return a / b;
    }
    return 0;
}
void main(int argc, char const *argv[])
{
    TPila P;
    char c;
    int resultado;
    IniciaP(&P);
    printf("Ingrese la expresión postfija (un caracter a la vez, termine con =):\n");
    scanf(" %c", &c);
    while (c != '=')
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            int a, b, res;
            if (!VaciaP(P))
                sacaP(&P, &b);
            if (!VaciaP(P))
                sacaP(&P, &a);
            res = aplicarOperacion(a, b, c);
            poneP(&P, res);
        }
        else
        {

            poneP(&P, c - '0');
        }

        scanf(" %c", &c);
    }
    if (!VaciaP(P))
    {
        sacaP(&P, &resultado);
        printf("%d", resultado);
    }
}
