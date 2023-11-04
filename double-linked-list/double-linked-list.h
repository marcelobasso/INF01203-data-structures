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
void imprimeListaRec(Node *primeiro_el);

// Imprime a lista de trás pra frente usando recursão
void imprimeListaReverse(Node *primeiro_el);

// Imprime a lista de trás pra frente caminhando nos ponteiros
void imprimeListaReversePointers(Node *primeiro_el);

// function headers
Node* iniciaLista(void);

// Insere um elemento no início da lista
Node* insereInicio(Node *primeiro_el, NodeInfo info);

// Insere um elemento no final da lista
Node* insereFinal(Node *primeiro_el, NodeInfo info);

// Insere um elemento após o elemento com o código informado
Node* insereAposCodigo(Node *primeiro_el, NodeInfo info, int codigo);

// Inverte dois elementos da lista
Node* inverteElementos(Node *primeiro_el, int cod_1, int cod_2);

// Remove o primeiro elemento de uma lista
Node* removePrimeiro(Node *primeiro_el);

// Remove o ultimo elemento de uma lista
void removeUltimo(Node *primeiro_el);