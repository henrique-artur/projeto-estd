#include <stdio.h>
#include <stdlib.h>
#include "livrosD.h"

LivrosD* cadastrarLivros(LivrosD *l, int numero){
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

LivrosD2* excluirLivros(LivrosD2 *l, LivrosD2 codigo) {
	LivrosD2* aux = (LivrosD2*)malloc(sizeof(LivrosD2));
	
	// Procurar o elemento
	// 
}



void imprimirLivros(LivrosD *l){
  LivrosD *aux = l;
	LivrosD2 *a = (LivrosD2*)malloc(sizeof(LivrosD2));
	int counter = 1;

  while (aux != NULL){
		printf("\n--------------------------------------\n");
		printf("\nLivro %d\n", counter);
    printf("Titulo = %s\n", aux->titulo);
		printf("Autor = %s\n", aux->autor);
		printf("Genero = %s\n", aux->genero);
		printf("Codigo = %d\n", a->codigo);
		printf("Preco = %.2f\n", aux->preco);
		printf("Editora = %s\n", aux->editora);
		printf("\nEstoque do livro %d = %d\n", counter, a->quantidade);
		printf("\n--------------------------------------\n");
		
		counter++;
    aux = aux->prox;
  }
}
