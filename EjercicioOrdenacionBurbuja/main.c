#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void capturarValores(int, int[]);
void intercambiar(int, int[], int, int);
void mostrarValores(int, int[]);
void ordenacionBurbuja(int, int[]);
void ordenacionSeleccion(int, int[]);
void ordenacionInsercion(int, int[]);

const int MIN = 0, MAX = 1000;

int main()
{
    srand(time(NULL));
    
    int n;
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);
    int arreglo[n];

    capturarValores(n, arreglo);
    mostrarValores(n, arreglo);
    //ordenacionBurbuja(n, arreglo);
    //ordenacionSeleccion(n, arreglo);
    ordenacionInsercion(n, arreglo);
    mostrarValores(n, arreglo);

    return 0;
}

void capturarValores(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        arreglo[i] = rand()%(MAX-MIN+1) + MIN;
    }
}

void intercambiar(int n, int arreglo[], int desde, int hasta)
{
    int burbuja;
    burbuja = arreglo[desde];
    arreglo[desde] = arreglo[hasta];
    arreglo[hasta] = burbuja;
}

void mostrarValores(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t", arreglo[i]);
}

void ordenacionBurbuja(int n, int arreglo[])
{
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<(n-i-1); j++)
            if(arreglo[j] > arreglo[j+1])
                intercambiar(n, arreglo, j, j+1);
}

void ordenacionInsercion(int n, int arreglo[])
{
    int i, j, temporal;

    for(i=1; i<n; i++)
    {
        j = i - 1;
        temporal = arreglo[i];
        while(j>=0 && arreglo[j] > temporal)
        {
            arreglo[j+1] = arreglo[j];
            j--;
        }
        arreglo[j+1] = temporal;
    }
}

void ordenacionSeleccion(int n, int arreglo[])
{
    int i, j, indiceMenor;

    for(i=0; i<n; i++)
    {
        indiceMenor = i;
        for(j=i+1; j<n; j++)
            if(arreglo[j] < arreglo[indiceMenor])
                indiceMenor = j; // Encontré un nuevo menor.
        intercambiar(n, arreglo, i, indiceMenor);
    }
}