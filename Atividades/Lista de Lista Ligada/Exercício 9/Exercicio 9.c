#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Dada  uma  lista  e  um  elemento,  escreva  uma  rotina  que  remova  da  lista  todas  as  ocorrências  do 
elemento.
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

void removerOcorrencias(struct Lista *l, int elemento){
    struct no *p = l->priElem;
    struct no *aux;

    while(p != NULL){
        if(p->elem == elemento){
            if(aux == NULL){ /* Caso 1 elemento. */
                l->priElem = p->prox;
                if(l->priElem == NULL){
                    l->ultElem = NULL;
                }
                free(p);
                p = l->priElem;
            }else{
                aux->prox = p->prox;
                if(p == l->ultElem){ /* Caso ultimo elemento. */
                    l->ultElem = aux;
                }
                free(p);
                p = aux;
            }
        }
    aux = p;
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


    insereNoComeco(lista, 2);
    insereNoComeco(lista, 2);
    insereNoComeco(lista, 3);
    insereNoComeco(lista, 8);
    insereNoComeco(lista, 5);

    Imprime(lista);
    printf("\n\n");


    removerOcorrencias(lista, 2);

    Imprime(lista);
    printf("\n\n");


liberarLista(lista);
return 0;
}