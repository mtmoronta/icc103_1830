#include <stdio.h>
#include <stdlib.h>

/* Programar un algoritmo recursivo que permita sumar
 * los elementos de una matriz de enteros.
 */
void capturarMatriz(int filas, int columnas, int matriz[filas][columnas]);
//void mostrarMatriz(int filas, int columnas, int matriz[filas][columnas]);
int sumarMatriz(int filas, int columnas, int matriz[filas][columnas], int filaActual, int columnaActual);

int main()
{
    int filas, columnas;
    printf("Digite la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Digite la cantidad de columnas: ");
    scanf("%d", &columnas);

    int matriz[filas][columnas];

    capturarMatriz(filas, columnas, matriz);
    //mostrarArreglo(n, arreglo);

    printf("%d", sumarMatriz(filas, columnas, matriz, 0, 0));

    return 0;
}

void capturarMatriz(int filas, int columnas, int matriz[filas][columnas])
{
    int i, j;
    for(i=0; i<filas; i++)
    {
        for(j=0; j<columnas; j++)
        {
            printf("Digite un valor: ");
            scanf("%d", &matriz[i][j]);
        }
    }
}
/*
void mostrarArreglo(int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", arreglo[i]);
    }
}*/

int sumarMatriz(int filas, int columnas, int matriz[filas][columnas], int filaActual, int columnaActual)
{
	// Hasta el final del arreglo.
	if(filaActual >= filas)
		return 0;
	
    if(columnaActual + 1 >= columnas)
        return matriz[filaActual][columnaActual]
                + sumarMatriz(filas, columnas, matriz, filaActual+1, 0);
    else
        return matriz[filaActual][columnaActual]
                + sumarMatriz(filas, columnas, matriz, filaActual, columnaActual+1);
}