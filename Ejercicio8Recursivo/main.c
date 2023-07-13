#include <stdio.h>
#include <stdlib.h>

void capturarArreglo(int, int[]);
int busquedaSecuencial(int, int, int[]);
int busquedaSecuencialRecursiva(int, int, int[], int);
int busquedaBinaria(int, int, int[]);
int busquedaBinariaRecursiva(int, int, int[], int, int);

int main()
{
    int n, valorBusqueda, posicionElemento;
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);

    int arr[n];

    capturarArreglo(n, arr);

    // Buscar un valor:
    printf("Digite el valor que desear encontrar: ");
    scanf("%d", &valorBusqueda);

    //posicionElemento = busquedaSecuencial(valorBusqueda, n, arr);
    //posicionElemento = busquedaSecuencialRecursiva(valorBusqueda, n, arr, 0);
    //posicionElemento = busquedaBinaria(valorBusqueda, n, arr);
    posicionElemento = busquedaBinariaRecursiva(valorBusqueda, n, arr, 0, n-1);

    if(posicionElemento >= 0)
        printf("Se encontró en la posición: %d\n", posicionElemento);
    else
        printf("No se encontró ese elemento en el arreglo.\n");
}

int busquedaBinaria(int valor, int n, int arreglo[])
{
    int limI = 0, limS = n-1, centro;

    while(limI < limS)
    {
        centro = (limI/2) + (limS/2);
        
        if(arreglo[centro] == valor)
            return centro;
        else if(arreglo[centro] > valor)
            limS = centro - 1;
        else
            limI = centro + 1;
    }

    // No lo encontró.
    return -1;
}

int busquedaBinariaRecursiva(int valor, int n, int arreglo[], int limI, int limS)
{
    int centro;
    // Caso base:
    if(limI > limS)
        return -1; // No lo encontró.
    
    // Cuerpo:
    centro = (int)(((float)limI/2) + ((float)limS/2));

    if(arreglo[centro] == valor)
        return centro;
    else if(arreglo[centro] > valor)
        return busquedaBinariaRecursiva(valor, n, arreglo, limI, centro-1);
    else
        return busquedaBinariaRecursiva(valor, n, arreglo, centro+1, limS);
}

int busquedaSecuencial(int valor, int n, int arreglo[])
{
    int i;
    for(i=0; i<n; i++)
    {
        if(arreglo[i] == valor)
            return i;
    }
    return -1;
}

int busquedaSecuencialRecursiva(int valor, int n, int arreglo[], int posActual)
{
    // Caso base (si llegué al final del arreglo y no encontré el valor.)
    if(posActual >= n)
        return -1;
    
    // Cuerpo
    if(arreglo[posActual] == valor)
        return posActual;
    
    // Llamada recursiva:
    return busquedaSecuencialRecursiva(valor, n, arreglo, posActual+1);
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