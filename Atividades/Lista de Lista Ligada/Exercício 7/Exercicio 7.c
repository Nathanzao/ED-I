#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva  uma  rotina  que  receba  uma  lista  e  um  número  X  e  retorne  duas  listas  onde  uma  possui 
valores menores do que o número X e a outra valores maiores do que X.
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

void percorrerListaAchar(struct Lista *lista, struct Lista *listaMenor, struct Lista *listaMaior, int elemento){
    struct no *pp = lista->priElem;

    while(pp != NULL){
        if(pp->elem > elemento){
            insereNoComeco(listaMaior, pp->elem);
        }else{
            insereNoComeco(listaMenor, pp->elem);
        }
        pp = pp->prox;
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

    struct Lista *listaMaior = (struct Lista*) malloc(sizeof(struct Lista));
    struct Lista *listaMenor = (struct Lista*) malloc(sizeof(struct Lista));

    inicializa(listaMaior);
    inicializa(listaMenor);

    insereNoComeco(lista, 2);
    insereNoComeco(lista, 3);
    insereNoComeco(lista, 8);
    insereNoComeco(lista, 5);

    percorrerListaAchar(lista, listaMenor, listaMaior, 4);

    Imprime(lista);
    printf("\n\n");

    Imprime(listaMenor);
    printf("\n\n");

    Imprime(listaMaior);
    printf("\n\n");



liberarLista(listaMaior);
liberarLista(listaMenor);
liberarLista(lista);
return 0;
}