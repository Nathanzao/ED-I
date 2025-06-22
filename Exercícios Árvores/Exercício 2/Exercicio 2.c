#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
2. Escreva uma função recursiva que conta o número de folhas em uma árvore binária.  

int conta folhas(No* t); 

*/

typedef struct no{
    int valor;
    struct no *esq;
    struct no *dir;
}No;

typedef struct FilaNo {
    No* no_arvore;
    struct FilaNo* prox;
} FilaNo;

typedef struct Fila {
    FilaNo* frente; /* Primeiro. */
    FilaNo* tras; /* ultimo. */
} Fila;

Fila* cria_fila() {
    Fila* f = malloc(sizeof(Fila));
    f->frente = NULL;
    f->tras = NULL;
    return f;
}

int fila_vazia(Fila* f) { /* Caso o primeiro esteja vazio, logo a fila está vazia. */
    return (f->frente == NULL);
}

void enfileira(Fila* f, No* no_arvore) {
    FilaNo* novo = malloc(sizeof(FilaNo));
    novo->no_arvore = no_arvore;
    novo->prox = NULL;
    if (fila_vazia(f)) {
        f->frente = novo;
    } else {
        f->tras->prox = novo;
    }
    f->tras = novo;
}

No* desenfileira(Fila* f) {
    if (fila_vazia(f)) {
        return NULL; // Fila vazia
    }
    FilaNo* temp = f->frente;
    No* no_arvore = temp->no_arvore;
    f->frente = f->frente->prox;
    if (f->frente == NULL) { // Se a fila ficou vazia
        f->tras = NULL;
    }
    free(temp);
    return no_arvore;
}

void libera_fila(Fila* f) {
    while (!fila_vazia(f)) {
        desenfileira(f); // Desenfileira para liberar os nós da fila
    }
    free(f);
}

void largura(No* t) {
    if (t == NULL) {
        return;
    }

    Fila* fila_auxiliar = cria_fila(); // Cria a fila 
    enfileira(fila_auxiliar, t); // Enfileira a raiz 

    while (!fila_vazia(fila_auxiliar)) { // Enquanto a fila não estiver vazia 
        No* atual = desenfileira(fila_auxiliar); // Desenfileira um nó 
        printf("%d ", atual->valor); // Processa o nó (imprime o valor)

        if (atual->esq != NULL) {
            enfileira(fila_auxiliar, atual->esq); // Enfileira o filho esquerdo 
        }
        if (atual->dir != NULL) {
            enfileira(fila_auxiliar, atual->dir); // Enfileira o filho direito 
        }
    }
    printf("\n");
    libera_fila(fila_auxiliar); // Libera a memória da fila
}


No* novo_no(int v) {
    No* no = (No*) malloc(sizeof(No));
    if (no != NULL) {
        no->valor = v;
        no->esq = NULL;
        no->dir = NULL;
    }
    return no;
}

void insereEsquerda(No *pai, int val){
    if(pai->esq == NULL){
        No *novo; 
        novo = novo_no(val);
        pai->esq = novo;
    }else{
        printf("\nErro. Ja existe um no filho para esquerda desse no pai.\n");
    }
}

void insereDireita(No* pai, int val){
    if(pai->dir == NULL){
        No *novo;
        novo = novo_no(val);
        pai->dir = novo;
    }else{
        printf("\nErro. Ja existe um no filho para direita desse no pai.\n");
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) { /* Lembrar da Torre de Hanói em ATP II */
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int contaFolhasIter(No* t){
    if(t == NULL){
        return 0;
    }
    
    
    Fila* fila_auxiliar = cria_fila(); // Cria a fila 
    enfileira(fila_auxiliar, t); // Enfileira a raiz
    
    int contador = 0;

    while(!fila_vazia(fila_auxiliar)){
        No *atual = desenfileira(fila_auxiliar);

        if(atual->dir == NULL && atual->esq == NULL){
            contador++;
        }else{
            if(atual->dir != NULL){ /* A ordem de desenfileiramento afeta o processamento. Logo, o ideal seria esquerda para direita. */
                enfileira(fila_auxiliar, atual->dir);
            }
            if(atual->esq != NULL){
                enfileira(fila_auxiliar, atual->esq);
            }
        }
    }

    libera_fila(fila_auxiliar);
    return contador;
}

int contaFolhasRecu(No* t) {
    if (t == NULL) { // Se a árvore é vazia, não há folhas 
        return 0;
    }
    // Se o nó não tem filhos esquerdo nem direito, é uma folha 
    if (t->esq == NULL && t->dir == NULL) {
        return 1;
    }
    // Caso contrário, soma as folhas da subárvore esquerda e direita 
    return contaFolhasRecu(t->esq) + contaFolhasRecu(t->dir);
}



int main() {
    // Exemplo de árvore:
    //      10
    //     /  \
    //    5   15
    //   / \    \
    //  2   7   20

    No *raiz = novo_no(10);
    insereEsquerda(raiz, 5);
    insereDireita(raiz, 15);
    insereEsquerda(raiz->esq, 2);
    insereDireita(raiz->esq, 7);
    insereDireita(raiz->dir, 20);
    

    printf("Percurso em largura: ");
    largura(raiz); // Saída esperada: 10 5 15 2 7 20

    printf("\nQuantidade de folhas, analisando pela funcao recursiva: %d.", contaFolhasRecu(raiz));
    printf("\nQuantidade de folhas, analisando pela funcao iterativa: %d.", contaFolhasIter(raiz));

    liberarArvore(raiz);

    return 0;
}