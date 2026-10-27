#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao(){
     tEleicao *eleicao = (tEleicao *) calloc(1, sizeof(tEleicao));

    int totalCandidatos;
    scanf("%d", &totalCandidatos);

    eleicao->presidentes = (tCandidato **) malloc(totalCandidatos * sizeof(tCandidato *));
    eleicao->governadores = (tCandidato **) malloc(totalCandidatos * sizeof(tCandidato *));

    for (int i = 0; i < totalCandidatos; i++){
        tCandidato *c = CriaCandidato();
        LeCandidato(c);

        if (ObtemCargo(c) == 'P'){
            eleicao->presidentes[eleicao->totalPresidentes++] = c;
        } else {
            eleicao->governadores[eleicao->totalGovernadores++] = c;
        }
    }

    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao){
    for (int i = 0; i < eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);

    for (int i = 0; i < eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);

    for (int i = 0; i < eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);

    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao){
    scanf("%d", &eleicao->totalEleitores);

    eleicao->eleitores = (tEleitor **) malloc(eleicao->totalEleitores * sizeof(tEleitor *));

    for (int i = 0; i < eleicao->totalEleitores; i++){
        tEleitor *e = CriaEleitor();
        LeEleitor(e);
        eleicao->eleitores[i] = e;

        // Presidente: 0 é branco, id que não existe é nulo
        int votoP = ObtemVotoPresidente(e);
        int p = 0;
        while (p < eleicao->totalPresidentes && !VerificaIdCandidato(eleicao->presidentes[p], votoP)){
            p++;
        }

        if (votoP == 0){
            eleicao->votosBrancosPresidente++;
        } else if (p == eleicao->totalPresidentes){
            eleicao->votosNulosPresidente++;
        } else {
            IncrementaVotoCandidato(eleicao->presidentes[p]);
        }

        // Governador: mesma regra
        int votoG = ObtemVotoGovernador(e);
        int g = 0;
        while (g < eleicao->totalGovernadores && !VerificaIdCandidato(eleicao->governadores[g], votoG)){
            g++;
        }

        if (votoG == 0){
            eleicao->votosBrancosGovernador++;
        } else if (g == eleicao->totalGovernadores){
            eleicao->votosNulosGovernador++;
        } else {
            IncrementaVotoCandidato(eleicao->governadores[g]);
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao){
    // Eleitor repetido anula a eleição
    for (int i = 0; i < eleicao->totalEleitores; i++){
        for (int j = i + 1; j < eleicao->totalEleitores; j++){
            if (EhMesmoEleitor(eleicao->eleitores[i], eleicao->eleitores[j])){
                printf("ELEICAO ANULADA\n");
                return;
            }
        }
    }

    // Presidente
    if (eleicao->totalPresidentes == 0){
        printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
    } else {
        tCandidato *presidente = eleicao->presidentes[0];
        int empate = 0;

        for (int i = 1; i < eleicao->totalPresidentes; i++){
            if (ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(presidente)){
                presidente = eleicao->presidentes[i];
                empate = 0;
            } else if (ObtemVotos(eleicao->presidentes[i]) == ObtemVotos(presidente) &&
                       !EhMesmoCandidato(eleicao->presidentes[i], presidente)){
                empate = 1;
            }
        }

        if (empate){
            printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        } else if (ObtemVotos(presidente) < eleicao->votosBrancosPresidente + eleicao->votosNulosPresidente){
            printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
        } else {
            printf("- PRESIDENTE ELEITO: ");
            ImprimeCandidato(presidente, CalculaPercentualVotos(presidente, eleicao->totalEleitores));
        }
    }

    // Governador
    if (eleicao->totalGovernadores == 0){
        printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
    } else {
        tCandidato *governador = eleicao->governadores[0];
        int empate = 0;

        for (int i = 1; i < eleicao->totalGovernadores; i++){
            if (ObtemVotos(eleicao->governadores[i]) > ObtemVotos(governador)){
                governador = eleicao->governadores[i];
                empate = 0;
            } else if (ObtemVotos(eleicao->governadores[i]) == ObtemVotos(governador) &&
                       !EhMesmoCandidato(eleicao->governadores[i], governador)){
                empate = 1;
            }
        }

        if (empate){
            printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
        } else if (ObtemVotos(governador) < eleicao->votosBrancosGovernador + eleicao->votosNulosGovernador){
            printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
        } else {
            printf("- GOVERNADOR ELEITO: ");
            ImprimeCandidato(governador, CalculaPercentualVotos(governador, eleicao->totalEleitores));
        }
    }

    // Nulos e brancos (somando presidente e governador)
    int nulos = eleicao->votosNulosPresidente + eleicao->votosNulosGovernador;
    int brancos = eleicao->votosBrancosPresidente + eleicao->votosBrancosGovernador;

    printf("- NULOS E BRANCOS: %d, %d", nulos, brancos);
}