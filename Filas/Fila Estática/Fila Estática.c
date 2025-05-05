#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Vai ser igual a lista estática, aquela que declaramos os vetores e a partir dai, fazemos operações
baseadas no indíce.
Essa daqui é aquela que tem aquele problema de não conseguir colocar os dados onde já foi excluído.

*/

struct fila{
    int vFila[10];
    int inicio;
    int final;
};

void inicializa(struct fila *f){
    f->inicio = 0;
    f->final = 0;
}

int verificaVazia(struct fila *f){
    if(f->final == f->inicio){
        printf("Fila esta vazia.");
        return 1;
    }else{
        return 0;
    }
}

int verificaCheia(struct fila *f){
    if(f->final == 10){
        printf("Fila esta cheia.");
        return 1;
    }else{
        return 0;
    }
}

void inserir(struct fila *f, int elemento){
    if((verificaCheia(f)) == 1){
        printf("Fila esta cheia.");
    }else{
        f->vFila[f->final] = elemento;
        f->final++;
    }
}

void removerSemPegarElemento(struct fila *f){ /* Remoção sem pegar o elemento que será removido. */
    if((verificaVazia(f)) == 1){
        printf("Fila esta vazia.");
    }else{
        f->inicio++;
    }
}

void removerPegandoElemento(struct fila *g, int *elemento){ /* Remoção pegando o elemento que será removido. */
    if (verificaVazia(g) == 1) {
        printf("Fila esta vazia.");
        return;
    }

    *elemento = g->vFila[g->inicio];
    g->inicio++;
}

void obterInicioFila(struct fila *f, int *elem){
    if((verificaVazia(f)) == 1){
        printf("Fila vazia.");
    }else{
        *elem = f->vFila[f->inicio];
    }
}

void exibirFila(struct fila *p){
    if(verificaVazia(p) == 1){
        printf("\n\nFila vazia.\n");
        return 0;
    }else{
        printf("Elementos da fila: \n");
        for(int i = p->inicio; i < p->final; i++){
            printf("%d ", p->vFila[i]);
        }
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");

    struct fila Fila;

    inicializa(&Fila);

    inserir(&Fila, 3);
    inserir(&Fila, 4);
    inserir(&Fila, 5);

    exibirFila(&Fila);

    printf("\n\n");

    removerSemPegarElemento(&Fila);

    exibirFila(&Fila);

    printf("\n\n");


return 0;
}