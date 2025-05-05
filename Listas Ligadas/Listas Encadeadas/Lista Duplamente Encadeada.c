#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Lista com ponteiro para o anterior e ao próximo.
*/

struct Nod{
    int elemento;
    struct Nod *anterior;
    struct Nod *proximo;
};

struct Lista{
    struct Nod *primElemento;
    struct Nod *ultimElemento;
};

void InicializaLista(struct Lista *l){
    l->primElemento = NULL;
    l->ultimElemento = NULL;
}

void insereNoInicio(int elem, struct Lista *List) {
    struct Nod *novoNo; // cria o novo elemento
    novoNo = (struct Nod*) malloc (sizeof(struct Nod));

    novoNo->elemento= elem;
    novoNo->proximo = novoNo->anterior = NULL;
    
    if (List->primElemento == NULL) { // se a lista está vazia
        List->ultimElemento = novoNo; //configura o último elemento da lista
    } else {                          //configura o atributo Ant do priElem para referenciar o novoNo, somente se o mesmo existir (lista não vazia)
        novoNo->proximo = List->primElemento;
        List->primElemento->anterior = novoNo;
    }
    
    List->primElemento = novoNo;      //o novo elemento passa a ser o primeiro da lista
}

void RemoveNo(int elementoD, struct Lista *lista){
    struct Nod *p = lista->primElemento;

    while(p != NULL && p->elemento != elementoD){
        p = p->proximo;
    }

    if(p->anterior == NULL){ /* Primeiro elemento da lista. */
        lista->primElemento = p->proximo;
        p->proximo->anterior = NULL;
    }else if(p->proximo == NULL){ /* Ultimo elemento da lista. */
        lista->ultimElemento = p->anterior;
        p->anterior->proximo = NULL;
    }else{ /* Meio da lista. */
        p->anterior->proximo = p->proximo;
        p->proximo->anterior = p->anterior;
    }

}

void Imprime(struct Lista *lista){
    struct Nod *p = lista->primElemento;

    while(p != NULL){
        printf("%d ", p->elemento);
        p = p->proximo;
    }

}

void LiberaLista(struct Lista *l){
    struct Nod *p = l->primElemento;
    while( p != NULL){
        struct Nod *pp = p;
        p = p->proximo;
        free(pp);
    }
    free(p);
}

int main (){
setlocale(LC_ALL, "Portuguese");
    struct Lista lista;
    InicializaLista(&lista);

    insereNoInicio(3, &lista);
    insereNoInicio(2, &lista);

    Imprime(&lista);

return 0;
}