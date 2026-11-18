#ifndef FILA_H
#define FILA_H

#define DIRETOR 1
#define COORDENADOR 2
#define FUNCIONARIO 3

typedef struct {
    char usuario[50];
    char documento[50];
    int prioridade;
} Pedido;

void fila_criar();

int fila_vazia();
int fila_cheia();

int fila_enfileirar(Pedido pedido);

int fila_desenfileirar(Pedido *pedido);

void fila_imprimir();

void fila_destruir();

void nome_cargo(int prioridade, char *destino);

#endif