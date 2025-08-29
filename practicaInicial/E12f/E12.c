#include <stdio.h>
int main()
{
    int n, res = 0;
    printf("ingrese un numero natural \n");
    scanf("%d", &n);
    while (n != 0)
    {
        res += n;
        printf("ingrese un numero natural \n");
        scanf(" %d", &n);
    }
    printf("el resultado es : %d", res);
    return 0;
}
