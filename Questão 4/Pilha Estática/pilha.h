#ifndef PILHA_H
#define PILHA_H

void pilha_criar();

int pilha_vazia();
int pilha_cheia();

int pilha_push(float valor);

int pilha_pop(float *valor);

int pilha_consultar(float *valor);

void pilha_destruir();

#endif