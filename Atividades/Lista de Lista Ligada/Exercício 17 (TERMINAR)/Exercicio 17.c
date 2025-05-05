#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Escreva uma rotina para combinar duas listas ordenadas numa única lista ordenada.
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
    struct no *p;
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

void concatenaDuasOrdenadas(struct Lista *l, struct Lista *l2, struct Lista *l3){
    struct no *p = l->priElem;
    struct no *pp = l2->priElem;
    struct no *ppp = l3->priElem;


    int tamanho1 = tamanho(l);
    int tamanho2 = tamanho(l2);
    int menor  = 0;
    if(tamanho1 > tamanho2){
        for(int i = 0; i < tamanho2; i++){
            for(int j = 0; j < tamanho1; j++){
                struct no *pSub = p;
                if(pp->elem < pSub->elem){
                    menor = pp->elem;
                }else{
                    menor = pSub->elem;
                }

                pSub = pSub->prox;

            }

            

        }
    }else{

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

    removeComIndice(lista, 1, &remocao);

    Imprime(lista);
    printf("\n\n");

    printf("Tivemos %d adicoes e %d remocoes.", adicao, remocao);

liberarLista(lista);
return 0;
}