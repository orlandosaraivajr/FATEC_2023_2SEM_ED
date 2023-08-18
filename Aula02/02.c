/*
Segundo programa em C++
Cadastro de aluno

Prof. Me. Orlando Saraiva Jr
*/
#include <iostream>
#include <string>

using namespace std;

string recebe_nome_aluno();
string recebe_disciplina_aluno();
float recebe_nota_1();
float recebe_nota_2();

int main(int argc, char *argv[]){
    string nome[2];
    string disciplina[2];
    float nota_1[2];
    float nota_2[2];

    int x;

    for ( x = 0; x<2; x++) {
        nome[x] = recebe_nome_aluno();
        disciplina[x] = recebe_disciplina_aluno();
        nota_1[x] = recebe_nota_1();
        nota_2[x] = recebe_nota_2();
    }

    for ( x = 0; x<2; x++) {
        cout << endl;
        cout << "Nome = " << nome[x] << endl;
        cout << "Disciplina = " << disciplina[x] << endl;
        cout << "Nota 1 = " << nota_1[x] << endl;
        cout << "Nota 2 = " << nota_2[x] << endl;
        cout << "Média Simples = " << (nota_1[x] + nota_2[x]) / 2 << endl;
        cout << "=====================================";
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
