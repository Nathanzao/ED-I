#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 10

/* Fila circular. A parte do "% MAX", garante que quando o valor chegue à 10, retorne zero e portanto volte ao inicio.
Veja que cada numero % 10, de 1 ate 9, ira dar ele mesmo. Por isso, nao altera a conta. */

struct fila {
    int vFila[MAX];
    int inicio;
    int final;
};

void inicializa(struct fila *f) {
    f->inicio = 0;
    f->final = 0;
}

int verificaVazia(struct fila *f) {
    return f->inicio == f->final;
}

int verificaCheia(struct fila *f) {
    return (f->final + 1) % MAX == f->inicio;
}

void inserir(struct fila *f, int elemento) {
    if (verificaCheia(f)) {
        printf("Fila esta cheia.\n");
    } else {
        f->vFila[f->final] = elemento;
        f->final = (f->final + 1) % MAX;
    }
}

void removerDoInicio(struct fila *f) {
    if (verificaVazia(f)) {
        printf("Fila esta vazia.\n");
    } else {
        f->inicio = (f->inicio + 1) % MAX;
    }
}

void remover2(struct fila *f, int *elemento) {
    if (verificaVazia(f)) {
        printf("Fila esta vazia.\n");
    } else {
        *elemento = f->vFila[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
    }
}

void obterInicioFila(struct fila *f, int *elem) {
    if (verificaVazia(f)) {
        printf("Fila esta vazia.\n");
    } else {
        *elem = f->vFila[f->inicio];
    }
}

void imprimirFila(struct fila *f){
    printf("Conteudo da fila:\n");
    int i = f->inicio;
    while (i != f->final) {
        printf("%d ", f->vFila[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {

    struct fila f;
    inicializa(&f);
    int inicio;

    for (int i = 1; i <= 11; i++) {
        inserir(&f, i); // O 11o elemento nao deve ser inserido
    }

    obterInicioFila(&f, &inicio);
    printf("Inicio da fila: %d\n", inicio);

    remover2(&f, &inicio);
    printf("Removido: %d\n", inicio);

    printf("Conteudo da fila apos remocao:\n");
    
    imprimirFila(&f);

    return 0;
}
