#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

NodoA *cria_arvore(void) {
    return NULL;
}

NodoA *InsereRaiz(NodoA *a, char ch) {
    if (a == NULL) {
        a = (NodoA *)malloc(sizeof(NodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }

    return a;
}

NodoA *consultaABP(NodoA *a, char chave) {
    if (a == NULL)
        return NULL;
    else if (a->info == chave)
        return a;
    else if (a->info > chave)
        return consultaABP2(a->esq, chave);
    else
        return consultaABP2(a->dir, chave);
}

NodoA *InsereArvore(NodoA *a, int ch) {
    if (a == NULL) {
        a = (NodoA *)malloc(sizeof(NodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (ch < a->info)
        a->esq = InsereArvore(a->esq, ch);
    else
        a->dir = InsereArvore(a->dir, ch);

    return a;
}

// -------------------------
// caminhamentos à esquerda
// -------------------------

void preFixadoEsq(NodoA *a) {
    if (a != NULL) {
        printf("%c\n", a->info);
        preFixado(a->esq);
        preFixado(a->dir);
    }
}

void centralEsq(NodoA *a) {
    if (a != NULL) {
        central(a->esq);
        printf("%c\n", a->info);
        central(a->dir);
    }
}

void posFixadoEsq(NodoA *a) {
    if (a != NULL) {
        posFixado(a->esq);
        posFixado(a->dir);
        printf("%c\n", a->info);
    }
}

// -------------------------
// caminhamentos à direita
// -------------------------

void preFixadoDir(NodoA *a) {
    if (a != NULL) {
        printf("%c\n", a->info);
        preFixado(a->dir);
        preFixado(a->esq);
    }
}

void centralDir(NodoA *a) {
    if (a != NULL) {
        central(a->dir);
        printf("%c\n", a->info);
        central(a->esq);
    }
}

void posFixadoDir(NodoA *a) {
    if (a != NULL) {
        posFixado(a->dir);
        posFixado(a->esq);
        printf("%c\n", a->info);
    }
}
