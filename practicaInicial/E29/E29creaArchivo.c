#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float temp;
} Ttemp;
void main(int argc, char const *argv[])
{
    FILE *archb, *archt;
    float tmp;
    Ttemp reg;
    archt = fopen("temperaturas.txt", "r");
    if (archt == NULL)
        printf("archivo de texto no existe");
    else
    {
        archb = fopen("temperatura.dat", "wb");
        if (archb == NULL)
        {
            printf("el archivo temperatura no pudo crearse");
            fclose(archt);
        }
        else
        {
            fscanf(archt, "%f \n", &tmp);
            while (!feof(archt))
            {
                reg.temp = tmp;
                fwrite(&reg, sizeof(Ttemp), 1, archb);
                fscanf(archt, "%f \n", &tmp);
            }
            fclose(archt);
            fclose(archb);
            printf("archivo creado con exito");
        }
    }
}
