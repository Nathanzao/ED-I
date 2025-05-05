#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
1. Cria uma string vazia, deve ser usada antes de qualquer outra operação
2. Reinicializa uma string existente, através da remoção de todos os elementos contidos nela
3. Imprime uma string dinâmica
4. Função que retorna o tamanho de uma string dinâmica
5. Insere um determinado caracter (c) na string (str1)
6. Copia o conteúdo da string (str1) para a string (str2) utilizando o função insere
7. Concatena a string (str1) com a string (str2) armazenando o resultado na string (str3)
utilizando a função copia
8. Remove da string (str1), a quantidade de caracteres especificado por (nro) a partir da posição
(start)
9. Insere na string (str1) uma substring (subs) a partir da posição (start). A inserção não deve
ser feita no fim da string. Inserção no fim deve usar a concatenação de strings
10. Função que verifica se uma string (str1) é menor que outra (str2), caso verdade a função
retorna True, senão False
11. Função que verifica se uma string (str1) é igual a outra (str2), caso verdade a função retorna
True, senão False
12. Busca a posição (local) na string (str1) em que a string (padrão) se inicia. Se (local) = 0
então (padrão) não esta contida em str1, caso contrário (local) e a posição de início da string
(padrão) dentro da string (str1)

FALTOU A 12. ALÉM DE QUE, SERIA BOM DAR UMA REVISADA. TEM VARIAS COISAS PRÉ-ASSUMIDAS E MAL FEITAS NOS CÓDIGOS.
*/

struct no{
    char caractere;
    struct no *prox;
};

struct Lista {
    struct no *priElem;
    struct no *ultElem;
};

void inicializa(struct Lista *l){
    l->priElem = NULL;
    l->ultElem = NULL;
}


void LiberaLista(struct Lista *l){
    struct no *p = l->priElem;

    while(p != NULL){
        struct no *pp = p;
        p = p->prox;
        free(pp);
    }
    free(p);
}

void criaStructVazia(struct Lista *l){
    struct no *No = (struct no*) malloc(sizeof(struct no));
    No->caractere = NULL;
    No->prox = NULL;

    l->priElem = No;
    l->ultElem = No;
}

void ReinicializaString(struct Lista *l){
    struct no *p = l->priElem;

    while(p != NULL){
        p->caractere = NULL;
        p = p->prox;
    }
}

void Imprime(struct Lista *l){
    struct no *p = l->priElem;

    while(p != NULL){
        printf("%c", p->caractere);
        p = p->prox;
    }
}

int tamanho(struct Lista *l){
    struct no *p = l->priElem;
    int contador = 0;

    while(p != NULL){
        contador++;
        p = p->prox;
    }

    return contador;
}


void insereNoComeco(struct Lista *l, char caractere){
    struct no *No = (struct no*) malloc(sizeof(struct no));
    No->caractere = NULL;
    No->prox = NULL;

    No->caractere = caractere;

    if(l->priElem == NULL){
        l->priElem = No;
        l->ultElem = No;
    }else{
        No->prox = l->priElem;
        l->priElem = No;
    }
}

void insereNoFim(struct Lista *l, char caractere){
    struct no *No = (struct no*) malloc(sizeof(struct no));
    No->caractere = NULL;
    No->prox = NULL;

    No->caractere = caractere;

    if(l->priElem == NULL){
        l->priElem = No;
        l->ultElem = No;
    }else{
        No->prox = l->priElem;
        l->ultElem = No;
    }
}

void CopiaConteudoMesmaString(struct Lista *l, int qualIndice, int qualString){/* 7 */
    struct no *p = l->priElem;
    struct no *pp = p;
    int contador = 0;

    while (qualIndice != 0){
        pp = pp->prox;
        qualIndice--;
    }

    if(qualString == 0){
        p->caractere = pp->caractere;
    }else{
        while(contador != qualString){
            p = p->prox;
            contador++;
        }
        p->caractere = pp->caractere;
    }

}

void CopiaConteudoStringsDiferentes(struct Lista *l, struct no *p){ /* 7.5 */
    struct no *pp = l->priElem;

    while(pp != NULL){
        p->caractere = pp->caractere;
        p = p->prox;
        pp = pp->prox;
    }
}

void CopiaStringInicio(struct Lista *l, struct Lista *l2){
    struct no *No = l->priElem;
    char c;

    while(No != NULL){
        c = No->caractere;
        insereNoComeco(l2, c);
        No = No->prox;
    }
}

void CopiaStringFinal(struct Lista *l, struct Lista *l2){
    struct no *No = l->priElem;
    char c;

    while(No != NULL){
        c = No->caractere;
        insereNoFim(l2, c);
        No = No->prox;
    }
}

void Concatena(struct Lista *l, struct Lista *l2, struct Lista *l3){ /* Se a gente tirasse o n2 como ponteiro, precisariamos do pp? */
    struct no *p = l->priElem;
    struct no *p2 = l2->priElem;

    while(p != NULL){
        CopiaString(l, l3); 
    }

    while(p2 != NULL){
        CopiaString(l2, l3);
    }
}

void RemovePelaQuantidadeIndicada(struct Lista *l, int quantidade){
    struct no *p = l->priElem;
    int contador = 0;

    while(contador != quantidade){
        struct no *aux = p;
        p = p->prox;
        free(aux);
        contador++;
    }
}

void insereNoStart(struct Lista *l, struct Lista *l2, int comeco){
    struct no *p = l->priElem;
    struct no *pp = l2->priElem;
    int contador = 0;

    if(comeco == tamanho(l)){
        CopiaStringFinal(l2, l);
    }else{
        while(contador != comeco){
            p = p->prox;
        }
    
        while(p != NULL){
            p->caractere = pp->caractere;
            pp = pp->prox;
            p = p->prox;
        }
    }
}

int ComparaTamanhoDuasStrings(struct Lista *l, struct Lista *l2){
    if((tamanho(l)) > (tamanho(l2))){
        return 1;
    }else{
        return 0;
    }
}

int ComparaDuasStrings(struct Lista *l, struct Lista *l2){
    struct no *p = l->priElem;
    struct no *pp = l2->priElem;

    if((tamanho(l)) == (tamanho(l2))){
        while(p != NULL){
            if(p->caractere != pp->caractere){
                return 0;
            }
            p = p->prox;
            pp = pp->prox;
        }
        return 1;
    }else{
        return 0;
    }
}

int main (){
setlocale(LC_ALL, "Portuguese");

    struct Lista l;


LiberaLista(&l);
return 0;
}