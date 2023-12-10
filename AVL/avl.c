#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

// fator positivo e sua subárvore da esquerda também tem um fator positivo
NodoAvl *rotacao_direita(NodoAvl *p) {
    NodoAvl *u;

    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;

    return p;
}

// fator negativo e sua subárvore da direita também tem um fator negativo
NodoAvl *rotacao_esquerda(NodoAvl *p) {
    NodoAvl *z;

    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;

    return p;
}

// fator positivo e sua subárvore da esquerda tem um fator negativo
NodoAvl *rotacao_dupla_direita(NodoAvl *p) {
    NodoAvl *u, *v;

    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;

    if (v->FB == 1)
        p->FB = -1;
    else
        p->FB = 0;

    if (v->FB == -1)
        u->FB = 1;
    else
        u->FB = 0;

    p = v;

    return p;
}

// fator negativo e sua subárvore da direita tem um fator positivo
NodoAvl *rotacao_dupla_esquerda(NodoAvl *p) {
    NodoAvl *z, *y;

    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;

    if (y->FB == -1)
        p->FB = 1;
    else
        p->FB = 0;

    if (y->FB == 1)
        z->FB = -1;
    else
        z->FB = 0;

    p = y;

    return p;
}

NodoAvl *InsereAVL(NodoAvl *a, Info x, int *ok) {
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
     x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL) {
        a = (NodoAvl *) malloc(sizeof(NodoAvl));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    } else if (x.codigo < a->info.codigo) {
        a->esq = InsereAVL(a->esq, x, ok);
        if (*ok) {
            switch (a->FB) {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
                
            case 0:
                a->FB = 1;
                break;

            case 1:
                a = Caso1(a, ok);
                break;
            }
        }
    } else {
        a->dir = InsereAVL(a->dir, x, ok);
        if (*ok) {
            switch (a->FB) {
            case 1:
                a->FB = 0;
                *ok = 0;
                break;

            case 0:
                a->FB = -1;
                break;

            case -1:
                a = Caso2(a, ok);
                break;
            }
        }
    }

    return a;
}

NodoAvl *Caso1(NodoAvl *a, int *ok) {
    NodoAvl *z;

    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);
    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;

    return a;
}

NodoAvl *Caso2(NodoAvl *a, int *ok) {
    NodoAvl *z;

    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);
    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;
    
    return a;
}
