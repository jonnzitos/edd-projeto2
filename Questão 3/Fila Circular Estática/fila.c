#include <stdio.h>
#include <string.h>
#include "fila.h"

#define MAX 10

static Pedido fila[MAX];
static int inicio = 0;
static int fim = 0;
static int quantidade = 0;

void fila_criar() {
    inicio = 0;
    fim = 0;
    quantidade = 0;
}

int fila_vazia() {
    return quantidade == 0;
}

int fila_cheia() {
    return quantidade == MAX;
}

int fila_enfileirar(Pedido pedido) {

    if (fila_cheia()) {
        return 0;
    }

    int i = quantidade;

    while (i > 0 && fila[(inicio + i - 1) % MAX].prioridade > pedido.prioridade) {
        fila[(inicio + i) % MAX] = fila[(inicio + i - 1) % MAX];
        i--;
    }

    fila[(inicio + i) % MAX] = pedido;

    quantidade++;

    fim = (inicio + quantidade) % MAX;

    return 1;
}

int fila_desenfileirar(Pedido *pedido) {

    if (fila_vazia()) {
        return 0;
    }

    *pedido = fila[inicio];

    inicio = (inicio + 1) % MAX;

    quantidade--;

    return 1;
}

void fila_imprimir() {

    char cargo[20];
    int i;

    if (fila_vazia()) {
        printf("\nA fila de impressao esta vazia!\n");
        return;
    }

    printf("\n----- FILA DE IMPRESSAO (%d/%d) -----\n", quantidade, MAX);

    for (i = 0; i < quantidade; i++) {
        Pedido pedido = fila[(inicio + i) % MAX];

        nome_cargo(pedido.prioridade, cargo);

        printf("%d) [%s] %s - documento: %s\n", i + 1, cargo, pedido.usuario, pedido.documento);
    }
}

void fila_destruir() {
    inicio = 0;
    fim = 0;
    quantidade = 0;
}

void nome_cargo(int prioridade, char *destino) {

    if (prioridade == DIRETOR) {
        strcpy(destino, "Diretor");
    } else if (prioridade == COORDENADOR) {
        strcpy(destino, "Coordenador");
    } else if (prioridade == FUNCIONARIO) {
        strcpy(destino, "Funcionario");
    } else {
        strcpy(destino, "Desconhecido");
    }
}