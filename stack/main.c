#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

main() {
    Stack *S1 = InicializaPilha();
    Stack *S2 = InicializaPilha();
    int *dado1, *dado2;

    PushPilha(&S1, 1);
    PushPilha(&S1, 2);
    PushPilha(&S1, 3);

    PushPilha(&S2, 1);
    PushPilha(&S2, 2);
    PushPilha(&S2, 3);
    PushPilha(&S2, 4);

    printf("Iguais: %s\n\n", ComparaPilhas(S1, S2) ? "Sim" : "Não");
}