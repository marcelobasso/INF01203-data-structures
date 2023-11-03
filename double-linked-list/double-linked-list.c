#include <stdio.h>
#include <stdlib.h>
#include "double-linked-list.h"

int main() {
    Node *primeiro_el = iniciaLista();
    NodeInfo novo_el_info;
    int sair = 0;
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

            case 'I':
            case 'i':
                leNovoEl(&novo_el_info);
                primeiro_el = insereInicio(primeiro_el, novo_el_info);
                break;

            case 'S':
            case 's':
                sair = 1;
                break;

            default:
                printf("\nSeleciona uma opcao valida!\n");
        }
    }

    return 0;
}
