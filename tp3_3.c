#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int productoID; //Numerado en ciclo iterativo
    int cantidad; // entre 1 y 10
    char *tipoProducto; // Algún valor del arreglo TiposProductos
    float precioUnitario; // entre 10 - 100
} typedef product;

 struct Cliente  {
    int clienteID; // Numerado en el ciclo iterativo
    char *nombreCliente; // Ingresado por usuario
    int cantidadProductosAPedir; // (aleatorio entre 1 y 5)
    product *productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
} typedef client;

void main () {
    int cantidadClientes;
    srand(time(NULL));
    printf ("\n\n------Clientes------\n\n Ingrese la cantidad de clientes:");
    scanf ("%d",&cantidadClientes);
    fflush(stdin);
    client * arregloClientes=(client *) malloc(cantidadClientes*sizeof(client));
    printf ("\n\n-Bien, Ahora ingrese los datos de los clientes:");
    for (int i=0;i<cantidadClientes;i++) {
        printf("\nCliente numero %d \n\n Ingrese el nombre del cliente: ",i+1);
        (arregloClientes+i)->nombreCliente=(char*) malloc(100*sizeof(char));
        gets((arregloClientes+i)->nombreCliente);
        (arregloClientes+i)->clienteID=i+1;
        (arregloClientes+i)->cantidadProductosAPedir=1 + rand() % 5;
        printf("\ncantidad de productos  %d", (arregloClientes+i)->cantidadProductosAPedir);
        printf("\n ID  %d", (arregloClientes+i)->clienteID);

    }

}