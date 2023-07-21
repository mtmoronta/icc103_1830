#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;

void generarAleatorios(int, int[]);
void intercambiar(int*, int*);
void mostrarArreglo(int, int[]);
int particionar(int[], int, int);
void quicksort(int, int[], int, int);

int main()
{
    int n;
    srand(time(NULL));
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);

    int arreglo[n];

    generarAleatorios(n, arreglo);
    mostrarArreglo(n, arreglo);
    quicksort(n, arreglo, 0, n-1);
    //printf("\n%d", particionar(arreglo, 0, n-1));
    mostrarArreglo(n, arreglo);
}

void generarAleatorios(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        arreglo[i] = rand()%(MAX-MIN+1)+MIN;
    }
}

void intercambiar(int *primero, int *segundo)
{
    int burbuja;
    burbuja = *primero;
    *primero = *segundo;
    *segundo = burbuja;
}

void mostrarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", arreglo[i]);
    }
}

int particionar(int arreglo[], int limI, int limS)
{
    // Primer paso: elegir el pivote.
    int pivote = arreglo[limS], i, indiceMenor = limI - 1;

    for(i=limI; i<limS; i++)
    {
        // Si el valor en la posición actual (i) es mayor o igual
        // que el pivote, no hago nada.

        if(arreglo[i] < pivote) // Si fueran cadenas: if(strcmp(str1, str2) < 0)
        {
            // Si es menor, se hacen dos cosas:
            // 1: Mover el índice menor a la derecha.
            indiceMenor++;

            // 2: Intercambiar el menor en la posición actual
            // con el que está en el índice menor.
            intercambiar(&arreglo[indiceMenor], &arreglo[i]);
        }
    }

    // Colocar el pivote donde corresponde:
    intercambiar(&arreglo[indiceMenor+1], &arreglo[limS]);
    return indiceMenor+1;
}

void quicksort(int n, int arreglo[], int limI, int limS)
{
    int posicionPivote;
    // Caso base:
    if(limI >= limS)
        return;
    
    // Posición Pivote es donde quedó el pivote después
    // de particionar.
    posicionPivote = particionar(arreglo, limI, limS);

    // Llamar recursivamente quicksort, una para el
    // lado izquierdo del pivote, y otra para el
    // lado derecho del pivote.

    // Lado izquierdo del pivote:
    quicksort(n, arreglo, limI, posicionPivote - 1);

    // Lado derecho del pivote:
    quicksort(n, arreglo, posicionPivote + 1, limS);
}