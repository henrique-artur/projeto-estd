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