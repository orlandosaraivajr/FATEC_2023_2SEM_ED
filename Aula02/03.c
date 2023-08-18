/*
Terceiro programa em C++
Cadastro de aluno

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string recebe_nome_aluno();
string recebe_disciplina_aluno();
float recebe_nota_1();
float recebe_nota_2();

int main(int argc, char *argv[]){
    struct cadastro {
        string nome;
        string disciplina;
        float nota_1;
        float nota_2;
    };

    int TOTAL = 4;
    int x;
    struct cadastro vetor_aluno[TOTAL];

    for ( x = 0; x<TOTAL; x++) {
        vetor_aluno[x].nome = recebe_nome_aluno();
        vetor_aluno[x].disciplina = recebe_disciplina_aluno();
        vetor_aluno[x].nota_1 = recebe_nota_1();
        vetor_aluno[x].nota_2 = recebe_nota_2();
    }

    for ( x = 0; x<TOTAL; x++) {
        cout << "Nome = " << vetor_aluno[x].nome << endl;
        cout << "Disciplina = " << vetor_aluno[x].disciplina << endl;
        cout << "Nota 1 = " << vetor_aluno[x].nota_1 << endl;
        cout << "Nota 2 = " << vetor_aluno[x].nota_2 << endl;
        cout << "Média Simples = " << (vetor_aluno[x].nota_1 + vetor_aluno[x].nota_2) / 2 << endl;
    }

    return 0;
}

string recebe_nome_aluno() {
    string nome_recebido;
    cout << "Digite o nome do aluno: ";
    cin >> nome_recebido;
    return nome_recebido;
}

string recebe_disciplina_aluno() {
    string disciplina;
    cout << "Digite a disciplina cursada: ";
    cin >> disciplina;
    return disciplina;
}

float recebe_nota_1() {
    float nota_1;
    cout << "Digite a nota do aluno: ";
    cin >> nota_1;
    return nota_1;
}

float recebe_nota_2() {
    string nota;
    float nota_2;
    cout << "Digite a nota do aluno: ";
    cin >> nota_2;
    return nota_2;
}
