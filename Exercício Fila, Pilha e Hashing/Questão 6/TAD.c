#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "TAD.h"

void criarFila(struct Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(struct Fila *f) {
    return (f->inicio == NULL);
}

int verificaCheia(); /* Não terá função pois não há limite na pilha (a não ser pela falta de memória.) */

void enfileirar(struct Fila *f, int valor) { /* A parte mais confusa é o fato do inicio haver proximo. Para entender, simule as 3 primeiras inserções. */
    struct noFila *novo = malloc(sizeof(struct noFila));
    novo->valor = valor;

    if (filaVazia(f)) {
        novo->prox = novo; // Aponta para ele mesmo
        f->inicio = novo;
        f->fim = novo;
    } else {
        novo->prox = f->inicio;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int desenfileirar(struct Fila *f, int *removido) {
    if (filaVazia(f)) {
        return 0; // Falha, fila vazia
    }

    struct noFila *aux = f->inicio;
    *removido = aux->valor;

    if (f->inicio == f->fim) {
        f->inicio = NULL;
        f->fim = NULL;
    } else {
        f->inicio = aux->prox;
        f->fim->prox = f->inicio;
    }

    free(aux);
    return 1; // Sucesso
}

void liberarFila(struct Fila *f){
    struct noFila *p = f->inicio;

    while(p != NULL){
        struct noFila *aux = p;
        p = p->prox;
        free(aux);
    }
}

void imprimir(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    struct noFila *aux = f->inicio;
    do {
        printf("%d ", aux->valor);
        aux = aux->prox;
    } while (aux != f->inicio);
    printf("\n");
}

int primeiroElemento(struct Fila *f, int *valor) {
    if (filaVazia(f)) {
        return 0;
    }

    *valor = f->inicio->valor;
    return 1;
}