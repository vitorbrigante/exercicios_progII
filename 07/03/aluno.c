#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"

typedef struct Aluno{
    char nome [51];
    float nota;
    char genero;
} tAluno;

/**
 * @brief Aloca memoria para um aluno
 * 
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
tAluno *CriaAluno(){
    tAluno *a = (tAluno *) malloc(sizeof(tAluno));

    return a;
}

/**
 * @brief Libera a memoria alocada para um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
*/
void DestroiAluno(data_type aluno){
    free(aluno);
}

/**
 * @brief Le os dados de um aluno
 * 
 * @param aluno Ponteiro para o aluno
*/
void LeAluno(tAluno *aluno){
    scanf(" %50[^;];%c;%f", aluno->nome, &aluno->genero, &aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
*/
char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 * 
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
*/
float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}

