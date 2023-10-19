/*
 * Segundo exemplo de fila
 *
 * Com uso de typedef.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 18/10/2023
 */

#include <iostream>

using namespace std;

typedef int ELEMENTO;

typedef struct NO{
 	ELEMENTO valor;
 	struct NO* prox;
}*FILA;

FILA novoElemento(ELEMENTO elem){
 	FILA aux = new NO;
 	aux->valor = elem;
 	aux->prox  = NULL;
 	return aux;
}

void enqueue(ELEMENTO elem, FILA no){
    if(no == NULL) {
        cout << "Ponteiro nulo " <<endl;
        exit(-1);
    }
 	FILA aux = no;
    while(aux->prox != NULL){
 		aux = aux->prox;
 	}
    FILA aux2 = novoElemento(elem);
    aux->prox = aux2;
 }

void mostraFila(FILA no){
 	while(no->prox != NULL){
 		cout <<"[" << no->valor << "] -> ";
 		no = no->prox;
 	}
    cout <<"[" << no->valor << "]";
 	cout << endl;
}

FILA dequeue(FILA no, int* valor){
 	FILA proximo_fila = no;
 	no = proximo_fila->prox;
 	proximo_fila->prox = NULL;
    *valor = proximo_fila->valor;
    // cout << "\nRemovido da Fila " << proximo_fila->valor<< "\n";
 	delete proximo_fila;
    return no;
}

int tamanhoFila(FILA no){
    FILA fila_local = no;
 	int cont = 0;
 	while(fila_local != NULL){
 		cont++;
 		fila_local = fila_local->prox;
 	}
 	return cont;
}

void destruir(FILA no){
    cout << endl<< endl;
    FILA noProximo = no;
    while(noProximo->prox != NULL){
 		// cout << "Removido: " << noProximo->valor << endl;
        no = noProximo;
        noProximo = no->prox;
        no->prox = NULL;
        delete(no);
 	}
    no = noProximo;
    // cout << "Removido: " << no->valor << endl;
    no->prox = NULL;
    delete(no);
}

int buscaFila(ELEMENTO elemento, FILA no){
    FILA aux = no;
    int cont = 1;
    while(aux != NULL){
        if (elemento == aux->valor ){
		    return cont;
	    }
	    aux = aux->prox;
        cont = cont + 1;
    }
    return cont;
 }

void posicao_na_fila(ELEMENTO elemento, FILA no){
    int tamanho = tamanhoFila(no);
    int posicao = buscaFila(elemento, no);
    if (tamanho == posicao - 1 ) {
        cout << "Não encontrado o elemento " << elemento << " na fila " << endl;
    } else {
        cout << "Encontrado " << elemento << " na posicao " << posicao << endl;
    }
}

int main(){
    int valor;
    FILA fila = NULL;
    fila = novoElemento(7);
    enqueue(5, fila);
    enqueue(8, fila);
    enqueue(1, fila);
    enqueue(3, fila);
    enqueue(12, fila);
    enqueue(4, fila);
    enqueue(2, fila);
    enqueue(10, fila);
    enqueue(34, fila);

    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila)  << endl;

    fila = dequeue(fila, &valor);
    cout << "Saiu da fila : " << valor << endl;

    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila) << endl;

    cout << "====================" << endl;
    posicao_na_fila(5, fila);
    posicao_na_fila(8, fila);
    posicao_na_fila(50, fila);
    posicao_na_fila(34, fila);
    cout << "====================" << endl;

    fila = dequeue(fila, &valor);
    cout << "Saiu da fila : " << valor << endl;

    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila)  << endl;

    cout << "====================" << endl;
    posicao_na_fila(5, fila);
    posicao_na_fila(8, fila);
    posicao_na_fila(50, fila);
    posicao_na_fila(34, fila);
    cout << "====================" << endl;
    mostraFila(fila);
    cout << "Tamanho da fila: " << tamanhoFila(fila) ;

    destruir(fila);
    return 0;
}
