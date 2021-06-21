#include "livrosD.h"
#include <stdlib.h>

int main(void) {
  LivrosD *iniciol = NULL;

  iniciol = inserirLivros(iniciol, 10);
  iniciol = inserirLivros(iniciol, 12);
  iniciol = inserirLivros(iniciol, 14);
  iniciol = inserirLivros(iniciol, 16);

  imprimirLivros(iniciol);

  return 0;
}
