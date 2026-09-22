#include <stdio.h>
#include "utils.h"

/**
 * @brief Troca os valores de duas variáveis inteiras.
 * 
 * Esta função recebe como parâmetro dois ponteiros para inteiros e troca os valores armazenados nas variáveis apontadas por eles.
 * 
 * @param n1 Ponteiro para a primeira variável a ser trocada.
 * @param n2 Ponteiro para a segunda variável a ser trocada.
 * @return 1 se os dois ponteiros forem trocados de lugar, 0 caso contrário (ou seja, a troca não foi realizada). 
 */
int TrocaInteiros(int *n1, int *n2)
{
    if (*n1 > *n2)
    {
        int temp;

        temp = *n1;
        *n1 = *n2;
        *n2 = temp;

        return 1;
    }

    return 0;
}
