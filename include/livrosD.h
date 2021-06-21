/*
	título, autor, gênero, código, preço, quantidade em estoque e editora.
*/
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
typedef struct livrosd LivrosD;

// Inserir livros no final da lista
LivrosD* inserirLivros(LivrosD *l, int valor);
// Imprimir no console a lista de livros
void imprimirLivros(LivrosD *l);
