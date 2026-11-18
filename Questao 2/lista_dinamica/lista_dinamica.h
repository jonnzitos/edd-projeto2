#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include "../funcionario/funcionario.h"

void lista_din_criar();

int lista_din_vazia();

int lista_din_inserir(Funcionario f);
int lista_din_remover(int id);
int lista_din_buscar(int id, Funcionario *f);

void lista_din_imprimir();

int lista_din_salvar();
int lista_din_carregar();

void lista_din_destruir();

#endif
