#include <stdio.h>
#include "data.h"

int main(){

int d1, m1, a1;

scanf("%d/%d/%d", &d1, &m1, &a1);

if (!verificaDataValida(d1, m1, a1)){
    printf("A data informada eh invalida\n");
    return 0;
}

printf("Data informada: ");
imprimeDataExtenso(d1, m1, a1);

if (verificaBissexto(a1)){
    printf("O ano informado eh bissexto\n");
}
else{
    printf("O ano informado nao eh bissexto\n");
}

printf("O mes informado possui %d dias\n", numeroDiasMes(m1, a1));

printf("A data seguinte eh: ");
imprimeProximaData(d1, m1, a1);

return 0;

}
