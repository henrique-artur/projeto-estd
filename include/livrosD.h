#include <stdio.h>
#include <stdlib.h>

typedef struct livrosd LivrosD;
typedef struct livrosd2 LivrosD2;

// Inserir livros no final da lista
LivrosD* cadastrarLivros(LivrosD *l);
// Excluir o livro numa posição específica
LivrosD* excluirLivros(LivrosD *l, int codigo);
// Imprimir no console a lista de livros
void imprimirLivros(LivrosD *l);
// Comprar livro e subtrair no estoque  
LivrosD* comprarLivro(LivrosD *l, LivrosD2 *l2, int codigo, int qtd);
// Livros fora de estoque
LivrosD2* foraDeEstoque(LivrosD2 *l2, LivrosD *l, int codigo, int qtd);
// Verificar se os livros suprem a demanda
int temEstoque(LivrosD *l, int codigo, int qtd);
// Cria um novo elemento na lista duplamente encadeada
LivrosD2* livroEsgotado(LivrosD2 *l2, int codigo, int qtd);
// Exibir livros fora de estoque
void imprimirForaEstoque(LivrosD2 *l2);