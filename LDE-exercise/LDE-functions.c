#include <stdlib.h>
#include <stdio.h>
#include "LDE.h"

#define LINE "---------------------"

Node* IniciaLista(void) {
    return (Node *) NULL;
}

Node* Inserir(Node *primeiro_el, NodeInfo info) {
    Node *novo_elemento = malloc(sizeof(Node));
    Node *ptAux = primeiro_el;

    novo_elemento->info = info;
    novo_elemento->proximo = NULL;

    if (ptAux) {
        while (ptAux->proximo) {
            ptAux = ptAux->proximo;
        }

        ptAux->proximo = novo_elemento;
        novo_elemento->anterior = ptAux;
    } else
        primeiro_el = novo_elemento;

    return primeiro_el;
}

void Imprimir(Node *primeiro_el) {
    if (primeiro_el) {
        ImprimeElemento(primeiro_el->info);
        Imprimir(primeiro_el->proximo);
    } else
        printf("\n%s", LINE);
}

void ImprimirReverso(Node *primeiro_el) {
    if (primeiro_el) {
        Imprimir(primeiro_el->proximo);
        ImprimeElemento(primeiro_el->info);
    } else
        printf("\n%s", LINE);
}

Node* Remover(Node *primeiro_el, int codigo) {
    Node *ptAux = primeiro_el;

    while (ptAux && ptAux->info.codigo != codigo) {
        ptAux = ptAux->proximo;
    }

    if (ptAux == NULL) {
        printf("\n**codigo nao encontrado.");
    } else {
        if (ptAux->anterior && ptAux->proximo) {
                ptAux->anterior->proximo = ptAux->proximo;
                ptAux->proximo->anterior = ptAux->anterior;
        } else {
            if (ptAux->anterior) {
                ptAux->anterior->proximo = NULL;
            } else if(ptAux->proximo) {
                ptAux->proximo->anterior = NULL;
                primeiro_el = ptAux->proximo;
            }
        }

        free(ptAux);
    }

    return primeiro_el;
}

Node* Destruir(Node *primeiro_el) {
    Node *ptAux;

    while (primeiro_el) {
        ptAux = primeiro_el;
        primeiro_el = primeiro_el->proximo;
        free(ptAux);
    }
    free(primeiro_el); // ?

    return NULL;
}

void ImprimeElemento(NodeInfo info) {
    printf("\n%s", LINE);
    printf("\nCodigo: %d", info.codigo);
    printf("\nNome: %s", info.nome);
    printf("Preco: %.2f", info.preco);
}

void Menu(void) {
    printf("\nOPERACOES SOBRE A LISTA: ");
    printf("\nN - inserir");
    printf("\nI - imprimir");
    printf("\nJ - imprimir reversa");
    printf("\nR - remover elemento");
    printf("\nD - destruir");
    printf("\nS - sair");
    printf("\nDigite a opcao desejada: ");
}

void NovoElemento(NodeInfo *info) {
    printf("\nNOVO ELEMENTO ");
    printf("\nCodigo: ");
    scanf("%d", &info->codigo);
    getchar();
    printf("Nome: ");
    fgets(info->nome, sizeof(info->nome), stdin);
    printf("Preco: ");
    scanf("%f", &info->preco);
    getchar();
}