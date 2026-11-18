#include <stdio.h>
#include "funcionario/funcionario.h"
#include "lista_estatica/lista_estatica.h"
#include "lista_dinamica/lista_dinamica.h"

int main() {

    int opcao;
    int tipo = 1; /* 1 = lista estatica, 2 = lista dinamica */
    int id;
    int ok;
    Funcionario f;

    lista_est_criar();
    lista_din_criar();

    do {

        if (tipo == 1) {
            printf("\n===== EMPRESA - LISTA ESTATICA =====\n");
        } else {
            printf("\n===== EMPRESA - LISTA DINAMICA =====\n");
        }

        printf("1 - Inserir funcionario\n");
        printf("2 - Remover funcionario\n");
        printf("3 - Buscar funcionario\n");
        printf("4 - Listar funcionarios\n");
        printf("5 - Salvar em arquivo\n");
        printf("6 - Carregar do arquivo\n");
        printf("7 - Trocar de lista\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
        }

        switch (opcao) {

            case 1:

                printf("\nID: ");
                scanf("%d", &f.id);

                printf("Nome (sem espacos): ");
                scanf("%s", f.nome);

                printf("Cargo (sem espacos): ");
                scanf("%s", f.cargo);

                printf("Salario: ");
                scanf("%f", &f.salario);

                if (tipo == 1) {
                    ok = lista_est_inserir(f);
                } else {
                    ok = lista_din_inserir(f);
                }

                if (ok) {
                    printf("\nFuncionario inserido com sucesso!\n");
                } else {
                    printf("\nErro: nao foi possivel inserir!\n");
                }

                break;

            case 2:

                printf("\nID do funcionario: ");
                scanf("%d", &id);

                if (tipo == 1) {
                    ok = lista_est_remover(id);
                } else {
                    ok = lista_din_remover(id);
                }

                if (ok) {
                    printf("\nFuncionario removido com sucesso!\n");
                } else {
                    printf("\nErro: funcionario nao encontrado!\n");
                }

                break;

            case 3:

                printf("\nID do funcionario: ");
                scanf("%d", &id);

                if (tipo == 1) {
                    ok = lista_est_buscar(id, &f);
                } else {
                    ok = lista_din_buscar(id, &f);
                }

                if (ok) {
                    printf("\n");
                    funcionario_imprimir(f);
                } else {
                    printf("\nErro: funcionario nao encontrado!\n");
                }

                break;

            case 4:

                if (tipo == 1) {
                    lista_est_imprimir();
                } else {
                    lista_din_imprimir();
                }

                break;

            case 5:

                if (tipo == 1) {
                    ok = lista_est_salvar();
                } else {
                    ok = lista_din_salvar();
                }

                if (ok) {
                    printf("\nDados salvos com sucesso!\n");
                } else {
                    printf("\nErro ao salvar o arquivo!\n");
                }

                break;

            case 6:

                if (tipo == 1) {
                    ok = lista_est_carregar();
                } else {
                    ok = lista_din_carregar();
                }

                if (ok) {
                    printf("\nDados carregados com sucesso!\n");
                } else {
                    printf("\nErro: arquivo nao encontrado!\n");
                }

                break;

            case 7:

                if (tipo == 1) {
                    tipo = 2;
                } else {
                    tipo = 1;
                }

                break;

            case 0:

                lista_est_destruir();
                lista_din_destruir();

                printf("\nPrograma encerrado!\n");

                break;

            default:

                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
