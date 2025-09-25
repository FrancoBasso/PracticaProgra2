#include "fracciones.h"
#include <stdio.h>
#include <stdlib.h>
int calcularMCD(int a, int b)
{

    if (b == 0)
    {
        return a;
    }
    else
    {

        return calcularMCD(b, a % b);
    }
}
Tfracc crear(int a, int b)
{
    Tfracc aux;
    aux.num = a;
    aux.den = b;
    return aux;
}
int denominador(Tfracc frac)
{
    return frac.den;
}
int numerador(Tfracc frac)
{
    return frac.num;
}

Tfracc sumar(Tfracc f1, Tfracc f2)
{
    Tfracc aux;
    if (f1.den == f2.den)
    {
        aux.den = f1.den;
        aux.num = f1.num + f2.num;
    }
    else
    {
        aux.den = f1.den * f2.den;
        aux.num = f1.num * f2.den + f1.den * f2.num;
    }
    return aux;
}
Tfracc restar(Tfracc f1, Tfracc f2)
{
    Tfracc aux;
    if (f1.den == f2.den)
    {
        aux.den = f1.den;
        aux.num = f1.num - f2.num;
    }
    else
    {
        aux.den = f1.den * f2.den;
        aux.num = f1.num * f2.den - f1.den * f2.num;
    }
    return aux;
}
Tfracc multiplicar(Tfracc f1, Tfracc f2)
{
    Tfracc aux;
    aux.den = f1.den * f2.den;
    aux.num = f1.num * f2.num;
    return aux;
}
Tfracc dividir(Tfracc f1, Tfracc f2)
{
    Tfracc aux;
    aux.num = f1.num * f2.den;
    aux.den = f1.den * f2.num;
    return aux;
}
Tfracc simplificar(Tfracc f1)
{
    Tfracc aux;
    int simpl;
    simpl = calcularMCD(abs(f1.num), abs(f1.den));

    aux.num = f1.num / simpl;
    aux.den = f1.den / simpl;
}
int iguales(Tfracc f1, Tfracc f2)
{
    if (f1.num == f2.num && f1.den == f2.den)
        return 1;
    else
        return 0;
}
