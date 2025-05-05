#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva uma rotina que receba uma lista e retorne duas listas onde uma possui os valores impares e 
a outra os valores pares da lista.
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

void recebeUmaRetornaDuas(struct Lista *lista, struct Lista *ListaPar, struct Lista *ListaImpar){
    struct no *p = lista->priElem;
    

    while(p != NULL){
        if((p->elem % 2) == 0){
            insereNoComeco(ListaPar, p->elem);
        }else{
            insereNoComeco(ListaImpar, p->elem);
        }
        p = p->prox;
    }
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

    struct Lista *listaPar = (struct Lista*) malloc(sizeof(struct Lista));
    struct Lista *listaImpar = (struct Lista*) malloc(sizeof(struct Lista));

    inicializa(listaImpar);
    inicializa(listaPar);

    insereNoComeco(lista, 2);
    insereNoComeco(lista, 3);
    insereNoComeco(lista, 8);
    insereNoComeco(lista, 5);

    recebeUmaRetornaDuas(lista, listaPar, listaImpar);

    Imprime(lista);
    printf("\n\n");

    Imprime(listaPar);
    printf("\n\n");

    Imprime(listaImpar);
    printf("\n\n");



liberarLista(listaImpar);
liberarLista(listaPar);
liberarLista(lista);
return 0;
}