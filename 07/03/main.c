#include <stdio.h>
#include "vector.h"
#include "aluno.h"
#include "relatorio.h"

int main() {
    int quantidade;

    scanf("%d", &quantidade);

    Vector *alunos = VectorConstruct();

    for (int i = 0; i < quantidade; i++) {
        tAluno *aluno = CriaAluno();

        LeAluno(aluno);

        VectorPushBack(alunos, aluno);
    }

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos, DestroiAluno);

    return 0;
}
