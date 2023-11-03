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

// function headers
Node* iniciaLista(void);