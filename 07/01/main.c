#include <stdio.h>
#include "tadgen.h"

int main() {
    int tipo, n;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    scanf("%d %d", &tipo, &n);

    tGeneric *gen = CriaGenerico((Type) tipo, n);

    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}