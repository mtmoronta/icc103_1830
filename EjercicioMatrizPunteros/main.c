#include <stdio.h>
#include <stdlib.h>

void capturarFrase(char *pFrase);

int main()
{
    char **matriz;
    matriz = (char*)malloc(sizeof(char));

    int cantidadFrases = 0;
    short continuar = 1; 

    while(continuar)
    {
        cantidadFrases++;
        matriz = (char*)realloc(matriz, cantidadFrases);
        *(matriz+cantidadFrases) = gets()
    }

    return 0;
}