#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float temp;

} Treg;
void main()
{
    float valmax = -999.0, valmin = 999.0, prom = 0;
    int cont = 0;
    FILE *archb;
    Treg reg;
    archb = fopen("temperatura.dat", "rb");
    if (archb == NULL)
        printf("el archivo no existe");
    else
    {
        fread(&reg, sizeof(Treg), 1, archb);
        while (!feof(archb))
        {
            cont++;

            if (reg.temp > valmax)

                valmax = reg.temp;
            if (reg.temp < valmin)
                valmin = reg.temp;
            prom = prom + reg.temp;
            fread(&reg, sizeof(Treg), 1, archb);
        }
        fclose(archb);
        printf("%d \n", cont);
        printf("temperatura maxima : %f \n", valmax);
        printf("temperatura minima : %f \n", valmin);
        if (cont != 0)
            printf("temperatura promedio : %f \n", prom / (float)cont);
    }
}