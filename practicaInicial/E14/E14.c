#include <stdio.h>
void cuadrado(int N)
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        if ((i == 1) || (i == N))
        {
            for (size_t j = 1; j <= N; j++)

            {
                printf("# ");
            }
        }
        else
        {
            for (size_t j = 1; j <= N; j++)
            {
                if ((j == 1) || (j == N))
                    printf("# ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int N;
    printf("ingrese la dimension del cuadrado");
    scanf("%d", &N);
    cuadrado(N);
    return 0;
}
