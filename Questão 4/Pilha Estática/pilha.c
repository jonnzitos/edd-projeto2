#include <stdio.h>
#include "pilha.h"

#define MAX 50

static float pilha[MAX];
static int topo = -1;

void pilha_criar() {
    topo = -1;
}

int pilha_vazia() {
    return topo == -1;
}

int pilha_cheia() {
    return topo == MAX - 1;
}

int pilha_push(float valor) {

    if (pilha_cheia()) {
        return 0;
    }

    topo++;

    pilha[topo] = valor;

    return 1;
}

int pilha_pop(float *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    *valor = pilha[topo];

    topo--;

    return 1;
}

int pilha_consultar(float *valor) {

    if (pilha_vazia()) {
        return 0;
    }

    *valor = pilha[topo];

    return 1;
}

void pilha_destruir() {
    topo = -1;
}