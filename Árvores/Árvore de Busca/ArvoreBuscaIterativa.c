#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Iremos fazer as funções sem recursão nesse arquivo.
*/

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void inserirIter(No* raiz, int valor) {
    No* novo = criarNo(valor);

    No* atual = raiz;
    No* pai = NULL;

    while (atual != NULL) {
        pai = atual;
        if (valor < atual->valor)
            atual = atual->esq;
        else if (valor > atual->valor)
            atual = atual->dir;
        else {
            free(novo); // Valor duplicado, não insere
            return;
        }
    }

    if (valor < pai->valor)
        pai->esq = novo;
    else
        pai->dir = novo;
}

No* buscaIter(No* raiz, int valorDesejado){
    No *p = raiz;
    while(p != NULL){
        if(p->valor == valorDesejado){
            return p;
        }
        if(valorDesejado > p->valor){
            p = p->dir;
        }else{
            p = p->esq;
        }
    }
    return NULL;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    // Raiz declarada como variável (não ponteiro)
    No raiz;
    raiz.valor = 40;
    raiz.esq = NULL;
    raiz.dir = NULL;

    // Inserções manuais
    inserirIter(&raiz, 20);
    inserirIter(&raiz, 60);
    inserirIter(&raiz, 10);
    inserirIter(&raiz, 30);
    inserirIter(&raiz, 50);
    inserirIter(&raiz, 70);

    printf("Elementos em ordem: ");
    imprimirEmOrdem(&raiz);
    printf("\n");

    int buscar[] = {10, 25, 70};
    for (int i = 0; i < 3; i++) {
        No* resultado = buscaIter(&raiz, buscar[i]);
        if (resultado != NULL)
            printf("Valor %d encontrado.\n", buscar[i]);
        else
            printf("Valor %d NAO encontrado.\n", buscar[i]);
    }

    liberarArvore(raiz.esq);
    liberarArvore(raiz.dir);

    return 0;
}