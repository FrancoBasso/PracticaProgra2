#include <stdio.h>
#include <stdlib.h>
void main()
{
    int i, n, sum = 0;
    FILE *arch;
    arch = fopen("numeros12.txt", "r");
    if (arch == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(arch, "%d", &n);
        sum = sum + n;

        while (!feof(arch))
        {

            fscanf(arch, " %d", &n);
            sum = sum + n;
            printf("%d \n", n);
        }
        fclose(arch);
        printf("el resultado de lo sumado en el archivo es %d", sum);
    }
}
