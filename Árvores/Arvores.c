#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* 
Árvore com alocação dinâmica. ChatGPT gerou.
*/

// Definição do tipo de nó
typedef struct No {
    int elem;
    struct No *esq;
    struct No *dir;
} No;

// Definir uma árvore vazia (ponteiro NULL)
No* criarArvoreVazia() {
    return NULL;
}

// Criar nó raiz
No* criarRaiz(int valor) {
    No* raiz = (No*) malloc(sizeof(No));
    if (raiz != NULL) {
        raiz->elem = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    }
    return raiz;
}

// Verificar se árvore está vazia
int estaVazia(No* raiz) {
    return (raiz == NULL);
}

// Criar filho à esquerda de um nó
void criarFilhoEsquerda(No* pai, int valor) {
    if (pai != NULL && pai->esq == NULL) {
        pai->esq = criarRaiz(valor);
    }
}

// Criar filho à direita de um nó
void criarFilhoDireita(No* pai, int valor) {
    if (pai != NULL && pai->dir == NULL) {
        pai->dir = criarRaiz(valor);
    }
}

// Verificar nível de um nó (nível da raiz é 0)
int nivelDoNo(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->elem == valor) return nivel;

    int nivelEsq = nivelDoNo(raiz->esq, valor, nivel + 1);
    if (nivelEsq != -1) return nivelEsq;

    return nivelDoNo(raiz->dir, valor, nivel + 1);
}

// Retornar pai de um dado nó (retorna ponteiro). Essa não assimilei muito bem ainda.
No* encontrarPai(No* raiz, int valor) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL)) return NULL;

    if ((raiz->esq != NULL && raiz->esq->elem == valor) ||
        (raiz->dir != NULL && raiz->dir->elem == valor)) {
        return raiz;
    }

    No* paiEsq = encontrarPai(raiz->esq, valor);
    if (paiEsq != NULL) return paiEsq;

    return encontrarPai(raiz->dir, valor);
}

// Exibir árvore em pré-ordem
void imprimirPreOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->elem);
        imprimirPreOrdem(raiz->esq);
        imprimirPreOrdem(raiz->dir);
    }
}

// Liberar memória da árvore
void liberarArvore(No* raiz) {/* Lembrar da Torre de Hanói em ATP II */
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int altura(No* raiz){ /* Calcula altura da árvore binária. */
    if (raiz == NULL) return -1;
    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);
    return (altEsq > altDir ? altEsq : altDir) + 1; /* Aqui está pegando o valor máximo entre os dois INT e somando com 1. */
}

int nivelDoNo(No* raiz, int valor, int nivelAtual) { /* Retorna o nível do nó com determinado valor. */
    if (raiz == NULL) return -1;
    if (raiz->elem == valor) return nivelAtual;

    int nivelEsq = nivelDoNo(raiz->esq, valor, nivelAtual + 1);
    if (nivelEsq != -1) return nivelEsq;

    return nivelDoNo(raiz->dir, valor, nivelAtual + 1);
}

int estaBalanceada(No* raiz) { /* Verifica se está balanceada. Retorna 1 para caso esteja, e zero caso não esteja. */
    if (raiz == NULL) return 1;

    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);

    if (abs(altEsq - altDir) > 1) return 0;

    return estaBalanceada(raiz->esq) && estaBalanceada(raiz->dir); /* Se os dois forem verdade, irá retornar 1. */
}

int estaPerfeitamenteBalanceada(No* raiz) { /* Verifica se está perfeitamente balanceada. Retorna 1 pra verdadeiro e zero pra falso. */
    if (raiz == NULL) return 1;

    int altEsq = altura(raiz->esq);
    int altDir = altura(raiz->dir);

    if (altEsq != altDir) return 0;

    return estaPerfeitamenteBalanceada(raiz->esq) && estaPerfeitamenteBalanceada(raiz->dir);
}

int ehEstritamenteBinaria(No* raiz) { /* Verifica se é estritamente binária. */
    if (raiz == NULL) return 1;

    if (raiz->esq == NULL && raiz->dir == NULL) return 1;

    if (raiz->esq != NULL && raiz->dir != NULL)
        return ehEstritamenteBinaria(raiz->esq) && ehEstritamenteBinaria(raiz->dir); /* Vai verificar os nós filhos, na esquerda e direita. Caso tudo dê certo, retornará 1 dentro do IF. Se não, nem entra no IF e retorna zero ao fim. */

    return 0;
}

// Exemplo de uso
// ... (código anterior continua igual)

int main() {
    No* raiz = criarRaiz(10);

    criarFilhoEsquerda(raiz, 5);
    criarFilhoDireita(raiz, 20);

    criarFilhoEsquerda(raiz->esq, 3);
    criarFilhoDireita(raiz->esq, 7);

    // Arvore atual:
    //         10
    //       /    \
    //      5      20
    //     / \
    //    3   7

    printf("Arvore em pre-ordem: ");
    imprimirPreOrdem(raiz);
    printf("\n");

    int valor = 7;
    int nivel = nivelDoNo(raiz, valor, 0);
    printf("Nivel do no %d: %d\n", valor, nivel);

    No* pai = encontrarPai(raiz, valor);
    if (pai != NULL)
        printf("Pai do no %d: %d\n", valor, pai->elem);
    else
        printf("Pai nao encontrado.\n");

    printf("A arvore %s vazia.\n", estaVazia(raiz) ? "esta" : "nao esta");

    // --------- Testes adicionados ----------
    printf("Altura da arvore: %d\n", altura(raiz));

    printf("A arvore %s balanceada.\n", estaBalanceada(raiz) ? "esta" : "nao esta");

    printf("A arvore %s perfeitamente balanceada.\n", estaPerfeitamenteBalanceada(raiz) ? "esta" : "nao esta");

    printf("A arvore %s estritamente binaria.\n", ehEstritamenteBinaria(raiz) ? "e" : "nao e");

    // ---------------------------------------

    liberarArvore(raiz);
    return 0;
}
