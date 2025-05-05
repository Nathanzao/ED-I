#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Fila dinâmica.
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
        f->fim->prox = novo;
        f->fim = novo;
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

int primeiroElemento(struct Fila *f){
    return f->inicio;
}

int main (){
setlocale(LC_ALL, "Portuguese");
    struct Fila fila;

    inicializar(&fila);

    inserirFinal(&fila, 2);
    inserirFinal(&fila, 7);
    inserirFinal(&fila, 6);

    imprimir(&fila);

    printf("\n\n");

    removeInicio(&fila);

    imprimir(&fila);

    printf("\n\n");

liberarFila(&fila);
return 0;
}