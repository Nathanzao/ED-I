#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Pilhas estáticas.
*/

struct Pilha { 
    int vPilha[10]; 
    int topo; 
};

int inicializacao(struct Pilha *pilha)
{
    pilha->topo = 0; // pilha vazia
}

int vazia(struct Pilha *pilha) // verifica se a pilha está vazia
{
    if (pilha->topo == 0){
        return 1;
    }else{
        return 0;
    }
}

int cheia(struct Pilha *pilha){
    if(pilha->topo == 10){
        return 1;
    }else{
        return 0;
    }
}

void push(struct Pilha *pilha, int elemento){
    if(cheia(pilha) == 1){
        printf("Pilha cheia.");
    }else{
        pilha->vPilha[pilha->topo++] = elemento;
    }
}

int pop(struct Pilha *pilha, int *elemento){ /* Veja que usamos o --pilha pois o topo aponta para uma posição disponível vazia. */
    if(vazia(pilha) == 1){
        printf("Pilha vazia.");
    }else{
        *elemento = pilha->vPilha[--pilha->topo];
        pilha->topo = NULL;
    }
}

void obterTopo(struct Pilha *pilha, int *elemento)
{
	if (vazia(pilha)) 
		 printf("Pilha Vazia - Não há elementos para desempilhar!!!");	
      else 
        *elemento = pilha->vPilha[pilha->topo-1] ; /* Pegar o elemento que está no topo. Considerando que o topo é a posição vazia mais acima, o valor é topo - 1. */
}



int main (){
setlocale(LC_ALL, "Portuguese");

return 0;
}