#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

int main(){
    int tamanho_atual = TAM_PADRAO;

    char *vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor, &tamanho_atual);
    ImprimeString(vetor);
    LiberaVetor(vetor);

    return 0;
}