#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Iremos fazer as funções com recursão nesse arquivo.
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

No* inserirRec(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor); /* Só vai criar 1 vez. */

    if (valor < raiz->valor)
        raiz->esq = inserirRec(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserirRec(raiz->dir, valor);

    return raiz; // retorna a raiz (inalterada ou atualizada). Retorna ela porque será a partir dela que iremos navegar nos nós.
}

No* buscarRec(No* raiz, int valorDesejado){
    if(raiz->valor == valorDesejado){ /* Achou. */
        return raiz;
    }

    if(raiz == NULL){ /* Procurou na arvore e não achou. */
        return raiz;
    }

    if(valorDesejado > raiz->valor){
        return buscarRec(raiz->dir, valorDesejado);
    }else{
        return buscarRec(raiz->esq, valorDesejado);
    }

    return raiz;
}

void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main () {
    setlocale(LC_ALL, "Portuguese");

    No* raiz = NULL;

    // Inserção de elementos
    int valores[] = {20, 10, 30, 5, 15, 25, 35};
    int tamanho = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < tamanho; i++) {
        raiz = inserirRec(raiz, valores[i]);
    }

    // Exibir a árvore em pré-ordem
    printf("Árvore em pré-ordem: ");
    imprimirPreOrdem(raiz);
    printf("\n");

    // Teste de busca
    int buscas[] = {15, 100, 5, 22}; // 15 e 5 existem, 100 e 22 não
    int numBuscas = sizeof(buscas) / sizeof(buscas[0]);

    for (int i = 0; i < numBuscas; i++) {
        int valor = buscas[i];
        No* encontrado = buscarRec(raiz, valor);

        if (encontrado != NULL)
            printf("Valor %d encontrado na árvore.\n", valor);
        else
            printf("Valor %d NÂO encontrado na árvore.\n", valor);
    }

    // Liberação de memória
    liberarArvore(raiz);

    return 0;
}
