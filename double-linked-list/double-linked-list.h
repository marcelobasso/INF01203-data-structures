// structs 
#include <stdlib.h>
#define NOME_SIZE 100

typedef struct nodeInfo {
    int codigo;
    char nome[NOME_SIZE];
} NodeInfo;

typedef struct node {
    struct node *proximo, *anterior;
    NodeInfo info;
} Node;

void imprimeMenu(void);

void leNovoEl(NodeInfo *el_info);

// Imprime todos os elementos da lista de forma recursiva
void imprimeListaRec(Node* primeiro_el);

// function headers
Node* iniciaLista(void);

// Insere um elemento no início da lista
Node* insereInicio(Node* primeiro_el, NodeInfo info);

// Insere um elemento no final da lista
Node* insereFinal(Node *primeiro_el, NodeInfo info);

// Insere um elemento após o elemento com o código informado
Node* insereAposCodigo(Node *primeiro_el, NodeInfo info, int codigo);
