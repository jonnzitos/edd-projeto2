#include <stdio.h>
#include "lista_estatica.h"

static Funcionario lista[MAX_EST];
static int tamanho = 0;

void lista_est_criar() {
    tamanho = 0;
}

int lista_est_vazia() {
    return tamanho == 0;
}

int lista_est_cheia() {
    return tamanho == MAX_EST;
}

int lista_est_inserir(Funcionario f) {

    if (lista_est_cheia()) {
        return 0;
    }

    lista[tamanho] = f;
    tamanho++;

    return 1;
}

int lista_est_remover(int id) {
    int i, j;

    for (i = 0; i < tamanho; i++) {

        if (lista[i].id == id) {

            for (j = i; j < tamanho - 1; j++) {
                lista[j] = lista[j + 1];
            }

            tamanho--;

            return 1;
        }
    }

    return 0;
}

int lista_est_buscar(int id, Funcionario *f) {
    int i;

    for (i = 0; i < tamanho; i++) {

        if (lista[i].id == id) {
            *f = lista[i];
            return 1;
        }
    }

    return 0;
}

void lista_est_imprimir() {
    int i;

    if (lista_est_vazia()) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\n----- LISTA ESTATICA (%d/%d) -----\n", tamanho, MAX_EST);

    for (i = 0; i < tamanho; i++) {
        funcionario_imprimir(lista[i]);
    }
}

int lista_est_salvar() {
    int i;
    FILE *arq = fopen("lista_estatica.txt", "w");

    if (arq == NULL) {
        return 0;
    }

    for (i = 0; i < tamanho; i++) {
        fprintf(arq, "%d %s %s %f\n", lista[i].id, lista[i].nome, lista[i].cargo, lista[i].salario);
    }

    fclose(arq);

    return 1;
}

int lista_est_carregar() {
    Funcionario f;
    FILE *arq = fopen("lista_estatica.txt", "r");

    if (arq == NULL) {
        return 0;
    }

    tamanho = 0;

    while (fscanf(arq, "%d %s %s %f", &f.id, f.nome, f.cargo, &f.salario) == 4) {
        lista_est_inserir(f);
    }

    fclose(arq);

    return 1;
}

void lista_est_destruir() {
    tamanho = 0;
}
