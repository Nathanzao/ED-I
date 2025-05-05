#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Faça uma rotina para concatenar duas listas.
*/

struct no{
    int elem;
    struct no *prox;
};

struct Lista {
    struct no *priElem;
    struct no *ultElem;
};

int tamanho(struct Lista *l){
    struct no *p = l->priElem;
    int contador = 0;

    while(p != NULL){
        contador++;

        p = p->prox;
    }

    return contador;
}

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

void insereFinal(struct Lista *l, int valor, int *cont){
    struct no *p = malloc(sizeof(struct no));
    
    l->ultElem->prox = p;
    l->ultElem = p;

    p->elem = valor;
    p->prox = NULL;

    *cont += 1;
}


void removePrimeiro(struct Lista *l, int *cont){
    struct no *p = l->priElem;

    l->priElem = p->prox;
    free(p);

    *cont += 1;
}

void insereMeio(struct Lista *l, struct no *anterior, struct no *proximo, int valor, int *cont){
    struct no *p = malloc(sizeof(struct no));

    p->elem = valor;
    anterior->prox = p;
    p->prox = proximo;

    *cont += 1;
}

void concatena(struct Lista *l, struct Lista *l2, int *cont){
    struct no *p = l->priElem;

    while(p != NULL){
        insereFinal(l2, p->elem, cont);
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

struct Lista *lista2 = (struct Lista*) malloc(sizeof(struct Lista));
    if(lista2 == NULL){
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

    printf("Lista 1: \n");
    Imprime(lista);
    printf("\n\n");

    insereNoComeco(lista2, 1, &adicao);
    insereNoComeco(lista2, 1, &adicao);
    insereNoComeco(lista2, 1, &adicao);
    insereNoComeco(lista2, 1, &adicao);
    insereNoComeco(lista2, 1, &adicao);

    printf("Lista 2: \n");
    Imprime(lista2);
    printf("\n\n");

    concatena(lista, lista2, &adicao);

    printf("Lista 2 modificada: \n");
    Imprime(lista2);
    printf("\n\n");


    printf("Tivemos %d adicoes e %d remocoes.", adicao, remocao);

liberarLista(lista2);
liberarLista(lista);
return 0;
}