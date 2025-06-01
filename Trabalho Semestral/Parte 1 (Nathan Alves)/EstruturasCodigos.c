#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "Estruturas.h"
/*

*/

struct Ocorrencia *filaOcorrencias = NULL;
struct Bairro *tabelaHashing[MAX];
struct UnidadeServico *listaDeServicos = NULL;
struct Cidadao *listaCidadoes = NULL;

int funcaoHashing(int id){
    return id % MAX;
}

void inicializaTabela(){
    for(int i = 0; i < MAX; i++){
        tabelaHashing[i] = NULL;
    }
}

void cadastrarBairro(int id, char *nome){
    int indice = funcaoHashing(id);

    struct Bairro *novo = malloc(sizeof(struct Bairro));

    novo->id = id;
    strcpy(novo->nomeBairro, nome);
    novo->prox = NULL;

    if(tabelaHashing[indice] != NULL){ /* Primeira posição já tem alguém. Iniciaremos o tratamento de colisão. */
        struct Bairro *atual = tabelaHashing[indice];;
        while(atual->prox != NULL){ /* Fica percorrendo até que o próximo seja NULL. */
            atual = atual->prox; 
        }
        atual->prox = novo;
        novo->prox = NULL;
    }else{
        tabelaHashing[indice] = novo;
    }
}

void cadastrarCidadao(char *cpf, char *nome, char *email, char *endereco, char *bairro){
    struct Cidadao *novo = malloc(sizeof(struct Cidadao));

    strcpy(novo->CPF, cpf);
    strcpy(novo->nomePessoa, nome);
    strcpy(novo->email, email);
    strcpy(novo->endereco, endereco);
    strcpy(novo->bairro, bairro);
    novo->prox = NULL;

    novo->prox = listaCidadoes;
    listaCidadoes = novo;
    
}

void cadastrarServico(int idDesejado, int tipo, char *nome, char *endereco, char *bairro){
    struct UnidadeServico *unidadeNova = malloc(sizeof(struct UnidadeServico));

    unidadeNova->id = idDesejado;
    unidadeNova->tipoUnidade = tipo;
    strcpy(unidadeNova->nomeServico, nome);
    strcpy(unidadeNova->endereco, endereco);
    strcpy(unidadeNova->bairro, bairro);

    unidadeNova->prox = listaDeServicos; /* Inserindo na lista de serviços. */
    listaDeServicos = unidadeNova;
    
}

void exibirBairrosRegistrados(){
    int indice;

    for(indice = 0; indice < MAX; indice++){
        struct Bairro *p = tabelaHashing[indice];
        
        while(p != NULL){
            printf("    Indice %d: \n\n\n", indice + 1); /* APAGAR */
            printf("Nome: %s\n", p->nomeBairro);
            printf("Id: %d\n", p->id);

            p = p->prox;
            printf("\n\n\n");
        }
        
    }
}

void exibirServicosRegistrados(){
    struct UnidadeServico *p = listaDeServicos;
    int i = 1;

    if(p == NULL){
        printf("\nNenhum servico foi registrado ate agora.\n");
    }else{
        while(p != NULL){
            
            printf("\n        Servico %d:\n\n", i);

            printf("Nome: %s\n", p->nomeServico);
            printf("Endereco: %s\n", p->endereco);
            printf("Bairro: %s\n", p->bairro);
            printf("ID: %d\n", p->id);
            printf("Tipo de Servico: %d\n", p->tipoUnidade);

            p = p->prox;
        }
    }
}

void exibirCidadoesRegistrados(){
    struct Cidadao *p = listaCidadoes;
    int i = 1;

    if(p == NULL){
        printf("\nNenhuma pessoa foi registrada até agora.\n");
    }else{
        while(p != NULL){
            
            printf("\n        Pessoa %d:\n\n", i);

            printf("Nome: %s\n", p->nomePessoa);
            printf("Endereco: %s\n", p->endereco);
            printf("Bairro: %s\n", p->bairro);
            printf("CPF: %s\n", p->CPF);
            printf("Email: %s\n", p->email);

            p = p->prox;
        }
    }
}

