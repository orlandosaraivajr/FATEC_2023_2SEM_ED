/*
 * Lista linear ordenada.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 11/05/2018
 */
#include <iostream>

using namespace std;

#define N 50

typedef struct{
    int chave;
} REGISTRO;

typedef struct{
    REGISTRO elementos[N];
    int numeroElementos;
} LISTA;

void inicializarLista(LISTA* l){
    l->numeroElementos = 0;
}
int tamanho(LISTA* l){
    return l->numeroElementos;
}
void exibirLista(LISTA* lista){
    int i;
    cout << "Lista: " << endl;
    for(i = 0 ; i < lista->numeroElementos; i++) {
        cout << " " << lista->elementos[i].chave << "  ";
    }
    cout << endl;
}
int buscaBinaria(LISTA* lista, REGISTRO registro){
    int esq, dir, meio;
    esq = 0;
    dir = lista->numeroElementos;
    while(esq <= dir) {
        meio = ((esq + dir) / 2);
        if(registro.chave == lista->elementos[meio].chave) {
            return meio;
        } else {
            if(lista->elementos[meio].chave < registro.chave){
                esq = meio + 1;
            } else {
                dir = meio + 1;
            }
        }
    }
    return -1;
}
bool inserirElemListaOrd(LISTA* lista, REGISTRO reg){
    int pos = tamanho(lista);
    if(lista->numeroElementos >= N) {
        return false;
    }
    while( pos > 0 && lista->elementos[pos-1].chave > reg.chave) {
        lista->elementos[pos] = lista->elementos[pos-1];
        pos--;
    }
    lista->elementos[pos] = reg;
    lista->numeroElementos++;
    return true;
}
bool excluirElemListaOrd(LISTA* lista, REGISTRO registro){
    int pos, j;
    // pos = buscaSequencial(lista, registro);
    pos = buscaBinaria(lista, registro);
    if(pos == -1) return false;
    for(j = pos; j< lista->numeroElementos-1; j++){
        lista->elementos[j] = lista->elementos[j+1];
    }
    lista->numeroElementos--;
    return true;
}

int main(void) {
    LISTA lista;
    REGISTRO registro;
    int x;
    bool deu_certo;

    inicializarLista(&lista);
    for(x = 0; x <= 10; x++) {
        registro.chave = x+2;
        inserirElemListaOrd(&lista,registro);
    }
    for(x = 0; x <= 2; x++) {
        registro.chave = x+2;
        inserirElemListaOrd(&lista,registro);
        exibirLista(&lista);
    }
    registro.chave = 3;
    cout << "Item 3 na posicao: "<< buscaBinaria(&lista, registro)+1 << endl;
    exibirLista(&lista);


    excluirElemListaOrd(&lista, registro);
    exibirLista(&lista);

    registro.chave = 50;
    inserirElemListaOrd(&lista,registro);
    exibirLista(&lista);
    registro.chave = 5;
    inserirElemListaOrd(&lista,registro);
    exibirLista(&lista);
    cout << "Item 3 na posicao: "<< buscaBinaria(&lista, registro)+1 << endl;

  return 0;
}
