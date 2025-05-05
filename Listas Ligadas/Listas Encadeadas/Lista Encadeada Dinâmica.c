#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Dentro da própria STRUCT, há um ponteiro que aponta para outro endereço de memória do mesmo tipo
àquele que pertence.
*/

struct no{
    int elem;
    struct no *prox;
};

struct Lista {
    struct no *priElem;
    struct no *ultElem;
};

void inicializaLista(struct Lista *list){ //Inicialização da Lista
    list->priElem = NULL;
    list->ultElem = NULL;
}

void insereNoComeco(struct Lista *lista){ /* Inserindo primeiro elemento e/ou elementos no começo. */
    struct no *p;
    p = (struct no*) malloc(sizeof(struct no));
    p->elem = NULL;
    p->prox = NULL;

    if(lista->priElem == NULL){
        lista->ultElem = p;
        lista->priElem = p;
    }else{
        p->prox = lista->priElem; /* O próximo aponta para onde o priElem ta apontando. */
        lista->priElem = p; /* E o primElem aponta para o p. Assim, p ficou em primeiro. */
    }


free(p); /* Na hora de usar, tem que tirar o FREE, e dar ele para outro lugar. */
}

void percorreEimprime(struct Lista *lista){
    struct no *aux;

    aux = lista->priElem;
    while(aux != NULL){
        printf("Conteudo de p: %d.", aux->elem);
        aux = aux->prox;
    }
}

struct no* BuscaNo(struct Lista *lista, int elemento){
    struct no *p;

    for(p = lista->priElem; p != NULL; p = p->prox){
        if(p->elem == elemento){
            return p;
        }
    }
}

void RemoveNO(struct Lista *lista, int elemento){
    struct no *p = lista->priElem;
    struct no *ant = NULL;

    while(p != NULL && p->elem != elemento){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        printf("Elemento nao encontrado.");
    }

    if(ant == NULL){ /* Caso seja o primeiro elemento encontrado, ant irá ser NULL. */
        lista->priElem = p->prox;
        free(p);
    }

    if(p == lista->ultElem){ /* Caso seja o último elemento encontrado. */
        lista->ultElem = ant;
        free(p);
    }else{
        ant->prox = p->prox; /* Tirando do meio da lista. */
        free(p);
    }



}

int quantElem(struct Lista *lista){
    int quant = 0;
    struct no *p = lista->priElem;

    while(p != NULL){
        quant++;
        p = p->prox;
    }

    return quant;
}

int main (){
setlocale(LC_ALL, "Portuguese");

return 0;
}