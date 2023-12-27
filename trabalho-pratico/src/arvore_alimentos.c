#ifndef HEADER_FILES
#define HEADER_FILES
#include "arvore_alimentos.h"
#include "../lib/abp/abp.h"
#include "../lib/avl/avl.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#define MAX_LINHA 100

char* toLower(char* s) {
    for(char *p=s; *p; p++) *p=tolower(*p);
    return s;
}

int alturaArvore(Nodo *a) {
    int alt_esq, alt_dir;

    if (a == NULL) return 0;

    alt_esq = alturaArvore(a->esq);
    alt_dir = alturaArvore(a->dir);

    if (alt_esq > alt_dir)
        return (1 + alt_esq);
    else
        return (1 + alt_dir);
}

int contaNodos(Nodo *a) {
    if (a == NULL) return 0;
    return 1 + contaNodos(a->esq) + contaNodos(a->dir);
}

int validaParametros(int argc) {
    if (argc < 3) {
        printf("N° incorreto de parâmetros. O comando deve seguir o padrao:\n./main <arquivo_entrada> <arquivo_saida>\n");

        return 0;
    }
    
    return 1;
}

Nodo *consulta(Nodo *a, char nome[MAX_NOME], float *time, int *comp) {
    char nome_consulta[MAX_NOME], nome_arvore[MAX_NOME];

    *time = clock();
    strcpy(nome_consulta, nome);
    while (a) {
        (*comp)++;
        strcpy(nome_arvore, a->dados.nome);

        // converte nomes para minusculo (not case sensitive)
        if (!strcmp(toLower(nome_arvore), toLower(nome_consulta))) {
            // calcula o tempo de busca 
            *time = clock() - *time;
            return a;
        } else {
            if (strcmp(a->dados.nome, nome) > 0)
                a = a->esq;
            else
                a = a->dir;
        }
    }
    // calcula o tempo de busca
    *time = clock() - *time;
    return NULL;
}

Nodo *criaArvores(char *nome_arq_dados, int *rotacoes, Nodo **abp, Nodo **avl) {
    char nome[MAX_NOME], linha[MAX_LINHA];
    int calorias, ok;
    FILE *arq_dados;
    Dados dados;

    arq_dados = fopen(nome_arq_dados, "r");
    if (arq_dados == NULL) {
        printf("\nErro na abertura do arquivo de dados!");
        return 0;
    }

    while (!feof(arq_dados)) {
        fgets(linha, MAX_LINHA, arq_dados);
        if (linha) {
            strcpy(dados.nome, strtok(linha, ";"));
            dados.calorias = atoi(strtok(NULL, ";"));

            *avl = InsereAvl(*avl, dados, &ok, rotacoes);
            *abp = InsereAbp(*abp, dados);
        } else {
            printf("\nErro ao ler linha do arquivo de dados");
        }
    }

    fclose(arq_dados);

    return NULL;
}

void imprimeMetricas(FILE *saida, Nodo *arvore, char *nome_arvore, Metricas *metricas) {
    fprintf(saida, "\n\n======== ESTATÍSTICAS %s ============", nome_arvore);
    fprintf(saida, "\nNumero de Nodos: %d", contaNodos(arvore));
    fprintf(saida, "\nAltura: %d", alturaArvore(arvore));
    // caso for ABP, rotações é 0
    fprintf(saida, "\nRotacoes: %d", !strcmp(nome_arvore, "ABP") ? 0 : metricas->rotacoes);
    fprintf(saida, "\nComparacoes: %d", metricas->comp);
    // calcula o tempo em segundos e multiplica por 1000 para ter ms  
    fprintf(saida, "\nMaior busca: %fms", metricas->maior_busca / CLOCKS_PER_SEC * 1000);
    fprintf(saida, "\nMenor busca: %fms", metricas->menor_busca / CLOCKS_PER_SEC * 1000);
    fprintf(saida, "\nTempo total: %fms", metricas->tempo_total / CLOCKS_PER_SEC * 1000);
}

int processaEntrada(char *argv[], char *tabela_dados, Nodo *arvore, char *nome_arvore, Metricas *metricas) {
    FILE *entrada, *saida;
    Nodo *busca;
    char linha_entrada[MAX_LINHA], alimento[MAX_NOME];
    int qnt_consumida, len, cal_alimento, cal_totais = 0;
    float time = 0;
    metricas->maior_busca = metricas->tempo_total = 0;
    metricas->menor_busca = INT_MAX;

    // abre o arquivo de entrada de informações do paciente
    entrada = fopen(argv[1], "r");
    if (entrada == NULL) {
        printf("\nErro na abertura do arquivo de entrada!");
        return 0;
    }

    // abre o arquivo de saída dos dados processados
    saida = fopen(argv[2], metricas->saida_concluida ? "a" : "w");
    if (saida == NULL) {
        printf("\nErro na abertura do arquivo de saida!");
        return 0;
    }

    // caso os dados ainda não tenham sido processados, imprime o cabeçalho do arquivo
    if (!metricas->saida_concluida)
        fprintf(saida, "Calorias calculadas para %s usando a tabela %s\n\n", argv[1], tabela_dados);
    
    while (!feof(entrada)) {
        // le uma linha do arquivo de entrada
        fgets(linha_entrada, MAX_LINHA, entrada);
        len = strlen(linha_entrada);
        
        if (len > 2) {  // ignora linhas vazias (com apenas o \n)   
            strcpy(alimento, strtok(linha_entrada, ";"));
            qnt_consumida = atoi(strtok(NULL, ";"));

            // consulta as informações do alimento consumido
            busca = consulta(arvore, alimento, &time, &(metricas->comp));
            // soma o tempo de busca na árvore ao tempo total
            metricas->tempo_total += time;

            // caso encontrou as informacoes do alimento  
            if (busca) {
                // caso o arquivo de saída ainda nao tenha sido escrito  
                if (!metricas->saida_concluida) {
                    // imprime as informações processadas do consumo do paciente
                    cal_alimento = (qnt_consumida * busca->dados.calorias) / 100;
                    cal_totais += cal_alimento;
                    fprintf(saida, "%dg de %s (%d calorias por 100g) = %d calorias\n", qnt_consumida, alimento, busca->dados.calorias, cal_alimento);
                }
            } else
                // caso o alimento nao foi encontrado, imprime mensagem de erro 
                printf("\nAlimento \"%s\" nao consta na lista de dados!", alimento);
        }
        // comparar o maior e menor tempo de busca por informações do alimento
        metricas->maior_busca = time > metricas->maior_busca ? time : metricas->maior_busca;
        metricas->menor_busca = time < metricas->menor_busca ? time : metricas->menor_busca;
    }

    // caso o arquivo de saída ainda não tenha sido escrito
    if (!metricas->saida_concluida) {
        // imprime as informações finais de consumo do paciente
        fprintf(saida, "\nTotal de %d calorias consumidas no dia.", cal_totais);
        // e atualiza variável de controle do arquivo de saída
        metricas->saida_concluida = 1;
    }

    // ao final, imprime as métrica do processamento no arquivo de saída
    imprimeMetricas(saida, arvore, nome_arvore, metricas);

    fclose(entrada);
    fclose(saida);

    return 1;
}
