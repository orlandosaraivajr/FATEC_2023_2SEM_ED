#include <stdio.h>
#include <stdlib.h>
/*
Exemplo de ponteiros em C
*/
int main(int argc, char *argv[]){
    int numero_1;
    int* numero_2;
    printf(" Digite um numero \n");
    scanf("%d", &numero_1);
    numero_2 = &numero_1;
    printf("O numero digitado foi: %d \n", *numero_2);

    /* Alocação no heap */
    numero_2 = (int *)malloc(sizeof(int));
    *numero_2 = 10;
    printf("Alocado em heap 1: %d \n", *numero_2);
    free(numero_2);

    numero_2 = (int *)malloc(sizeof(int));
    *numero_2 = 15;
    printf("Alocado em heap 2: %d \n", *numero_2);
    free(numero_2);
    return 0;
}
