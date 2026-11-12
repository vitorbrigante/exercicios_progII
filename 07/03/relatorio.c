#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"
#include "vector.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos){
    int quantidade = VectorSize(alunos);

    float somaNotas = 0;
    int aprovados = 0;

    int masculino = 0;
    int feminino = 0;
    int outro = 0;

    for (int i = 0; i < quantidade; i++) {
        tAluno *aluno = (tAluno *)VectorGet(alunos, i);

        somaNotas += GetNotaAluno(aluno);

        if (GetNotaAluno(aluno) >= 6) {
            aprovados++;
        }

        if (GetGeneroAluno(aluno) == 'M') {
            masculino++;
        }
        else if (GetGeneroAluno(aluno) == 'F') {
            feminino++;
        }
        else if (GetGeneroAluno(aluno) == 'O') {
            outro++;
        }
    }

    if (quantidade == 0) {
        printf("Media das notas: 0.00\n");
        printf("Porcentagem de alunos aprovados: 0.00%%\n");
        printf("Porcentagem de cada genero:\n");
        printf("Masculino: 0.00%%\n");
        printf("Feminino: 0.00%%\n");
        printf("Outro: 0.00%%\n");
        return;
    }

    printf("Media das notas: %.2f\n", somaNotas / quantidade);

    printf("Porcentagem de alunos aprovados: %.2f%%\n",
           (float)aprovados / quantidade * 100);

    printf("Porcentagem de cada genero:\n");

    printf("Masculino: %.2f%%\n",
           (float)masculino / quantidade * 100);

    printf("Feminino: %.2f%%\n",
           (float)feminino / quantidade * 100);

    printf("Outro: %.2f%%\n",
           (float)outro / quantidade * 100);
}

