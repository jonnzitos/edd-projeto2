#include <stdio.h>
#include "funcionario.h"

void funcionario_imprimir(Funcionario f) {
    printf("ID: %d | Nome: %s | Cargo: %s | Salario: %.2f\n", f.id, f.nome, f.cargo, f.salario);
}
