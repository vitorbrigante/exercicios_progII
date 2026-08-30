
#include <stdio.h>
#include "string_utils.h"


/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str){
    int i = 0;

    while (1){
        if (str[i] == '\0'){
            break;
        }
        i++;
    }

    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest){
    int i = 0;
    while (1){
        dest[i] = src[i];
        if (src[i] == '\0'){
            break;
        }
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if((str[i] >= 'a') && (str[i] <= 'z')){
            str[i] = str[i] - 32;
        }
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str){
    int i = 0;
    while (str[i] != '\0'){
        if((str[i] >= 'A') && (str[i] <= 'Z')){
            str[i] = str[i] + 32;
        }
        i++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str){
    int tamanho = string_length(str);
    int i;
    char tmp;
    for (i = 0; i < tamanho / 2; i++){
        tmp = str[i];
        str[i] = str[tamanho - 1 - i];
        str[tamanho - 1 - i] = tmp;
    }
}
