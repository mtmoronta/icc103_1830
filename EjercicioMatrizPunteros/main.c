#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXCADENA 100

void capturarFrase(char *str);
int capturarMatriz(char**);
void mostrarMatriz(char**, int);

int main()
{
    char **matriz;
    matriz = (char**)malloc(sizeof(char**));

    char continuar = 's';
    int filas = 1;
    
    do
    {
        matriz = (char**)realloc(matriz, sizeof(char**)*(filas));
        *(matriz+filas-1) = (char*)malloc(sizeof(char));

        capturarFrase(*(matriz+filas-1));
        //printf("%s\n", *(matr+filas-1));

        filas++;
        printf("Capturar otra frase? (S/N) ");
        fflush(stdin);
        continuar = tolower(getc(stdin));
    } while (continuar == 's');
    filas--;

    mostrarMatriz(matriz, filas);

    return 0;
}

void capturarFrase(char *str)
{
    char cadenaTemporal[MAXCADENA];

    printf("Digite una frase: ");
    fflush(stdin);
    gets(cadenaTemporal);

    str = (char*)realloc(str, sizeof(char) * strlen(cadenaTemporal) + 1);
    strcpy(str, cadenaTemporal);
}

int capturarMatriz(char **matr)
{
    char continuar = 's';
    int filas = 1;
    
    do
    {
        matr = (char**)realloc(matr, sizeof(char**)*(filas));
        *(matr+filas-1) = (char*)malloc(sizeof(char));

        capturarFrase(*(matr+filas-1));
        //printf("%s\n", *(matr+filas-1));

        filas++;
        printf("Capturar otra frase? (S/N) ");
        fflush(stdin);
        continuar = tolower(getc(stdin));
    } while (continuar == 's');

    return filas - 1;
}

void mostrarMatriz(char **matr, int filas)
{
    int i;
    for(i=0; i<filas; i++)
        printf("%s\n", matr[i]); // *(matr+i) equivale a matr[i]
}