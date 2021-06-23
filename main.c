#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./include/livrosD.h"

int main() {
  LivrosD *iniciol = NULL;
  int op, codigo;

  setlocale(LC_ALL,""); // Permite acentuações

  do {
    printf("Bem-vindo(a) à sua loja de livros virtual.\n");
    printf("Bom dia, em que posso ajudar? \n");
    printf("| 1 - Cadastrar um livro\n");
    printf("| 2 - Excluir um livro\n");
    printf("| 3 - Consultar livros\n");
    printf("| 4 - Comprar livros\n");
    printf("| 0 - Sair\n");
    scanf("%d", &op);

    switch (op) {
      case 1:
        iniciol = cadastrarLivros(iniciol);
        break;
      case 2:
        printf("Informe o código do produto: \n");
        scanf("%d", &codigo);
        iniciol = excluirLivros(iniciol, codigo);
        break;
      case 3:
        imprimirLivros(iniciol);
        break;
      case 4:
        // iniciol = comprarLivros(iniciol);
        break;
      case 0:
        printf("Obrigado pela preferência\n");
        printf("Compras finalizadas!\n");
        break;
    }
  } while (op != 0);
  return 0;
}