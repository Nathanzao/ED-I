/*
6. Implemente  o  TAD  Fila,  seguindo  o  esquema  de  uma  fila  dinâmica  simplesmente  encadeada 
circular. Nesta Fila o último elemento aponta para o primeiro elemento. Apresente a definição do tipo 
de dado e a implementação das funções inserção, remoção, criação da fila, fila vazia e primeiro elemento 
da fila.
*/

struct noFila{
    int valor;
    struct noFila *prox;
};

struct Fila{
    struct noFila *inicio;
    struct noFila *fim;
};

void criarFila(struct Fila *f);
int filaVazia(struct Fila *f);
void enfileirar(struct Fila *f, int valor);
int desenfileirar(struct Fila *f, int *removido);
void liberarFila(struct Fila *f);
void imprimir(struct Fila *f);
int primeiroElemento(struct Fila *f, int *valor);