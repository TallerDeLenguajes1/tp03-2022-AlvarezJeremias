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
                        // "CantidadProductosAPedir"
} typedef client;

float CalcularTotal (product*puntero);
void main () {
    int cantidadClientes,i;
	srand(time(NULL));
	printf ("\n\n------Clientes------\n\n Ingrese la cantidad de clientes:");
	scanf ("%d",&cantidadClientes);
   // fflush(stdin);
   getchar();
	client * arregloClientes=(client *) malloc(cantidadClientes*sizeof(client));
    if (cantidadClientes>0) {
        printf ("\n\n-Bien, Ahora ingrese los datos de los clientes: ");
        for(i=0;i<cantidadClientes;i++)
        {
            float totalPorCliente=0;
            char * buffer=(char*) malloc(100*sizeof(char));
            printf("\n\n\n---CLIENTE NUMERO %d--- \n\nIngrese el nombre del cliente: ",i+1);
            fgets(buffer,100,stdin);
            (arregloClientes+i)->nombreCliente=(char *) malloc ((strlen(buffer)+1)*sizeof(char));
            strcpy((arregloClientes+i)->nombreCliente,buffer);
            (arregloClientes+i)->clienteID=i+1;
            (arregloClientes+i)->cantidadProductosAPedir=1 + rand() % 5;
            printf("\n\n-ID del cliente: %d", (arregloClientes+i)->clienteID);
            printf("\n\n-Cantidad de productos: %d", (arregloClientes+i)->cantidadProductosAPedir);
            for (int j = 0; j < (arregloClientes+i)->cantidadProductosAPedir; j++){
                int auxiliar= rand()% 5;
                float totalProducto;
                (arregloClientes+i)->productos=(product *) malloc((arregloClientes+i)->cantidadProductosAPedir*sizeof(product));
                (arregloClientes+i)->productos->productoID=j+1;
                (arregloClientes+i)->productos->cantidad=1 + rand() % 5;
                (arregloClientes+i)->productos->precioUnitario=1 +rand() % 100;
                (arregloClientes+i)->productos->tipoProducto=TiposProductos[auxiliar];
                totalProducto=CalcularTotal((arregloClientes+i)->productos);
                printf("\n\n\n--PRODUCTO %d--",(arregloClientes+i)->productos->productoID);
                printf("\n\n-Tipo de producto: ");
                puts((arregloClientes+i)->productos->tipoProducto);
                printf("\n-Cantidad : %d",(arregloClientes+i)->productos->cantidad);
                printf("\n\n-Precio unitario: $%.2f",(arregloClientes+i)->productos->precioUnitario);
                printf("\n\n-Total del producto %d :  $%.2f",j+1,totalProducto);
                totalPorCliente=totalPorCliente+totalProducto;
            }
            printf("\n\n-Total a pagar de este cliente: $%.2f \n\n",totalPorCliente);  
        }
        printf("\n\n------Fin de la ejecucion------\n\n"); 
    }
}
float CalcularTotal (product*puntero) {
    float totalProducto=puntero->cantidad * puntero->precioUnitario;
    return totalProducto;
}