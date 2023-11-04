#include <stdio.h>
#include <stdlib.h>
#include "double-linked-list.h"

int main() {
    Node *primeiro_el = iniciaLista();
    NodeInfo novo_el_info;
    int sair = 0, codigo_insercao, cod_inverter_1, cod_inverter_2;
    char opcao;

    while (!sair) {
        imprimeMenu();
        scanf("%c", &opcao);
        getchar();
        system("clear");

        switch (opcao) {
            case 'L':
            case 'l':
                imprimeListaRec(primeiro_el);
                break;

            case 'R':
            case 'r':
                imprimeListaReversePointers(primeiro_el);
                break;

            case 'I':
            case 'i':
                leNovoEl(&novo_el_info);
                primeiro_el = insereInicio(primeiro_el, novo_el_info);
                break;

            case 'F':
            case 'f':
                leNovoEl(&novo_el_info);
                primeiro_el = insereFinal(primeiro_el, novo_el_info);
                break;

            case 'A':
            case 'a':
                leNovoEl(&novo_el_info);
                printf("\nInserir apos o codigo: ");
                scanf("%d", &codigo_insercao);
                getchar();
                primeiro_el = insereAposCodigo(primeiro_el, novo_el_info, codigo_insercao);
                break;

            case 'T':
            case 't':
                printf("\nCodigo do primeiro elemento: ");
                scanf("%d", &cod_inverter_1);
                getchar();
                printf("\nCodigo do segundo elemento: ");
                scanf("%d", &cod_inverter_2);
                getchar();
                inverteElementos(primeiro_el, cod_inverter_1, cod_inverter_2);
                break;

            case 'D':
            case 'd':
                primeiro_el = removePrimeiro(primeiro_el);
                break;

            case 'P':
            case 'p':
                removeUltimo(primeiro_el);
                break;

            case 'S':
            case 's':
                sair = 1;
                break;

            default:
                printf("\nSeleciona uma opcao valida!\n");
        }

        if (!sair) {
            printf("\n**Pressione enter para voltar ao menu");
            getchar();
        }
    }

    return 0;
}
