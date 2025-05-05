#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Fila prioridade.
*/

struct noFila{
    int valor;
    struct noFila *prox;
};

struct Fila{
    struct noFila *inicio;
    struct noFila *fim;
};

void inicializar(struct Fila *f){
    f->fim = NULL;
    f->inicio = NULL;
}

int verificaVazia(struct Fila *f){
    if((f->inicio) == NULL){
        return 1;
    }else{
        return 0;
    }
}

int verificaCheia(); /* Não terá função pois não há limite na pilha (a não ser pela falta de memória.) */

void inserirFinal(struct Fila *f, int elem){
    struct noFila *novo = malloc(sizeof(struct noFila));
    novo->valor = elem;
    novo->prox = NULL;


    if((verificaVazia(f)) == 1){
        f->inicio = novo;
        f->fim = novo;
    }else{
        if(elem > 70){
            if(f->inicio->valor < 70){
                novo->prox = f->inicio;
                f->inicio = novo;
            }else{
                struct noFila *aux = f->inicio;
                while(aux->prox != NULL && aux->prox->valor > 70){ /* Encontro quem não é prioridade depois do inicio. */
                    aux = aux->prox;
                }
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }else{
            f->fim->prox = novo;
            f->fim = novo;
        }
    }
}

void removeInicio(struct Fila *f){ /* Não retorna endereço. */
    
    if((verificaVazia(f)) == 1){
        printf("\n\nFila nao tem nada para remover: esta vazia.\n\n");
        return 0;
    }
    
    struct noFila *aux = f->inicio;
    f->inicio = f->inicio->prox;

    if((verificaVazia(f)) == 1){
        f->fim = NULL;
    }

    free(aux);
}

void liberarFila(struct Fila *f){
    struct noFila *p = f->inicio;

    while(p != NULL){
        struct noFila *aux = p;
        p = p->prox;
        free(aux);
    }
}

void imprimir(struct Fila *f){
    struct noFila *p = f->inicio;

    while(p != NULL){
        printf("%d ", p->valor);
        p = p->prox;
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");
    struct Fila fila;

    inicializar(&fila);

    inserirFinal(&fila, 23);
    inserirFinal(&fila, 77);
    inserirFinal(&fila, 64);
    inserirFinal(&fila, 78);

    imprimir(&fila);

    printf("\n\n");

    removeInicio(&fila);

    imprimir(&fila);

    printf("\n\n");

liberarFila(&fila);
return 0;
}