#define NAME_SIZE 100

// #define structs
typedef struct nodeInfo {
    int codigo;
    float preco;
    char nome[NAME_SIZE];
} NodeInfo;

typedef struct node {
    NodeInfo info;
    struct node *proximo, *anterior;
} Node;

// #define function headers

// Retorna um ponteiro nulo para iniciar a lista.
Node* IniciaLista(void);

// Insere um elemento no final da lista.
Node* Inserir(Node *primeiro_el, NodeInfo info);

// Imprime todos os elementos da lista;
void Imprimir(Node *primeiro_el);

// Imprime os elementos da lista de trás pra frente
void ImprimirReverso(Node *primeiro_el);

// Remove o elemento da lista com o codigo informado.
Node* Remover(Node *primeiro_el, int codigo);

// Destroi a lista e desaloca da memoria
Node* Destruir(Node *primeiro_el);

// Funcao auxiliar para imprimir informacoes do elemento.
void ImprimeElemento(NodeInfo info);

// Funcao auxiliar para exibeir menu de opcoes.
void Menu(void);

// Funcao auxiliar para ler as informacoes de um novo elemento.
void NovoElemento(NodeInfo *info);
