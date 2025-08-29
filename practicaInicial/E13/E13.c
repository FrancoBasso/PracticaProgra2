#include <stdio.h>
#define N 15
int main(int argc, char const *argv[])
{
    int i;
    for (i = 1; i <= N; i++)
    {
        if ((i % 2) != 0)
            printf("%d \n", i);
    }

    return 0;
}
