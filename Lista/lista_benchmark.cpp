/*
 * Busca Sequencial x Busca Binária.
 *
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 11/05/2018
 */
#include <iostream>
#include <chrono>

using namespace std;

#define MAX 2000000

typedef struct{
    int chave;
} REGISTRO;

typedef struct{
    REGISTRO elementos[MAX];
    int nroElem;
} LISTA;
bool inserirElemListaOrd(LISTA* , REGISTRO);

void inicializarLista(LISTA* l){
    int x;
    REGISTRO registro;
    l->nroElem = 0;
    for(x = 0; x <= MAX; x++) {
        registro.chave = x;
        inserirElemListaOrd(l,registro);
    }
    for(x = MAX; x > 0; x--) {
        registro.chave = x;
        inserirElemListaOrd(l,registro);
    }
}

int tamanho(LISTA* l){
    return l->nroElem;
}

void exibirLista(LISTA* l){
    int i;
    cout << "Lista: " << endl;
    for(i = 0 ; i < l->nroElem; i++) {
        cout << " " << l->elementos[i].chave << "  ";
    }
    cout << endl;
}

int buscaSequencial(LISTA* l, REGISTRO ch){
    int i = 0;
    while(i < l->nroElem){
        if(ch.chave == l->elementos[i].chave) {
          return i;
        } else {
          i++;
        }
    }
    return -1;
}

int buscaBinaria(LISTA* l, REGISTRO ch){
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem;
    while(esq <= dir) {
        meio = ((esq + dir) / 2);
        if(ch.chave == l->elementos[meio].chave) {
            return meio;
        } else {
            if(l->elementos[meio].chave < ch.chave){
                esq = meio + 1;
            } else {
                dir = meio + 1;
            }
        }
    }
    return -1;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg){
    int pos = tamanho(l);
    if(l->nroElem >= MAX) {
        return false;
    }
    while( pos > 0 && l->elementos[pos-1].chave > reg.chave) {
        l->elementos[pos] = l->elementos[pos-1];
        pos--;
    }
    l->elementos[pos] = reg;
    l->nroElem++;
    return true;
}

void benchmark(LISTA* l, REGISTRO ch) {
    cout << "\n***************************************************\n";
    cout << "Busca no Elemento " << ch.chave << endl;
    auto start = chrono::steady_clock::now();
    buscaBinaria(l, ch);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Busca binária  " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    buscaSequencial(l, ch);
    end = chrono::steady_clock::now();
    diff = end - start;
    cout << "Busca sequencial " << endl;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << endl << endl;
}

int main(void) {
    LISTA lista;
    REGISTRO registro;
    int x;

    inicializarLista(&lista);

    // exibirLista(&lista);
    cout << "Tamanho da lista: " << tamanho(&lista) << endl;

    registro.chave = 300;
    benchmark(&lista, registro);
    registro.chave = 3000;
    benchmark(&lista, registro);
    registro.chave = 30000;
    benchmark(&lista, registro);
    registro.chave = 3000000;
    benchmark(&lista, registro);
    registro.chave = 9003000;
    benchmark(&lista, registro);
  return 0;
}
