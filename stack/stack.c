#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* InicializaPilha (void) {
    return (Stack *) NULL;
}

int PilhaVazia(Stack *Topo) {
    return Topo == NULL;
}

// retorna 1 se exclui e zero se não exclui
int PopPilha(Stack **Topo, int *Dado) {
    Stack *ptaux;

    if (!PilhaVazia(*Topo)) {
        *Dado = (*Topo)->dado; // devolve o valor do topo
        ptaux = *Topo;         // guarda o endereço do topo
        *Topo = (*Topo)->prox;  // o próximo passa a ser o topo

        free(ptaux);           // libera o que estava no topo
        ptaux = NULL;

        return 1;
    } else
        return 0; // a pilha está vazia
}

void PushPilha(Stack **Topo, int Dado) {
    Stack *novo; // novo elemento

    /*insere a informação no novo nodo*/
    novo = (Stack *) malloc(sizeof(Stack));

    novo->dado = Dado;
    novo->prox = *Topo;

    /*retorna novo topo */
    *Topo = novo;
}

int ConsultaPilha(Stack *Topo) {
    return Topo->dado;
}

void DestroiPilha(Stack **Topo) {
    Stack *ptaux;

    while (*Topo != NULL) {
        ptaux = *Topo;     // guarda o endereço do topo
        *Topo = (*Topo)->prox; // o próximo passa a ser o topo
        free(ptaux);      // libera o que estava no topo
    }

    *Topo = NULL;
}

int ComparaPilhas(Stack *S1, Stack *S2) {
    int dado1, dado2, igual = 1;

    while (PopPilha(&S1, &dado1) && PopPilha(&S2, &dado2) && igual) {
        igual = dado1 == dado2;
    }

    return PilhaVazia(S1) && PilhaVazia(S2) && igual;
}
