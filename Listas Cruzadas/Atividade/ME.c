#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "ME.h"


void inicializar(struct matriz *p){
    for(int i = 0; i < LINHA; i++){
        p->linha[i] = NULL;
    }

    for(int i = 0; i < COLUNA; i++){
        p->coluna[i] = NULL;
    }
}

void insere(struct matriz *p, int Linha, int coluna, int info){
    struct no *novo = malloc(sizeof(struct no));

    novo->abaixo = NULL;
    novo->direita = NULL;
    novo->coluna = coluna;
    novo->linha = Linha;
    novo->valor = info;

    struct no *ponteiroParaColuna = p->coluna[coluna];
    struct no *ponteiroParaLinha = p->linha[Linha];
    struct no *anterior = NULL;

        if(ponteiroParaColuna == NULL){ /* Caso não tenha nenhum elemento ocupando a posição da coluna desejada. */
            p->coluna[coluna] = novo;
        }else{ /* Caso não esteja vazia. */
            anterior = NULL;
            while((ponteiroParaColuna != NULL) && (ponteiroParaColuna->linha < Linha)){
                anterior = ponteiroParaColuna;
                ponteiroParaColuna = ponteiroParaColuna->abaixo;
            }
            if(ponteiroParaColuna != NULL){
                if(ponteiroParaColuna->linha == Linha){
                    printf("Ja existe na coluna.");
                }else{
                    if(anterior == NULL){ /* Insere no inicio. */
                        novo->abaixo = p->coluna[coluna];
                        p->coluna[coluna] = novo;
                    }else{ /* Insere no meio. */
                        novo->abaixo = ponteiroParaColuna;
                        anterior->abaixo = novo;
                    }
                }
            }else{
                anterior->abaixo = novo;
            }
                    /* Agora vai ser a mesma coisa, só que para a linha. */

            if(ponteiroParaLinha == NULL){ /* Caso não tenha nenhum elemento ocupando a posição da linha desejada. */
            p->linha[Linha] = novo;
        }else{ /* Caso não esteja vazia. */
            anterior = NULL;
            while((ponteiroParaLinha != NULL) && (ponteiroParaLinha->coluna < coluna)){
                anterior = ponteiroParaLinha;
                ponteiroParaLinha = ponteiroParaLinha->direita;
            }
            if(ponteiroParaLinha != NULL){
                if(ponteiroParaLinha->coluna == coluna){
                    printf("Ja existe na linha.");
                }else{
                    if(anterior == NULL){ /* Insere no inicio. */
                        novo->direita = p->linha[Linha];
                        p->linha[Linha] = novo;
                    }else{ /* Insere no meio. */
                        novo->direita = ponteiroParaLinha;
                        anterior->direita = novo;
                    }
                }
            }else{
                anterior->direita = novo;
            }
        }
    }

};


void imprime(struct matriz *p){
    struct no *aux;
    for(int linha = 0; linha < LINHA; linha++){
        aux = p->linha[linha];
        printf("\n");


        for(int coluna = 0; coluna < COLUNA; coluna++){
            if(aux != NULL && aux->coluna == coluna){
                printf("%d ", aux->valor);
                aux = aux->direita;
            }else{
                printf("0 ");
            }
        }
    }
};

void removerElemento(struct matriz *matriz, int linha, int coluna) {
    struct no *atualLinha = matriz->linha[linha];
    struct no *anterior = NULL;

    // Buscar na linha
    while (atualLinha != NULL && atualLinha->coluna < coluna) {
        anterior = atualLinha;
        atualLinha = atualLinha->direita;
    }

    if (atualLinha == NULL || atualLinha->coluna != coluna) {
        printf("Elemento [%d][%d] não encontrado!\n", linha, coluna);
        return;
    }

    // Remover da lista da linha
    if (anterior == NULL) {
        matriz->linha[linha] = atualLinha->direita;
    } else {
        anterior->direita = atualLinha->direita;
    }

    // Buscar e remover da lista da coluna
    struct no *atualColuna = matriz->coluna[coluna];
    anterior = NULL;

    while (atualColuna != NULL && atualColuna->linha < linha) {
        anterior = atualColuna;
        atualColuna = atualColuna->abaixo;
    }

    if (atualColuna != NULL && atualColuna->linha == linha) {
        if (anterior == NULL) {
            matriz->coluna[coluna] = atualColuna->abaixo;
        } else {
            anterior->abaixo = atualColuna->abaixo;
        }
    }

    free(atualLinha);  // Libera o nó removido (mesmo ponteiro de atualColuna)
}


void somarNaLinha(struct matriz *mat, int linha, int incremento) {
    struct no* atual = mat->linha[linha];

    for (int col = 0; col < COLUNA; col++) {
        if (atual != NULL && atual->coluna == col) {
            atual->valor += incremento;
            atual = atual->direita;
        } else {
            // Verifica se o elemento já existe antes de inserir
            // Para evitar inserir repetido por erro de estrutura
            struct no* busca = mat->linha[linha];
            while (busca != NULL && busca->coluna < col)
                busca = busca->direita;

            if (busca == NULL || busca->coluna != col)
                insere(mat, linha, col, incremento);  // Inserir novo elemento
        }
    }
}
