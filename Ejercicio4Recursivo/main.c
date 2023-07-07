#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Realice un programa que permita imprimir una línea
* de texto de manera inversa utilizando una función
* recursiva sin emplear arreglos.
*/

void capturarTextoInverso();

int main()
{
    fflush(stdin);
    capturarTextoInverso();
    return 0;
}

void capturarTextoInverso()
{
    char letraActual = getch();

    // Caso base:
    if(letraActual == 13)
        return;

    // Llamada recursiva:
    capturarTextoInverso();

    printf("%c", letraActual);
}