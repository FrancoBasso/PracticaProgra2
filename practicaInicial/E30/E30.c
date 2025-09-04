#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char patente[7];
    int vel, velmax;
    char fecha[16];

} Treg;
void Listado()
{
    FILE *archb;
    Treg reg;
    archb = fopen("radar.dat", "rb");
    if (archb == NULL)
    {
        printf("el archivo no existe");
    }
    else
    {
        fread(&reg, sizeof(Treg), 1, archb);
        while (!feof(archb))
        {
            printf("%s %d %d %s", reg.patente, reg.vel, reg.velmax, reg.patente);
            fread(&reg, sizeof(Treg), 1, archb);
        }
        fclose(archb);
    }
}
void main()
{
    Treg reg;
    int vel, velmax;
    char pat[7];
    char fecha[16];
    FILE *archt, *archb;
    archt = fopen("radar.txt", "r");
    if (archt == NULL)
    {
        printf("el archivo de texto no pudo leerse");
        fclose(archt);
    }
    else
    {
        archb = fopen("radar.dat", "wb");
        if (archb == NULL)
        {
            printf("el archivo binario no pudo crearse");
        }
        else
        {
            fscanf(archt, "%s %d %d %s \n", pat, &vel, &velmax, fecha);
            while (!feof(archt))
            {
                if (vel > velmax * 1.20)
                {
                    reg.vel = vel;
                    reg.velmax = velmax;
                    strcpy(reg.patente, pat);
                    strcpy(reg.fecha, fecha);
                    fwrite(&reg, sizeof(Treg), 1, archb);
                }
                fscanf(archt, "%s %d %d %s \n", pat, &vel, &velmax, fecha);
            }
            fclose(archt);
            fclose(archb);
        }
        Listado();
    }
}
