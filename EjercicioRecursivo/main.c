#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarRangoIterativo(int, int);
void MostrarRangoRecursivo(int, int, int);

int main()
{
    // Realice un programa que muestre todos los números dentro de un
    // rango indicado por el usuario.
    int limI, limS;

    printf("Digite los límites: ");
    do
    {
        printf("Inferior: ");
        scanf("%d", &limI);
        printf("Superior: ");
        scanf("%d", &limS);
    } while (limI > limS);

    //MostrarRangoIterativo(limI, limS);
    MostrarRangoRecursivo(limI, limS, limI);

    return 0;
}

void MostrarRangoIterativo(int limI, int limS)
{
    int valorActual;
    for(valorActual = limI; valorActual <= limS; valorActual++)
    {
        printf("%d\t", valorActual);
    }
}

void MostrarRangoRecursivo(int limI, int limS, int valorActual)
{
    // Axioma, o caso base.
    if(valorActual > limS)
        return;

    // Cuerpo:
    printf("%d\t", valorActual);

    // Llamada recursiva (con un cambio).
    MostrarRangoRecursivo(limI, limS, valorActual + 1);

    // Ahora, imprimo otra cosa:
    //printf("\nMitad: %d\t", valorActual / 2);
    printf("%d\t", valorActual);
}