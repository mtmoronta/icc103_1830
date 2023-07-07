#include <stdio.h>
#include <stdlib.h>

/* Programar un algoritmo recursivo que permita sumar
 * los elementos de un arreglo de enteros.
 */

void capturarArreglo(int n, int arreglo[]);
void mostrarArreglo(int n, int arreglo[]);
int sumarArreglo(int n, int arreglo[], int posActual);

int main()
{
    int n;
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);
    int arreglo[n];

    capturarArreglo(n, arreglo);
    mostrarArreglo(n, arreglo);

    printf("%d", sumarArreglo(n, arreglo, 0));

    return 0;
}

void capturarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Digite un valor: ");
        scanf("%d", &arreglo[i]);
    }
}

void mostrarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", arreglo[i]);
    }
}

int sumarArreglo(int n, int arreglo[], int posActual)
{
	// Hasta el final del arreglo.
	if(posActual >= n)
		return 0;
	
	return arreglo[posActual] + sumarArreglo(n, arreglo, posActual+1);
}