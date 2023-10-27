/*
 Com base no código lista_linear_ordenada.cpp,
 crie um mini banco de dados contendo os campos:

 id ( campo índice )
 Nome
 RA
 Curso ( Sistemas para Internet | outros )

Espera-se funções
 Para adicionar e remover aluno de forma ordenada.
 Uma busca binária será pelo id.
 Uma busca sequencial por RA


 Prof. Me. Orlando Saraiva Jr
 Criado em : 18/05/2018
 */
#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#define N 5

typedef struct{
    int chave;
    string nome;
    int RA;
    bool curso; /* True = DSM, False = outros*/
} REGISTRO;

typedef struct{
    REGISTRO elementos[N];
    int numeroElementos;
} LISTA;

int tamanho(LISTA* l){
    return l->numeroElementos;
}
void zerar_registro(REGISTRO* registro) {
    registro->nome = "";
    registro->chave = -1;
    registro->RA = -1;
}
void inicializarLista(LISTA* lista){
    REGISTRO registro_zerado;
    zerar_registro(&registro_zerado);
    int i;
    for(i = 0 ; i < N; i++) {
        lista->elementos[i].nome = "";
        lista->elementos[i].chave = -1;
        lista->elementos[i].RA = -1;
    }
    lista->numeroElementos = 0;
}
void mostra_elemento(LISTA* lista, int chave_elemento){
    cout << lista->elementos[chave_elemento].chave << " - ";
    cout << " " << lista->elementos[chave_elemento].chave << " - ";
    cout << lista->elementos[chave_elemento].nome << " - ";
    cout << lista->elementos[chave_elemento].RA;
    if(lista->elementos[chave_elemento].curso){
        cout << " - Sistemas para Internet" << endl;
    } else {
        cout << " - outro curso" << endl;
    }

}
void exibirLista(LISTA* lista){
    int i;
    cout << "Lista: " << endl;
    for(i = 0 ; i < lista->numeroElementos; i++) {
        mostra_elemento(lista, i);
    }
    cout << endl;
}
int buscaSequencial(LISTA* lista, REGISTRO registro){
    int i = 0;
    while(i < lista->numeroElementos){
        if(registro.RA == lista->elementos[i].RA) {
          return i;
        } else {
          i++;
        }
    }
    return -1;
}
bool inserirAluno(LISTA* lista, REGISTRO registro){
    int pos = tamanho(lista);
    if(lista->numeroElementos >= N) {
        return false;
    }
    while( pos > 0 && lista->elementos[pos-1].chave > registro.chave) {
        lista->elementos[pos] = lista->elementos[pos-1];
        pos--;
    }
    lista->elementos[pos] = registro;
    lista->numeroElementos++;
    return true;
}
bool atualizarAluno(LISTA* lista, REGISTRO registro, int i){
    int pos = tamanho(lista);
    if(i > pos) {
        return false;
    }
    if(i < 0) {
        return false;
    }
    registro.chave = i;
    lista->elementos[i] = registro;
    return true;
}
bool excluirElemListaOrd(LISTA* lista, REGISTRO registro){
    int pos, j;
    pos = buscaSequencial(lista, registro);
    if(pos == -1) return false;
    for(j = pos; j< lista->numeroElementos-1; j++){
        lista->elementos[j] = lista->elementos[j+1];
    }
    lista->numeroElementos--;
    return true;
}
bool gravar_em_disco(LISTA* lista){
    ofstream arquivo;
    arquivo.open ("banco_de_dados.txt");
    if (arquivo.is_open()){
        for(int i = 0 ; i < lista->numeroElementos; i++) {
            arquivo << lista->elementos[i].chave << " ";
            arquivo << lista->elementos[i].nome << " ";
            arquivo << lista->elementos[i].RA << " ";
            if(lista->elementos[i].curso){
                arquivo << "1" << endl;
            } else {
                arquivo << "0" << endl;
            }
        }
        arquivo.close();
        return true;
    } else {
        return false;
    }
}
bool ler_do_disco(LISTA* lista){
    ifstream arquivo;
    arquivo.open ("banco_de_dados.txt");
    string line, nome;
    int chave, RA, curso;
    REGISTRO registro;
    zerar_registro(&registro);
    /*
    Utilizando token |. Não concluido.
    while (getline(arquivo, line, '|')) {
            cout << line << "\n";
    }*/

    while (getline(arquivo, line)) {
        istringstream iss(line);
        iss >> chave;
        iss >> nome;
        iss >> RA;
        iss >> curso;

        cout << chave << '\n';
        cout << nome << '\n';
        cout << RA << '\n';
        cout << curso << '\n';
        cout << line << '\n';

        registro.chave = chave;
        registro.nome = nome;
        registro.RA = RA;
        if (curso == 0) {
            registro.curso = false;
        } else {
            registro.curso = true;
        }
        inserirAluno(lista, registro);
        zerar_registro(&registro);
    }
    arquivo.close();
    return true;
}

