// structs
typedef struct stack {
    int dado;
    struct stack *prox;
} Stack;

// cria pilha vazia
Stack* InicializaPilha (void);

// retorna 1 se pilha vazia, e 0 em caso contrário
int PilhaVazia(Stack *Topo);

// insere nodo no topo da pilha, retorna novo topo
void PushPilha(Stack **Topo, int Dado);

// remove nodo no topo da pilha
int PopPilha(Stack **Topo, int *Dado);

// retorna informação no topo da pilha
int ConsultaPilha(Stack *Topo);

// libera posições ocupadas pela pilha
void DestroiPilha(Stack **Topo);

// retorna 1 se as pilhas forem iguais, 0 caso contrário.
int ComparaPilhas(Stack *S1, Stack *S2);
