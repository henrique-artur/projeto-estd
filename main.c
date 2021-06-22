#include "./include/livrosD.h"
#include <stdlib.h>

int main(void) {
  LivrosD *iniciol = NULL;

  iniciol = cadastrarLivros(iniciol);

  imprimirLivros(iniciol);

  return 0;
}