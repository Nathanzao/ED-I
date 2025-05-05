#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva  uma  rotina  que  receba  uma  lista  e  um  número  X  e  retorne  o  número  de  nós  da  lista  que 
possuem valores menores do que o número X.
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


void liberarLista(struct Lista *lista) {
    struct no *atual = lista->priElem;
    struct no *prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int percorrerListaAcharMenor(struct no *pp, int elemento){
    int contador = 0;
    
    while(pp != NULL){
        if(pp->elem > elemento){
            contador++;
        }
        pp = pp->prox;
    }
    return contador;
}


int main (){
setlocale(LC_ALL, "Portuguese");
    


    struct Lista *lista = (struct Lista*) malloc(sizeof(struct Lista));
    if (lista == NULL) {
        printf("Erro de memória para a lista.\n");
        return -1;
    }

    lista->priElem = NULL;
    lista->ultElem = NULL;

    insereNoComeco(lista , 3);
    insereNoComeco(lista , 5);
    insereNoComeco(lista , 2);
    insereNoComeco(lista , 2);
    insereNoComeco(lista , 4);

    struct no *p = lista->priElem;

    int valor = percorrerListaAcharMenor(p, 3);
    printf("%d", valor);

    liberarLista(lista);
    free(lista);
return 0;
}