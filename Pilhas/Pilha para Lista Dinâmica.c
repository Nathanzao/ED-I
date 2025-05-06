#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Pilha dinâmica. Nesse caso, o ponteiro não ficará uma posição acima do último elemento. Ele ficará no próprio último elemento.
Nesse caso, o topo fica no final do vetor, e os noPilha são inseridos em ordem de caminhar ao início, através dele.
Pense que, ao colocar coisas na pilha, você tá caminhando pra trás em um vetor.
*/

struct noPilha {
	int elemento;
	struct noPilha *prox;
};

struct Pilha{
	struct noPilha *topo;
};

void inicializa(struct Pilha *p){
    p->topo = NULL;
}

int vazia(struct Pilha *p){
    if(p->topo ==NULL){
        return 1;
    }else{
        return 0;
    }
}

int cheia(struct Pilha *p){
    struct noPilha *pp = malloc(sizeof(struct noPilha));

    if(pp == NULL){
        free(pp);
        return 1;
    }else{
        free(pp);
        return 0;
    }
}

void obterTopo(struct Pilha *pilha, int *elemento)
{
	if (vazia(pilha) == 1) 
		 printf("Pilha Vazia - Não há elementos para desempilhar!!!");	
      else 
       *elemento = pilha->topo->elemento;
}

void push(struct Pilha *p, int elemento){
    struct noPilha *pp = malloc(sizeof(struct noPilha));

    if(cheia(p) == 1){
        printf("Lista cheia.");
    }else{
        pp->elemento = elemento;
        pp->prox = p->topo; /* O topo, nesse caso, faz um papel de ponteiro para o último elemento. É o final do vetor. Está indo do final do vetor para a frente. */
        p->topo = pp;
    }
}

void pop(struct Pilha *p, int *elemento){
    if(vazia(p) == 1){
        printf("Lista vazia.");
    }else{
        struct noPilha *aux = p->topo; /* Serve somente para liberar a memória. */
        *elemento = p->topo->elemento;
        p->topo = p->topo->prox;
        free(aux);
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

return 0;
}