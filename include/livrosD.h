/*
	título, autor, gênero, código, preço, quantidade em estoque e editora.
*/
struct livrosd {
	char titulo[50];
	char autor[30];
	int codigo;
	char genero[20];
	float preco;
	int quantidade;
	char editora[15];
  struct livrosd *prox;
};
typedef struct livrosd LivrosD;

struct livrosd2 {
	int codigo;
	int quantidade;
	struct livrosd2 *prox, *ant;
};
typedef struct livrosd2 LivrosD2;

/*
	cadastrar, excluir, consultar e comprar livros.
*/

// Inserir livros no final da lista
LivrosD* cadastrarLivros(LivrosD *l);
// Excluir o livro numa posição específica
LivrosD* excluirLivros(LivrosD *l);
// Imprimir no console a lista de livros
void consultarLivros(LivrosD *l);
