#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /*int a = 5, b = 10;
    int *p_a = &a;

    printf("%d\t%d\n", sizeof(p_a), sizeof(a));

    printf("Valor de p_a: %x\n", p_a);
    printf("Valor de a: %d\n", *p_a);

    p_a = &b;

    printf("Valor de p_a: %x\n", p_a);
    printf("Valor de b: %d\n", *p_a);*/

    /*
    char cadena[] = "Hola Mundo Cruel.";
    char *p_cadena = cadena;
    printf("%x\n", cadena);
    printf("%x\n", cadena+1);
    printf("%c\n", *(cadena+1));

    printf("%d\n", sizeof(char));*/

    /*
    char c;
    char *pc;
    pc = &c;
    for(c='A'; c<='Z'; c++)
        printf("%c\t", *pc);
    */

   /*
    int v[10];
    int *p;
    p = v;

    *p = 5;
    printf("%d\n", v[0]); // 5.

    *(p+4) = 50;
    printf("%d\n", v[4]);
    
    p += 6; // p = p + 6
    *p = 100;
    
    printf("%d", v[6]);*/

    /*long int enteroLargo = 10000;

    printf("%d", sizeof(enteroLargo));*/

    //const int TAMANOCADENA = 100;
    char cadena[100];
    int i, longitud;

    printf("Digite su nombre completo: ");
    gets(cadena);
    longitud = strlen(cadena);
    printf("%s\nTamaño: %d\n", cadena, longitud);

    // Manejo dinámico de memoria:
    char *pCadena;
    pCadena = (char*)malloc(sizeof(char)*longitud);

    strcpy(pCadena, cadena);

    puts(pCadena);

    return 0;
}