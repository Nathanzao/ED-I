#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
a. Dado um inteiro n, apresentar o n-ésimo elemento a partir do topo da pilha, deixando a pilha sem 
seus n elementos superiores
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

void removeNesimo(struct Pilha *p, int enesimo){
    int i = 0;
    char lixo;

    while(i != enesimo){
        pop(p, &lixo);
        i++;
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

    removeNesimo(&p, 3);

    imprime(&p);

esvazia(&p);
return 0;
}
