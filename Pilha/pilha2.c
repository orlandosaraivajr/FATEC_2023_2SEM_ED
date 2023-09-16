/*
 * Exemplo do uso de pilha.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 05/04/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha * inicializar() {
    // Pilha * s = (Pilha *)malloc(sizeof(Pilha));
    Pilha * s = new Pilha;
    s->size = 0;  // Setar o tamanho da pilha como zero.
    s->top = NULL; // o topo da pilha é NULL
    return s;
}

void push(Pilha *s, int value) {
    Node *np;  // Criar um ponteiro de Node (nó)

    // np = (Node *)malloc(sizeof(Node));  // Alocar Node na memória
    np = new Node;
    if (np == NULL) {
        exit(1);
    }

    np->item = value; // Setar o valor no Node.
    np->next = s->top; // Copiar o último endereço que estará no topo da pilha
    s->top = np; // O topo está apontando para o novo Node criado .

    s->size++; // Incrementar o tamanho do contador de pilha
}

int pop(Pilha *s) {
    int temp;
    Node *np;

    if (s->top == NULL) {
        exit(1);
    }

    np = s->top; // Um ponteiro de nó está apontando para o topo da pilha.
    temp = s->top->item; // armazenar em temp o valor corrente do topo da pilha.
    s->top = np->next; // fazer o topo da pilha apontar para o nó abaixo
    s->size--; // decrementar o tamanho da pilha
    //free(np); // desalocar o nó topo
    delete(np);
    return temp; // retornar o valor desempilhado
}

void destruir_pilha(Pilha *s) {
    while (s->top != NULL) {
        pop(s);
    }
    pop(s);
    free(s);
}

void imprime_pilha(Pilha *s) {
	Node* temp;

    if (s->top == NULL) {
        return;
    }
	temp = s->top;
    printf("# %d \n",s->size);
	while(temp!=NULL){
		printf("%d ",temp->item);
		temp = temp->next;
	}

	printf("\n");
}

int main() {
    int valor;

    Pilha *minha_pilha = inicializar();
    imprime_pilha(minha_pilha);
    push(minha_pilha, 7);
    imprime_pilha(minha_pilha);
    push(minha_pilha, 9);
    push(minha_pilha, 3);
    push(minha_pilha, 6);
    push(minha_pilha, 2);
    push(minha_pilha, 1);
    imprime_pilha(minha_pilha);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);
    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    imprime_pilha(minha_pilha);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    valor = pop(minha_pilha);
    printf("Valor desempilhado:\t %d\n", valor);

    destruir_pilha(minha_pilha);
    return 0;
}
