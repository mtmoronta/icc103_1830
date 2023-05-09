//#include <stdlib.h>
#include <stdio.h>

int calcularMediana(int n, int arreglo[]);

int main()
{
    const int MAX = 9000, PARADA = 99999;
    int valores[10000];
    int valorActual, valorAnterior = 0;
    long sumatoria = 0;
    short esError = 0, cantidad = 0;

    do
    {
        do{
            printf("\nIngrese un entero positivo (%d para detener): ", PARADA);
            scanf("%d", &valorActual);
            
            if(valorActual <= 0)
                esError = 1;
            else if (valorActual < valorAnterior)
                esError = 1;
            else
                esError = 0;
            
            if(esError)
                printf("Error. Debe ser en orden ascendente, y positivo.\n");
        }while(esError);
        
        if(valorActual == PARADA)
            break;

        valores[cantidad] = valorActual;
        valorAnterior = valorActual;
        
        sumatoria += valorActual;
        cantidad++;

    } while (valorActual != PARADA);

    printf("Promedio: %.2f\n", (float)(sumatoria)/cantidad);    

    printf("La mediana es: %d\n", calcularMediana(cantidad, valores));

    printf("La sumatoria es: %ld\n\nLa cantidad es: %d\n", sumatoria, cantidad);

    return 0;
}

int calcularMediana(int n, int arreglo[])
{
    if(n % 2)
        return arreglo[n/2];
    else
        return (arreglo[n/2-1] + arreglo[n/2]) / 2;
}