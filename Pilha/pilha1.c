/*
 * Exemplo do uso de pilha com uso de vetor.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define STACK_MAX 6


struct Pilha {
    int     data[STACK_MAX];
    int     size;
};

void inicializar(Pilha *ponteiro_pilha) {
    ponteiro_pilha->size = 0;
}

void push(Pilha *ponteiro_pilha, int d) {
    if (ponteiro_pilha->size < STACK_MAX) {
        ponteiro_pilha->data[ponteiro_pilha->size] = d;
        ponteiro_pilha->size = ponteiro_pilha->size + 1;
    } else {
        fprintf(stderr, "Erro: pilha cheia\n");
    }   
}

int pop(Pilha *ponteiro_pilha) {
    int retorno;
    if (ponteiro_pilha->size == 0) {
        fprintf(stderr, "Erro: pilha vazia\n");
        exit(-1);
    } else {
        ponteiro_pilha->size--;
        retorno = ponteiro_pilha->data[ponteiro_pilha->size];
        ponteiro_pilha->data[ponteiro_pilha->size] = 0;
        return(retorno);
    }
}

void imprime_pilha(Pilha *ponteiro_pilha) {
    int x;
	for (x = ponteiro_pilha->size; x > 0 ; x--)
		std::cout << ponteiro_pilha->data[x-1];
	printf("\n");
}

int main() {
    Pilha minhaPilha;
    int valor;

    inicializar(&minhaPilha);

    push(&minhaPilha, 3);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 5);
    imprime_pilha(&minhaPilha);
    push(&minhaPilha, 1);
    imprime_pilha(&minhaPilha);

    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(&minhaPilha);
    printf("Valor desempilhado:\t %d\n", valor);

}
