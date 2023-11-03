#include <stdlib.h>
#include <stdio.h>
#include "double-linked-list.h"

#define NOME_SIZE 100
#define HORIZONTAL_LINE "---------------------------------\n"

void imprimeMenu(void) {
    printf("\n\nESCOLHA A OPCAO DESEJADA:\n\n");
    printf("L - imprimir os elementos da lista\n");
    printf("R - imprimir os elementos da lista de trás pra frente\n");
    printf("I - inserir um elemento no inicio da lista\n");
    printf("F - inserir um elemento no final da lista\n");
    printf("A - inserir um elemento após o codigo desejado\n");
    printf("T - inverter a posicao de dois elementos informados\n");
    printf("DF - remover o primeiro elemento da lista\n");
    printf("DL - remover o último elemento da lista\n");
    printf("DN - remover o elemento N da lista\n");
    printf("S - sair\n");
    printf("\nOpcao desejada: ");
}

void leNovoEl(NodeInfo *el_info) {
    printf("Codigo do novo elemento: ");
    scanf("%d", &el_info->codigo);
    getchar();
    printf("Nome do novo elemento: ");
    fgets(el_info->nome, sizeof(el_info->nome), stdin);
}

// define functions
Node* iniciaLista(void) {
    return (Node *) NULL;
}

void imprimeListaRec(Node* primeiro_el) {
    if (primeiro_el) {
        printf(HORIZONTAL_LINE);
        printf("Nome: %s", primeiro_el->info.nome);
        printf("Codigo: %d\n", primeiro_el->info.codigo);
        imprimeListaRec(primeiro_el->proximo);
    }
}

Node* insereInicio(Node* primeiro_el, NodeInfo info) {
    Node* novo_el;

    novo_el = (Node *) malloc(sizeof(Node));
    novo_el->info = info;
    novo_el->anterior = NULL;
    novo_el->proximo = primeiro_el;

    if (primeiro_el) {
        primeiro_el->anterior = novo_el;
    }

    primeiro_el = novo_el;
    
    return primeiro_el;
}

Node* insereFinal(Node *primeiro_el, NodeInfo info) {
    Node *ptAux, *novo_el;

    novo_el = (Node *) malloc(sizeof(Node));
    novo_el->info = info;
    novo_el->proximo = NULL;

    if (primeiro_el == NULL) {
        primeiro_el = novo_el;
        novo_el->anterior = NULL;
    } else {
        // encontra o último elemento
        for (ptAux = primeiro_el; ptAux; ptAux = ptAux->proximo);

        ptAux->proximo = novo_el;
        novo_el->anterior = ptAux;
    }

    return primeiro_el;
}

Node* insereAposCodigo(Node *primeiro_el, NodeInfo info, int codigo) {
    Node *novo_el, *ptAux;

    novo_el = (Node *) malloc(sizeof(Node));
    novo_el->info = info;

    if (primeiro_el == NULL) {
        printf("\n**Codigo nao encontrado.");
    } else {
        for (ptAux = primeiro_el; ptAux && ptAux->info.codigo != codigo; ptAux = ptAux->proximo);

        if (ptAux == NULL) {
            printf("\n**Codigo nao encontrado.");
        } else {
            novo_el->proximo = ptAux->proximo;
            novo_el->anterior = ptAux;
            ptAux->proximo->anterior = novo_el;
            ptAux->proximo = novo_el;
        }
    }
}











