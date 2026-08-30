#include <stdio.h>
#include "string_utils.h"

int main (){
    char str[99];
    char str2[99];
    int o = 0;

    scanf("%98[^\n]", str);

    while (1){

        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: ");

        if (scanf("%d", &o) != 1){
            break;
        }

        if (o == 1){
            printf("\nTamanho da string: %d", string_length(str));
        }

        if (o == 2){
            string_copy(str, str2);
            printf("\nString copiada: %s", str2);
        }

        if (o == 3){
            string_upper(str);
            printf("\nString convertida para maiusculas: %s", str);
        }

        if (o == 4){
            string_lower(str);
            printf("\nString convertida para minusculas: %s", str);
        }

        if (o == 5){
            string_reverse(str);
            printf("\nString invertida: %s", str);
        }

        if (o == 6){
            break;
        }
        printf("\n\n");
    }

    return 0;
}