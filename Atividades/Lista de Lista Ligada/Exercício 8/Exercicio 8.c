#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva uma rotina que receba uma lista e um número X e um Y e troque todas as ocorrências do 
número X pelo número Y. Retorne a lista modificada e a quantidade de vezes que houve troca. 
*/

struct no{
    int elem;
    struct no *prox;
};

struct Lista {
    struct no *priElem;
    struct no *ultElem;
};

void inicializa(struct Lista *lista){
    lista->priElem = NULL;
    lista->ultElem = NULL;
}

void insereNoComeco(struct Lista *lista, int elemento){ /* Inserindo primeiro elemento e/ou elementos no começo. */
    struct no *p;
    p = (struct no*) malloc(sizeof(struct no));
    p->elem = elemento;
    p->prox = NULL;

    if(lista->priElem == NULL){
        lista->ultElem = p;
        lista->priElem = p;
    }else{
        p->prox = lista->priElem; /* O próximo aponta para onde o priElem ta apontando. */
        lista->priElem = p; /* E o primElem aponta para o p. Assim, p ficou em primeiro. */
    }
}

void trocaOcorrencias(struct Lista *l, int X, int Y, int *contador){
    struct no *p = l->priElem;
    int cont = 0;

    while(p != NULL){
        if(p->elem == X){
            p->elem = Y;
            cont++;
        }
        p = p->prox;
    }
    *contador = cont;
}

void liberarLista(struct Lista *lista) {
    struct no *atual = lista->priElem;
    struct no *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

void Imprime(struct Lista *l){
    struct no *p = l->priElem;

    while(p != NULL){
        printf("%d ", p->elem);
        p = p->prox;
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");

struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    if(lista == NULL){
        printf("Erro.");
        return -1;
    }


    insereNoComeco(lista, 2);
    insereNoComeco(lista, 2);
    insereNoComeco(lista, 3);
    insereNoComeco(lista, 8);
    insereNoComeco(lista, 5);

    Imprime(lista);
    printf("\n\n");

    int contador = 0;
    trocaOcorrencias(lista, 2, 10, &contador);

    printf("\nO contador de vezes que apareceu 2 eh: %d.\n", contador);
    Imprime(lista);
    printf("\n\n");



liberarLista(lista);
return 0;
}