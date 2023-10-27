/*
 * Lista linear sequencial.
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

void inicializarLista(LISTA* lista){
    lista->numeroElementos = 0;
}
void exibirLista(LISTA* lista){
    int i;
    cout << "Lista: " << endl;
    for(i = 0 ; i < lista->numeroElementos; i++) {
        cout << " " << lista->elementos[i].chave << "  ";
    }
    cout << endl;
}
int buscaSequencial(LISTA* lista, REGISTRO registro){
    int i = 0;
    while(i < lista->numeroElementos){
        if(registro.chave == lista->elementos[i].chave) {
          return i;
        } else {
          i++;
        }
    }
    return -1;
}
bool inserirElemLista(LISTA* lista, REGISTRO registro, int i){
    int j;
    if((lista->numeroElementos == N) || (i <0) || i > lista->numeroElementos)
        return false;
    for(j = lista->numeroElementos; j > i; j--) {
        lista->elementos[j] = lista->elementos[j-1];
    }
    lista->elementos[i] = registro;
    lista->numeroElementos++;
    return true;
}
bool excluirElemLista(LISTA* lista, REGISTRO registro){
    int pos, j;
    pos = buscaSequencial(lista, registro);
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
    for(x = 0; x <= 15; x++) {
        registro.chave = x+2;
        inserirElemLista(&lista,registro,x);
    }

    registro.chave = 3;
    cout << "Item 3 na posicao: "<< buscaSequencial(&lista, registro)+1 << endl;
    exibirLista(&lista);

    excluirElemLista(&lista, registro);
    exibirLista(&lista);

    deu_certo = inserirElemLista(&lista,registro,15);
    if( !deu_certo) {
        cout << "\n\n Deu ruim inserir elemento na posicao 16" << endl << endl;
    }
    exibirLista(&lista);
    deu_certo = inserirElemLista(&lista,registro,40);
    if( !deu_certo) {
        cout << "\n\n Deu ruim inserir elemento na posicao 40" << endl << endl;
    }
    exibirLista(&lista);
    cout << "Item 3 na posicao: "<< buscaSequencial(&lista, registro)+1 << endl;
  return 0;
}
