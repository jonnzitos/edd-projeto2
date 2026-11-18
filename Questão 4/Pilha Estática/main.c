#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void limpar(void) {
    system("cls");
}

void pause_menu(void) {
    system("pause");
}

int eh_numero(char *s) {

    int i = 0;
    int pontos = 0;
    int digitos = 0;

    if (s[0] == '-') {
        i = 1;
    }

    while (s[i] != '\0') {

        if (s[i] >= '0' && s[i] <= '9') {
            digitos++;
        } else if (s[i] == '.') {
            pontos++;
        } else {
            return 0;
        }

        i++;
    }

    return digitos > 0 && pontos <= 1;
}

void calcular_expressao() {

    char token[50];
    float a, b, resultado;
    int erro = 0;
    int tam;

    pilha_criar();

    printf("\nDigite os numeros e operadores separados por espaco e termine com =\n");
    printf("Exemplo: 1 2 3 * + 4 - =\n");
    printf("\nExpressao: ");

    while (scanf("%49s", token) == 1 && strcmp(token, "=") != 0) {

        tam = strlen(token);

        if (token[tam - 1] == ',') {
            token[tam - 1] = '\0';
            tam--;
        }

        if (erro == 1 || tam == 0) {
            continue;
        }

        if (eh_numero(token)) {

            if (!pilha_push(atof(token))) {
                printf("\nErro: pilha cheia!\n");
                erro = 1;
            }

        } else if (tam == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {

            if (!pilha_pop(&b) || !pilha_pop(&a)) {
                printf("\nErro: faltam operandos para o operador %c!\n", token[0]);
                erro = 1;
            } else if (token[0] == '+') {
                pilha_push(a + b);
            } else if (token[0] == '-') {
                pilha_push(a - b);
            } else if (token[0] == '*') {
                pilha_push(a * b);
            } else if (b == 0) {
                printf("\nErro: divisao por zero!\n");
                erro = 1;
            } else {
                pilha_push(a / b);
            }

        } else {
            printf("\nErro: simbolo invalido \"%s\"!\n", token);
            erro = 1;
        }
    }

    if (erro == 0) {

        if (!pilha_pop(&resultado)) {
            printf("\nErro: expressao vazia!\n");
        } else if (!pilha_vazia()) {
            printf("\nErro: sobraram operandos, faltam operadores!\n");
        } else {
            printf("\nResultado: %.2f\n", resultado);
        }
    }

    pilha_destruir();
}

int main() {

    int opcao;

    do {

        limpar();

        printf("\n===== CALCULADORA NPI =====\n");
        printf("1 - Calcular expressao NPI\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");

        if (scanf("%d", &opcao) != 1) {
            opcao = 0;
        }

        switch (opcao) {

            case 1:

                calcular_expressao();

                break;

            case 0:

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