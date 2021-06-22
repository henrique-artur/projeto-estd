#include <stdio.h>
#include <stdlib.h>
#include "../include/livrosD.h"

LivrosD* cadastrarLivros(LivrosD *l, int numero){
  LivrosD* aux = (LivrosD*)malloc(sizeof(LivrosD));
	// Em construção
  return aux;
}

LivrosD* excluirLivros(LivrosD *l, int codigo) {
	LivrosD *aux = l;
  
  while (aux != NULL) {
    if (aux->codigo == codigo) {
			printf("Codigo do livro excluido = %d", aux->codigo);
			
			free(aux);
      
      return 1;
    }
		else {
			printf("Elemento não encontrado!");
		}
    
    aux = aux->prox;
  }

  return 0;
}



void imprimirLivros(LivrosD *l) {
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
