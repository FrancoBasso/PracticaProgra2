#include <stdio.h>
#include <stdlib.h>
#include "piladin.h"
#define SIZE 50
typedef struct
{
    int total;
    TPila PP;

} jugadores;
void creaMazo(TPila *P);
void iniciaMazos(jugadores vec[], int N);
void muestraResultados(jugadores vec[], int N);
void main()
{
    jugadores vec[SIZE];
    int N, i;
    TElementoP carta;
    TPila Mazo;
    IniciaP(&Mazo);
    creaMazo(&Mazo);
    printf("ingrese la cantidad de jugadores \n ");
    scanf("%d", &N);
    iniciaMazos(vec, N);
    while (!VaciaP(Mazo))
    {
        for (i = 0; i < N; i++)
            if (!VaciaP(Mazo))
            {
                sacaP(&Mazo, &carta);
                if (!VaciaP(vec[i].PP) && carta.palo == consultaP(vec[i].PP).palo)
                    vec[i].total = vec[i].total + 2 * carta.valor;
                else
                    vec[i].total = vec[i].total + carta.valor;
                poneP(&vec[i].PP, carta);
            }
    }
    muestraResultados(vec, N);
}
void creaMazo(TPila *P)
{
    FILE *archt;
    TElementoP aux;
    archt = fopen("Mazo_de_cartas.txt", "rt");
    if (archt == NULL)
        printf("el archivo no existe");
    else
    {
        fscanf(archt, "%c %d", &aux.palo, &aux.valor);
        while (!feof(archt))
        {
            poneP(P, aux);
            fscanf(archt, "%c %d", &aux.palo, &aux.valor);
        }
        fclose(archt);
    }
}
void iniciaMazos(jugadores vec[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        vec[i].total = 0;
        IniciaP(&vec[i].PP);
    }
}
void muestraResultados(jugadores vec[], int N)
{
    int i;
    printf("pel puntaje de los jugadores es el siguiente \n");
    for (i = 0; i < N; i++)
    {
        printf("jugador %d : %d \n", i + 1, vec[i].total);
    }
}
