#include <stdio.h>
#include <stdlib.h>
int producto(int n1, int n2)
{
    if (n1 == 0)
        return 0;
    else
        return n2 + producto(n1 - 1, n2);
}
void main(int argc, char const *argv[])
{
    int n1, n2;
    printf("ingrese los 2 numeros enteros positivos \n");
    scanf(" %d %d", &n1, &n2);
    printf("resultado= %d", producto(n1, n2));
}
