#include <stdio.h>
#include "data.h"

/**
 * @brief Verifica se uma data é válida.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){

    if (ano <= 0){
        return 0;
    }

    if (mes < 1 || mes > 12){
        return 0;
    }

    if (dia < 1 || dia > numeroDiasMes(mes, ano)){
        return 0;
    }

    return 1;
}

/**
 * @brief Imprime uma data no formato DD/MM/AAAA.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano){
    printf("%02d/%02d/%d", dia, mes, ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 *
 * @param mes Mês da data.
 */
void imprimeMesExtenso(int mes){
    if (mes == 1){
        printf("Janeiro");
    }
    else if (mes == 2){
        printf("Fevereiro");
    }
    else if (mes == 3){
        printf("Marco");
    }
    else if (mes == 4){
        printf("Abril");
    }
    else if (mes == 5){
        printf("Maio");
    }
    else if (mes == 6){
        printf("Junho");
    }
    else if (mes == 7){
        printf("Julho");
    }
    else if (mes == 8){
        printf("Agosto");
    }
    else if (mes == 9){
        printf("Setembro");
    }
    else if (mes == 10){
        printf("Outubro");
    }
    else if (mes == 11){
        printf("Novembro");
    }
    else if (mes == 12){
        printf("Dezembro");
    }
}

/**
 * @brief Imprime uma data por extenso.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){

    printf("Data informada: %d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){
    if (ano % 400 == 0){
        return 1;
    }

    if (ano % 100 == 0){
        return 0;
    }

    if (ano % 4 == 0){
        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
        mes == 8 || mes == 10 || mes == 12){
        return 31;
    }

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }

    if (mes == 2){
        if (verificaBissexto(ano)){
            return 29;
        }

        return 28;
    }

    return 0;
}

/**
 * @brief Compara duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna 1, -1 ou 0.
 */
int comparaData(int dia1, int mes1, int ano1,
                int dia2, int mes2, int ano2){

    if (ano1 > ano2){
        return 1;
    }

    if (ano1 < ano2){
        return -1;
    }

    if (mes1 > mes2){
        return 1;
    }

    if (mes1 < mes2){
        return -1;
    }

    if (dia1 > dia2){
        return 1;
    }

    if (dia1 < dia2){
        return -1;
    }

    return 0;
}

/**
 * @brief Calcula o número de dias até o início de um determinado mês.
 *
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano){
    int dias = 0;
    int i;

    for (i = 1; i < mes; i++){
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1,
                         int dia2, int mes2, int ano2){

    int dias1 = dia1 + calculaDiasAteMes(mes1, ano1);
    int dias2 = dia2 + calculaDiasAteMes(mes2, ano2);

    int i;

    for (i = 1; i < ano1; i++){
        if (verificaBissexto(i)){
            dias1 += 366;
        }
        else{
            dias1 += 365;
        }
    }

    for (i = 1; i < ano2; i++){
        if (verificaBissexto(i)){
            dias2 += 366;
        }
        else{
            dias2 += 365;
        }
    }

    if (dias1 > dias2){
        return dias1 - dias2;
    }

    return dias2 - dias1;
}

/**
 * @brief Imprime a próxima data.
 *
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano){

    if (dia < numeroDiasMes(mes, ano)){
        imprimeData(dia + 1, mes, ano);
    }
    else if (mes < 12){
        imprimeData(1, mes + 1, ano);
    }
    else{
        imprimeData(1, 1, ano + 1);
    }
}