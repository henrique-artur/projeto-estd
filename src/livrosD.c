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

/*
	l = NULL;
	l = inserid(l, 10); 12 10 NULL
	l = inserird(l, 12); 14 12 10
	l = inserird(l, 14); 15 14 12
	l = inserird(l, 15); NULL 15 14
*/

void imprimirLivros(LivrosD *l){
  LivrosD *aux = l;
	/*
		char titulo[50];
		char autor[30];
		char genero[20];
		int codigo;
		float preco;
		int estoque;
		char editora[15];
	*/
  while (aux != NULL){
		int counter = 1;
		printf("\n--------------------------------------\n");
		printf("\nLivro %d\n", counter);
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
