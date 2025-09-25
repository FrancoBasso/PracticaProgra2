#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
void main()
{
    FILE *archt;
    TPila P;
    char car;
    archt = fopen("caracteresE2.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        IniciaP(&P);
        fscanf(archt, "%c", &car);
        while (!feof(archt))
        {
            poneP(&P, car);
            fscanf(archt, "%c", &car);
        }
        fclose(archt);
        while (!VaciaP(P))
        {
            sacaP(&P, &car);
            printf("%c \n", car);
        }
    }
}