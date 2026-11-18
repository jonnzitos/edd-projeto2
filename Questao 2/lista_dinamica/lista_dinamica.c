#include <stdio.h>
#include <stdlib.h>
#include "lista_dinamica.h"

typedef struct No {
    Funcionario dado;
    struct No *prox;
} No;

static No *inicio = NULL;
static int tamanho = 0;

void lista_din_criar() {
    inicio = NULL;
    tamanho = 0;
}

int lista_din_vazia() {
    return inicio == NULL;
}

int lista_din_inserir(Funcionario f) {
    No *novo = (No *) malloc(sizeof(No));
    No *aux;

    if (novo == NULL) {
        return 0;
    }

    novo->dado = f;
    novo->prox = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        aux = inicio;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = novo;
    }

    tamanho++;

    return 1;
}

int lista_din_remover(int id) {
    No *aux = inicio;
    No *anterior = NULL;

    while (aux != NULL && aux->dado.id != id) {
        anterior = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        inicio = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    free(aux);
    tamanho--;

    return 1;
}

int lista_din_buscar(int id, Funcionario *f) {
    No *aux = inicio;

    while (aux != NULL) {

        if (aux->dado.id == id) {
            *f = aux->dado;
            return 1;
        }

        aux = aux->prox;
    }

    return 0;
}

void lista_din_imprimir() {
    No *aux = inicio;

    if (lista_din_vazia()) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\n----- LISTA DINAMICA (%d) -----\n", tamanho);

    while (aux != NULL) {
        funcionario_imprimir(aux->dado);
        aux = aux->prox;
    }
}

int lista_din_salvar() {
    No *aux = inicio;
    FILE *arq = fopen("lista_dinamica.txt", "w");

    if (arq == NULL) {
        return 0;
    }

    while (aux != NULL) {
        fprintf(arq, "%d %s %s %f\n", aux->dado.id, aux->dado.nome, aux->dado.cargo, aux->dado.salario);
        aux = aux->prox;
    }

    fclose(arq);

    return 1;
}

int lista_din_carregar() {
    Funcionario f;
    FILE *arq = fopen("lista_dinamica.txt", "r");

    if (arq == NULL) {
        return 0;
    }

    lista_din_destruir();

    while (fscanf(arq, "%d %s %s %f", &f.id, f.nome, f.cargo, &f.salario) == 4) {
        lista_din_inserir(f);
    }

    fclose(arq);

    return 1;
}

void lista_din_destruir() {
    No *aux = inicio;
    No *proximo;

    while (aux != NULL) {
        proximo = aux->prox;
        free(aux);
        aux = proximo;
    }

    inicio = NULL;
    tamanho = 0;
}
