#include <stdio.h>
#include <stdlib.h>

// Estructura nodo (data, siguiente).
typedef struct sNodo
{
    int data;
    struct sNodo *siguiente;
}Nodo;

// Estructura cola (cabeza, cola).
typedef struct
{
    Nodo *cabeza, *cola;
}Cola;

Cola* crearCola();

void encolar(Cola *cola, int valor);

int desencolar(Cola *cola);

int main()
{
    Cola *miCola = crearCola();

    encolar(miCola, 6);
    encolar(miCola, 20);
    encolar(miCola, 18);
    encolar(miCola, -5);
    printf("\n%d\n", desencolar(miCola));
    printf("%d\n", desencolar(miCola));
    printf("%d\n", desencolar(miCola));
    encolar(miCola, 10);
    encolar(miCola, 0);
    encolar(miCola, 15);
    printf("%d\n", desencolar(miCola));
    printf("%d\n", desencolar(miCola));
    printf("%d\n", desencolar(miCola));
    printf("%d\n", desencolar(miCola));

    return 0;
}

Cola* crearCola()
{
    Cola *nuevaCola;
    nuevaCola = (Cola*)malloc(sizeof(Cola)); // OJO: malloc dentro de una función.
    nuevaCola->cabeza = nuevaCola->cola = NULL;
    return nuevaCola;
}

void encolar(Cola *cola, int valor)
{
    // Esto es crear un nuevo nodo y guardar su valor:
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->data = valor;
    nuevo->siguiente = NULL;

    // Ahora, vamos a agregarlo a la cola.
    if(cola->cabeza == NULL)
    {
        // Es una cola nueva o está vacía.
        cola->cabeza = cola->cola = nuevo;
        return;
    }

    cola->cola->siguiente = nuevo;
    cola->cola = nuevo;
}

int desencolar(Cola *cola)
{
    if(cola == NULL || cola->cabeza == NULL)
        return 0; // Si la cola está vacía, no hago nada.

    int valor = cola->cabeza->data;
    Nodo *temporal = cola->cabeza;

    cola->cabeza = cola->cabeza->siguiente;

    // Hay que pregunta si, ya que saqué un valor,
    // mi cola se quedó vacía:
    if(cola->cabeza == NULL)
        cola->cola = NULL;

    // Aquí, en esta línea, ya cola->cabeza no apunta al 6.
    // sino, que apunta al 18.
    // ¿Cómo le doy un free al 6, entonces? Ahh, por el nodo temporal.
    free(temporal);

    return valor;
}