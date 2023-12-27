#ifndef HEADER_FILES
#define HEADER_FILES
#include "arvore_alimentos.h"
#include "../lib/abp/abp.h"
#include "../lib/avl/avl.h"
#endif

#define ARQ_DADOS_1 "test/1000Shuffled.csv"
#define ARQ_DADOS_2 "test/1000Sorted.csv"

int main(int argc, char *argv[]) {
    Nodo *abp = cria_arvore(), *avl = cria_arvore();
    Metricas metricas = {
        .comp = 0,
        .rotacoes = 0,
        .saida_concluida = 0
    };

    if (validaParametros(argc)) {
        criaArvores(ARQ_DADOS_1, &(metricas.rotacoes), &abp, &avl);
        processaEntrada(argv, ARQ_DADOS_1, abp, "ABP", &metricas);
        processaEntrada(argv, ARQ_DADOS_1, avl, "AVL", &metricas);
    }

    return 0;
}
