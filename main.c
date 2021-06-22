#include "./include/livrosD.h"
#include <stdlib.h>

int main(void) {
  LivrosD *iniciol = NULL;

  iniciol = cadastrarLivros(iniciol, 10);
  iniciol = cadastrarLivros(iniciol, 12);
  iniciol = cadastrarLivros(iniciol, 14);
  iniciol = cadastrarLivros(iniciol, 16);

  imprimirLivros(iniciol);

  return 0;
}
