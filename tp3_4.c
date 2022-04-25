#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **V;
    char *buff;
    int cantidad = 0;
    puts("Ingrese la cantidad de nombres:");
    scanf("%d", &cantidad);
    getchar();
    buff = (char*) malloc(100*sizeof(char));
    V = (char**) malloc(cantidad*sizeof(char));
    printf("\nIngrese los nombres\n");
    for (int i = 0; i < cantidad; i++)
    {
        fgets(buff,100,stdin);
        V[i] = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(V[i], buff);
    }
    puts("Los nombres son:\n");
    for (int i = 0; i < cantidad; i++)
    {
        puts(V[i]);
    }
    free(buff);
    free(V);
    return 0;
}