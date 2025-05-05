#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva  um  programa  que  permita  contar  o  número  de  vezes  que  houve  inserção  e  remoção  de 
elementos em uma lista.
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

void insereNoComeco(struct Lista *lista, int elemento, int *cont){ /* Inserindo primeiro elemento e/ou elementos no começo. */
    *cont += 1;
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


void removePrimeiro(struct Lista *l, int *cont){
    struct no *p = l->priElem;

    l->priElem = p->prox;
    free(p);

    *cont += 1;
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

    int remocao = 0;
    int adicao = 0;


    insereNoComeco(lista, 2, &adicao);
    insereNoComeco(lista, 2, &adicao);
    insereNoComeco(lista, 3, &adicao);
    insereNoComeco(lista, 8, &adicao);
    insereNoComeco(lista, 5, &adicao);

    Imprime(lista);
    printf("\n\n");


    removePrimeiro(lista, &remocao);
    removePrimeiro(lista, &remocao);


    Imprime(lista);
    printf("\n\n");


    printf("Tivemos %d adicoes e %d remocoes.", adicao, remocao);


liberarLista(lista);
return 0;
}