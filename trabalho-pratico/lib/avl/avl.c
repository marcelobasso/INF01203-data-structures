#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// fator positivo e sua subárvore da esquerda também tem um fator positivo
Nodo *rotacao_direita(Nodo *p, int *rotacoes) {
    Nodo *u;

    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->fator = 0;
    p = u;
    (*rotacoes)++;

    return p;
}

// fator negativo e sua subárvore da direita também tem um fator negativo
Nodo *rotacao_esquerda(Nodo *p, int *rotacoes) {
    Nodo *z;

    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->fator = 0;
    p = z;
    (*rotacoes)++;

    return p;
}

// fator positivo e sua subárvore da esquerda tem um fator negativo
Nodo *rotacao_dupla_direita(Nodo *p, int *rotacoes) {
    Nodo *u, *v;

    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->fator == 1)
        p->fator = -1;
    else
        p->fator = 0;

    if (v->fator == -1)
        u->fator = 1;
    else
        u->fator = 0;

    p = v;
    (*rotacoes)++;

    return p;
}

// fator negativo e sua subárvore da direita tem um fator positivo
Nodo *rotacao_dupla_esquerda(Nodo *p, int *rotacoes) {
    Nodo *z, *y;

    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->fator == -1)
        p->fator = 1;
    else
        p->fator = 0;

    if (y->fator == 1)
        z->fator = -1;
    else
        z->fator = 0;

    p = y;
    (*rotacoes)++;

    return p;
}

Nodo *Caso1(Nodo *a, int *ok, int *rotacoes) {
    Nodo *z;

    z = a->esq;
    if (z->fator == 1)
        a = rotacao_direita(a, rotacoes);
    else
        a = rotacao_dupla_direita(a, rotacoes);

    a->fator = 0;
    *ok = 0;

    return a;
}

Nodo *Caso2(Nodo *a, int *ok, int *rotacoes) {
    Nodo *z;

    z = a->dir;
    if (z->fator == -1)
        a = rotacao_esquerda(a, rotacoes);
    else
        a = rotacao_dupla_esquerda(a, rotacoes);

    a->fator = 0;
    *ok = 0;
    
    return a;
}

Nodo *InsereAvl(Nodo *a, Dados dados, int *ok, int *rotacoes) {
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
     x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL) {
        a = (Nodo *) malloc(sizeof(Nodo));
        a->dados = dados;
        a->esq = NULL;
        a->dir = NULL;
        a->fator = 0;
        *ok = 1;
    } else if (strcmp(a->dados.nome, dados.nome) > 0) {
        a->esq = InsereAvl(a->esq, dados, ok, rotacoes);
        if (*ok) {
            switch (a->fator) {
            case -1:
                a->fator = 0;
                *ok = 0;
                break;
                
            case 0:
                a->fator = 1;
                break;

            case 1:
                a = Caso1(a, ok, rotacoes);
                break;
            }
        }
    } else {
        a->dir = InsereAvl(a->dir, dados, ok, rotacoes);
        if (*ok) {
            switch (a->fator) {
            case 1:
                a->fator = 0;
                *ok = 0;
                break;

            case 0:
                a->fator = -1;
                break;

            case -1:
                a = Caso2(a, ok, rotacoes);
                break;
            }
        }
    }

    return a;
}
