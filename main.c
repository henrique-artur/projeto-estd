#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./include/livrosD.h"

int main() {
  LivrosD *iniciol = NULL;
  LivrosD2 *iniciol2 = NULL;
  int op, codigo, qtd;

  setlocale(LC_ALL,""); // Permite acentuações

  do {
    printf("Bem-vindo(a) à sua loja de livros virtual.\n");
    printf("Bom dia, em que posso ajudar? \n");
    printf("| 1 - Cadastrar um livro\n");
    printf("| 2 - Excluir um livro\n");
    printf("| 3 - Consultar livros\n");
    printf("| 4 - Comprar livros\n");
    printf("| 5 - Limpar tela\n");
    printf("| 0 - Sair\n");
    scanf("%d", &op);

    switch (op) {
      case 1:
        iniciol = cadastrarLivros(iniciol);
        break;
      case 2:
        printf("Informe o código do produto: ");
        scanf("%d", &codigo);
        iniciol = excluirLivros(iniciol, codigo);
        break;
      case 3:
        imprimirLivros(iniciol);
        break;
      case 4:
        printf("Informe o código do produto: ");
        scanf("%d", &codigo);
        printf("Informe a quantidade do pedido: ");
        scanf("%d", &qtd);
        if(temEstoque(iniciol, codigo, qtd)){
          iniciol = comprarLivro(iniciol, iniciol2, codigo, qtd);
        } else {
          iniciol2 = foraDeEstoque(iniciol2, iniciol, codigo, qtd);
          imprimirForaEstoque(iniciol2);
        }
        break;
      case 5:
        system("clear");
        break;
      case 0:
        printf("Obrigado pela preferência\n");
        printf("Compras finalizadas!\n");
        break;
      default : 
        printf("Opcao invalida!\n");
        break;
    }
  } while (op != 0);
  return 0;
}