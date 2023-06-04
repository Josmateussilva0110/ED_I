typedef struct pessoa Pessoa; 
Pessoa *add_pessoa();
void mostrar_pessoas(Pessoa *p, int t);
void seach_people(Pessoa *p, float height, int t);
void remover_pessoa(Pessoa *p, int *tamanho, const char *nome);
