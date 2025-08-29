#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define esalfabetico(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
int main()
{
    int a, b, x;
    char z;
    printf("ingrese 2 valores \n");
    scanf("%d %d", &a, &b);
    x = max(a, b);
    printf("%d ", x);
    printf("ingrese un caracter \n");
    scanf(" %c", &z);
    if (esalfabetico(z))
        printf("es alfabetico");
    else
        printf("no es alfabetico");
    return 0;
}
