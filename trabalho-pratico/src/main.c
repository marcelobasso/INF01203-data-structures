#include "../lib/abp/abp.h"
#include "../lib/avl/avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ_DADOS_1 "test/1000Shuffled.csv"
#define ARQ_DADOS_2 "test/1000Sorted.csv"
#define MAX_LINHA 100

int comp = 0;


void iniciaArquivos(FILE *dados, FILE *entrada, FILE *saida, char *argv[]) {
    entrada = fopen(argv[1], "r");
    if (entrada == NULL)
        printf("\nErro na abertura do arquivo de entrada");

    saida = fopen(argv[2], "w");
}

Nodo *consulta(Nodo *a, char nome[MAX_NOME]) {
    while (a != NULL) {
        comp++;
        if (!strcmp(a->dados.nome, nome))
            return a;
        else {
            if (strcmp(a->dados.nome, nome) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    return NULL;
}

Nodo *criaArvores(FILE *arq_dados, Nodo *abp, Nodo *avl) {
    char nome[MAX_NOME], linha[MAX_LINHA];
    int calorias, ok;
    Dados dados;

    arq_dados = fopen(ARQ_DADOS_1, "r");
    if (arq_dados == NULL)
        printf("\nErro na abertura do arquivo de dados!");

    while (!feof(arq_dados)) {
        fgets(linha, MAX_LINHA, arq_dados);
        if (linha) {
            strcpy(dados.nome, strtok(linha, ";"));
            dados.calorias = atoi(strtok(NULL, ";"));

            avl = InsereAvl(avl, dados, &ok);
            abp = InsereAbp(abp, dados);
        } else {
            printf("\nErro ao ler linha do arquivo de dados");
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {

    // • Para ler cada linha dos arquivos de entrada, utilize a função fgets.

    // • Para tokenizar as linhas (separar o nome do alimento do seu número de calorias ou quantidade),
    // utilize a função strtok. O separador utilizado no arquivo csv é “;”.

    // • A ordem lexicográfica dos nomes dos alimentos determinará a organização da árvore, i.e., a ordem
    // em que aparecem no dicionário. Por exemplo, se a palavra “morango” for a raiz da árvore, então a
    // palavra “alface” deve aparecer na subárvore esquerda da raiz (utilize a função strcmp) para
    // comparar as strings.

    Nodo *abp = cria_arvore(), *avl = cria_arvore();
    FILE *dados, *entrada, *saida;

    if (argc != 3) {
        printf("N° incorreto de parâmetros. O comando deve seguir o padrao:\n./main <arquivo_entrada> <arquivo_saida>\n");
        return 0;
    }

    criaArvores(dados, abp, avl);


    return 0;
}
