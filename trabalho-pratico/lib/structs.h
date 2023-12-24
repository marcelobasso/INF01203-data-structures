#define MAX_NOME 100

typedef struct dados {
    char nome[MAX_NOME];
    int calorias;
} Dados;

typedef struct nodo {
    Dados dados;
    int fator;
    struct nodo *esq;
    struct nodo *dir;
} Nodo;