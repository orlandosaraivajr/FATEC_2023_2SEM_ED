#include <iostream>

using namespace std;

/*
Exemplo de funções e passagem de parâmetros
*/

void nao_troca_valores(int valor_1, int valor_2);
void troca_valores(int *ponteiro_1, int *ponteiro_2);

void funcao_1_1(){
    float b;
    b = 7;
    cout << "Dentro da funcao_1_1: " << b << endl;
}

void funcao_1(){
    float a;
    a = 4.5;
    funcao_1_1();
    cout << "Dentro da funcao_1: " << a << endl;
    funcao_1_1();
}


int main(int argc, char *argv[]){
    int numero_1;
    int numero_2;

    funcao_1();

    cout << " Digite primero numero " << endl;
    cin >> numero_1;
    cout << " Digite primero numero " << endl;
    cin >> numero_2;

    cout << "Numeros digitados: " <<  numero_1 << "  " << numero_2 << endl;

    nao_troca_valores(numero_1, numero_2);
    cout << "Numeros digitados: "<<  numero_1 << "  " << numero_2 << endl;

    troca_valores(&numero_1, &numero_2);
    cout << "Numeros digitados: "<<  numero_1 << "  " << numero_2 << endl;

    return 0;
}

/* Passagem por valor */
void nao_troca_valores(int valor_1, int valor_2) {
    int auxiliar;
    auxiliar = valor_1;
    valor_1 = valor_2;
    valor_2 = auxiliar;
    cout <<"Dentro da funcao nao_troca_valores: "<< valor_1 << "  " <<  valor_2 << endl;
    return;
}
/* Passagem por referência */
void troca_valores(int *ponteiro_1, int *ponteiro_2) {
    int auxiliar;
    auxiliar = *ponteiro_1;
    *ponteiro_1 = *ponteiro_2;
    *ponteiro_2 = auxiliar;
    cout <<"Dentro da funcao nao_troca_valores: "<< *ponteiro_1 << "  " <<  *ponteiro_2 << endl;
    return;
}
