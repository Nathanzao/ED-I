#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Dado  um  inteiro  n,  apresentar o  n-ésimo  elemento  a  partir  do topo  da  pilha,  deixando  a  pilha 
inalterada.
*/

struct noPilha{
    char elemento;
    struct noPilha *prox;
};

struct Pilha{
    struct noPilha *topo;
};

void inicializa(struct Pilha *p){
    p->topo = NULL;
}

int verificaVazia(struct Pilha *p){
    if(p->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(struct Pilha *p, char caractere){
    struct noPilha *no = malloc(sizeof(struct noPilha));
    
    no->elemento = caractere;
    no->prox = p->topo;
    p->topo = no;
}

void pop(struct Pilha *p, char *caractere){
    if((verificaVazia(p)) == 1){
        printf("\nNao ha nenhum valor na pilha.\n");
        return;
    }else{
        struct noPilha *aux = p->topo; 
        *caractere = p->topo->elemento;
        p->topo = p->topo->prox;
        free(aux);
    }
}

void imprimeEnesimo(struct Pilha *p, int enesimo){
    struct noPilha *pp = p->topo;
    int i = 0;

    printf("\n\nPilha a partir do enesimo (%d):\n", enesimo);
    while(i < enesimo && pp != NULL){
        pp = pp->prox;
        i++;
    }

    while(pp != NULL){
        printf("%c\n", pp->elemento);
        pp = pp->prox;
    }
}

void imprime(struct Pilha *p){
    struct noPilha *pp = p->topo;

    printf("\n\nPilha:\n");
    while(pp != NULL){
        printf("%c\n", pp->elemento);
        pp = pp->prox;
    }
}

void esvazia(struct Pilha *p){
    struct noPilha *pp = p->topo;
    struct noPilha *aux;

    while(pp != NULL){
        aux = pp;
        pp = pp->prox;
        free(aux);
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");

    struct Pilha p;

    inicializa(&p);

    push(&p, 'a');
    push(&p, 'b');
    push(&p, 'c');
    push(&p, 'd');
    push(&p, 'e');

    imprime(&p);

    printf("\n\n");

    imprimeEnesimo(&p, 3);

esvazia(&p);
return 0;
}
