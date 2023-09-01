#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_NOME 50

static int contador = 0;

int main(int argc, char *argv[]){

    int x;

    struct CadastroAluno {
        char nome[TAMANHO_NOME];
        float nota_1;
        float nota_2;
    };

    CadastroAluno aluno;
    CadastroAluno *vetor_alunos;

    printf(" Digite o número de elementos: \n");
    scanf("%d", &contador);

    vetor_alunos = (CadastroAluno*) malloc(contador * sizeof(CadastroAluno));

    /*    Entrada de dados    */
    for(x = 0; x < contador; x++) {
        printf("\nDigite o nome do aluno %d : ", x+1);
        scanf("%s",vetor_alunos[x].nome);
        printf("\nDigite a nota 1 do aluno %d : ", x+1);
        scanf("%f",&vetor_alunos[x].nota_1);
        printf("\nDigite a nota 2 do aluno %d : ", x+1);
        scanf("%f",&vetor_alunos[x].nota_2);
    }

    printf("\n ********************** \n");
    /* Imprimir resultados  */
    for(x = 0; x < contador; x++) {
        printf("O nome do aluno:\t %s \n", vetor_alunos[x].nome);
        printf("Média:\t %4.2f \n", ( vetor_alunos[x].nota_1 + vetor_alunos[x].nota_2 ) / 2);
    }

    free(vetor_alunos);

    return 0;
}
