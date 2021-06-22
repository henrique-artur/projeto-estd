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
	int estoque;
  struct livrosd2 *prox, *ant;
};

LivrosD* cadastrarLivros(LivrosD *l){
  LivrosD *aux = (LivrosD*)malloc(sizeof(LivrosD));
	
	printf("Nome do livro: ");
	fgets(aux->titulo, 50, stdin);
	
	printf("Nome do autor: ");
	fgets(aux->autor, 30, stdin);
	
	printf("Nome do genero: ");
	fgets(aux->genero, 20, stdin);
	
	printf("Nome da editora: ");
	fgets(aux->editora, 15, stdin);

	printf("Codigo do livro: ");
	scanf("%d", &aux->codigo);

	printf("Preco do livro: ");
	scanf("%f", &aux->preco);
	
	printf("Estoque do livro: ");
	scanf("%d", &aux->estoque);

	setbuf(stdin, NULL);

	aux->prox = l;
  
  return aux;
}

LivrosD* excluirLivros(LivrosD *l, int codigo) {
	

	if(l == NULL) {
		printf("Lista vazia\n");
		return l;
	} else {
		LivrosD *aux = l;

		if(l->codigo == codigo) {
			printf("Valor foi encontrado\n");
			return l->prox;
		}

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

  while (aux != NULL){
		printf("\nLivro %d\n", counter);
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