#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include "../funcionario/funcionario.h"

#define MAX_EST 100

void lista_est_criar();

int lista_est_vazia();
int lista_est_cheia();

int lista_est_inserir(Funcionario f);
int lista_est_remover(int id);
int lista_est_buscar(int id, Funcionario *f);

void lista_est_imprimir();

int lista_est_salvar();
int lista_est_carregar();

void lista_est_destruir();

#endif
