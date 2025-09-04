#include <stdio.h>
void ordenadas(int *x, int *y)
{
    int aux;
    if (*x > *y)
    {
        aux = *x;
        *x = *y;
        *y = aux;
    }
}
int main()
{
    int a = 30, b = 20;
    ordenadas(&a, &b);
    printf(" valor de a %d\tvalor de b %d\n", a, b);
    return 0;
}
// preguntar en la practica si es correcto