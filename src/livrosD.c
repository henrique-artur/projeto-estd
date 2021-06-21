#include <stdio.h>
#include <stdlib.h>
#include "livrosD.h"

LivrosD* inserirLivros(LivrosD *l, int numero){
  LivrosD* aux = (LivrosD*)malloc(sizeof(LivrosD));
	// Em construção
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
