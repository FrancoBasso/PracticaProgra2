#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void VertAlc(int R[][MAX], int i, int j, int N, int *Vmax, int *suma, int *sumaA);
void main()
{
    int R[MAX][MAX];
    int N, sumaact, sumaM, Vmax;
    VertAlc(R, 0, 0, N, &Vmax, &sumaM, &sumaact);
    printf("el vertice que mayor alcance tiene es : %d", Vmax);
}
void VertAlc(int R[][MAX], int i, int j, int N, int *Vmax, int *sumaM, int *sumaAct)
{
    if (j < N)
    {
        if (i < N)
        {
            *sumaAct = *sumaAct + R[i][j];
            VertAlc(R, i + 1, j, N, Vmax, sumaM, sumaAct);
        }
        else
        {

            if (*sumaAct > *sumaM)
            {
                *sumaM = *sumaAct;
                *Vmax = j;
            }
            *sumaAct = 0;
            VertAlc(R, 0, j + 1, N, Vmax, sumaM, sumaAct);
        }
    }
}