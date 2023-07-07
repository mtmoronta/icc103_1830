#include <stdio.h>
#include <stdlib.h>

/* Realice un programa que, recursivamente, capture valores positivos
   y muestre al final su suma.
 */

int sumarValoresUsuario();

int main()
{
    printf("\n%d", sumarValoresUsuario());
    return 0;
}

int sumarValoresUsuario()
{
    int valorActual;
    // Axioma.
    printf("Digite un valor positivo: ");
    scanf("%d", &valorActual);

    if(valorActual <= 0)
        return 0;

    // Cuerpo y llamada recursiva.
    return valorActual + sumarValoresUsuario();
}