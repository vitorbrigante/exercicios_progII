#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

typedef struct generic{
    Type type;
    int numElem;
    void *vetor;
} tGeneric;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = (tGeneric*) malloc(sizeof(tGeneric));

    gen->type = type;
    gen->numElem = numElem;
    if (type == INT) {
        gen->vetor = malloc(numElem * sizeof(int));
    } else {
        gen->vetor = malloc(numElem * sizeof(float));
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    int i;

    printf("\nDigite o vetor:\n");

    for (i = 0; i < gen->numElem; i++) {
        if (gen->type == INT) {
            scanf(" %d", &((int*) gen->vetor)[i]);
        } else {
            scanf(" %f", &((float*) gen->vetor)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    int i;

    for (i = 0; i < gen->numElem; i++) {
        if (gen->type == INT) {
            printf("%d", ((int*) gen->vetor)[i]);
        } else {
            printf("%.2f", ((float*) gen->vetor)[i]);
        }

        if (i < gen->numElem - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
