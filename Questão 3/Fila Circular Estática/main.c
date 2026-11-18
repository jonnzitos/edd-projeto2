#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void limpar(void) {
    system("cls");
}

void pause_menu(void) {
    system("pause");
}

int main() {

    int opcao;
    Pedido pedido;
    char cargo[20];

    fila_criar();

    do {

        limpar();

        printf("\n===== SPOOLER DE IMPRESSAO =====\n");
        printf("1 - Enviar documento para impressao\n");
        printf("2 - Imprimir proximo documento\n");
        printf("3 - Mostrar fila de impressao\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
        }

        switch (opcao) {

            case 1:

                printf("\nNome do usuario: ");
                scanf(" %49[^\n]", pedido.usuario);

                printf("Nome do documento: ");
                scanf(" %49[^\n]", pedido.documento);

                printf("Cargo (1 - Diretor, 2 - Coordenador, 3 - Funcionario): ");
                pedido.prioridade = 0;
                scanf("%d", &pedido.prioridade);

                if (pedido.prioridade < DIRETOR || pedido.prioridade > FUNCIONARIO) {
                    printf("\nErro: cargo invalido!\n");
                } else if (fila_enfileirar(pedido)) {
                    printf("\nDocumento enviado para a fila com sucesso!\n");
                } else {
                    printf("\nErro: fila cheia!\n");
                }

                break;

            case 2:

                if (fila_desenfileirar(&pedido)) {
                    nome_cargo(pedido.prioridade, cargo);
                    printf("\nImprimindo \"%s\" de %s (%s)...\n", pedido.documento, pedido.usuario, cargo);
                } else {
                    printf("\nErro: fila vazia!\n");
                }

                break;

            case 3:

                fila_imprimir();

                break;

            case 0:

                fila_destruir();

                printf("\nPrograma encerrado!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

        if (opcao != 0) {
            pause_menu();
        }

    } while (opcao != 0);

    return 0;
}