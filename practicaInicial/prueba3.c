#include <stdio.h>

int main(int argc, char const *argv[])
{

    int c = 3, d = 2;
    c -= d++ * 3;
    printf(" valor de c %d\tvalor de d %d\n", c, d);

    return 0;
}