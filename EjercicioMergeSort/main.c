#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 1000, MIN = 0;

void generarAleatorios(int, int[]);
void mostrarArreglo(int, int[]);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);

int main()
{
    int n;
    srand(time(NULL));
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);

    int arreglo[n];

    generarAleatorios(n, arreglo);
    mostrarArreglo(n, arreglo);
    mergeSort(arreglo, 0, n-1);
    mostrarArreglo(n, arreglo);

    return 0;
}

void generarAleatorios(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        arreglo[i] = rand()%(MAX-MIN+1)+MIN;
    }
}

void merge(int arreglo[], int limI, int limS, int centro)
{
    // Idea 1:
    // Calcular el tamaño de cada mitad.
    // Copiar el contenido en cada mitad.
    // Llenar el arreglo principal con las dos mitades,
    // tomando siempre el menor.

    // Idea 2:
    // Trabajar sobre el mismo arreglo.
    // Dejar los valores de la mitad de la izquierda
    // donde están, y si se encuentra en el lado
    // izquierdo un valor mayor que en el lado derecho,
    // tomar el menor en una burbuja, ir rodando a la derecha
    // todos los valores hasta llegar al índice actual izquierdo.
    // Colocar ahí el valor de la burbuja.
    // Incrementar en uno: el índice izquierdo, derecho y el centro.
    int i, j = centro, burbuja, k;

    for(i=limI; i<centro; i++)
    {
        if(arreglo[i] <= arreglo[j] || j > limS) // Aquí, se hizo un bucle infinito si j>limS.
            continue;
        
        // arreglo[i] es mayor que arreglo[j]...
        // osea, tengo que mover de j a i.
        burbuja = arreglo[j];

        // Rodar los valores a la derecha,
        // hasta llegar a i.
        k = j;
        while(k>i)
        {
            arreglo[k] = arreglo[k-1];
            k--;
        }
        arreglo[i] = burbuja;
        j++;
        centro++;
    }
}

void mergeSort(int arreglo[], int limI, int limS)
{
    int centro;

    // Caso base:
    if(limI >= limS) // Hay un solo elemento, o se cruzaron los límites.
        return; // No hay nada qué hacer.
    
    centro = (float)limI/2 + (float)(limS+1)/2;

    // Ordenar ambas mitades:
    mergeSort(arreglo, limI, centro-1);
    mergeSort(arreglo, centro, limS);

    // Aquí, ya las mitades están ordenadas:
    merge(arreglo, limI, limS, centro);
}

void mostrarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", arreglo[i]);
    }
    printf("\n"); // Salto de línea, para separar el arreglo desordenado del ordenado.
}