#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 11
/*
11. Desenvolva uma função de inclusão de dados em um arquivo binário utilizando uma função hash 
(não esqueça de pensar em uma função ótima) para calcular o endereço físico de cada elemento baseado 
na  chave  (a  chave  deve  ser  uma  sequência  de  caracteres).  Definia  um  método  para  o  tratamento  de 
colisões
*/

struct Pessoa {
    int matricula; /* vai ser a chave */
    char nome[10];
    struct Pessoa *prox;
};

struct Pessoa *tabelaHashing[MAX]; /* Variavel global. */

void inicializa(){
    for(int i = 0; i < MAX; i++){
        tabelaHashing[i] = NULL;
    }
}

int gerarCodigo(int matri){
    return matri % MAX;
}

struct Pessoa* lerTeclado(struct Pessoa *p){
    
    printf("Digite o nome: ");
    fgets(p->nome, 10, stdin);
    fflush(stdin);
    printf("Digite a matricula: ");
    scanf("%d", &p->matricula);

    return p;
}

void insere(){
    struct Pessoa *pp = malloc(sizeof(struct Pessoa));
    
    lerTeclado(pp);
    pp->prox = NULL; /* Declarando o NULL apenas. */

    int indice = gerarCodigo(pp->matricula);

    pp->prox = tabelaHashing[indice]; /* Veja que não tem problema caso seja o 1 valor do indice pois, na primeira tentativa, tabelaHashing[indice] = NULL.  */
    tabelaHashing[indice] = pp;

}

struct Pessoa* busca(int matri){
    int indice = gerarCodigo(matri);
    struct Pessoa *p = tabelaHashing[indice];
    while(p != NULL && p->matricula != matri){
        p = p->prox;
    }

    if(p == NULL){
        printf("\nPessoa nao encontrada.\n\n");
        return NULL;
    }
    if(p->matricula == matri){
        printf("\nPessoa encontrada no indice %d correto.\n\n", indice);
        return p;
    }
}



void imprimir(){
    int i = 0;
    
    while(i < MAX){
        struct Pessoa *p = tabelaHashing[i];
        if(p == NULL){
            printf("\n%d indice vazio.\n", i);
        }else{
            while(p != NULL){
                printf("\nIndice %d, matricula %d e nome %s", i, p->matricula, p->nome);
                p = p->prox;
            }
        }
        i++;
        
    }
}

void removePessoa(int matri){
    int indice = gerarCodigo(matri);
    struct Pessoa *p = tabelaHashing[indice];
    struct Pessoa *ant = NULL;

    while(p != NULL && p->matricula != matri){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        printf("\nPessoa nao encontrada.\n\n");
        return;
    }

    if (ant == NULL) {
        tabelaHashing[indice] = p->prox; /* Primeiro no. */
        free(p);
    } else {
        ant->prox = p->prox;
        free(p);
    }


}

void liberaTabela() {
    for (int i = 0; i < MAX; i++) {
        struct Pessoa *p = tabelaHashing[i];
        while (p != NULL) {
            struct Pessoa *temp = p;
            p = p->prox;
            free(temp);
        }
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");

    insere(); /* 5 */
    printf("\n\n");
    fflush(stdin);
    insere(); /* 28 */
    printf("\n\n");


    imprimir();
    printf("\n\n");

    removePessoa(34);
    printf("\n\n");

    imprimir();
    printf("\n\n");

    busca(34);






 
    
liberaTabela();
return 0;
}