int main(void) {
    char escolha = 'x';
    int i;
    string escolha_interna;
    LISTA lista;
    REGISTRO registro;
    bool deu_certo;

    inicializarLista(&lista);
    do {
          zerar_registro(&registro);
          cout << "\n********************************\n";
          cout << "Digite uma letra\n\n";
          cout << "c \t Adicionar Aluno\t Create \n";
          cout << "r \t Buscar por RA \t\t Read \n";
          cout << "u \t Atualizar aluno\t Update \n";
          cout << "d \t Excluir por RA\t\t Delete \n\n";
          cout << "m \t Mostrar alunos cadastrados \n\n";
          cout << "w \t Gravar dados \n";
          cout << "l \t Ler dados \n\n";
          cout << "q \t Encerrar banco de dados.\n\n\n";
          cin >> escolha;
          /*           CREATE          */
          if(escolha == 'c' || escolha == 'C'){
              registro.chave = (tamanho(&lista) + 1);
              cout << "Digite o nome do aluno: " << endl;
              cin >> registro.nome;
              cout << "Digite o RA do aluno: " << endl;
              cin >> registro.RA;
              cout << "Aluno do curso Sistemas para Internet ? (S/N): " << endl;
              cin >> escolha_interna;
              if (escolha_interna.compare("n") == 0) {
                  registro.curso = false;
              } else {
                  registro.curso = true;
              }
             deu_certo =  inserirAluno(&lista, registro);
             if(deu_certo) {
                 cout << "Aluno " << registro.nome << " cadastrado com sucesso";
             } else {
                 cout << "Erro ao cadastrar " << registro.nome << endl;
             }
          }
          /*          READ           */
          if(escolha == 'r' || escolha == 'R'){
              cout << "Digite o RA: " << endl;
              cin >> escolha_interna;
              registro.RA = atoi(escolha_interna.c_str());
              i = buscaSequencial(&lista, registro);
              if(i > -1) {
                  mostra_elemento(&lista, i );
                  i = -1;
              }
          }
          /*          UPDATE           */
          if(escolha == 'u' || escolha == 'U'){
              cout << "Digite o RA: " << endl;
              cin >> escolha_interna;
              registro.RA = atoi(escolha_interna.c_str());
              i = buscaSequencial(&lista, registro);
              registro.chave = i;
              if(i > -1) {
                  cout << "Digite o nome do aluno: " << endl;
                  cin >> registro.nome;
                  cout << "Digite o RA do aluno: " << endl;
                  cin >> registro.RA;
                  cout << "Aluno do curso Sistemas para Internet ? (S/N): " << endl;
                  cin >> escolha_interna;
                  if (escolha_interna.compare("n") == 0) {
                      registro.curso = false;
                  } else {
                      registro.curso = true;
                  }
                 deu_certo =  atualizarAluno(&lista,registro, i);
                 if(deu_certo) {
                     cout << "Aluno " << registro.nome << " atualizado";
                 } else {
                     cout << "Erro ao atualizar " << registro.nome << endl;
                 }

                  i = -1;
              } else {
                  cout << "Não foi possivel encontrar RA informado." << '\n';
              }
          }
          /*          DELETE         */
          if(escolha == 'd' || escolha == 'D'){
              cout << "Digite o RA: " << endl;
              cin >> escolha_interna;
              registro.RA = atoi(escolha_interna.c_str());
              excluirElemListaOrd(&lista, registro);
          }
          /*          Mostrar Aluno          */
          if(escolha == 'm' || escolha == 'M'){
              cout << "Tamanho da fila: " << tamanho(&lista) << endl;
              exibirLista(&lista);
          }
          /*          Gravar dados em disco          */
          if(escolha == 'w' || escolha == 'W'){
              cout << "Gravando em disco " << endl;
              deu_certo = gravar_em_disco(&lista);
              if(deu_certo) {
                  cout << "Gravado em disco com sucesso.";
              } else {
                  cout << "Nao foi possivel gravar em disco.";
              }
          }
          if(escolha == 'l' || escolha == 'L'){
              cout << "Lendo do disco " << endl;
              deu_certo = ler_do_disco(&lista);
              if(deu_certo) {
                  cout << "Acesso ao disco com com sucesso.";
              } else {
                  cout << "Nao foi possivel ler em disco.";
              }
          }
      } while( escolha != 'q');

  return 0;
}