void registrarOcorrencia(int idDaOcorrencia, char *cpfCidadaoSolicitante, int prioridade, int tipoDaOcorrencia, int idDoBairroAlvo){
    struct Ocorrencia *novo = malloc(sizeof(struct Ocorrencia));
    tempo(); /* Aumentar o tempo. */

    strcpy(novo->cpfCidadao, cpfCidadaoSolicitante);
    novo->id = idDaOcorrencia;
    novo->gravidade = prioridade;
    novo->tipo = tipoDaOcorrencia;
    novo->IdDoBairro = idDoBairroAlvo;
    novo->prox = NULL;

    

    if(filaOcorrencias == NULL || novo->gravidade > filaOcorrencias->gravidade){
        novo->prox = filaOcorrencias; /* Mesmo que seja o primeiro caso, só irá apontar para NULL. */
        filaOcorrencias = novo;
    }else{
        struct Ocorrencia *p = filaOcorrencias;
        struct Ocorrencia *ant = NULL;
        
        while(p != NULL && p->gravidade >= novo->gravidade){ /* Percorrendo até chegar ao fim ou achar alguma ocorrência com prioridade menor. */
            ant = p;
            p = p->prox;
        }

        if(p == NULL){ /* Caso tenha chegado ao final e não tenha encontrado nenhuma prioridade menor. */
            ant->prox = novo;
        }else{ /* Caso encontrou uma prioridade menor antes de chegar ao final. */
            ant->prox = novo;
            novo->prox = p;
        }

    }
}

void processarOcorrencia(){
    if(filaOcorrencias == NULL){
        printf("\n\nFila de ocorrencias esta vazia.\n");
        return;
    }
    tempo(); /* Aumentar o tempo. */

    struct Ocorrencia *ocorrenciaAtual = filaOcorrencias;
    filaOcorrencias = filaOcorrencias->prox;

     printf("Processando ocorrencia ID %d do cidadao %s (gravidade %d, tipo %d, bairro ID %d)\n",
        ocorrenciaAtual->id,
        ocorrenciaAtual->cpfCidadao,
        ocorrenciaAtual->gravidade,
        ocorrenciaAtual->tipo,
        ocorrenciaAtual->IdDoBairro);

    free(ocorrenciaAtual);
}

void exibirOcorrencias(){
    struct Ocorrencia *ocorrenciaAtual = filaOcorrencias;

    while(ocorrenciaAtual != NULL){
        printf("Ocorrencia ID %d do cidadao %s (gravidade %d, tipo %d, bairro ID %d)\n",
        ocorrenciaAtual->id,
        ocorrenciaAtual->cpfCidadao,
        ocorrenciaAtual->gravidade,
        ocorrenciaAtual->tipo,
        ocorrenciaAtual->IdDoBairro);

        ocorrenciaAtual = ocorrenciaAtual->prox;
    }
}

int tempoAtual = 0;

void tempo() {
    tempoAtual++;
}

void limparTudo(){
    struct Ocorrencia *oco = filaOcorrencias;
    struct Ocorrencia *ant = NULL;

    while(oco != NULL){
        ant = oco;
        oco = oco->prox;
        free(ant);
    }

    struct UnidadeServico *uni = listaDeServicos;
    struct UnidadeServico *antUni = NULL;

    while(uni != NULL){
        antUni = uni;
        uni = uni->prox;
        free(antUni);
    }

    struct Cidadao *cid = listaCidadoes;
    struct Cidadao *antC = NULL;

    while(cid != NULL){
        antC = cid;
        cid = cid->prox;
        free(antC);
    }

    int indice;

    for(indice = 0; indice < 50; indice++){
        struct Bairro *bai = tabelaHashing[indice];
        struct Bairro *antBai = NULL;

        while(bai != NULL){
            antBai = bai;
            bai = bai->prox;
            free(antBai);
        }
    }
    



}