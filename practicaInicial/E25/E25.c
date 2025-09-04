#include <stdio.h>
#include <string.h>
#define size 50
typedef struct
{
    char cad[16];
    int edad;
} Treg;
void Leevector(Treg vec[], int n);
float porcentaje(Treg vec[], int n);
void Listado(Treg vec[], int n, int x);

void main()
{
    Treg vec[size];
    int n, x;
    printf("ingrese la cantidad de personas \n");
    scanf("%d", &n);

    Leevector(vec, n);
    printf("ingrese la edad a superar \n");
    scanf("%d", &x);
    Listado(vec, n, x);
    printf("el porcentaje de personas que son mayores de edad es %f %% \n", porcentaje(vec, n));
}
void Leevector(Treg vec[], int n)
{
    int i;
    for (size_t i = 0; i < n; i++)
    {
        printf("ingrese el nombre y la edad de la persona %d \n", i + 1);
        getchar();
        fgets(vec[i].cad, sizeof(vec[i].cad), stdin);
        vec[i].cad[strcspn(vec[i].cad, "\n")] = '\0'; // quitar \n
        printf("ingrese la edad de la persona %d \n", i + 1);
        scanf(" %d", &vec[i].edad);
    }
}
void Listado(Treg vec[], int n, int x)
{
    int i;
    for (size_t i = 0; i < n; i++)
    {
        if (vec[i].edad > x)
            printf("%s \n", vec[i].cad);
    }
}
float porcentaje(Treg vec[], int n)
{
    int i, suma = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (vec[i].edad >= 18)
            suma++;
    }
    return (float)suma * 100 / n;
}