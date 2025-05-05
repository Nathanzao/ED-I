#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 10
/*
O hashing é dar uma chave e ela indicar um endereço em certo armazenamento: mostra o indice de alguma informação.
*/

struct Pessoa {
    int matricula; /* vai ser a chave */
    char nome[10];
};

struct Pessoa tabelaHashing[MAX]; /* Variavel global. */

void inicializaTabela(){
    for(int i = 0; i < MAX; i++){
        tabelaHashing[i].matricula = -1;
    }
}

int gerarCodigo(int matri){
    return matri % MAX; /* Será nossa metragem de valores. Só é "% MAX", por conta que na hora de colocar uma pessoa, caso o indice gerado esteja ocupado, iriamos incrementar +1. Mas imagina caso seja o último caso. */
}

struct Pessoa lerTeclado(){ /* Armazenar os dados de uma pessoa. */
    struct Pessoa p;
    printf("Digite o valor da matricula: ");
    scanf("%d", &p.matricula);
    fflush(stdin);
    printf("\nDigite o nome: ");
    fgets(p.nome, 10, stdin);


    return p;
}

int verificaCheia(){
    for(int i = 0; i < MAX; i++){
        if(tabelaHashing[i].matricula == -1){
            return 0;
        }
    }
    return 1;
}

void inserePessoa(){ /*  */
    if((verificaCheia()) == 1){
        printf("\n\nTabela cheia.\n\n");
        return;
    }
    
    struct Pessoa p = lerTeclado();
    int indice = gerarCodigo(p.matricula);

    while(tabelaHashing[indice].matricula != -1){
        indice = gerarCodigo(indice + 1);
    }
    tabelaHashing[indice] = p;

}

void removePessoa(int matri){
    int indice = gerarCodigo(matri);
    int contador = 0;


    while(tabelaHashing[indice].matricula != matri){
        indice = gerarCodigo(indice + 1);
        contador++;

        if(contador == MAX){
            printf("\nPessoa nao encontrada.\n");
            return;
        }
    }
    
    tabelaHashing[indice].matricula = -1;
}

struct Pessoa* buscar(int matri){
    int indice = gerarCodigo(matri);
    while(tabelaHashing[indice].matricula != -1){ /* Se achar -1, é porque não está na tabela. */
        if(tabelaHashing[indice].matricula == matri){
            return &tabelaHashing[indice];
        }else{
            indice = gerarCodigo(indice + 1);
        }
    }
    return NULL;
}

void imprimir(){
    for(int i = 0; i < MAX; i++){
        if(tabelaHashing[i].matricula != -1){
            printf("%d(indice) : %d(matricula) e %s", i, tabelaHashing[i].matricula, tabelaHashing[i].nome);
        }else{
            printf("%d indice esta vazio.\n", i);
        }
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");



    inicializaTabela();

    inserePessoa();
    printf("\n\n");
    inserePessoa();

    printf("\n\n");

    imprimir();

    struct Pessoa *pp = buscar(123);
    if(pp == NULL){
        printf("\n\nMatricula nao encontrada.\n");
    }else{
        printf("\nVerificando se os dados batem: \n");
        printf("Matricula: %d.\n", pp->matricula);
        printf("Nome: %s", pp->nome);
    }

    printf("\n\n");

    removePessoa(222);

    imprimir();
    

return 0;
}