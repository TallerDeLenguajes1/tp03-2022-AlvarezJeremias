#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define cantidad 5

void main () {
    char *V[5];
    char * buff;
    printf ("\nIngrese los nombres:\n ");
    for (int i=0;i<cantidad;i++) {
        buff= (char *) malloc(100*sizeof(char));
        gets(buff);
        V[i]= (char *) malloc ((strlen(buff)+1)*sizeof(char));
        strcpy(V[i],buff);
    }
    printf("\nLos nombres escritos son:\n ");
    for (int i=0;i<cantidad;i++) {
        puts(V[i]);
    }
    free (buff);
    free (V);
    
}