#ifndef STRUCTS_H
#define STRUCTS_H
#include "../lib/structs.h"
#endif
#include <stdio.h>

typedef struct struct_metricas {
    int saida_concluida, rotacoes, comp;
    float maior_busca, menor_busca, tempo_total;
} Metricas;

// funcao para converter strings para minusculo para comparações não case-sensitive
char* toLower(char* s);

// lê os parâmetros passados por linha de comando
int validaParametros(int argc);

// funcao para pesquisar nodo em arvore e contar comparacoes e tempo de processamento
Nodo *consulta(Nodo *a, char nome[MAX_NOME], float *time, int *comp);

// funcao para criar as arvores necessarias a partir de um arquivo de entrada de dados
Nodo *criaArvores(char *nome_arq_dados, int *rotacoes, Nodo **abp, Nodo **avl);

// calcula a altura de uma arvore
int alturaArvore(Nodo *a);

// conta a quantidade de nodos de uma arvore
int contaNodos(Nodo *a);

// funcao responsável por processar o arquivo de entrada e gerar o arquivo de saída, com todas informações nele contidas
int processaEntrada(char *argv[], char *tabela_dados, Nodo *arvore, char *nome_arvore, Metricas *metricas);

// funcao responsável por imprimir as métricas no arquivo de saída
void imprimeMetricas(FILE *saida, Nodo *arvore, char *nome_arvore, Metricas *metricas);