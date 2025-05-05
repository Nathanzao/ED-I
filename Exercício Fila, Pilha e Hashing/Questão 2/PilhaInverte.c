#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define TAM 15

/*

2. Escreva  uma  função  que,  utilizando  a  Estrutura  de  Dados Pilha,  inverta  a ordem  das  letras  de 
cada palavra de uma string, preservando a ordem das palavras. Por exemplo, dado o texto 
ESTRUTURAS DE DADOS DA UNESP a saída deve ser PSENU AD SODAD ED SARUTURTSE. 

Implementar função que, através de uma pilha, inverta os caracteres de uma string.
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

void trocaOrdem(struct Pilha *p, char *caracteres){
    int tamanho = strlen(caracteres);
    char copia[tamanho], c;

    int i = 0;
    while(i < tamanho){
        push(p, caracteres[i]);
        i++;
    }

    i = 0;
    while(i < tamanho){
        pop(p, &c);
        copia[i] = c;
        i++;
    }

    copia[tamanho] = '\0';

    printf("%s", copia);
}

int main (){
setlocale(LC_ALL, "Portuguese");

    struct Pilha p;

    inicializa(&p);

    char nome[TAM] = "Nathan Arroz";

    trocaOrdem(&p, nome);

    /* printf("Nome alterado: %s", nome);
    printf("\n\n"); */

return 0;
}
