#include <stdio.h>
#include <stdlib.h>

/*
	título, autor, gênero, código, preço, quantidade em estoque e editora.
*/
typedef struct livrosd LivrosD;
typedef struct livrosd2 LivrosD2;

// Inserir livros no final da lista
LivrosD* cadastrarLivros(LivrosD *l); 
// Imprimir no console a lista de livros
void imprimirLivros(LivrosD *l); 
