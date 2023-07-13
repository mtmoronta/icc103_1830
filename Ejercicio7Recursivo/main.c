#include <stdio.h>
#include <stdlib.h>

void capturarArreglo(int n, int arreglo[]);
void inverso_arreglo(int[], int, int);
void mostrarArreglo(int n, int arreglo[]);

int main()
{
    int n;
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);

    int arreglo[n];

    capturarArreglo(n, arreglo);
    mostrarArreglo(n, arreglo);
    inverso_arreglo(arreglo, 0, n-1);
    mostrarArreglo(n, arreglo);
    return 0;
}

void capturarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Digite el valor %d: ", i+1);
        scanf("%d", &arreglo[i]);
    }
}

void inverso_arreglo(int arr[], int limI, int limS)
{
    int burbuja;

    // Caso base:
    if(limI >= limS)
        return;
    
    // Cuerpo:
    burbuja = arr[limI];
    arr[limI] = arr[limS];
    arr[limS] = burbuja;

    // Llamada recursiva, con el cambio:
    inverso_arreglo(arr, limI+1, limS-1);
}

void mostrarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t", arreglo[i]);
}