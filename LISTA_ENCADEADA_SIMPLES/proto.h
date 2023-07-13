typedef struct pessoa Pessoa;
Pessoa *inserirPessoaInicio(Pessoa *lista);
Pessoa *inserirPessoaFim(Pessoa *lista);
Pessoa *inserirPessoaOrdenado(Pessoa *lista); //utilizar a idade para inserir em ordem crescente

void mostrarPessoa(Pessoa p);
void mostrarTodasPessoas(Pessoa *lista);
int contrarPessoasNaLista(Pessoa *lista);
void buscarPessoa(Pessoa *lista, int op);
Pessoa *removerPessoa(Pessoa *lista);
void liberar(Pessoa *lista);
