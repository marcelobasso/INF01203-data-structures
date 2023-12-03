typedef struct nodoA {
    char info;
    struct nodoA *esq;
    struct nodoA *dir;
} NodoA;

// cria uma árvore vazia
NodoA* cria_arvore(void);

// aloca nodo raiz e insere dado
NodoA* InsereRaiz(NodoA *a, char ch);

// insere um nodo na sub-árvore esquerda
NodoA* InsereEsq(NodoA * a, char info, char infopai);

// insere um nodo na sub-árvore direita
NodoA* InsereDir(NodoA * a, char info, char infopai);

NodoA *consultaABP(NodoA *a, char chave);

NodoA *InsereArvore(NodoA *a, int ch);

void preFixadoEsq(NodoA *a);
void centralEsq(NodoA *a);
void posFixadoEsq(NodoA *a);

void preFixadoDir(NodoA *a);
void centralDir(NodoA *a);
void posFixadoDir(NodoA *a);