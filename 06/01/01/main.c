#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){
    int tamanho = -1;

    scanf("%d", &tamanho);

    int *v = CriaVetor(tamanho);
    LeVetor(v, tamanho);
    float media = CalculaMedia(v, tamanho);

    printf("%.2f\n", media);

    LiberaVetor(v);

    return 0;
}