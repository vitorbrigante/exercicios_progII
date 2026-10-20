#include <stdio.h>
#include "evento.h"

/**
 * Cadastra um novo evento no calendário e o insere na próxima posição do array.
 *
 * @param eventos Array de eventos onde o novo evento será cadastrado.
 * @param numEventos Ponteiro para o número atual de eventos cadastrados.
 */
void cadastrarEvento(Evento* eventos, int* numEventos){
    Evento e;

    scanf("%[^\n]\n", e.nome);
    scanf("%d %d %d", &e.dia, &e.mes, &e.ano);

    eventos[*numEventos] = e;

    *numEventos++;

    printf("Evento cadastrado com sucesso!\n");
}

/**
 * Exibe todos os eventos cadastrados no calendário.
 *
 * @param eventos Array de eventos a serem exibidos.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void exibirEventos(Evento* eventos, int* numEventos){
    int i = 0;

    printf("Eventos cadastrados:\n");
    for (i = 0; i < *numEventos; i++){
        printf("%d - %s - %02d/%02d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }

}

/**
 * Troca a data de um evento específico no calendário.
 *
 * @param eventos Array de eventos onde o evento será modificado.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarDataEvento(Evento* eventos, int* numEventos){
    int i = 0;

    scanf("%d ", &i);

    if (i > *numEventos || i < 0){
        printf("Indice invalido!\n");
    } else {
        scanf("%d %d %d ", &eventos[i].dia, &eventos[i].mes, &eventos[i].ano);

        printf("Data modificada com sucesso!\n");
    }
}

/**
 * Troca a posição de dois eventos, a partir do índice, dentro do array de eventos.
 *
 * @param eventos Array de eventos onde a troca será realizada.
 * @param indiceA Ponteiro para o primeiro índice.
 * @param indiceB Ponteiro para o segundo índice.
 * @param numEventos Ponteiro para o número total de eventos cadastrados.
 */
void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    Evento e = eventos[*indiceA];

    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = e;

    printf("Eventos trocados com sucesso!");
}



