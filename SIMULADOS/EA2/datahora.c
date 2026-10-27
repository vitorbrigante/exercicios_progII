#include <stdio.h>
#include <stdlib.h>
#include "datahora.h"


typedef struct DataHora {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
} DataHora;

/**
 * @brief   Cria uma data/hora a partir dos valores informados.
 *
 * @param dia     [entrada]  Dia do mês, inteiro em [1, 31] (válido para o mês/ano).
 * @param mes     [entrada]  Mês, inteiro em [1, 12].
 * @param ano     [entrada]  Ano com 4 dígitos (ex.: 2026), inteiro >= 1.
 * @param hora    [entrada]  Hora do dia, inteiro em [0, 23].
 * @param minuto  [entrada]  Minuto, inteiro em [0, 59].
 *
 * @return  Ponteiro para o DataHora criado (alocado dinamicamente);
 *          NULL se a alocação de memória falhar.
 *
 * @pre     Os valores formam uma data/hora válida (a função NÃO valida).
 * @post    O chamador é dono do DataHora retornado e deve liberá-lo com
 *          liberaDataHora() (ou transferir a posse para outro TAD que o libere).
 */
DataHora *criaDataHora(int dia, int mes, int ano, int hora, int minuto){
    DataHora *dh = (DataHora *) malloc(sizeof(DataHora));

    dh->dia = dia;
    dh->mes = mes;
    dh->ano = ano;
    dh->hora = hora;
    dh->minuto = minuto;

    return dh;
}

/**
 * @brief   Lê uma data/hora da entrada padrão e cria o DataHora correspondente.
 *
 * Lê UMA linha no formato "DD/MM/AAAA HH:MM" (data, um espaço, horário), por
 * exemplo "27/10/2026 08:05", consumindo também a quebra de linha final.
 *
 * @return  Ponteiro para o DataHora lido (mesmas regras de posse de criaDataHora()).
 *
 * @pre     A próxima linha da entrada padrão contém uma data/hora válida no formato
 *          acima.
 */
DataHora *lerDataHora(){
    DataHora *dh = (DataHora *) malloc(sizeof(DataHora));

    scanf("%d/%d/%d %d:%d", &dh->dia, &dh->mes, &dh->ano, &dh->hora, &dh->minuto);

    return dh;
}

/**
 * @brief   Calcula quantos minutos se passaram entre duas datas/horas.
 *
 * O cálculo considera o calendário real:
 *   - meses com 31 dias: 1, 3, 5, 7, 8, 10, 12; com 30 dias: 4, 6, 9, 11;
 *   - fevereiro tem 29 dias em ano bissexto e 28 nos demais;
 *   - um ano é bissexto se for divisível por 400, ou se for divisível por 4 e NÃO
 *     for divisível por 100 (ex.: 2028 e 2000 são bissextos; 2026 e 2100 não são);
 *   - cada dia tem 24 * 60 = 1440 minutos.
 * Exemplos:
 *   inicio = 27/10/2026 08:50, fim = 27/10/2026 10:05  ->  75
 *   inicio = 27/10/2026 23:30, fim = 28/10/2026 00:10  ->  40
 *   inicio = 28/02/2028 12:00, fim = 01/03/2028 12:00  ->  2880 (2028 é bissexto)
 *
 * @param inicio  [entrada]  Data/hora inicial (não-nula).
 * @param fim     [entrada]  Data/hora final (não-nula).
 *
 * @return  Diferença em minutos (fim - inicio). É >= 0 sempre que fim não for
 *          anterior a inicio.
 *
 * @pre     inicio != NULL e fim != NULL.
 * @note    Nenhuma das duas datas/horas é modificada ou liberada.
 */
int diferencaMinutosDataHora(DataHora *inicio, DataHora *fim){
    if(inicio->dia == fim->dia && inicio->mes == fim->mes && inicio->ano == fim->ano){
        return (fim->hora * 60 + fim->minuto) - (inicio->hora * 60 + inicio->minuto);
    }

    int d1 = inicio->dia;
    int m1 = inicio->mes;
    int a1 = inicio->ano;
    int totalMinutos = 0;
    int diasMes = 0; 

    while(a1 != fim->ano || m1 != fim->mes || d1 != fim->dia){
        if (m1 == 1 || m1 == 3 || m1 == 5 || m1 == 7 || m1 == 8 || m1 == 10 || m1 == 12){
            diasMes = 31;
        }
        else if(m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11) {
            diasMes = 30;
        } else if(m1 == 2) {
            if (a1 % 400 == 0 || (a1 % 4 == 0 && a1 % 100 != 0)){
                diasMes = 29;
            } else {
                diasMes = 28;
            }
        }

        totalMinutos += 1440;
        d1++;
        if(d1 > diasMes){
            d1 = 1;
            m1++;
            if(m1 > 12){
                m1 = 1;
                a1++;
            }
        }
    }

    return totalMinutos - (inicio->hora * 60 + inicio->minuto) + (fim->hora * 60 + fim->minuto);
}

/**
 * @brief   Imprime a data/hora na saída padrão no formato "DD/MM/AAAA HH:MM".
 *
 * Dia, mês, hora e minuto são impressos SEMPRE com dois dígitos e o ano com quatro
 * (zeros à esquerda quando necessário). Ex.: "05/03/2027 08:05". Há exatamente um
 * espaço entre a data e o horário. NÃO imprime quebra de linha nem espaços
 * antes/depois.
 *
 * @param dh  [entrada]  Data/hora a imprimir (não-nula).
 * @pre     dh != NULL.
 */
void imprimeDataHora(DataHora *dh){
    printf("%02d/%02d/%04d %02d:%02d", dh->dia, dh->mes, dh->ano, dh->hora, dh->minuto);
}

/**
 * @brief   Libera a memória alocada para uma data/hora.
 *
 * @param dh  [entrada]  Data/hora a liberar.
 * @post    A memória apontada por dh é liberada; o ponteiro não deve mais ser usado.
 */
void liberaDataHora(DataHora *dh){
    free (dh);
}



