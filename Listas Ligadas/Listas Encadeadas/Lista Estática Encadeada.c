#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
É um vetor que está expresso em STRUCT, mas de forma encadeada.
*/

#define MAX 11
struct reg
{
    int elem;
    int prox;//Este campo é necessário para gerar o encadeamento entre os
};


struct lista
{
    int disp;
    int prim;
    int quantidadeEleme;
    struct reg A[MAX];
};

void InicializaLista(struct lista *L)
{
    int i = 0;
    L->disp = 0;
    L->prim = -1;
    L->quantidadeEleme = 0;
    for(i=0 ; i<MAX-1 ; i++){ //Inicializando o prox de cada elemento
        L->A[i].prox=i+1;
    }
    L->A[MAX - 1].prox= -1; /* ??? */

}

void Remove(struct lista *l, int indice){
    if((indice - 1) < 0){ /* Caso aquele que quero remover seja o primeiro elemento.*/
        l->prim = l->A[indice].prox;
    }else{
        l->A[indice - 1].prox = indice + 1; /* O anterior do elemento agora aponta para o proximo dele. */
    }

    l->A[indice].prox = l->disp;
    l->disp = indice; /* O elemento removido agora é visto como disponivel. */
    l->quantidadeEleme--;
}

void adicionaNaLista(struct lista *l, int valor){
    int disponi = l->disp;
    l->quantidadeEleme++;

    if(disponi == 0){ /* Caso seja o primeiro caso da lista. */
        l->prim = 0;
    }

    l->disp = l->A[disponi].prox;
    
    
    l->A[disponi].elem = valor;
    
}

void ImprimeLista(struct lista *l){
    int aux = l->prim, contador = 0;

    while(contador != l->quantidadeEleme){
        printf("%d ", l->A[aux].elem);
        aux = l->A[aux].prox;
        contador++;
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");
    struct lista l;
    InicializaLista(&l);

    adicionaNaLista(&l, 3);
    adicionaNaLista(&l, 4);
    adicionaNaLista(&l, 5);

    ImprimeLista(&l);
    printf("\n\n");
    Remove(&l, 1);

    ImprimeLista(&l);
    printf("\n\n");

return 0;
}