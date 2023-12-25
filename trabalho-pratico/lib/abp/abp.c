#include "abp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Nodo *cria_arvore(void) {
    return NULL;
}

Nodo *consultaABP(Nodo *a, char nome[MAX_NOME]) {
    if (a == NULL)
        return NULL;
    else if (!strcmp(a->dados.nome, nome))
        return a;
    else if (strcmp(a->dados.nome, nome) > 0)
        return consultaABP(a->esq, nome);
    else
        return consultaABP(a->dir, nome);
}

Nodo *InsereAbp(Nodo *a, Dados dados) {
    if (a == NULL) {
        a = (Nodo *) malloc(sizeof(Nodo));
        a->dados = dados;
        a->esq = NULL;
        a->dir = NULL;
    } else if (strcmp(a->dados.nome, dados.nome) > 0)
        a->esq = InsereAbp(a->esq, dados);
    else
        a->dir = InsereAbp(a->dir, dados);

    return a;
}
