#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char marca[50];
}Automovil;

typedef struct
{
    int id;
    char nombre[50];
    char ciudad[50];
}Cliente;

typedef struct
{
    int idCliente;
    int idVehiculo;
    int dias;
    float precio;
}Alquiler;

int mostrarMenu();
void capturarCliente(FILE*, Cliente*);
void mostrarClientes(FILE*);

int main()
{
    char rutaClientes[] = "clientes.dat";
    Cliente cliente;
    Automovil automovil;
    Alquiler alquiler;
    int seleccion;
    FILE *archivoClientes = fopen(rutaClientes, "a+b");


    do{
        seleccion = mostrarMenu();

        switch(seleccion)
        {
            case 0:
                printf("Hasta luego!");
                break;
            case 1:
                capturarCliente(archivoClientes, &cliente);
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }while(seleccion != 0);

    mostrarClientes(archivoClientes);

    return 0;
}

void capturarCliente(FILE *archivoClientes, Cliente *cliente)
{
    printf("Digite el ID: ");
    scanf("%d", &cliente->id);
    fflush(stdin);
    printf("Digite el nombre: ");
    gets(cliente->nombre);
    printf("Digite la ciudad: ");
    gets(cliente->ciudad);

    fwrite(cliente, sizeof(Cliente), 1, archivoClientes);
}

void mostrarClientes(FILE *archivoClientes)
{
    Cliente clienteActual;

    fseek(archivoClientes, 0, SEEK_END);
    int tamano = ftell(archivoClientes); 
    fseek(archivoClientes, 0, SEEK_SET);

    while(ftell(archivoClientes) < tamano) // reemplazando el feof().
    {
        fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);

        //if(strcmp(clienteActual.ciudad, ciudadFiltro) == 0)
        printf("\nID: %d\nNombre: %s\nCiudad: %s",
            clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
    }
}

int mostrarMenu()
{
    char opcion;
    printf("1: Capturar cliente.\n");
    printf("2: Capturar automovil.\n");
    printf("3: Registrar alquiler.\n");
    printf("\n0: Salir.\n");
    printf("\nSeleccione: ");
    fflush(stdin);
    opcion = getchar();

    switch(opcion)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        default:
            return 0;
    }
}