#include <stdio.h>
void formato(int N)
{
    int h, m, s;
    h = N / 3600;
    N = N % 3600;
    m = N / 60;
    s = N % 60;
    printf("%d:%d:%d\n", h, m, s);
}
int main()
{
    int N;
    printf("ingrese los segundos");
    scanf("%d", &N);
    formato(N);
    return 0;
}
