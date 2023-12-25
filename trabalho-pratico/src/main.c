#include "../lib/abp/abp.h"
#include "../lib/avl/avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARQ_DADOS_1 "test/1000Shuffled.csv"
#define ARQ_DADOS_2 "test/1000Sorted.csv"
#define MAX_LINHA 100

int rotacoes = 0;
int comp = 0;

// funcao para converter strings para minusculo para comparar não case-sensitive
char* toLower(char* s) {
    for(char *p=s; *p; p++) *p=tolower(*p);
    return s;
}

Nodo *consulta(Nodo *a, char nome[MAX_NOME]) {
    char nome_consulta[MAX_NOME], nome_arvore[MAX_NOME];

    strcpy(nome_consulta, nome);
    while (a) {
        comp++;
        strcpy(nome_arvore, a->dados.nome);

        // converte nomes para minusculo (not case sensitive)
        if (!strcmp(toLower(nome_arvore), toLower(nome_consulta)))
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

Nodo *criaArvores(FILE *arq_dados, Nodo **abp, Nodo **avl) {
    char nome[MAX_NOME], linha[MAX_LINHA];
    int calorias, ok;
    Dados dados;

    arq_dados = fopen(ARQ_DADOS_1, "r");
    if (arq_dados == NULL) {
        printf("\nErro na abertura do arquivo de dados!");
        return 0;
    }

    while (!feof(arq_dados)) {
        fgets(linha, MAX_LINHA, arq_dados);
        if (linha) {
            strcpy(dados.nome, strtok(linha, ";"));
            dados.calorias = atoi(strtok(NULL, ";"));

            *avl = InsereAvl(*avl, dados, &ok, &rotacoes);
            *abp = InsereAbp(*abp, dados);
        } else {
            printf("\nErro ao ler linha do arquivo de dados");
        }
    }

    fclose(arq_dados);

    return NULL;
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

void estatisticasAbp(FILE *saida, Nodo *abp) {
    fprintf(saida, "\n\n======== ESTATÍSTICAS ABP ============");
    fprintf(saida, "\nNumero de Nodos: %d", contaNodos(abp));
    fprintf(saida, "\nAltura: %d", alturaArvore(abp));
    fprintf(saida, "\nRotacoes: 0");
    fprintf(saida, "\nComparacoes: %d", comp);
}

void estatisticasAvl(FILE *saida, Nodo *avl) {
    fprintf(saida, "\n\n======== ESTATÍSTICAS AVL ============");
    fprintf(saida, "\nNumero de Nodos: %d", contaNodos(avl));
    fprintf(saida, "\nAltura: %d", alturaArvore(avl));
    fprintf(saida, "\nRotacoes: %d", rotacoes);
    fprintf(saida, "\nComparacoes: %d", comp);
}

int processaEntrada(char arq_entrada[MAX_NOME], char arq_saida[MAX_NOME], Nodo *abp, Nodo *avl) {
    FILE *entrada, *saida;
    Nodo *busca;
    char linha_entrada[MAX_LINHA], alimento[MAX_NOME];
    int qnt_consumida, len, cal_alimento, cal_totais = 0;

    entrada = fopen(arq_entrada, "r");
    if (entrada == NULL) {
        printf("\nErro na abertura do arquivo de entrada!");
        return 0;
    }

    saida = fopen(arq_saida, "w");
    if (saida == NULL) {
        printf("\nErro na abertura do arquivo de saida!");
        return 0;
    }

    fprintf(saida, "Calorias calculadas para %s usando a tabela %s\n\n", arq_entrada, ARQ_DADOS_1);

    comp = 0;
    // processa entradas fazendo busca na ABP
    while (!feof(entrada)) {
        fgets(linha_entrada, MAX_LINHA, entrada);

        len = strlen(linha_entrada);
        
        if (len > 2) {  // ignora linhas vazias (com apenas o \n)   
            strcpy(alimento, strtok(linha_entrada, ";"));
            qnt_consumida = atoi(strtok(NULL, ";"));

            busca = consulta(abp, alimento);

            if (busca) {
                cal_alimento = (qnt_consumida * busca->dados.calorias) / 100;
                cal_totais += cal_alimento;
                fprintf(saida, "%dg de %s (%d calorias por 100g) = %d calorias\n", qnt_consumida, alimento, busca->dados.calorias, cal_alimento);
            } else
                printf("\nAlimento \"%s\" nao consta na lista de dados!", alimento);
        }
    }

    fprintf(saida, "\nTotal de %d calorias consumidas no dia.", cal_totais);
    estatisticasAbp(saida, abp);        

    // processa entrada fazendo buscas na AVL
    comp = 0;
    rewind(entrada);
    while (!feof(entrada)) {
        fgets(linha_entrada, MAX_LINHA, entrada);

        len = strlen(linha_entrada);
        
        if (len > 2) {  // ignora linhas vazias (com apenas o \n)   
            strcpy(alimento, strtok(linha_entrada, ";"));
            busca = consulta(avl, alimento);

            if (!busca)
                printf("\nAlimento \"%s\" nao consta na lista de dados!", alimento);
        }
    }

    estatisticasAvl(saida, avl);

    fclose(saida);
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
    FILE *dados;

    if (argc != 3) {
        printf("N° incorreto de parâmetros. O comando deve seguir o padrao:\n./main <arquivo_entrada> <arquivo_saida>\n");
        return 0;
    }

    criaArvores(dados, &abp, &avl);
    processaEntrada(argv[1], argv[2], abp, avl);

    return 0;
}
