#include "./include/livrosD.h"
#include <stdlib.h>

int main(void) {
  LivrosD *iniciol = NULL;

  iniciol = cadastrarLivros(iniciol);
  iniciol = cadastrarLivros(iniciol);

  imprimirLivros(iniciol);

  iniciol = excluirLivros(iniciol, 2);

  imprimirLivros(iniciol);

  return 0;
}