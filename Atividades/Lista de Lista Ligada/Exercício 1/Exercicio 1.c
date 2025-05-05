#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva uma rotina que retorne o número de elementos de uma lista.
*/

struct no{
    int elem;
    struct no *prox;
};

struct Lista {
    struct no *priElem;
    struct no *ultElem;
};

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

int quantosElementos(struct Lista *lista){
    struct no *p;
    p = lista->priElem;
    int contador = 0;

    while(p != NULL){
        contador++;
        p = p->prox;
    }

    return contador;
}

int main (){
setlocale(LC_ALL, "Portuguese");
    


    struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    if (lista == NULL) {
        printf("Erro de memória para a lista.\n");
        return;
    }

    lista->priElem = NULL;
    lista->ultElem = NULL;

    insereNoComeco(lista , 3);
    insereNoComeco(lista , 5);
    insereNoComeco(lista , 2);

    int quantidadeElementos = quantosElementos(lista);

    printf("%d", quantidadeElementos);


    free(lista);
return 0;
}