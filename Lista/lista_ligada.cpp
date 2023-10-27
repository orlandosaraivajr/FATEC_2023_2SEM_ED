/*
 * Lista ligada.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Criado em : 11/05/2018
 */
#include <iostream>

using namespace std;

typedef struct NO {
   int valor;
   struct NO* prox;
}*LISTA;

static LISTA head = NULL;
static LISTA tail = NULL;
static LISTA temp = NULL;

bool esta_vazio(){
    return head == NULL;
}
void inserir(int x){
    temp = new NO;
    temp->valor = x;
    if(esta_vazio()){
        temp->prox = NULL;
        tail = temp;
    } else {
        temp->prox = head;
    }
    head = temp;
}
void inserir_no_final(int x){
    temp = new NO;
    temp->valor = x;
    temp->prox = NULL;
    if(esta_vazio()){
        head = temp;
        tail = temp;
    } else {
        tail->prox = temp;
        tail = temp;
    }
}
void inserir_na_posicao(int posicao, int valor){
    LISTA temp2;
    int x = posicao ;
    if(esta_vazio()){
        cout << "Lista vazia " << endl;
    } else {
        if(posicao == 0) {
            inserir(valor);
        }
        temp = head;
        x--;
        while (temp->prox != NULL && x != 0) {
            x--;
            temp = temp->prox;

        }
        //cout << temp->valor << endl<< endl;
        if(temp->prox != NULL) {
            temp2 = new NO;
            temp2->valor = valor;
            temp2->prox = temp->prox;
            temp->prox = temp2;
        }
    }
}
void remover(int x){
    temp = head;
    NO *prev;
    while(temp->prox != NULL && temp->valor != x){
        prev = temp;
        temp = temp->prox;
    }
    if(temp->valor == x) {
        prev->prox = temp->prox;
        delete temp;
    }
    else if(temp->prox == NULL)
    {
        cout << "Valor " << x << " nao encontrado para ser removido." << endl;
    }
}
void encontrar(int x){
    int i=1;
    temp = head;
    while (temp->prox != NULL && temp->valor != x) {
        temp = temp->prox;
        i++;
    }
    if(temp->valor == x)
    {
        cout << "Encontrado na posicao:" << i << endl;
    }
    else if(temp->prox == NULL)
    {
        cout << "Nenhum valor encontrado..." << endl;
    }
}
void mostrar(){
    if(!esta_vazio()) {
        for(temp = head; temp != NULL; temp=temp->prox){
            cout << temp->valor << " ";
        }
        cout << endl;
    } else {
        cout << "Lista vazia !" << endl;
    }
}
void limpar_memorias(){
    LISTA thanos;
    delete temp;
    delete tail;
    while (head->prox != NULL) {
        thanos = head;
        head = head->prox;
        // cout << thanos->valor << " -- " << head->valor << endl<< endl;
        thanos->prox = NULL;
        delete thanos;
    }
}

int main(){
    mostrar();

    for (int x = 0; x < 10; x++){
        inserir_no_final(x);
    }
    mostrar();

    inserir_na_posicao(9, 99);
    inserir_na_posicao(4, 77);
    /*sinserir_na_posicao(1, 66);
    mostrar();
    inserir_na_posicao(1, 88);
    mostrar();
    inserir_na_posicao(3, 77);
    mostrar();
    /*
    inserir(15);
    mostrar();
    inserir(25);
    mostrar();
    inserir(35);
    mostrar();
    inserir(45);
    mostrar();
    encontrar(15);
    remover(25);
    mostrar();
    remover(22);
    mostrar();
    inserir_na_posicao(2, 66);
    mostrar();
    inserir_no_final(55);

    inserir_no_final(65);*/
    mostrar();
    limpar_memorias();
}
