#include <stdio.h>
void consecutivo(int a, int b, int c)
{
    int min = a, max = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;

    if (b > max)
        max = b;
    if (c > max)
        max = c;

    if (max - min == 2 && a != b && b != c && a != c)
        printf("Los numeros son consecutivos\n");
    else
        printf("No son consecutivos\n");
}
int main()
{
    int a, b, c;
    printf("ingrese los numeros consecutivos o no");
    scanf("%d %d %d", &a, &b, &c);
    consecutivo(a, b, c);

    return 0;
}
