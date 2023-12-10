typedef struct info {
    int codigo;
} Info;

typedef struct nodoAvl{
    Info info;
    int FB;
    struct nodoAvl *esq;
    struct nodoAvl *dir;
} NodoAvl;

NodoAvl *rotacao_direita(NodoAvl *p);
NodoAvl *rotacao_esquerda(NodoAvl *p);
NodoAvl *rotacao_dupla_direita(NodoAvl *p);
NodoAvl *rotacao_dupla_esquerda(NodoAvl *p);
NodoAvl *InsereAVL(NodoAvl *a, Info x, int *ok);
NodoAvl *Caso1(NodoAvl *a, int *ok);
NodoAvl *Caso2(NodoAvl *a, int *ok);
