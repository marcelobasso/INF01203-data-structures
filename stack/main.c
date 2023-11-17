#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Stack *S1 = InicializaPilha();
    Stack *S2 = InicializaPilha();
    Stack *S3 = InicializaPilha();
    Stack *S4 = InicializaPilha();
    
    // pilha 4, 3, 2, 1
    PushPilha(&S1, 1);
    PushPilha(&S1, 2);
    PushPilha(&S1, 3);
    PushPilha(&S1, 4);
    ImprimirPilha(S1);

    // pilha 4, 3, 2
    PushPilha(&S2, 2);
    PushPilha(&S2, 3);
    PushPilha(&S2, 4);
    ImprimirPilha(S2);

    // pilha 1, 2, 3, 4
    PushPilha(&S3, 4);
    PushPilha(&S3, 3);
    PushPilha(&S3, 2);
    PushPilha(&S3, 1);
    ImprimirPilha(S3);

    // pilha 1, 2, 3, 4
    PushPilha(&S4, 4);
    PushPilha(&S4, 3);
    PushPilha(&S4, 2);
    PushPilha(&S4, 1);
    ImprimirPilha(S4);

    printf("\nAs pilhas P1 e P2 %ssao iguais\n", ComparaPilhas(S1, S2) ? "" : "NAO ");
    printf("As pilhas P3 e P4 %ssao iguais\n", ComparaPilhas(S3, S4) ? "" : "NAO ");

    return 0;
}