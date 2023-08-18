/*
Cadastro de aluno

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>

using namespace std;


string recebe_nome_aluno();
string recebe_disciplina_aluno();
float recebe_nota_1();
float recebe_nota_2();

int main(int argc, char *argv[]){
    string nome;
    string disciplina;
    float nota_1;
    float nota_2;

    nome = recebe_nome_aluno();
    disciplina = recebe_disciplina_aluno();
    nota_1 = recebe_nota_1();
    nota_2 = recebe_nota_2();

    cout << "Nome = " << nome << endl;
    cout << "Disciplina = " << disciplina << endl;
    cout << "Nota 1 = " << nota_1 << endl;
    cout << "Nota 2 = " << nota_2 << endl;
    cout << "Média Simples = " << (nota_1 + nota_2) / 2 << endl;
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
    float nota_2;
    cout << "Digite a nota do aluno: ";
    cin >> nota_2;
    return nota_2;
}
