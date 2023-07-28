#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int MIN = 0, MAX = 1000;

typedef struct sNodo
{
    int data;
    struct sNodo *enlace;
}Nodo;

void mostrarLista(Nodo*);
void DividirMitades(Nodo*, Nodo**, Nodo**);
Nodo* crearNodo(Nodo*, int);
Nodo* generarAleatorioLista(int, Nodo*);
int obtenerTamanoLista(Nodo*);

int main()
{
    Nodo **ptrMitad1 = NULL, **ptrMitad2 = NULL;
    srand(time(NULL));
    int n;
    Nodo *lista = NULL;
    printf("Digite la cantidad de valores a generar: ");
    scanf("%d", &n);

    lista = generarAleatorioLista(n, lista);
    mostrarLista(lista);
    DividirMitades(lista, ptrMitad1, ptrMitad2);
    if(ptrMitad1 != NULL)
    {
        printf("Lista delantera:\n");
        mostrarLista(*ptrMitad1);
    }
    if(ptrMitad2 != NULL)
    {
        printf("Lista trasera:\n");
        mostrarLista(*ptrMitad2);
    }

    return 0;
}

Nodo* crearNodo(Nodo *lista, int dato)
{
    Nodo *nuevo, *temporal;

    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = dato;
    nuevo->enlace = NULL;

    if(lista == NULL)
        lista = nuevo;
    else
    {
        temporal = lista;
        while(temporal->enlace != NULL)
            temporal = temporal->enlace;
        
        temporal->enlace = nuevo;
    }

    return lista;
}

void DividirMitades(Nodo *lista,
                    Nodo **ptrMitadDelantera,
                    Nodo **ptrMitadTrasera)
{
    int n = obtenerTamanoLista(lista), i = 0;
    Nodo *temporal = lista;

    if(lista == NULL)
        return;
    
    ptrMitadDelantera = &lista;
    if(n == 1)
    {
        ptrMitadTrasera = NULL;
        return;
    }

    while(i <= n / 2)
    {
        /* Si n==2, ((n+1)/2)-1 da 0. Yo quiero entrar al if.
           Si n==3, ((n+1)/2)-1 da 1. Yo quiero entrar al if.
           Si n==4, (n/2)-1 da 1.
           Si n==5, (n/2) da 2.
           Si n==6, (n/2)-1 da 2.
           Si n==7, (n/2) da 3.
           Si n==8, (n/2)-1 da 3.
        */
        if((n<=3 && (i == ((n+1)/2)-1)) || // Estoy en el centro de la lista.
            (n>=4 && n%2==0 && (i == (n/2)-1)) ||
            (n>=4 && n%2==1 && (i == (n/2))))
        {
            // Es necesario dividir la lista, luego de
            // asignar el ptrMitadTrasera.
            Nodo* tmp = (Nodo*)malloc(sizeof(Nodo));
            tmp->data = temporal->enlace->data;
            tmp->enlace = temporal->enlace->enlace;

            ptrMitadTrasera =  &(tmp);
            temporal->enlace = NULL;

            if(ptrMitadDelantera != NULL)
            {
                printf("\nLista delantera:\n");
                mostrarLista(*ptrMitadDelantera);
            }
            if(ptrMitadTrasera != NULL)
            {
                printf("Lista trasera:\n");
                mostrarLista(*ptrMitadTrasera);
            }
            return;
        }

        i++;
        temporal = temporal->enlace;
    }
}

Nodo* generarAleatorioLista(int n, Nodo *lista)
{
    int i;

    for(i=0; i<n; i++)
    {   
        lista = crearNodo(lista, rand()%(MAX-MIN)+MIN);
    }
    return lista;
}

void mostrarLista(Nodo *lista)
{
    Nodo *temporal = lista;

    while(temporal != NULL)
    {
        printf("%d\t", temporal->data);
        temporal = temporal->enlace;
    }
}

int obtenerTamanoLista(Nodo *lista)
{
    int n=0;
    Nodo *temporal = lista;

    while(temporal != NULL)
    {
        n++;
        temporal = temporal->enlace;
    }

    return n;
}