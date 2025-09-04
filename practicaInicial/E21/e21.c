#include <stdio.h>
void leevector(int vec[], int *n)
{
    int i = 0;
    char c;
    printf("desea ingresar valores al vector? \n");
    scanf("%c", &c);
    while (c != 'n' && c != 'N')
    {
        printf("ingrese el vector en la posicion %d \n ", i);
        scanf("%d", &vec[i]);
        i++;
        printf("desea ingresar valores al vector?\n");
        scanf(" %c", &c);
    }
    *n = i;
}
void posicionesimpares(int vec[], int n)
{
    if (n > 6)
    {
        printf("%d \t %d \t %d \n", vec[1], vec[3], vec[5]);
    }
}
void generarOtro(int vec1[], int vec2[], int n, int *l, int k)
{
    int i;
    *l = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (vec1[i] % k == 0)
        {

            vec2[*l] = vec1[i];
            (*l)++;
        }
    }
}
int buscapos(int vec[], int n, int x)
{
    int i = 0;
    while (i < n && vec[i] != x)
        i++;
    if (i < n)
        return i;
    else
        return -1;
}
void muestra(int vec[], int n)
{
    int i;
    for (size_t i = 0; i < n; i++)
    {
        printf("%d \t", vec[i]);
    }
    printf("\n");
}
void main()
{
    int vec1[15], vec2[15], n, l, k, x, h;
    leevector(vec1, &n);
    posicionesimpares(vec1, n);
    printf("ingrese el valor k");
    scanf("%d", &k);
    generarOtro(vec1, vec2, n, &l, k);
    muestra(vec2, l);
    printf("ingrese un valor x a buscar ");
    scanf("%d", &x);
    h = buscapos(vec1, n, x);
    if (h > -1)

        printf("el valor dado se encuentra en la posicion %d", h);
    else
        printf("no se encuentra el valor dado en el vector");
}