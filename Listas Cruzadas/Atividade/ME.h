#define COLUNA 5
#define LINHA 5

struct no{
    int valor, linha, coluna;
    struct no *direita;
    struct no *abaixo;
};

struct matriz{
    struct no *linha[LINHA];
    struct no *coluna[COLUNA];
};


void inicializar(struct matriz *p);
void insere(struct matriz *p, int linha, int coluna, int valor);
void imprime(struct matriz *pp);
int somaLinha(struct no *p, int linha, int valor);