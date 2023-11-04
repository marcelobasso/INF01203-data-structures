#include <stdlib.h>
#include <stdio.h>
#include "LDE.h"

int main() {
    Node *primeiro_el = IniciaLista();
    NodeInfo novo_el_info;
    char opcao;
    int sair = 0, codigo;

    while (!sair) {
        system("clear");
        // system('cls');
        Menu();
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {
            case 'N':
            case 'n':
                NovoElemento(&novo_el_info);
                primeiro_el = Inserir(primeiro_el, novo_el_info);
                break;

            case 'I':
            case 'i':
                Imprimir(primeiro_el);
                break;

            case 'J':
            case 'j':
                ImprimirReverso(primeiro_el);
                break;

            case 'R':
            case 'r':
                printf("\nRemover elemento n: ");
                scanf("%d", &codigo);
                getchar();
                primeiro_el = Remover(primeiro_el, codigo);
                break;

            case 'D':
            case 'd':
                primeiro_el = Destruir(primeiro_el);
                break;

            case 'S':
            case 's':
                sair = 1;
                break;
            
            default:
                printf("\n**digite uma opcao valida!");
        }

        if (!sair) {
            printf("\n**aperte enter para voltar ao menu.");
            getchar();
        }
    }

    return 0;
}