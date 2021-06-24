#include <stdio.h>
#include <stdlib.h>
#include "../include/livrosD.h"

struct livrosd {
	char titulo[50];
	char autor[30];
	char genero[20];
	int codigo;
	float preco;
	int estoque;
	char editora[15];
  struct livrosd *prox;
};

struct livrosd2 {
	int codigo;
	int quantidade;
  struct livrosd2 *prox, *ant;
};

LivrosD* cadastrarLivros(LivrosD *l){
  LivrosD *aux = (LivrosD*)malloc(sizeof(LivrosD));
	
	printf("Nome do livro: ");
	scanf(" %[^\t\n]s", aux->titulo); // Lê a string com espaços e tabulações
	setbuf(stdin, NULL);
	
	printf("Nome do autor: ");
	scanf(" %[^\t\n]s", aux->autor);
	setbuf(stdin, NULL);

	printf("Nome do genero: ");
	scanf(" %[^\t\n]s", aux->genero);
	setbuf(stdin, NULL);

	printf("Nome da editora: ");
	scanf(" %[^\t\n]s", aux->editora);
	setbuf(stdin, NULL);

	printf("Codigo do livro: ");
	scanf("%d", &aux->codigo);

	printf("Preco do livro: ");
	scanf("%f", &aux->preco);
	
	printf("Estoque do livro: ");
	scanf("%d", &aux->estoque);

	LivrosD *aux2;

	aux2 = l;
	// Ordenando os livros na lista
	if (aux2 == NULL) {
		aux->prox = aux2;

		return aux;
	}
	else {
		if (aux2->codigo > aux->codigo) {
			aux->prox = aux2;

			return aux;
		}

		while (aux2->prox != NULL) {
			if ((aux2->prox)->codigo > aux->codigo) {
				aux->prox = aux2->prox;
				aux2->prox = aux;

				return l;
			}

			aux2 = aux2->prox;
		}

		aux2->prox = aux;

		return l;
	}
}

LivrosD* excluirLivros(LivrosD *l, int codigo) {
	if (l == NULL) {
		printf("Lista vazia\n");
		return l;
	} else {
		if (l->codigo == codigo) {
			printf("Valor foi encontrado no inicio da lista\n");
			return l->prox;
		}

		LivrosD *aux = l;

		for (aux = l; aux->prox != NULL; aux = aux->prox) {
    	if ((aux->prox)->codigo == codigo) {
				printf("Codigo do livro excluido = %d\n", (aux->prox)->codigo);
			
				LivrosD *local;
				local = (aux->prox)->prox;
				aux->prox = local;
				
				return l;
    	}
  	}

		printf("Elemento não encontrado!\n");

  	return l;
	}
}

void imprimirLivros(LivrosD *l) {
  LivrosD *aux = l;
	int counter = 1;

	if (l == NULL){
		printf("Lista vazia!\n");
		return;
	}

  while (aux != NULL){
		printf("\nLivro %d", counter);
		printf("\n--------------------------------------\n");
    printf("Titulo = %s\n", aux->titulo);
		printf("Autor = %s\n", aux->autor);
		printf("Genero = %s\n", aux->genero);
		printf("Codigo = %d\n", aux->codigo);
		printf("Preco = %.2f\n", aux->preco);
		printf("Editora = %s\n", aux->editora);
		printf("\nEstoque do livro %d = %d\n", counter, aux->estoque);
		printf("\n--------------------------------------\n");
		
		counter++;
    aux = aux->prox;
  }
}

LivrosD* comprarLivro(LivrosD *l, LivrosD2 *l2, int codigo, int qtd) {
	if (l == NULL){
		printf("Não há livros no acervo!\n");
		return l;
	}
	
	LivrosD *aux = l;

	while (aux != NULL){
		if (aux->codigo == codigo){
			aux->estoque -= qtd;
			
			printf("Valor da compra: %.2f\n", aux->preco*qtd);

			return l;
		}

		aux = aux->prox;
	}

	printf("Livro nao encontrado\n");

	return l;
}

LivrosD2* foraDeEstoque(LivrosD2 *l2, LivrosD *l, int codigo, int qtd) {
	LivrosD *aux = l;
	
	if(aux == NULL){
		printf("Não há livros no acervo!\n");
		return l2;
	}
	
	int qtdForaEstoque = 0;
	
	while (aux != NULL) {
		if (aux->codigo == codigo) {
			qtdForaEstoque = qtd - aux->estoque;
			break;
		}
		aux = aux->prox;
	}

	while (l2 != NULL){
		if (l2->codigo == codigo) {
			l2->quantidade += qtdForaEstoque;
			return l2;
		}

		l2 = l2->prox;
	}

	l2 = livroEsgotado(l2, codigo, qtdForaEstoque);

	return l2;
}

LivrosD2* livroEsgotado(LivrosD2 *l2, int codigo, int qtd) {
	LivrosD2 *novo = (LivrosD2*)malloc(sizeof(LivrosD2));

	novo->codigo = codigo;
	novo->quantidade = qtd;
	novo->prox = l2;
	novo->ant = NULL;

	if (l2 != NULL) 
		l2->ant = novo;
		
	return novo;
}

int temEstoque(LivrosD *l, int codigo, int qtd) {
	LivrosD *aux = l;

	while (aux != NULL) {
		if (aux->codigo == codigo) {
			if (qtd > aux->estoque) 
				return 0;
			else 
				return 1;
		}

		aux = aux->prox;
	}
}

void imprimirForaEstoque(LivrosD2 *l2) {
	LivrosD2 *aux = l2;

	if (aux == NULL) {
		printf("Não há livros no acervo!\n");
		return;
	}
	
	printf("\nFora de estoque \n");
	while (aux != NULL){
		printf("Codigo: %d\n", aux->codigo);
		printf("Quantidade: %d\n", aux->quantidade);

		aux = aux->prox;
	}
}
